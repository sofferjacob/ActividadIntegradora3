#ifndef _AI3_ENTRY_NODE_H
#define _AI3_ENTRY_NODE_H

#include <algorithm>
#include <vector>
#include <iostream>
#include "ip.h"

class EntryNode {
public:
    EntryNode(std::string);
    bool operator>(EntryNode&);
    bool operator<(EntryNode&);
    // This is not a hard equal.
    // Returns true if both objects
    // have the same IP address.
    bool operator==(EntryNode&);
    std::string getEntry();
    Ip getIp();
private:
    int getFactor();
    std::string entry;
    Ip ip;
};

EntryNode::EntryNode(std::string entry) : entry(entry), ip("10.15.189.242") {
    std::vector<std::string> parts;
    int lastI = 0;
    for (int i = 0; i < entry.length(); i++) {
        std::cout << i << std::endl;
        if (entry[i] == ' ') {
            parts.push_back(entry.substr(lastI + 1, i - lastI));
            lastI = i;
        }
    }
    std::cout << "exit for" << std::endl;
    ip = Ip(parts[3].substr(0, parts[3].find(":")));
}

std::string EntryNode::getEntry() {
    return entry;
}

bool EntryNode::operator>(EntryNode& other) {
    return ip > other.ip;
}

bool EntryNode::operator<(EntryNode& other) {
    return ip < other.ip;
}

bool EntryNode::operator==(EntryNode& other) {
    return (getIp()) == (other.getIp());
}

Ip EntryNode::getIp() {
    return ip;
}

#endif