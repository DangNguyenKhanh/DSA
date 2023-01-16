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
class Queue {
private:
	Node<T>* Front;
	Node<T>* Rear;
	int Count;
public:
	Queue();
	bool IsEmpty();
	void Enqueue(T);
	T Dequeue();
	T Peek();
	void Display();
	void Clear();
	~Queue();
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
	cout << Info << endl;
}

template<class T>
Queue<T>::Queue()
{
	this->Front = NULL;
	this->Rear = NULL;
	this->Count = 0;
}

template<class T>
bool Queue<T>::IsEmpty()
{
	return this->Front == NULL;
}

template<class T>
void Queue<T>::Enqueue(T Data)
{
	Node<T>* p = new Node<T>(Data);
	if (this->IsEmpty())
	{
		this->Front = p;
	}
	else
	{
		this->Rear->Next = p;
	}
	this->Rear = p;
	this->Count++;
}

template<class T>
T Queue<T>::Dequeue()
{
	T result;
	if (this->IsEmpty()) 
		result = 0;
	else
	{
		Node<T>* p = this->Front;
		result = p->Info;
		if (this->Front == this->Rear)
		{
			this->Rear = NULL;
		}
		this->Front = p->Next;
		delete p;
		this->Count--;
	}
	return result;
}

template<class T>
T Queue<T>::Peek()
{
	T result;
	if (this->IsEmpty()) 
		result = 0;
	else
	{
		result = this->Front->Info;
	}
	return result;
}

template<class T>
void Queue<T>::Display()
{
	if (this->IsEmpty())
	{
		cout << "Hang doi rong ..." << endl;
	}
	else
	{
		cout << "Noi dung hang doi: " << endl;
		Node<T>* p = this->Front;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So luong phan tu: " << this->Count << endl;
	}
}

template<class T>
void Queue<T>::Clear()
{
	Node<T>* p;
	while (this->Front != NULL)
	{
		p = this->Front;
		this->Front = p->Next;
		delete p;
	}
	Rear = NULL;
	this->Count = 0;
}

template<class T>
Queue<T>::~Queue()
{
	this->Clear();
}
