//
// Created by Ellie Kunze on 9/27/22.
//

#ifndef LAB3_ABQ_H
#define LAB3_ABQ_H

#include <stdexcept>

using namespace std;
template <typename T>
class ABQ {
private:
    int capacity = 0;
    int size = 0;
    T *arr = nullptr;
public:

    ABQ();
    ABQ(int capacity);
    ABQ(const ABQ &d);
    ABQ &operator=(const ABQ &d);
    ~ABQ();
    void enqueue (T data);
    T dequeue ();
    T peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    T* getData();
    void moveQueue();
    void reduceCap(int capacity);
};

template<typename T>
ABQ<T>::ABQ() {
    capacity = 1;
    size = 0;
    arr = new T[capacity];
}

template<typename T>
ABQ<T>::ABQ(int capacity) {
    this->capacity = capacity;
    size = 0;
    arr = new T[capacity];
}

template<typename T>
ABQ<T>::~ABQ() {
    delete[] arr;
}

template<typename T>
unsigned int ABQ<T>::getSize() {
    return size;
}

template<typename T>
unsigned int ABQ<T>::getMaxCapacity() {
    return capacity;
}

template<typename T>
T* ABQ<T>::getData() {
    return arr;
}

template<typename T>
ABQ<T>::ABQ(const ABQ &d) {
    arr = nullptr;
    arr = new T[d.capacity()];
    capacity = d.capacity();
    this->size = d.size();
    for (unsigned int i = 0; i < d.size(); i++) {
        arr[i] = d.temp[i];
    }
}

template<typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ &d) {
    delete[] arr;
    arr = new T[d.capacity()];
    capacity = d.capacity();
    this->size = d.size();
    for (unsigned int i = 0; i < d.size(); i++) {
        arr[i] = d.temp[i];
    }
    delete[] d;
    return *this;
}

template<typename T>
T ABQ<T>::peek() {
    if (size == 0) {
        throw runtime_error("Runtime error");
    }
    return arr[0]; //what size should this be? temp?
}
//stores array arr from the front and puts it into temp.
// Deletes this front section of array and calls moveQueue to move arr over one space
// to the left if array empty, then array arr is dequeue
template<typename T>
T ABQ<T>:: dequeue() {
    if (size == 0) {
        throw runtime_error("Nothing to dequeue"); //nothing to dequeue
    }
    T tempElement = arr[0];
    size--;
    //shifting down
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i + 1];
    } //resize
    if (((double) capacity / (double) size) > 2) {
        reduceCap(capacity);
    }
    return tempElement;
}

template<typename T>
void ABQ<T>:: enqueue(T data) { //resized correctly
    if (size < capacity) {
        arr[size] = data;
        size++;
    }
    else {
        T* newQueue = new T[2* size];
        for (int i = 0; i < size; i++) {
            newQueue[i] = arr[i];
        }
        capacity = capacity * 2;
        delete[] arr;
        //arr = temp;
        newQueue[size] = data;
        size++;
        arr = newQueue;
    }
}

template<typename T>
void ABQ<T>:: reduceCap(int capacity)
{
    T *temp = new T[size];
    for ( int i = 0; i < size; i++) {
        temp[i] = arr[i]; //relook
    }
    delete[] arr;
    this->capacity = capacity / 2;
    arr = new T[this->capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
}

#endif //LAB3_ABQ_H
