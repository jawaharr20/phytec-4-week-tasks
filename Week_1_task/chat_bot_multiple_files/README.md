# UDP Chat Bot

This project is a simple UDP-based client-server chat application written in C.
It demonstrates basic socket programming and inter-process communication using UDP sockets.

Directory Structure

    chat_bot_multiple_files/
    ├── client/            # (May contain client-specific code or binaries) 
    ├── server/            # (May contain server-specific code or binaries)
    ├── common.h           # Shared header file with common definitions
    ├── udp_client.c       # UDP client implementation
    ├── udp_server.c       # UDP server implementation


# How It Works

The server listens for client messages on a specified port.
The client connects to the server at a given IP address and port, allowing two-way message exchange.
All communication is via UDP sockets.

# Compilation

First run the server 

       gcc udp_server.c -o server

 Then Run the Client

      gcc udp_client.c -o client

# Start the Server

    ./server <PORT>

example:

         ./server 8080


# start the client

        ./client <SERVER_IP> <PORT>

example

         ./client 127.0.0.1 8080
         

# chat example

Server terminal:

       Client: hi
       You (server): hello

Client terminal:

        You: hi
        Server: hello



Notes

    Both server and client must be running on the same network.
    The server must be started before the client connects.
    Use Ctrl+C to exit the server or client.
    The common.h file contains shared data structures or constants.

