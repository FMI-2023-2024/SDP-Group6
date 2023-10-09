#include "stack.hpp"
#include <cstring>

template<typename T>
void Stack<T>::clear() {
    while(!this->Empty()) {
        this->Pop();
    }
}

template<typename T>
void Stack<T>::copy(Node<T>*& destination, const Node<T>* source) {
    if(source == NULL) {
        return;
    }

    this->size = this->size + 1;
    destination = new Node<T> {
        .data = source->data,
        .next = NULL
    };
    copy(destination->next, source->next);        
}

template<typename T>
std::ostream& Stack<T>::print(std::ostream& out, const Node<T>* current) const {
    while(current != NULL) {
        out << current->data << " ";
        current = current->next;
    }

    return out;
}

template<typename T>
Stack<T>::Stack() {
    this->size = 0;
    this->head = NULL;
}
    
template<typename T>
Stack<T>::Stack(const Stack<T>& other) {
    this->size = 0;
    copy(this->head, other.head);
}
 
template<typename T>   
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if(this != &other) {
        clear();
        copy(this->head, other.head);
    }
    
    return *this;

}

template<typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
void Stack<T>::Push(const T& element) {
    this->size = this->size + 1;
    this->head = new Node<T> {
        .data = element,
        .next = this->head
    };
}

template<typename T>
T Stack<T>::Pop() {
    T result = this->head->data;
    Node<T>* head = this->head;
    
    this->size = this->size-1;
    this->head = this->head->next;

    delete head;

    return result;
}

template<typename T>
T Stack<T>::Peek() const {
    return this->head->data;
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
    return stack.print(out, stack.head);
}

