#ifndef _IP_H
#define _IP_H

#include <string>
#include <vector>

class Ip {
public:
    Ip(std::string);
    bool operator >(Ip&);
    bool operator >=(Ip&);
    bool operator <(Ip&);
    bool operator <=(Ip&);
    bool operator ==(Ip&);
    bool operator !=(Ip&);
    const std::string address;
    //private:
    std::vector<int> octets;
};

Ip::Ip(std::string ip) : address(ip) {
    octets.push_back(stoi(ip.substr(0, 2)));
    octets.push_back(stoi(ip.substr(3, 2)));
    octets.push_back(stoi(ip.substr(6, 3)));
    octets.push_back(stoi(ip.substr(10, 3)));
}

bool Ip::operator >(Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] > other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator >=(Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] >= other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator <(Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] < other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator <=(Ip& other) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] <= other.octets[i]) return true;
        if (octets[i] != other.octets[i]) return false;
    }
    return false;
}

bool Ip::operator ==(Ip& other) {
    return address == other.address;
}

bool Ip::operator !=(Ip& other) {
    return address != other.address;
}

#endif