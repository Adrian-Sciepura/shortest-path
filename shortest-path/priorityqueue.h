#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "List.h"

template <class T>
class PriorityQueue
{
private:
    int numberOfElements;
    List<T> data;

public:
    PriorityQueue();
    void push(const T& value);
    void push(T&& value);
    void pop();
    T& top();
    bool empty();
    int size();
};

template<class T>
PriorityQueue<T>::PriorityQueue() : numberOfElements(0)
{
}

template<class T>
void PriorityQueue<T>::push(const T& value)
{
    ListNode<T>* current = data.first;
    while (current != nullptr)
    {
        if (current->data > value)
        {
            if (current != data.first)
            {
                ListNode<T>* newNode = new ListNode<T>(value);
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev = newNode;
                newNode->prev->next = newNode;
                data.numberOfNodes++;
                return;
            }
        }
        current = current->next;
    }

    data.push_front(value);
}

template<class T>
void PriorityQueue<T>::push(T&& value)
{
    ListNode<T>* current = data.first;
    while (current != nullptr)
    {
        if (current->data > value)
        {
            if (current != data.first)
            {
                ListNode<T>* newNode = new ListNode<T>(static_cast<T&&>(value));
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev = newNode;
                newNode->prev->next = newNode;
                data.numberOfNodes++;
                return;
            }
        }
        current = current->next;
    }

    data.push_front(static_cast<T&&>(value));
}

template<class T>
void PriorityQueue<T>::pop()
{
    data.pop_front();
}

template<class T>
T& PriorityQueue<T>::top()
{
    return data.first->data;
}

template<class T>
bool PriorityQueue<T>::empty()
{
    return data.empty();
}

template<class T>
int PriorityQueue<T>::size()
{
	return data.size();
}

#endif