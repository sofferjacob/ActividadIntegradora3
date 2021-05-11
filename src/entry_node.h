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

#endif