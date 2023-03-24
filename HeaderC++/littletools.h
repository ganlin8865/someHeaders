#pragma once
#ifndef LITTLETOOLS_H
#define LITTLETOOLS_H

#include <random>
#include <algorithm>
#include <iostream>
#include <vector>

namespace ltools
{
	//About Stack
	namespace stack
	{
		class Stack
		{
		private:
			int* arr;
			int capacity;
			int top;
		public:
			Stack(int cap = 10)
			{
				arr = new int[cap];
				capacity = cap;
				top = -1;
			}

			~Stack()
			{
				delete[] arr;
			}

			bool empty()
			{
				return top == -1;
			}

			bool full()
			{
				return top == capacity - 1;
			}

			int size()
			{
				return top + 1;
			}

			void push(int x)
			{
				if (full())
				{
					int* temp = new int[capacity * 2];
					for (int i = 0; i < capacity; i++)
					{
						temp[i] = arr[i];
					}
					delete[] arr;
					arr = temp;
					capacity *= 2;
				}
				arr[++top] = x;
			}

			void clear()
			{
				top = -1;
			}

			int pop()
			{
				if (empty())
				{
					throw std::runtime_error("Stack underflow");
				}
				return arr[top--];
			}

			int peek()
			{
				if (empty())
				{
					throw std::runtime_error("Stack underflow");
				}
				return arr[top];
			}

			friend std::ostream& operator<<(std::ostream& os, const Stack& s)
			{
				os << "[";
				for (int i = 0; i <= s.top; i++)
				{
					os << s.arr[i];
					if (i != s.top)
					{
						os << ", ";
					}
				}
				os << "]";
				return os;
			}

			void swap(Stack& other)
			{
				std::swap(arr, other.arr);
				std::swap(capacity, other.capacity);
				std::swap(top, other.top);
			}

			void resize(int new_capacity)
			{
				if (new_capacity < size())
				{
					throw std::invalid_argument("New capacity must be greater than or equal to the current size");
				}
				int* temp = new int[new_capacity];
				for (int i = 0; i <= top; i++)
				{
					temp[i] = arr[i];
				}
				delete[] arr;
				arr = temp;
				capacity = new_capacity;
			}

			int min()
			{
				if (empty())
				{
					throw std::runtime_error("Stack underflow");
				}
				int min_value = arr[0];
				for (int i = 1; i <= top; i++)
				{
					if (arr[i] < min_value)
					{
						min_value = arr[i];
					}
				}
				return min_value;
			}

			int max()
			{
				if (empty())
				{
					throw std::runtime_error("Stack underflow");
				}
				int max_value = 0;
				for (int i = 1; i <= top; i++)
				{
					if (arr[i] > max_value)
					{
						max_value = arr[i];
					}
				}
				return max_value;
			}

			bool operator==(const Stack& other) const
			{
				if (top != other.top)
				{
					return false;
				}
				for (int i = 0; i <= top; i++)
				{
					if (arr[i] != other.arr[i])
					{
						return false;
					}
				}
				return true;
			}
		};
	}
	//About Sort
	namespace sort
	{
		void BubbleSort(int arr[], int size);
		void InsertionSort(int arr[], int size);
		void QuickSort(int arr[]);
	}
	namespace classic
	{
		template<typename T>
		void print(T content)
		{
			std::cout << content;
		}
		template<typename T>
		void input(T& content)
		{
			std::cin >> content;
		}
	}
	//About Random
	namespace random
	{
		int RandomInt(int L, int R);
	}
}

#endif