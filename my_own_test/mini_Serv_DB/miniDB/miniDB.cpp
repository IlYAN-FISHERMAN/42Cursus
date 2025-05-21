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

	std::cout << "Get data\n";
	while (_inputFile >> key >> value)
		database.insert(std::make_pair(key, value));
	_inputFile.close();
}

void handleSigint(int sig){
	std::cout << "SIGINT\n";
	sigHandler = true;
	(void)sig;
}

void copyData(std::map<std::string, std::string> &database){
	std::cout << "Copy data\n";
	if (!database.empty()){
		std::ofstream outfile("data.txt");
		for (std::map<std::string, std::string>::iterator i = database.begin(); i != database.end(); i++)
			outfile << i->first << " " << i->second << " ";
		outfile.close();
	}
	std::exit(2);
}

std::string parsBody(const char *buffer, std::map<std::string, std::string> &data){
	std::stringstream ss(buffer);
	std::vector<std::string> body;
	std::string tmp;
	while (ss >> tmp)
		body.push_back(tmp);
	for (std::vector<std::string>::iterator it = body.begin(); it != body.end();){
		if (*it == "POST"){
			it++;
			data.insert(std::make_pair(*it, *(++it)));
			return ("0");
		}
		else if (*it == "GET"){
			it++;
			std::string lol = data[*it];
			if (lol.empty())
				return "1";
			else
				return ("0 " + lol);
		}
		else if (*it == "DELETE"){
			it++;
			if (data[*it].empty())
				return ("1");
			else{
				data.erase(*it);
				return ("0");
			}
		}
		else
			return "2";
	}
	return ("3");
}

int main() {
	std::ifstream _inputFile;
	std::map<std::string, std::string> database;
	std::string test;

	signal(SIGINT, handleSigint);
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
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        return 1;
    }

	std::vector<pollfd> fds;
    fds.push_back(pollfd{server_fd, POLLIN, 0});  // On surveille le serveur pour les nouvelles connexions

    std::cout << "ready" << std::endl;
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
					std::cout << "newclient\n";
					sockaddr_in newClient{};
                    socklen_t clientLent = sizeof(newClient);
					int client_fd = accept(server_fd, (sockaddr*)&newClient, &clientLent);
                    if (client_fd >= 0)
						fds.push_back({server_fd, POLLIN, 0});
                }
				else {
					std::cout << "read\n";
                    char buffer[BUFFER_SIZE];
					ssize_t n = read(fds[i].fd, buffer, sizeof(buffer));
					if (n <= 0){
						close(fds[i].fd);
						fds.erase(fds.begin() + i);
						// i--;
                    }else {
						std::cout << "parse\n";
                        std::string reply = parsBody(buffer, database) + "\n";
                        send(fds[i].fd, reply.c_str(), reply.size(), 0);
                    }
                }
            }
        }
    }
	if (sigHandler == true)
		copyData(database);

    close(server_fd);
    return 0;
}
