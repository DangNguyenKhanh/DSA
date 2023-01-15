#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T Info;
	Node<T>* Next;
public:
	Node(T data) : Info(data), Next(NULL) {};
	void Display()
	{
		cout << this->Info << endl;
	}
};

template<class T>
class Stack {
private:
	Node<T>* sp;
	int count;
public:
	Stack() : sp(NULL), count(0) {};
	bool IsEmpty()
	{
		return sp == NULL;
	}
	void Push(T data)
	{
		Node<T>* p = new Node<T>(data);
		p->Next = sp;
		sp = p;
		this->count++;
	}
	T Pop()
	{
		T result;
		if (IsEmpty())
			result = 0;
		else
		{
			Node<T>* p = sp;
			result = p->Info;
			sp = p->Next;
			delete p;
			this->count--;
		}
		return result;
	}
	T Peek()
	{
		T result;
		if (this->IsEmpty()) result = 0;
		else
		{
			result = sp->Info;
		}
		return result;
	}
	void Display()
	{
		if (this->IsEmpty())
			cout << "Stack rong ..." << endl;
		else
		{
			cout << "Noi dung cua Stack: " << endl;
			Node<T>* p = sp;
			while (p != NULL)
			{
				p->Display();
				p = p->Next;
			}
			cout << "So phan tu cua Stack: " << this->count << endl;
		}
	}
	void Clear()
	{
		Node<T>* p;
		while (sp != NULL)
		{
			p = sp;
			sp = p->Next;
			delete p;
		}
		this->count = 0;
	}
	~Stack() { this->Clear(); };
};
