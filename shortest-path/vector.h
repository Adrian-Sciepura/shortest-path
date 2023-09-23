#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
private:
	int numberOfElements;
	int capacity;
	T* data;

public:
	Vector();
	~Vector();
	void push_back(const T& value);
	void push_back(T&& value);
	void pop_back();
	
	void resize(int newCapacity);
	bool empty();
	int size();
	
	T& operator[](int index);
};

#endif

template<class T>
Vector<T>::Vector() : data(new T[2]), numberOfElements(0), capacity(2)
{
}

template<class T>
Vector<T>::~Vector()
{
	delete[] data;
}

template<class T>
void Vector<T>::push_back(const T& value)
{
	if (numberOfElements == capacity)
		resize(capacity * 2);
	
	data[numberOfElements] = value;
	numberOfElements++;
}

template<class T>
void Vector<T>::push_back(T&& value)
{
	if (numberOfElements == capacity)
		resize(capacity * 2);

	data[numberOfElements] = static_cast<T&&>(value);
	numberOfElements++;
}

template<class T>
void Vector<T>::pop_back()
{
	if (numberOfElements == 0)
		return;

	numberOfElements--;
}

template<class T>
void Vector<T>::resize(int newCapacity)
{
	if (newCapacity < numberOfElements)
		return;

	T* newData = new T[newCapacity];
	memcpy(newData, data, numberOfElements * sizeof(T));
	capacity = newCapacity;
	delete[] data;
	data = newData;
}

template<class T>
bool Vector<T>::empty()
{
	return numberOfElements == 0;
}

template<class T>
int Vector<T>::size()
{
	return numberOfElements;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return data[index];
}
