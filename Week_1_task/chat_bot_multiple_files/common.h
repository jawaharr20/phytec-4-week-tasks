// common.h - Shared constants for UDP client/server communication

#ifndef COMMON_H   // Header guard to prevent multiple inclusion
#define COMMON_H

// Port number used for both server and client communication.
// Make sure this matches on both sides.
#define PORT 8080

// Maximum size of message buffer in bytes.
// This is used for both sending and receiving.
#define MAX_BUFFER_SIZE 1024

// Server IP address (client uses this to send messages).
// 127.0.0.1 means localhost (same device). Replace with actual IP on LAN.
#define SERVER_IP "127.0.0.1"

#endif  // End of COMMON_H

