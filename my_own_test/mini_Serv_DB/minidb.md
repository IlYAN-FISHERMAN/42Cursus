-# MINIDB
 Write a program that will store a database of key-values. Your program will be launched with a port and a path to a file.
 Upon receiving SIGINT, you must save the contents of the database to the file, and read it back when launching mini_db.
 In order to communicate to the database, you will listen on the port given as a first argument. You must support the GET, POST and DELETE operations.
 Once your server is ready, you must write "ready\n" on the standard output. The keys and values will never have a space in them and will be alphanumeric, no need to check. A command will not be larger than 1000 characters.
 Examples:
 \> echo "POST A B" | nc 127.0.0.1 8080
 \> 0
 \> echo "GET A" | nc 127.0.0.1 8080
 \> 0 B
 \> echo "GET C" | nc 127.0.0.1 8080
 \> 1
 \> echo "DELETE A" | nc 127.0.0.1 8080
 \> 0
 \> echo "DELETE dontexist" | nc 127.0.0.1 8080
 \> 1
 \> echo "UNKNOWN_COMMAND" | nc 127.0.0.1 8080
 \> 2
 A client can issue multiple commands in one session, and can send multiple commands in one go, separated by a "\n".

Expected files: *.cpp, *.hpp
Allowed functions: *
