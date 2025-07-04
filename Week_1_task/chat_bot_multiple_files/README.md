# UDP Chat Bot (Multiple Files)

This directory contains a simple UDP-based chat bot implemented in C, split into separate server and client programs. The client sends messages to the server, and the server echoes or responds to the client.

## How It Works

- **UDP** (User Datagram Protocol) is a connectionless transport layer protocol. Unlike TCP, it does not establish a persistent connection or guarantee delivery, order, or error checking. It's fast and lightweight, making it suitable for simple messaging or streaming applications.
- In this implementation, the server listens for messages from any client and responds back using UDP sockets.
- The client sends messages to the server and displays the server's responses.

## How to Run

1. **Build the Programs**
   
   Compile both the server and client C files (adjust filenames if needed):

   ```bash
        gcc -o server server.c
        gcc -o client client.c
   ```

2. **Start the Server**

   Run the server first, specifying the port (e.g., 8080):

   ```bash
        ./server 8080
   ```

   **Output Example:**
   ```
   🟢 Server online. Waiting for client...
   ```

3. **Start the Client**

   In a new terminal, run the client, providing the server's IP (localhost, `127.0.0.1`) and port:

   ```bash
         ./client 127.0.0.1 8080
   ```

   **Output Example:**
   ```
   🟡 Client started. Type messages:
   You: hi
   Server: hello
   You:
   ```

4. **Chat Interaction**

   - Type messages in the client terminal. They will be sent to the server.
   - The server receives and displays the client's message, and you can type a reply in the server terminal.
   - The client displays the server's reply.

   **Example Session:**

   *Server terminal:*
   ```
   🟢 Server online. Waiting for client...
   Client: hi
   You (server): hello
   ```

   *Client terminal:*
   ```
   🟡 Client started. Type messages:
   You: hi
   Server: hello
   You:
   ```

## Explanation: Why UDP?

- **No Connection Overhead:** UDP does not require a handshake to establish a connection, making it faster for simple message exchanges.
- **No Guaranteed Delivery:** Messages may be lost or arrive out of order, but for quick chat applications or local network demos, this is acceptable.
- **Simple and Lightweight:** The code is easier to write and understand for learning purposes, focusing on socket programming basics.

## Notes

- Both server and client must be run from the same directory, or provide correct paths.
- The programs currently support basic message exchange and are intended for learning/demo purposes.

## Files

- `server.c` - UDP server implementation
- `client.c` - UDP client implementation

---

**Author:** jawahar  
**Contact:** jawaharr20  
