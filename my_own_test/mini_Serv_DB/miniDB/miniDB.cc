#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <poll.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <map>
#include <signal.h>
#include <sstream>

#define PORT 8080
#define MAX_CLIENTS 1024
#define BUFFER_SIZE 1024

bool sigHandler = false;

void getData(std::map<std::string, std::string> &database, std::ifstream &_inputFile){
	std::string key;
	std::string value;

	while (_inputFile >> key >> value)
		database.insert(std::make_pair(key, value));
	_inputFile.close();
}

void handleSigint(int sig){
	std::cout << "SIGINT\n";
	(void)sig;
	sigHandler = true;
}

void copyData(std::map<std::string, std::string> &database){
	if (!database.empty()){
		std::ofstream outfile("data.txt");
		for (std::map<std::string, std::string>::iterator i = database.begin(); i != database.end(); i++)
			if (!i->second.empty())
				outfile << i->first << " " << i->second << " ";
		outfile.close();
	}
	std::exit(2);
}

void parsBody(std::string &msg, std::map<std::string, std::string> &data, int fd){
	
	std::vector<std::string> body;
	std::string tmp;
	for (size_t ite = msg.find("\\n"); ite < msg.size(); ite = msg.find("\\n"))
		msg.at(ite) = ' ';
	std::stringstream ss(msg);
	while (ss >> tmp)
		body.push_back(tmp);
	for (std::vector<std::string>::iterator it = body.begin(); it != body.end() && it < body.end() && it >= body.begin();){
		if (*it == "POST"){
			it++;
			data.insert(std::make_pair(*it, *(++it)));
			send(fd, "0\n", 2, 0);
			it++;
		}
		else if (*it == "GET"){
			it++;
			std::string lol = data[*it];
			if (lol.empty())
				send(fd, "1\n", 2, 0);
			else{
				lol = "0 " + lol + "\n";
				send(fd, lol.c_str(), lol.size(), 0);
			}
			it++;
		}
		else if (*it == "DELETE"){
			it++;
			if (data[*it].empty())
				send(fd, "1\n", 2, 0);
			else{
				data.erase(*it);
				send(fd, "0\n", 2, 0);
			}
			it++;
		}
		else{
			send(fd, "2\n", 2, 0);
			it++;
		}
	}
}

int main(int ac, char **av) {
	std::ifstream _inputFile;
	std::map<std::string, std::string> database;
	std::string test;

	if (ac != 2){
		std::cerr << "Error: no port specified" << std::endl;
		return (1);
	}
	signal(SIGINT, handleSigint);
	signal(SIGPIPE, SIG_IGN);
	_inputFile.open("data.txt");
	if (_inputFile.is_open())
		getData(database, _inputFile);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(av[1]));

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0 || listen(server_fd, 5) < 0)
        return 1;

	std::vector<pollfd> fds;
    fds.push_back(pollfd{server_fd, POLLIN | POLLOUT, 0});  // On surveille le serveur pour les nouvelles connexions

    std::cout << "ready" << std::endl;
	std::string msg;
    while (!sigHandler)
	{
		int rtn = poll(fds.data(), fds.size(), -1);
        if (rtn < 0)
            break;
        for (size_t i = 0; i < fds.size(); ++i)
		{
			if (fds[i].revents & POLLIN)
			{
				if (fds[i].fd == server_fd){
					sockaddr_in newClient{};
                    socklen_t clientLent = sizeof(newClient);
					int client_fd = accept(server_fd, (sockaddr*)&newClient, &clientLent);
                    if (client_fd >= 0)
						fds.push_back({client_fd, POLLIN | POLLOUT, 0});
                }
				else {
					char buffer[BUFFER_SIZE]{};
					ssize_t n = read(fds[i].fd, buffer, sizeof(buffer)-1);
					if (n <= 0){
						close(fds[i].fd);
						fds.erase(fds.begin() + i);
						if (i > 0)
							i--;
						msg.clear();
					}else {
						msg += buffer;
					}
                }
            }
			else if (fds[i].revents & POLLOUT){
				parsBody(msg, database, fds[i].fd);
				msg.clear();
			}
        }
    }
	if (sigHandler == true)
		copyData(database);

    close(server_fd);
    return 0;
}
