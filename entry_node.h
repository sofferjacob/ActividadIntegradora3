#ifndef _AI3_ENTRY_NODE_H
#define _AI3_ENTRY_NODE_H

#include <algorithm>
#include "node.h"

class EntryNode : public Node {
public:
    EntryNode(std::string);
    // bool operator>(EntryNode&);
    // bool operator<(EntryNode&);
    // // This is not a hard equal.
    // // Returns true if both objects
    // // have the same IP address.
    // bool operator==(EntryNode&);
    std::string getEntry();
private:
    int getFactor();
    std::string entry;
    int ipNum;
};

EntryNode::EntryNode(std::string entry) : Node(entry) {
    this->entry = entry;
    std::string tmp = getIp();
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '.'), tmp.end());
    ipNum = std::stoi(tmp);
}

std::string EntryNode::getEntry() {
    return entry;
}

int EntryNode::getFactor() {
    return ipNum;
}

// bool EntryNode::operator>(EntryNode& other) {
//     return ipNum > other.ipNum;
// }

// bool EntryNode::operator<(EntryNode& other) {
//     return ipNum < other.ipNum;
// }

// bool EntryNode::operator==(EntryNode& other) {
//     return (getIp()) == (other.getIp());
// }

#endif