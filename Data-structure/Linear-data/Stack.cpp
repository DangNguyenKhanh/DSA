#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T Info;
	Node<T>* Next;
public:
	Node(T);
	void Display();
};

template<class T>
Node<T>::Node(T Data)
{
	this->Info = Data;
	this->Next = NULL;
}

template<class T>
void Node<T>::Display()
{
	cout << this->Info << endl;
}

template<class T>
class Stack {
private:
	Node<T>* Sp;
	int Count;
public:
	Stack();
	bool IsEmpty();
	void Push(T);
	T Pop();
	T Peek();
	void Display();
	void Clear();
	~Stack();
};

template<class T>
Stack<T>::Stack()
{
	this->Sp = NULL;
	this->Count = 0;
}

template<class T>
bool Stack<T>::IsEmpty()
{
	return Sp == NULL;
}

template<class T>
void Stack<T>::Push(T Data)
{
	Node<T>* p = new Node<T>(Data);
	p->Next = Sp;
	Sp = p;
	this->Count++;
}

template<class T>
T Stack<T>::Pop()
{
	T result;
	if (IsEmpty())
		result = 0;
	else
	{
		Node<T>* p = Sp;
		result = p->Info;
		Sp = p->Next;
		delete p;
		this->Count--;
	}
	return result;
}

template<class T>
T Stack<T>::Peek()
{
	T result;
	if (this->IsEmpty()) 
		result = 0;
	else
		result = Sp->Info;
	return result;
}

template<class T>
void Stack<T>::Display()
{
	if (this->IsEmpty())
		cout << "Stack rong ..." << endl;
	else
	{
		cout << "Noi dung cua Stack: " << endl;
		Node<T>* p = Sp;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu cua Stack: " << this->Count << endl;
	}	
}

template<class T>
void Stack<T>::Clear()
{
	Node<T>* p;
	while (Sp != NULL)
	{
		p = Sp;
		Sp = p->Next;
		delete p;
	}
	this->Count = 0;
}

template<class T>
Stack<T>::~Stack()
{
	this->Clear();
}

