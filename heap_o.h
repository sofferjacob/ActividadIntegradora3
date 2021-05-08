/*
heap.h
Heap implementation
Jacobo Soffer
A01028653
*/
#ifndef _DS_HEAP_H
#define _DS_HEAP_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

template<class T>
class Heap {
public:
    Heap();
    // Inserts an element to the heap
    void push(T);
    // Removes the element with the highest
    // priority from the heap. Throws
    // std::out_of_range if heap is empty.
    T poll();
    // Returns the element with the highest
    // priority from the heap. Throws
    // std::out_of_range if heap is empty.
    T peek();
    // Returns wether the heap is empty
    bool empty();
    // Returns the number of elements in the heap.
    int size();
    // Prints every element in the heap.
    void print();
    // Sorts through heap sort
    void sort();
    // Temp
    std::vector<T>& getData();
private:
    std::vector<T> data;
    void bubbleUp();
    void bubbleDown(int f = 0, int exclude = -1);
    int getParent(int);
    int getLChild(int);
    int getRChild(int);
};

template<class T>
std::vector<T>& Heap<T>::getData() {
    return data;
}

template<class T>
Heap<T>::Heap() {}

template<class T>
int Heap<T>::getParent(int i) {
    return (i - 1) / 2;
}

template<class T>
int Heap<T>::getLChild(int i) {
    return (i * 2) + 1;
}

template<class T>
int Heap<T>::getRChild(int i) {
    return (i * 2) + 2;
}

template<class T>
void Heap<T>::bubbleUp() {
    if (empty()) {
        throw std::out_of_range("Heap is empty");
    }
    int i = size() - 1;
    while (i != 0 && data.at(getParent(i)) < data.at(i)) {
        iter_swap(data.begin() + i, data.begin() + getParent(i));
        i = getParent(i);
    }
}

template<class T>
void Heap<T>::bubbleDown(int i, int to) {
    // if (empty()) {
    //     throw std::out_of_range("Heap is empty");
    // }
    // if (exclude == -1) {
    //     exclude = data.size() - 1;
    // }
    // int i = 0;
    // while (getLChild(i) < exclude) {
    //     int lChild = getLChild(i);
    //     int rChild = getRChild(i);
    //     int larger = i;
    //     if (lChild <= exclude && data.at(lChild) > data.at(larger)) {
    //         larger = lChild;
    //     }
    //     if (rChild <= exclude && data.at(rChild) > data.at(lChild)) {
    //         larger = rChild;
    //     }
    //     if (larger == i) break;
    //     iter_swap(data.begin() + i, data.begin() + larger);
    //     i = larger;
    // }
    if (to == -1) {
        to = (size()) - 1;
    }
    int l = getLChild(i);
    int r = getRChild(i);
    int smallest = i;
    if (l < to && data[l] > data[i])
        smallest = l;
    if (r < to && data[r] > data[smallest])
        smallest = r;
    if (smallest != i)
    {
        T tmp = data[i];
        data[i] = data[smallest];
        data[smallest] = tmp;
        bubbleDown(smallest, to);
    }
}

template<class T>
void Heap<T>::push(T e) {
    data.push_back(e);
    bubbleUp();
}

template<class T>
T Heap<T>::poll() {
    if (empty()) {
        throw std::out_of_range("Heap is empty");
    }
    T value = data.at(0);
    data[0] = data.at(size() - 1);
    data.pop_back();
    bubbleDown();
    return value;
}

template<class T>
T Heap<T>::peek() {
    if (empty()) {
        throw std::out_of_range("Heap is empty");
    }
    return data[0];
}

template<class T>
int Heap<T>::size() {
    return data.size();
}

template<class T>
bool Heap<T>::empty() {
    return size() == 0;
}

template<class T>
void Heap<T>::print() {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data.at(i) << " ";
    }
    std::cout << std::endl;
}

template<class T>
void Heap<T>::sort() {
    int lastI = data.size() - 1;
    while (lastI > 0) {
        T tmp = data[0];
        data[0] = data[lastI];
        data[lastI] = tmp;
        lastI--;
        bubbleDown(0, lastI);
        //print();
    }
}

#endif