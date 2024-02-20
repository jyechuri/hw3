#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
// inherit from std::vector<T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T &item);
    void pop();           // throws std::underflow_error if empty
    const T &top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::~Stack()
{
    // nothing to implement
}

/*
    since both classes have that function and it will default to the derived
    version and lead to an infinite recursion. Instead, scope the call (e.g. LList<T>::size()
*/
template <typename T>
bool Stack<T>::empty() const
{
    if (std::vector<T>::size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
size_t Stack<T>::size() const
{
    return (std::vector<T>::size());
}

// push
template <typename T>
void Stack<T>::push(const T &item)
{
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Called pop on empty stack. Underflow error.");
    }
    else
    {
        return std::vector<T>::pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const
{
    if (empty())
    {
        throw std::underflow_error("Called top on empty stack. Underflow error.");
    }
    else
    {
        return std::vector<T>::back();
    }
}

#endif