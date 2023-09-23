#ifndef LIST_NODE_H
#define LIST_NODE_H

template <class T>
struct ListNode
{
	T data;
	ListNode* next;
	ListNode* prev;
	ListNode(const T& value);
	ListNode(T&& value);
};

template <class T>
ListNode<T>::ListNode(const T& value) : data(value), next(nullptr), prev(nullptr)
{
}

template<class T>
ListNode<T>::ListNode(T&& value) : data(static_cast<T&&>(value)), next(nullptr), prev(nullptr)
{
}

#endif