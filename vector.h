/*************************************************************************
* Title: Vector
* File: vector.h
* Author: James Eli
* Date: 10/26/2018
*
* Vector class using smart pointers with basic functionality (no iterators, 
* removing items, etc.).
*
* Notes:
*  (1) Compiled/tested with MS Visual Studio 2017 Community (v141), and
*      Windows SDK version 10.0.17134.0 (32 & 64-bit), and with Eclipse
*      Oxygen.3a Release (4.7.3a), using CDT 9.4.3/MinGw32 gcc-g++ (6.3.0-1).
*************************************************************************
* Change Log:
*  10/26/2018: Initial release. JME
*  11/06/2018: Corrected copy ctor. JME
*************************************************************************/
#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include <memory> // shared/unique pointer

namespace myVector 
{
	template<typename T>
	class Vector
	{
		std::size_t count;         // Number of actually stored objects.
		std::size_t capacity;      // Allocated capacity.
		std::shared_ptr<T[]> data; // Data element.

	public:
		// Default ctor.
		Vector() : count(0), capacity(0), data(nullptr) { };
		// Copy ctor.
		Vector(Vector const &rhs) : count(rhs.count), capacity(rhs.capacity)
		{
			std::unique_ptr<T[]> newData = std::make_unique<T[]>(count);
			for (std::size_t i = 0; i < count; i++)
				newData[i] = rhs.data[i];
			data.reset(newData.release());
		};
		// Move ctor.
		Vector(Vector const &&rhs)
		{
			count = rhs.count;
			capacity = rhs.capacity;
			data = std::move(rhs.data);
		};

		// Dtor.
		~Vector() { clear(); };

		// Clear.
		void clear() { data.reset(); };

		// Assignment operator.
		Vector &operator= (Vector const &rhs)
		{
			count = rhs.count;
			capacity = rhs.capacity;
			std::unique_ptr<T[]> temp(static_cast<T*>(data.release()));
			data.reset(new T[capacity]);
			for (std::size_t i = 0; i < count; i++)
				data[i] = temp[i];
			return *this;
		};

		// Adds new value, and if needed allocates more space.
		void push_back(T const &d)
		{
			if (capacity == count)
				resize();
			data[count++] = d;
		};

		// Removes value.
		void pop_back()
		{
			if (count == 0)
				return;
			count--;
		};

		// Size getter.
		size_t size() const { return count; };

		// Bracketed set/get.
		T const &operator[] (size_t i) const { return data[i]; };
		T &operator[] (size_t i) { return data[i]; };

		T* begin() { return data.get(); }
		T* end() { return (data.get() + count); }

	private:
		// Allocates double the old space.
		void resize()
		{
			capacity = capacity ? capacity * 2 : 1;
			std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity);
			for (std::size_t i = 0; i < count; i++)
				newData[i] = data[i];
			data.reset(newData.release());
		};
	};
}

#endif
