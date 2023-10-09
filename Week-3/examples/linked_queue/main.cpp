#include<iostream>
#include "queue.cpp"

int main()
{
    Queue<int> q;
    
    q.Add(1);
    std::cout << "Elements: " << q << ", Size: " << q.Size() << std::endl;
    q.Add(2);
    std::cout << "Elements: " << q << ", Size: " << q.Size() << std::endl;
    q.Add(3);
    std::cout << "Elements: " << q << ", Size: " << q.Size() << std::endl;

    Queue<int> qc = q;
    
    std::cout << "Elements: " << qc << ", Size: " << qc.Size() << std::endl;
    
    qc.Add(4);
    
    std::cout << "Elements: " << qc << ", Size: " << qc.Size() << std::endl;

    std::cout << "Elements: " << q << ", Size: " << q.Size() << std::endl;
    std::cout << "Elements: " << qc << ", Size: " << qc.Size() << std::endl;
    
    std::cout << "Removed: " << q.Remove() << std::endl;
    std::cout << "Elements: " << q << ", Size: " << q.Size() << std::endl; 

    std::cout << "Removed: " << q.Remove() << std::endl;
    std::cout << "Elements: " << q << ", Size: " << q.Size() << std::endl;

    std::cout << "Removed: " << q.Remove() << std::endl;
    std::cout << "Elements: " << q << ", Size: " << q.Size() << std::endl;
    
    std::cout << "Elements: " << qc << ", Size: " << qc.Size() << std::endl;

    return 0;
}
