/*
ip.h
Stores an IP address
and enables comparisons.
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#ifndef _IP_H
#define _IP_H

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

class Ip {
public:
    // Default constructor.
    // setAddress() must be
    // called before using 
    // object.
    Ip();
    // Takes an IPv4 address with port
    // as an argument. Fully initializes
    // the object.
    Ip(std::string);
    bool operator >(const Ip&);
    bool operator >=(const Ip&);
    bool operator <(const Ip&);
    bool operator <=(const Ip&);
    bool operator ==(const Ip&);
    bool operator !=(const Ip&);
    // Returns the stored IP address
    // as a string
    std::string getAddress();
    // Sets the IP address.
    // Takes an IPv4 address with port
    // as an argument
    void setAddress(std::string);
    // Returns a vector containing
    // every segment of the IP address
    // as an integer
    std::vector<int> getOctets();
private:
    // Weighted IP address value.
    // Used for comparisons
    double weight;
    std::vector<int> octets;
    std::string address;
};

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

#endif