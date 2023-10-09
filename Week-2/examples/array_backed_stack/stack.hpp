#include <iostream>

template<typename T>
class Stack {
private:
    T* elements;
    size_t size;
    size_t capacity;

    void clear();
    void scale(size_t capacity);
    void copy(const Stack<T>& other);

public:

    Stack(size_t capacity = 64);
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
