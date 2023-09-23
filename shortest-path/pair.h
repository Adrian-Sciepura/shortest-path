#ifndef PAIR_H
#define PAIR_H

template <class T1, class T2>
struct Pair
{
	T1 first;
	T2 second;

	Pair();
	Pair(const T1& first, const T2& second);
	Pair(T1&& first, T2&& second);

	Pair<T1, T2>& operator=(const Pair<T1, T2>& source);
    bool operator>(const Pair<T1, T2>& source) const;
    bool operator<(const Pair<T1, T2>& source) const;
};

template<class T1, class T2>
Pair<T1, T2>::Pair() : first(), second()
{
}

template <class T1, class T2>
Pair<T1, T2>::Pair(const T1& first, const T2& second) : first(first), second(second)
{
}

template <class T1, class T2>
Pair<T1, T2>::Pair(T1&& first, T2&& second) : 
	first(static_cast<T1&&>(first)), second(static_cast<T2&&>(second))
{
}

template<class T1, class T2>
Pair<T1, T2>& Pair<T1, T2>::operator=(const Pair<T1, T2>& source)
{
	this->first = source.first;
	this->second = source.second;
	return *this;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator>(const Pair<T1, T2>& source) const
{
    return this->first > source.first;
}

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2>& source) const
{
    return this->first < source.first;
}

#endif