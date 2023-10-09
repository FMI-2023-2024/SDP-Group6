#include<iostream>

template<typename T>
class Queue {
private:
    T* elements;
    size_t size;
    size_t start;
    size_t capacity;

    void clear();
    void reconcile();
    void scale(size_t capacity);
    void copy(const Queue<T>& other);

public:

    Queue(size_t capacity = 64);
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

