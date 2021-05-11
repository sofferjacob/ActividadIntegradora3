/*
ip.cpp
IP class methods definition
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#include <stdexcept>
#include <cmath>
#include "ip.h"

Ip::Ip() : address(""), weight(0) {}

Ip::Ip(std::string ip) : weight(0) {
    setAddress(ip);
}

std::string Ip::getAddress() {
    return address;
}

void Ip::setAddress(std::string ip) {
    address = ip.substr(0, ip.find(":"));
    int strPos = address.find(".");
    int lastPos = 0;
    while (strPos != std::string::npos) {
        octets.push_back(stoi(address.substr(lastPos, strPos - lastPos)));
        lastPos = strPos + 1;
        strPos = address.find(".", lastPos);
    }
    octets.push_back(stoi(address.substr(lastPos, address.length() - (lastPos))));
    if (octets.size() != 4) {
        throw std::invalid_argument("Invalid IP address");
    }
    weight = (pow(octets[0], 4) + pow(octets[1], 3) + pow(octets[2], 2) + octets[3]);
}

std::vector<int> Ip::getOctets() {
    return octets;
}

bool Ip::operator >(const Ip& other) {
    return weight > other.weight;
}

bool Ip::operator >=(const Ip& other) {
    return weight >= other.weight;
}

bool Ip::operator <(const Ip& other) {
    return weight < other.weight;
}

bool Ip::operator <=(const Ip& other) {
    return weight <= other.weight;
}

bool Ip::operator ==(const Ip& other) {
    return weight == other.weight;
}

bool Ip::operator !=(const Ip& other) {
    return weight != other.weight;
}