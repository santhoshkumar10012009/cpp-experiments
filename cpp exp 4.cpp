#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

template <class T>
class MyStack
{
private:
    T data[10000];
    int topIndex;

public:
    MyStack() : topIndex(-1) {}

    bool push(const T& value)
    {
        if (topIndex >= 9999)
            return false;

        data[++topIndex] = value;
        return true;
    }

    bool pop()
    {
        if (topIndex < 0)
            return false;

        --topIndex;
        return true;
    }
};

template <class T>
class MyQueue
{
private:
    T data[10000];
    int frontIndex, rearIndex;

public:
    MyQueue() : frontIndex(0), rearIndex(-1) {}

    bool enqueue(const T& value)
    {
        if (rearIndex >= 9999)
            return false;

        data[++rearIndex] = value;
        return true;
    }

    bool dequeue()
    {
        if (frontIndex > rearIndex)
            return false;

        ++frontIndex;
        return true;
    }
};

int main()
{
    const int N = 10000;

    auto start = high_resolution_clock::now();

    MyStack<int> myStack;

    for (int i = 0; i < N; i++)
        myStack.push(i);

    for (int i = 0; i < N; i++)
        myStack.pop();

    auto end = high_resolution_clock::now();

    auto customStackTime =
        duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();

    stack<int> stlStack;

    for (int i = 0; i < N; i++)
        stlStack.push(i);

    for (int i = 0; i < N; i++)
        stlStack.pop();

    end = high_resolution_clock::now();

    auto stlStackTime =
        duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();

    MyQueue<int> myQueue;

    for (int i = 0; i < N; i++)
        myQueue.enqueue(i);

    for (int i = 0; i < N; i++)
        myQueue.dequeue();

    end = high_resolution_clock::now();

    auto customQueueTime =
        duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();

    queue<int> stlQueue;

    for (int i = 0; i < N; i++)
        stlQueue.push(i);

    for (int i = 0; i < N; i++)
        stlQueue.pop();

    end = high_resolution_clock::now();

    auto stlQueueTime =
        duration_cast<microseconds>(end - start);

    cout << "Custom Stack Time: "
         << customStackTime.count()
         << " microseconds\n";

    cout << "STL Stack Time: "
         << stlStackTime.count()
         << " microseconds\n";

    cout << "Custom Queue Time: "
         << customQueueTime.count()
         << " microseconds\n";

    cout << "STL Queue Time: "
         << stlQueueTime.count()
         << " microseconds\n";

    return 0;
}