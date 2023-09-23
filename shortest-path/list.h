#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

template <class T>
class List
{
public:
	int numberOfNodes;

	ListNode<T>* first;
	ListNode<T>* last;

	List();
	~List();

	void push_back(const T& value);
	void push_back(T&& value);
	void push_front(const T& value);
	void push_front(T&& value);
	void pop_back();
	void pop_front();
	bool empty();
	int size();
};

template<class T>
List<T>::List() : numberOfNodes(0), first(nullptr), last(nullptr)
{
}

template<class T>
List<T>::~List()
{
	ListNode<T>* temp = this->first;
	ListNode<T>* temp2 = nullptr;
	while (temp != nullptr)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (numberOfNodes == 0)
	{
		this->first = new ListNode<T>(value);
		this->last = this->first;
		numberOfNodes++;
		return;
	}

	ListNode<T>* newNode = new ListNode<T>(value);
	newNode->prev = this->last;
	last->next = newNode;
	this->last = newNode;
	numberOfNodes++;
}

template<class T>
void List<T>::push_back(T&& value)
{
	if (numberOfNodes == 0)
	{
		this->first = new ListNode<T>(static_cast<T&&>(value));
		this->last = this->first;
		numberOfNodes++;
		return;
	}

	ListNode<T>* newNode = new ListNode<T>(static_cast<T&&>(value));
	newNode->prev = this->last;
	last->next = newNode;
	this->last = newNode;
	numberOfNodes++;
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (numberOfNodes == 0)
	{
		this->first = new ListNode<T>(value);
		this->last = this->first;
		numberOfNodes++;
		return;
	}

	ListNode<T>* newNode = new ListNode<T>(value);
	newNode->next = this->first;
	first->prev = newNode;
	this->first = newNode;
	numberOfNodes++;
}

template<class T>
void List<T>::push_front(T&& value)
{
	if (numberOfNodes == 0)
	{
		this->first = new ListNode<T>(static_cast<T&&>(value));
		this->last = this->first;
		numberOfNodes++;
		return;
	}

	ListNode<T>* newNode = new ListNode<T>(static_cast<T&&>(value));
	newNode->next = this->first;
	first->prev = newNode;
	this->first = newNode;
	numberOfNodes++;
}

template<class T>
void List<T>::pop_back()
{
	if(numberOfNodes == 0)
		return;
	else if (numberOfNodes == 1)
	{
		delete this->last;
		this->last = nullptr;
		this->first = nullptr;
		numberOfNodes--;
		return;
	}

	ListNode<T>* temp = this->last->prev;
	temp->next = nullptr;
	delete this->last;
	this->last = temp;
	numberOfNodes--;
}

template<class T>
void List<T>::pop_front()
{
	if (numberOfNodes == 0)
		return;
	else if (numberOfNodes == 1)
	{
		delete this->first;
		this->last = nullptr;
		this->first = nullptr;
		numberOfNodes--;
		return;
	}

	ListNode<T>* temp = this->first->next;
	temp->prev = nullptr;
	delete this->first;
	this->first = temp;
	numberOfNodes--;
}

template<class T>
bool List<T>::empty()
{
	return numberOfNodes == 0;
}

template<class T>
int List<T>::size()
{
	return numberOfNodes;
}

#endif