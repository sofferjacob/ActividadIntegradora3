#ifndef _AI3_NODE_H
#define _AI3_NODE_H

#include <string>

class Node {
public:
    Node(std::string);
    virtual bool operator>(Node&);
    virtual bool operator>=(Node&);
    virtual bool operator<=(Node&);
    virtual bool operator<(Node&);
    virtual bool operator==(Node&);
    std::string getIp();
protected:
    std::string ip;
    // Returns the comparison factor
    virtual int getFactor() = 0;
};

Node::Node(std::string entry) {
    ip = entry.substr(15, 14);
}

std::string Node::getIp() {
    return ip;
}

bool Node::operator>(Node& other) {
    return (getFactor()) > (other.getFactor());
}

bool Node::operator>=(Node& other) {
    return (getFactor()) >= (other.getFactor());
}

bool Node::operator<(Node& other) {
    return (getFactor()) < (other.getFactor());
}

bool Node::operator<=(Node& other) {
    return (getFactor()) <= (other.getFactor());
}

bool Node::operator==(Node& other) {
    return (getFactor()) == (other.getFactor());
}

#endif