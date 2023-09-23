#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <class T>
class Queue
{
private:
	int numberOfElements;
	List<T> data;

public:
	Queue();
	~Queue();
	void push(const T& value);
	void push(T&& value);
	void pop();
	T& front();
	T& back();
	bool empty();
	int size();
};

template<class T>
Queue<T>::Queue() : numberOfElements(0)
{
}

template<class T>
Queue<T>::~Queue()
{
}

template<class T>
void Queue<T>::push(const T& value)
{
	data.push_back(value);
}

template<class T>
void Queue<T>::push(T&& value)
{
	data.push_back(static_cast<T&&>(value));
}

template<class T>
void Queue<T>::pop()
{
    data.pop_front();
}

template<class T>
T& Queue<T>::front()
{
	return data.first->data;
}

template<class T>
T& Queue<T>::back()
{
	return data.last->data;
}

template<class T>
bool Queue<T>::empty()
{
	return data.empty();
}

template<class T>
int Queue<T>::size()
{
	return data.size();
}

#endif