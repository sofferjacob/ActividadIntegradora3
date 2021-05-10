/*
entry_node.h
Stores an entry from
the log.
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#ifndef _ENTRY_NODE_H
#define _ENTRY_NODE_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "ip.h"

class EntryNode {
public:
    // Takes the full entry as a string
    EntryNode(std::string);
    // Returns the stored IP address
    Ip getIp();
    // Returns the full entry as a string
    std::string getEntry();
    // Returns a vector containing the parts of the entry
    std::vector<std::string> getParts();
    // Returns true if this object's IP addres is greater than
    // than the rarg.
    bool operator >(EntryNode&);
    // Returns true if this object's IP addres is lesser than
    // than the rarg.
    bool operator <(EntryNode&);
private:
    std::vector<std::string> parts;
    std::string entry;
    Ip ip;
};

EntryNode::EntryNode(std::string e) : entry(e) {
    int strPos = entry.find(" ");
    int lastPos = 0;
    while (strPos != std::string::npos) {
        parts.push_back(entry.substr(lastPos, strPos - lastPos));
        lastPos = strPos + 1;
        strPos = entry.find(" ", lastPos);
    }
    parts.push_back(entry.substr(lastPos, entry.length() - (lastPos)));
    if (parts.size() < 4) {
        throw std::invalid_argument("Could not parse entry");
    }
    ip.setAddress(parts.at(3));
}

Ip EntryNode::getIp() {
    return ip;
}

std::string EntryNode::getEntry() {
    return entry;
}

std::vector<std::string> EntryNode::getParts() {
    return parts;
}

bool EntryNode::operator >(EntryNode& other) {
    return ip > other.ip;
}

bool EntryNode::operator <(EntryNode& other) {
    return ip < other.ip;
}

#endif