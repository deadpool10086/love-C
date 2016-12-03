#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
	public:
		Stack();
		bool empty();
		T peek();
		T push(T value);
		T pop();
		int getSize();
		
	private:
		T elements[100];
		int size; 
};


template<typename T>
Stack<T>::Stack()
{
	size = 0;
}

template<typename T>
bool Stack<T>::empty()
{
	if (size == 0)
	return true;
	else
	return false;
}

template<typename T>
T Stack<T>::peek()
{
	return elements[size - 1];
} 

template<typename T>
T Stack<T>::push(T valude)
{
	return elements[size++] = valude;
}

template<typename T>
T Stack<T>::pop()
{
	return elements[--size];
}

template<typename T>
int Stack<T>::getSize()
{
	return size;
}
#endif 
