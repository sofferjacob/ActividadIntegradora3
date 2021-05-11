/*
count_node.cpp
CountNode class methods definition
Jacobo Soffer | A01028653
Modified: 10/05/21
*/
#include "count_node.h"

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