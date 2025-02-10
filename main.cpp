#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    const std::string HOST = "your-own-test-server.com"; // Replace with your server
    const int PORT = 80;
    const std::string REQUEST = "GET / HTTP/1.1\r\nHost: " + HOST + "\r\n\r\n";

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Socket creation failed.\n";
        return 1;
    }

    // Define server address
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) { // Use your server's IP
        std::cerr << "Invalid address.\n";
        return 1;
    }

    // Connect to server
    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection failed.\n";
        return 1;
    }

    // Send HTTP request
    send(sock, REQUEST.c_str(), REQUEST.size(), 0);
    std::cout << "Sent 1 HTTP request to " << HOST << ".\n";

    // Close socket
    close(sock);
    return 0;
}
