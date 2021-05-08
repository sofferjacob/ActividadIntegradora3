#ifndef _IP_H
#define _IP_H

#include <string>
#include <vector>
#include <iostream>

class Ip {
public:
    Ip(std::string);
    bool operator >(const Ip&);
    bool operator >=(const Ip&);
    bool operator <(const Ip&);
    bool operator <=(const Ip&);
    bool operator ==(const Ip&);
    bool operator !=(const Ip&);
    std::string address;
private:
    std::vector<int> octets;
};

Ip::Ip(std::string ip) : address(ip) {
    std::cout << "ip: " << ip << std::endl;
    int lastI = 0;
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') {
            octets.push_back(stoi(ip.substr(lastI + 1, i - lastI)));
            lastI = i;
        }
    }
}

bool Ip::operator >(const Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] > other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator >=(const Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] >= other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator <(const Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] < other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator <=(const Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] <= other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator ==(const Ip& other) {
    return address == other.address;
}

bool Ip::operator !=(const Ip& other) {
    return address != other.address;
}

#endif