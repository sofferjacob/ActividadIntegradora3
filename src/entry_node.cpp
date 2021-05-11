/*
entry_node.cpp
Entry Node methods
definition
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#include "entry_node.h"
#include <stdexcept>

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