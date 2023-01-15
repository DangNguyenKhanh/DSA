#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T Data;
	Node<T>* Next;
	Node<T>* Prev;
public:
	Node(T Data);
	void Display();
};

template<class T>
class DoubleLinkedList
{
private:
	Node<T>* Head;
	Node<T>* Tail;
	int Count;
public:
	DoubleLinkedList();
	bool IsEmpty();
	void InsertHead(T);
	void InsertTail(T);
	void InsertOrder(T);
	Node<T>* Find(T);
	Node<T>* FindOrder(T);
	bool Find_B(T);
	bool FindOrder_B(T);
	bool Remove(T);
	bool RemoveOrder(T);
	void DisplayNext();
	void DisplayPrevious();
	void Clear();
	~DoubleLinkedList();
};

template<class T>
Node<T>::Node(T Data)
{
	this->Data = Data;
	this->Next = NULL;
	this->Prev = NULL;
}

template<class T>
void Node<T>::Display()
{
	cout << this->Data << endl;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	this->Head = NULL;
	this->Tail = NULL;
	this->Count = 0;
}

template<class T>
bool DoubleLinkedList<T>::IsEmpty()
{
	return this->Head == NULL;
}

template<class T>
void DoubleLinkedList<T>::InsertHead(T Data)
{
	Node<T>* p = new Node<T>(Data);
	if (this->Head == NULL)
	{
		this->Head = p;
		this->Tail = p;
		this->Count++;
		return;
	}
	else
	{
		p->Next = this->Head;
		this->Head->Prev = p;
		this->Head = p;
		this->Count++;
		return;
	}
}

template<class T>
void DoubleLinkedList<T>::InsertTail(T Data)
{
	Node<T>* p = new Node<T>(Data);
	if (this->Tail == NULL)
	{
		this->Head = p;
		this->Tail = p;
		this->Count++;
		return;
	}
	else
	{
		this->Tail->Next = p;
		p->Prev = this->Tail;
		this->Tail = p;
		this->Count++;
		return;
	}
}

template<class T>
void DoubleLinkedList<T>::InsertOrder(T Data)
{
	Node<T>* p = this->Head;
	while (p != NULL)
		if (p->Data < Data)
			p = p->Next;
		else
			break;

	if (p == this->Head)
		this->InsertHead(Data);
	else
		if (p == NULL)
		{
			this->InsertTail(Data);
		}
		else
		{
			Node<T>* q = new Node<T>(Data);
			Node<T>* tp = p->Prev;
			tp->Next = q;
			q->Next = p;
			p->Prev = q;
			q->Prev = tp;
			this->Count++;
		}
}

template<class T>
Node<T>* DoubleLinkedList<T>::Find(T Data)
{
	Node<T>* p = this->Head;
	while (p != NULL)
	{
		if (p->Data == Data)
			break;
		else
			p = p->Next;
	}
	return p;
}

template<class T>
Node<T>* DoubleLinkedList<T>::FindOrder(T Data)
{
	Node<T>* p = this->Head;
	while (p != NULL)
	{
		if (p->Data < Data)
			p = p->Next;
		else if (p->Data == Data)
			break;
		else
			p = NULL;
	}
	return p;
}

template<class T>
bool DoubleLinkedList<T>::Find_B(T Data)
{
	Node<T>* p = this->Head;
	while (p != NULL)
	{
		if (p->Data == Data)
			break;
		else
			p = p->Next;
	}
	return p != NULL;
}

template<class T>
bool DoubleLinkedList<T>::FindOrder_B(T Data)
{
	Node<T>* p = this->Head;
	while (p != NULL)
	{
		if (p->Data < Data)
			p = p->Next;
		else if (p->Data == Data)
			break;
		else
			p = NULL;
	}
	return p != NULL;
}

template<class T>
bool DoubleLinkedList<T>::Remove(T Data)
{
	Node<T>* p = this->Head;
	while (p != NULL)
	{
		if (p->Data == Data)
			break;
		else
			p = p->Next;
	}
	if (p == NULL)
	{
		return false;
	}
	if (p == this->Head)
	{
		this->Head = p->Next;
		this->Head->Prev = NULL;
		delete p;
		this->Count--;
		return true;
	}
	if (p == this->Tail)
	{
		this->Tail = p->Prev;
		this->Tail->Next = NULL;
		delete p;
		this->Count--;
		return true;
	}
	else
	{
		Node<T>* tp = p->Prev;
		Node<T>* sp = p->Next;
		tp->Next = sp;
		sp->Prev = tp;
		delete p;
		this->Count--;
		return true;
	}
	return false;
}

template<class T>
bool DoubleLinkedList<T>::RemoveOrder(T Data)
{
	Node<T>* p = this->Head;
	while (p != NULL)
	{
		if (p->Data < Data)
		{
			p = p->Next;
		}
		else if (p->Data == Data)
		{
			break;
		}
		else
			p = NULL;
	}
	if (p == NULL)
	{
		return false;
	}
	if (p == this->Head)
	{
		this->Head = p->Next;
		this->Head->Prev = NULL;
		delete p;
		this->Count--;
		return true;
	}
	if (p == this->Tail)
	{
		this->Tail = p->Prev;
		this->Tail->Next = NULL;
		delete p;
		this->Count--;
		return true;
	}
	else
	{
		Node<T>* tp = p->Prev;
		Node<T>* sp = p->Next;
		tp->Next = sp;
		sp->Prev = tp;
		delete p;
		this->Count--;
		return true;
	}
	return false;
}

template<class T>
void DoubleLinkedList<T>::DisplayNext()
{
	if (IsEmpty())
		cout << "Danh sach rong" << endl;
	else
	{
		cout << "Noi dung cua danh sach:" << endl;
		Node<T>* p = this->Head;
		while (p != NULL)
		{
			p->Display();
			p = p->Next;
		}
		cout << "So phan tu = " << this->Count << endl;
	}
}

template<class T>
void DoubleLinkedList<T>::DisplayPrevious()
{
	if (IsEmpty())
		cout << "Danh sach rong" << endl;
	else
	{
		cout << "Noi dung cua danh sach:" << endl;
		Node<T>* p = this->Tail;
		while (p != NULL)
		{
			p->Display();
			p = p->Prev;
		}
		cout << "So phan tu = " << this->Count << endl;
	}
}

template<class T>
void DoubleLinkedList<T>::Clear()
{
	Node<T>* p;
	while (this->Head != NULL)
	{
		p = this->Head;
		this->Head = p->Next;
		delete p;
	}
	this->Tail = NULL;
	this->Count = 0;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	this->Clear();
}


