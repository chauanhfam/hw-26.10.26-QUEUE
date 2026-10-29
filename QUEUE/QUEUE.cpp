#include <iostream>
using namespace std;
template <typename T>
class Queue
{
private:
    struct Elem
    {
        T data;
        Elem* next;
        Elem* prev;

        Elem(T val)
        {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Elem* Head;
    Elem* Tail;
    int size;

public:
    Queue();
    ~Queue();

    void Enqueue(T value);
    void Dequeue();
    bool Empty();
    int GetSize();
    void Print();
    bool IsEmpty();
    void Clear();
    T Front();
};

template<typename T>
Queue<T>::Queue()
{
    Head = nullptr;
    Tail = nullptr;
    size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    Clear();
}

template<typename T>
void Queue<T>::Enqueue(T value)
{
    Elem* newElem = new Elem(value);

    if (Head == nullptr)
    {
        Head = newElem;
        Tail = newElem;
    }
    else
    {
        newElem->prev = Tail;
        Tail->next = newElem;
        Tail = newElem;
    }

    size++;
}

template<typename T>
void Queue<T>::Dequeue()
{
    if (Head == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Elem* temp = Head;
    Head = Head->next;

    if (Head != nullptr)
    {
        Head->prev = nullptr;
    }
    else
    {
        Tail = nullptr;
    }

    delete temp;
    size--;
}

template<typename T>
bool Queue<T>::Empty()
{
    return Head == nullptr;
}

template<typename T>
bool Queue<T>::IsEmpty()
{
    return Head == nullptr;
}

template<typename T>
int Queue<T>::GetSize()
{
    return size;
}

template<typename T>
void Queue<T>::Print()
{
    Elem* current = Head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

template<typename T>
void Queue<T>::Clear()
{
    while (Head != nullptr)
    {
        Elem* temp = Head;
        Head = Head->next;
        delete temp;
    }

    Head = nullptr;
    Tail = nullptr;
    size = 0;
}

template<typename T>
T Queue<T>::Front()
{
    if (Head == nullptr)
    {
        cout << "Queue is empty" << endl;
        return T();
    }

    return Head->data;
}

int main()
{
    Queue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    cout << "Queue: ";
    q.Print();
    cout << "First element: " << q.Front() << endl;
    cout << "Amount of elements: " << q.GetSize() << endl;
    q.Dequeue();
    cout << "After erase: ";
    q.Print();

    cout << "First element: " << q.Front() << endl;
    cout << "Is Queue empty? ";
    if (q.IsEmpty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    q.Clear();
    cout << "After clearing: ";
    q.Print();

    return 0;
}