#ifndef _AI3_HEAP_H
#define _AI3_HEAP_H

#include <iostream>
#include <vector>

template<class T>
class Heap {
public:
    Heap();
    void push(T);
    T poll();
    T peek();
    int getSize();
    std::vector<T> getData();
    void sort();
    void print();
private:
    int parent(int);
    int left(int);
    int right(int);
    void fixUp();
    void fixDown();
    std::vector<T> data;
    int size;
};

template<class T>
Heap<T>::Heap() : size(0) {}

template<class T>
int Heap<T>::getSize() {
    return size;
}

template<class T>
int Heap<T>::parent(int i) {
    return i / 2;
}

template<class T>
int Heap<T>::left(int i) {
    return i * 2;
}

template<class T>
int Heap<T>::right(int i) {
    return (i * 2) + 1;
}

template<class T>
void Heap<T>::fixDown() {
    int i = 0;
    while (i < size) {
        int largest = i;
        int l = left(i + 1) - 1;
        int r = right(i + 1) - 1;
        if (l < size && data[l] > data[largest]) {
            largest = l;
        }
        if (r < size && data[r] > data[largest]) {
            largest = r;
        }
        if (largest != i) {
            T tmp = data[i];
            data[i] = data[largest];
            data[largest] = tmp;
            i = largest;
        }
        else {
            break;
        }
    }
}

template<class T>
void Heap<T>::fixUp() {
    int i = size - 1;
    while (i > 0) {
        int p = parent(i + 1) - 1;
        if (data[p] < data[i]) {
            T tmp = data[i];
            data[i] = data[p];
            data[p] = tmp;
        }
        else break;
    }
}

template<class T>
void Heap<T>::push(T e) {
    data.push_back(e);
    size++;
    fixUp();
}

template<class T>
T Heap<T>::peek() {
    return data[0];
}

template<class T>
T Heap<T>::poll() {
    T tmp = data[0];
    data[0] = data[size - 1];
    data.pop_back();
    size--;
    fixDown();
    return tmp;
}

template<class T>
std::vector<T> Heap<T>::getData() {
    return data;
}

template<class T>
void Heap<T>::sort() {
    while (size != 0) {
        T tmp = data[0];
        data[0] = data[size - 1];
        data[size - 1] = tmp;
        size--;
        fixDown();
    }
}

template<class T>
void Heap<T>::print() {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

#endif