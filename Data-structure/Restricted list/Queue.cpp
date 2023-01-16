#include<iostream>
using namespace std;

template<class T>
class Queue {
private:
	template<class T>
	class Node;
private:
	Node<T>* Front;
	Node<T>* Rear;
	int Count;
public:
	Queue() : Front(NULL), Rear(NULL), Count(0) {};

	bool IsEmpty()
	{
		return this->Front == NULL;
	}

	void Enqueue(T data)
	{
		Node<T>* p = new Node<T>(data);
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

	T Dequeue()
	{
		T result;
		if (IsEmpty()) result = 0;
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

	T Peek()
	{
		T result;
		if (IsEmpty()) result = 0;
		else
		{
			result = this->Front->Info;
		}
		return result;
	}

	void Display()
	{
		if (IsEmpty())
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

	void Clear()
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

	~Queue() { Clear(); }

private:
	template<class T>
	class Node {
	public:
		T Info;
		Node<T>* Next;
	public:
		Node(T data) : Info(data), Next(NULL) {};
		void Display()
		{
			cout << Info << endl;
		}
	};
};

template<class T>
