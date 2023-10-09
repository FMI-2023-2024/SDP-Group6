#ifndef _STACK_HPP
#define _STACK_HPP

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T> *next;
};

template<typename T>
class Stack {
private:
    size_t size;
    Node<T> *head;

    void clear();
    void copy(Node<T>*& destination, const Node<T>* source);
    std::ostream& print(std::ostream& out, const Node<T>* current) const;

public:

    Stack();
    Stack(const Stack<T>& other);
    Stack& operator=(const Stack<T>& other);
    ~Stack();

    T Pop();
    T Peek() const;
    void Push(const T& element);

    bool Empty() const;
    size_t Size() const;

    template<typename E>
    friend std::ostream& operator<<(std::ostream& out, const Stack<E>& stack);
};

#endif