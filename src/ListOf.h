#pragma once

#define MAX 10

template <class T> class ListOf
{
	T* list[MAX];
	int number;
public:
	ListOf(void);
	ListOf(const ListOf&);
	~ListOf(void);

	void operator+=(T* t);
	void erase();
	T& operator[](int index);
	void operator=(ListOf&);

	int getNumber() { return number; }
};

template<class T> ListOf<T>::ListOf(void)
{
	for (int i=0; i < MAX; i++)
		list[i] = NULL;
	number = 0;
}

template<class T> ListOf<T>::ListOf(const ListOf& l)
{
	for (int i = 0; i < MAX; i++)
		list[i] = NULL;
	number = 0;
	for (int i = 0; i < l.number; i++)
		list[i] = l.list[i];
	number = l.number;
}

template<class T> ListOf<T>::~ListOf(void)
{
	//erase();
}

template<class T> void ListOf<T>::operator+=(T* t)
{
	for (int i=0; i < number; i++)
		if (list[i] == t)
			return;
	if (number < MAX)
		list[number++] = t;
}

template<class T> void ListOf<T>::erase()
{
	for (int i=0; i < number; i++)
		delete list[i];
	number = 0;
}

template<class T> T& ListOf<T>::operator[](int index)
{
	if (index < 0)
		index = 0;
	if (index >= number)
		index = number - 1;
	return *list[index];
}

template<class T> void ListOf<T>::operator=(ListOf& l)
{
	for (int i = 0; i < l.number; i++)
		list[i] = l.list[i];
	number = l.number;
}
