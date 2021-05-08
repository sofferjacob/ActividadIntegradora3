#include <iostream>
#include <fstream>
#include <vector>
#include "node.h"
#include "entry_node.h"
#include "count_node.h"
#include "heap.h"
#include "ip.h"

using namespace std;

int main() {
    Heap<EntryNode> records;
    Heap<CountNode> counted;
    cout << "Building heap..." << endl;
    ifstream file("bitacora.txt");
    if (!file.good()) {
        file.close();
        throw invalid_argument("File not found");
        return 0;
    }
    string currentLine;
    while (getline(file, currentLine)) {
        records.push(EntryNode(currentLine));
    }
    file.close();
    cout << "Heap built" << endl;
    records.sort();
    vector<EntryNode> orderedNodes = records.getData();
    ofstream orderedFile("bitacora_ordenada.txt");
    for (int i = 0; i < orderedNodes.size(); i++) {
        orderedFile << (orderedNodes[i].getEntry()) << endl;
    }
    orderedFile.close();
    while (orderedNodes.size() > 0) {
        CountNode c(orderedNodes.back().getEntry());
        orderedNodes.pop_back();
        while (orderedNodes.back().getIp() == c.getIp()) {
            c.push(orderedNodes.back().getEntry());
            orderedNodes.pop_back();
        }
        counted.push(c);
    }
    //vector<CountNode> topNodes;
    cout << "IPs con más accesos:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "#" << (i + 1) << endl;
        CountNode n = counted.poll();
        cout << n << endl;
    }
    // Heap<int> records;
    // records.push(4);
    // records.push(3);
    // records.push(4);
    // records.push(3);
    // records.push(4);
    // records.print();
    // cout << "begin sort" << endl;
    // records.sort();
    // cout << "end sort" << endl;
    // records.print();
    return 0;
}