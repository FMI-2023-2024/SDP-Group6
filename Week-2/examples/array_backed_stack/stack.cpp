#include "stack.hpp"
#include <cstring>

template<typename T>
void Stack<T>::clear() {
    this->size = 0;
    this->capacity = 0;
    delete this->elements;
}

template<typename T>
void Stack<T>::scale(size_t capacity) {
    T* elements = new T[capacity];

    memcpy(elements, this->elements, this->size * sizeof(T));
    
    delete this->elements;
    this->capacity = capacity;
    this->elements = elements;
}

template<typename T>
void Stack<T>::copy(const Stack<T>& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->elements = new T[this->capacity];
    
    memcpy(this->elements, other.elements, this->size * sizeof(T));
}

template<typename T>
Stack<T>::Stack(size_t capacity) {
    this->size = size;
    this->capacity = capacity;
    this->elements = new T[capacity];
}
    
template<typename T>
Stack<T>::Stack(const Stack<T>& other) {
    this->copy(other);
}
 
template<typename T>   
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if(this != &other) {
        this->clear();
        this->copy(other);
    }
    
    return *this;

}

template<typename T>
Stack<T>::~Stack() {
    this->clear();
}

template<typename T>
void Stack<T>::Push(const T& element) {
    if (this->size == this->capacity) {
        this->scale(this->capacity * 2);
    }

    this->elements[this->size++] = element;
}

template<typename T>
T Stack<T>::Pop() {
    if ((this->size-1) == this->capacity / 2) {
        this->scale(this->capacity / 2);
    }

    return this->elements[this->size--];
}

template<typename T>
T Stack<T>::Peek() const {
    return this->elements[this->size];
}
    
template<typename T>
size_t Stack<T>::Size() const {
    return this->size;
}

template<typename T>   
bool Stack<T>::Empty() const {
    return this->size == 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& stack) {
    for(size_t idx = 0; idx < stack.size; idx++) {
        out << stack.elements[idx] << " ";
    }
    
    return out;
}