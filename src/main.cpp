#include <iostream>
#include <fstream>
#include <vector>
#include "entry_node.h"
#include "count_node.h"
#include "heap.h"
#include "ip.h"

using namespace std;

int main() {
    Heap<EntryNode> records;
    Heap<CountNode> counted;
    cout << "Construyendo heap a partir de bitacora.txt ..." << endl;
    ifstream file("bitacora.txt");
    if (!file.good()) {
        file.close();
        //throw invalid_argument("File not found");
        cout << "Error: Archivo bitacora.txt no encontrado" << endl;
        return 1;
    }
    string currentLine;
    while (getline(file, currentLine)) {
        records.push(EntryNode(currentLine));
    }
    file.close();
    cout << "Heap construido" << endl;
    cout << "Ordenando datos..." << endl;
    records.sort();
    vector<EntryNode> orderedNodes = records.getData();
    ofstream orderedFile("bitacora_ordenada.txt");
    for (int i = 0; i < orderedNodes.size(); i++) {
        orderedFile << (orderedNodes[i].getEntry()) << endl;
    }
    orderedFile.close();
    cout << "Procesando datos..." << endl;
    while (orderedNodes.size() > 0) {
        CountNode c(orderedNodes.back().getIp(), orderedNodes.back().getEntry());
        orderedNodes.pop_back();
        while (orderedNodes.back().getIp() == c.getIp()) {
            c.push(orderedNodes.back().getEntry());
            orderedNodes.pop_back();
        }
        counted.push(c);
    }
    cout << "IPs con más accesos:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "#" << (i + 1) << endl;
        CountNode n = counted.poll();
        cout << n << endl;
    }
    return 0;
}