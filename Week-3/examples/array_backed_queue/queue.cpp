#include<iostream>
#include<cstring>
#include "queue.hpp"

template<typename T>
void Queue<T>::clear() {
    this->size = 0;
    this->capacity = 0;
    delete this->elements;
}

template<typename T>
void Queue<T>::reconcile() {
    if(this->start == 0 || (this->start + this->size) < (this->capacity - 1) ) {
        return;
    }

    memmove(this->elements, this->elements + this->start, this->size * sizeof(T));
    this->start = 0;
}

template<typename T>
void Queue<T>::scale(size_t capacity) {
    T* elements = new T[capacity];

    memcpy(elements, this->elements, this->size * sizeof(T));

    delete this->elements;
    this->capacity = capacity;
    this->elements = elements;
}

template<typename T>
void Queue<T>::copy(const Queue<T>& other) {
    this->size = other.size;
    this->start = other.start;
    this->capacity = other.capacity;
    this->elements = new T[this->capacity];
    
    memcpy(this->elements + this->start, other.elements + other.start, this->size * sizeof(T));
}

template<typename T>
Queue<T>::Queue(size_t capacity) {
    this->size = 0;
    this->start = 0;
    this->capacity = capacity;
    this->elements = new T[capacity];
}
    
template<typename T>
Queue<T>::Queue(const Queue<T>& other) {
    this->copy(other);
}
    
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    if(this != &other) {
        this->clear();
        this->copy(other);
    }
    
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    this->clear();
}

template<typename T>
void Queue<T>::Add(const T& element) {
    if (this->size == this->capacity) {
        this->scale(this->capacity * 2);
    }

    this->reconcile();
    this->elements[this->size++] = element;
}
    
template<typename T>
T Queue<T>::Remove() {
    if ((this->size-1) == this->capacity / 2) {
        this->scale(this->capacity / 2);
    }

    this->size = this->size - 1;
    return this->elements[this->start++];
}

template<typename T>
T Queue<T>::Peek() const {
    return this->elements[this->start];
}
    
template<typename T>
size_t Queue<T>::Size() const {
    return this->size;
}

template<typename T>
bool Queue<T>::Empty() const {
    return this->size == 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& queue) {
    for(size_t idx = queue.start; idx < queue.size; idx++) {
        out << queue.elements[idx] << " ";
    }

    return out;
}

