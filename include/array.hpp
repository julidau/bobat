/*
 * array.hpp
 *
 *  Created on: 20.09.2012
 *      Author: julian
 */

#ifndef BOBAT_ARRAY_
#define BOBAT_ARRAY_

namespace core
{

#include "types.h"

template <class T>
class array
{
private:
	T * data;
	u32 size, lenght;
public:
	array() : data(0), size(0), lenght(0) {}
	array(u32 init_size) : data(0), size(0), lenght(0) { allocate(init_size); }
	array(const array<T> &other) { *this = other; }	// Copy constructor

	~array() { clear(); }
	void allocate(u32 newsize)
	{
		if (size == newsize)
			return;
		if (newsize < lenght)
			return;

		size = newsize;

		T * olddata = data;

		data = new T[size];

		// Copy elements
		for (u32 i = 0; i < lenght; i++)
		{
			data[i] = olddata[i];
		}

		// Erase old data
	/*	for (u32 i = 0; i < lenght; i++)
			delete olddata[i];*/

		// erase array
		if (olddata)
			delete [] olddata;
	}

	void insert(const T &elem, u32 index = 0)
	{
		if (lenght+1 > size)
			allocate(size+5);

		// Insert not at end
		if (index+1 < lenght)
		{
			for (u32 i = lenght-1; i >= index; i--)
				data[i+1] = data[i];
			data [index] = elem;
		}
		else
			data[lenght] = elem;

		lenght++;
	}

	void remove(u32 index, bool shrink = false)
	{
		if (!(index < lenght) || index < 0) return;

		// not at end
		if (index+1 < lenght)
		{
			delete data[index];

			for (u32 i = index; i < lenght; i++)
				data[i] = data[i+1];

		}
		else
			delete data[lenght-1];

		lenght--;
		if (shrink)
			allocate(lenght);
	}

	void clear()
	{
		for (u32 i = 0; i < lenght; i++)
			data[i].~T();

		delete[] data;

		size = 0;
		lenght = 0;
		data = 0;
	}

	void push_back(const T &elem)
	{
		insert(elem,lenght);
	}

	void push_front(const T &elem)
	{
		insert(elem);
	}

	T &at(u32 index) const
	{
		_DEBUG_BREAK_IF(index > size);
		return data [index];
	}

	T * Data() { return data; }
	T &operator[] (u32 i)
	{
		return at(i);
	}

	u32 getSize() const
	{
		return lenght;
	}
};

}


#endif /* ARRAY_HPP_ */
