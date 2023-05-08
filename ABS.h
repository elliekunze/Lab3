//
// Created by Ellie Kunze on 9/23/22.
//

#ifndef LAB3_ABS_H
#define LAB3_ABS_H
#include <stdexcept>
using namespace std;
template <typename T>
class ABS {
private:
    int capacity;
    int size;
    T *arr = nullptr;
    T *temp = nullptr;
public:

    ABS();
    ABS(int capacity);
    ABS(const ABS &d);
    ABS &operator=(const ABS &d);
    ~ABS();
    void push(T data);
    T pop();
    T peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    void reduceCap(int capacity);
};

    template<typename T>
    ABS<T>::ABS() {
        capacity = 1;
        size = 0;
        arr = new T[capacity];
    }

    template<typename T>
    ABS<T>::ABS(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new T[capacity];
    }

    template<typename T>
    ABS<T>::~ABS() {
        delete[] arr;
    }

    template<typename T>
    ABS<T>::ABS(const ABS &d) {
        arr = new T[d.capacity()];
        capacity = d.capacity();
        this->size = d.size();
        for (unsigned int i = 0; i < d.size(); i++) {
            arr[i] = d.arr[i];
        }
        delete[] d;
    }

template<typename T>
ABS<T>& ABS<T>::operator=(const ABS &d) {
    arr = new T[d.capacity()];
    capacity = d.capacity();
    this->size = d.size();
    for (unsigned int i = 0; i < d.size(); i++) {
        arr[i] = d.arr[i];
    }
    delete[] d;
    return *this;
    }


template<typename T>
unsigned int ABS<T>::getSize() {
    return size;
}

template<typename T>
unsigned int ABS<T>::getMaxCapacity() {
    return capacity;
}

//template<typename T>
//T* ABS<T>::getData {
//    return arr;
//};

template<typename T>
void ABS<T>::push(T data) {
        if (size < capacity) {
            arr[size] = data;
            size++;
        }
        else {
            T* newStack = new T[2* size];
            for ( int i = 0; i < size; i++) {
                newStack[i] = arr[i];
                    }
            capacity = capacity * 2;
            delete[] arr;
            //arr = temp;
            newStack[size] = data;
            size++;
            arr = newStack;
        }
    }

template<typename T>
T ABS<T>::peek() {
        if (size == 0) {
            throw runtime_error("Runtime error");
        }
        return arr[size - 1];
    }

template<typename T>
T ABS<T>::pop() {
        if (size < 1) {
            throw runtime_error("Runtime error");
        }
        size--;
        T tempElement = arr[size];

        if (((double) capacity / (double) size) > 2) {
            reduceCap(capacity);
        }
        return tempElement;
    }

template<typename T>
void ABS<T>:: reduceCap(int capacity)
    {
        temp = new T[size];
        for ( int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        this->capacity = capacity / 2;
        arr = new T[this->capacity];
        for ( int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
//};


#endif //LAB3_ABS_H
