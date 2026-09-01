#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void findNetAndHost(const std::string& ip) {
    std::stringstream ss(ip);
    std::string token;
    std::vector<int> octets;

   
    while (std::getline(ss, token, '.')) {
        octets.push_back(std::stoi(token));
    }

    if (octets.size() != 4) {
        std::cout << "Invalid IPv4 format.\n";
        return;
    }

    int first_octet = octets[0];

    
    if (first_octet >= 0 && first_octet <= 127) {
        std::cout << "Class: A\n";
        std::cout << "NetID: " << octets[0] << ".0.0.0\n";
        std::cout << "HostID: " << octets[1] << "." << octets[2] << "." << octets[3] << "\n";
    } 
    else if (first_octet >= 128 && first_octet <= 191) {
        std::cout << "Class: B\n";
        std::cout << "NetID: " << octets[0] << "." << octets[1] << ".0.0\n";
        std::cout << "HostID: " << octets[2] << "." << octets[3] << "\n";
    } 
    else if (first_octet >= 192 && first_octet <= 223) {
        std::cout << "Class: C\n";
        std::cout << "NetID: " << octets[0] << "." << octets[1] << "." << octets[2] << ".0\n";
        std::cout << "HostID: " << octets[3] << "\n";
    } 
    else if (first_octet >= 224 && first_octet <= 239) {
        std::cout << "Class: D (Multicast - No NetID/HostID allocation)\n";
    } 
    else if (first_octet >= 240 && first_octet <= 255) {
        std::cout << "Class: E (Experimental - No NetID/HostID allocation)\n";
    } 
    else {
        std::cout << "Invalid IP address range.\n";
    }
}

int main() {
    std::string ip;
    std::cout << "Enter IPv4 address : ";
    std::cin >> ip;

    findNetAndHost(ip);

    return 0;
}