#ifndef _QUEUE_HPP
#define _QUEUE_HPP

#include<iostream>

template<typename T>
struct Node {
    T data;
    Node<T> *next;
};

template<typename T>
class Queue {
private:
    size_t size;
    Node<T> *head;
    Node<T> *tail;

    void clear();
    void copy(const Node<T>* source);
    Node<T>* append(Node<T>*& destination, const T& element);
    std::ostream& print(std::ostream& out, const Node<T>* current) const;

public:
    Queue();
    Queue(const Queue<T>& other);
    Queue& operator=(const Queue<T>& other);
    ~Queue();

    void Add(const T& element);
    T Remove();
    T Peek() const;
    
    size_t Size() const;
    bool Empty() const;

    template<typename E>
    friend std::ostream& operator<<(std::ostream& out, const Queue<E>& queue);
};

template<typename T>
void Queue<T>::clear() {
    while(!this->Empty()) {
        this->Remove();
    }
}

template<typename T>
void Queue<T>::copy(const Node<T>* source) {
    while(source != NULL) {
        this->Add(source->data);
        source = source->next;
    }
}

template<typename T>
Node<T>* Queue<T>::append(Node<T>*& destination, const T& element) {
    this->size = this->size + 1;

    return destination = new Node<T> {
        .data = element,
        .next = NULL
    };
}

template<typename T>
std::ostream& Queue<T>::print(std::ostream& out, const Node<T>* current) const {
    while(current != NULL) {
        out << current->data << " ";
        current = current->next;
    }

    return out;
}

template<typename T>
Queue<T>::Queue() {
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) {
    this->size = 0;
    this->copy(other.head);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    if(this != &other) {
        this->clear();
        this->copy(other.head);
    }

    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    this->clear();
}

template<typename T>
void Queue<T>::Add(const T& element) {
    this->tail = this->append(this->tail == NULL ? this->tail : this->tail->next, element);
    this->head = this->head == NULL ? this->tail : this->head;
}

template<typename T>
T Queue<T>::Remove() {
    T result = this->head->data;
    Node<T>* head = this->head;

    this->size = this->size - 1;
    this->head = this->head->next;
    this->tail = this->head == NULL ? NULL : this->tail;

    delete head;

    return result;
}

template<typename T>
T Queue<T>::Peek() const {
    return this->head->data;
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
    return queue.print(out, queue.head);
}

#endif