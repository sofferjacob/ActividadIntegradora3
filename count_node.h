/*
count_node.h
Stores an IP address
and one or more entries from
a log.
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#ifndef _COUNT_NODE_H
#define _COUNT_NODE_H

#include <vector>
#include <string>
#include <iostream>
#include "ip.h"

class CountNode {
public:
    // Takes an Ip address and the first entry as a string
    CountNode(Ip, std::string entry);
    // Returns the number of entries stored as an integer
    int getCount();
    // Returns a vector containing the stored entries as a string
    std::vector<std::string> getEntries();
    // Returns the IP address stored
    Ip getIp();
    // Adds an entry
    void push(std::string);
    // Not a hard comparison.
    // Returns true if this object
    // has more entries than the rarg.
    bool operator >(CountNode&);
    // Not a hard comparison.
    // Returns true if this object
    // has less entries than the rarg.
    bool operator <(CountNode&);
    // Outputs the IP address and entry count to the stream
    friend std::ostream& operator<<(std::ostream& os, CountNode& cn);
private:
    int count;
    Ip ip;
    std::vector<std::string> entries;
};

CountNode::CountNode(Ip ip, std::string entry) : ip(ip), count(0) {
    push(entry);
}

void CountNode::push(std::string entry) {
    entries.push_back(entry);
    count++;
}

int CountNode::getCount() {
    return count;
}

Ip CountNode::getIp() {
    return ip;
}

std::vector<std::string> CountNode::getEntries() {
    return entries;
}

bool CountNode::operator >(CountNode& other) {
    return count > other.count;
}

bool CountNode::operator <(CountNode& other) {
    return count < other.count;
}

std::ostream& operator<<(std::ostream& os, CountNode& cn) {
    os << "Address: " << (cn.ip.getAddress()) << "; Count: " << cn.count;
    return os;
}

#endif