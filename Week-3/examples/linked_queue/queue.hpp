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

