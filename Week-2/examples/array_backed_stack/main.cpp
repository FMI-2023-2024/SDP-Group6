#include<iostream>
#include "stack.cpp"

int main()
{
    Stack<int> s;
    
    s.Push(1);
    std::cout << "Elements: " << s << ", Size: " << s.Size() << std::endl;
    s.Push(2);
    std::cout << "Elements: " << s << ", Size: " << s.Size() << std::endl;
    s.Push(3);
    std::cout << "Elements: " << s << ", Size: " << s.Size() << std::endl;

    Stack<int> sc = s;
    
    std::cout << "Elements: " << sc << ", Size: " << sc.Size() << std::endl;
    
    sc.Push(4);
    
    std::cout << "Elements: " << sc << ", Size: " << sc.Size() << std::endl;

    std::cout << "Elements: " << s << ", Size: " << s.Size() << std::endl;
    std::cout << "Elements: " << sc << ", Size: " << sc.Size() << std::endl;
    
    std::cout << "Removed: " << s.Pop() << std::endl;
    std::cout << "Elements: " << s << ", Size: " << s.Size() << std::endl; 

    std::cout << "Removed: " << s.Pop() << std::endl;
    std::cout << "Elements: " << s << ", Size: " << s.Size() << std::endl;

    std::cout << "Removed: " << s.Pop() << std::endl;
    std::cout << "Elements: " << s << ", Size: " << s.Size() << std::endl;
    
    std::cout << "Elements: " << sc << ", Size: " << sc.Size() << std::endl;

    return 0;
}