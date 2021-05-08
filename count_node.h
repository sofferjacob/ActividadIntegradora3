#ifndef _AI3_COUNT_NODE_H
#define _AI3_COUNT_NODE_H

#include <iostream>
#include <vector>
#include "node.h"

class CountNode : public Node {
public:
    CountNode(std::string);
    // bool operator>(CountNode&);
    // bool operator<(CountNode&);
    // // This is not a hard equal.
    // // Returns true if both objects
    // // have the same entry count.
    // bool operator==(CountNode&);
    friend std::ostream& operator<<(std::ostream&, CountNode&);

    void push(std::string);
    int getCount();
private:
    std::vector<std::string> entries;
    int count;
    int getFactor();
};

CountNode::CountNode(std::string entry) : Node(entry) {
    entries.push_back(entry);
    count = 1;
}

int CountNode::getFactor() {
    return count;
}

// bool CountNode::operator>(CountNode& other) {
//     return count > other.count;
// }

// bool CountNode::operator<(CountNode& other) {
//     return count < other.count;
// }

// bool CountNode::operator==(CountNode& other) {
//     return (ip) == (other.ip);
// }

int CountNode::getCount() {
    return count;
}

void CountNode::push(std::string entry) {
    entries.push_back(entry);
    count++;
}

std::ostream& operator<<(std::ostream& out, CountNode& node) {
    out << "IP: " << node.ip << std::endl;
    out << "Accesos: " << node.count << std::endl;
    out << "Entradas:" << std::endl;
    for (int i = 0; i < node.count; i++) {
        out << node.entries[i] << std::endl;
    }
    return out;
}

#endif