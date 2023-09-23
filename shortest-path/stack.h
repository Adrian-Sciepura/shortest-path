#ifndef STACK_H
#define STACK_H

#include "List.h"

template <class T>
class Stack
{
private:
    List<T> data;

public:
    Stack();
    void push(const T& value);
    void push(T&& value);
    void pop();
    T& top();
    bool empty();
    int size();
};

template<class T>
Stack<T>::Stack()
{
}

template<class T>
void Stack<T>::push(const T& value)
{
    data.push_front(value);
}

template<class T>
void Stack<T>::push(T&& value)
{
    data.push_front(static_cast<T&&>(value));
}

template<class T>
void Stack<T>::pop()
{
    data.pop_front();
}

template<class T>
T& Stack<T>::top()
{
    return data.first->data;
}

template<class T>
bool Stack<T>::empty()
{
	return data.empty();
}

template<class T>
int Stack<T>::size()
{
	return data.size();
}

#endif