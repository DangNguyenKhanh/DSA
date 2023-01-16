#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Node
{
    public:
        T Key;
        int Count;
        Node<T>* Left;
        Node<T>* Right;
    public:
        Node(T);
        void Display();
};

template<class T>
Node<T>::Node(T theKey)
{
    Key = theKey;
    Count = 1;
    Left = NULL;
    Right = NULL;
}

template<class T>
void Node<T>::Display()
{
    cout << Key << " ";
}

template<class T>
class BST
{
    private:
        Node<T>* Root;
    public:
        BST();
        bool IsEmpty();
        void Insert(T);
        void TraverseNLR();
        void TraverseLevels();
        Node<T>* Find(T);
        void Remove(T);
        bool IsBST();
        void Clear();
        ~BST();
    private:
        void Insert_Recursive(Node<T>*&, T);
        void TraverseNLR_Recursive(Node<T>*);
        Node<T>* Find_Recursive(Node<T>*, T);
        void Remove_Recursive(Node<T>*&, T);
        void RemoveRightMostNode(Node<T>*&, Node<T>*&);
        bool IsBST_Recursive(Node<T>*, T&, bool&);
        void ClearLRN(Node<T>*&);
};

template<class T>
BST<T>::BST()
{
    Root = NULL;
}

template<class T>
bool BST<T>::IsEmpty()
{
    return Root == NULL;
}

template<class T>
void BST<T>::Insert(T theKey)
{
   Insert_Recursive(Root, theKey);
}

template<class T>
void BST<T>::Insert_Recursive(Node<T>*& p, T theKey)
{
    if(p == NULL)
        p = new Node<T>(theKey);
    else if(theKey < p->Key)
        Insert_Recursive(p->Left, theKey);
    else if(theKey == p->Key)
        p->Count++;
    else
        Insert_Recursive(p->Right, theKey);
}

template<class T>
void BST<T>::TraverseNLR()
{
    if(IsEmpty())
        cout << "Tree is empty..." << endl;
    else    
        TraverseNLR_Recursive(Root);
}

template<class T>
void BST<T>::TraverseNLR_Recursive(Node<T>* p)
{
    if(p != NULL)
    {
        p->Display();
        TraverseNLR_Recursive(p->Left);
        TraverseNLR_Recursive(p->Right);
    }
    else
        cout << "NULL" << " ";
}

template<class T>
void BST<T>::TraverseLevels()
{
    if(!IsEmpty())
    {
        queue<Node<T>*> theQueue;
        theQueue.push(Root);
        while(!theQueue.empty())
        {
            Node<T>* p = theQueue.front();
            theQueue.pop();
            p->Display();
            if(p->Left != NULL)
                theQueue.push(p->Left);
            if(p->Right != NULL)
                theQueue.push(p->Right);
        }
    }
}

template<class T>
Node<T>* BST<T>::Find(T theKey)
{
    return Find_Recursive(Root, theKey);
}

template<class T>
Node<T>* BST<T>::Find_Recursive(Node<T>* p, T theKey)
{
    Node<T>* result;
    if(p == NULL)
        result = NULL;
    else
    {
        if(theKey < p->Key)
            result = Find_Recursive(p->Left, theKey);
        else if(theKey == p->Key)
            result = p;
        else
            result = Find_Recursive(p->Right, theKey);
    }
    return result;
}

template<class T>
void BST<T>::Remove(T theKey)
{
    Remove_Recursive(Root, theKey);
}

template<class T>
void BST<T>::Remove_Recursive(Node<T>*& p, T theKey)
{
    if(p != NULL)
    {
        if(theKey < p->Key)
            Remove_Recursive(p->Left, theKey);
        else if(theKey > p->Key)
            Remove_Recursive(p->Right, theKey);
        else
        {
            Node<T>* q = p;
            if(p->Left == NULL && p->Right == NULL)
                p = NULL;
            else if(p->Left != NULL && p->Right == NULL)
                p = p->Left;
            else if(p->Left == NULL && p->Right != NULL)
                p = p->Right;
            else
                RemoveRightMostNode(p->Left, q);
            delete q;
        }
    }
}

template<class T>
void BST<T>::RemoveRightMostNode(Node<T>*& r, Node<T>*& q)
{
    if(r->Right != NULL)
        RemoveRightMostNode(r->Right, q);
    else
    {
        q->Key = r->Key;
        q->Count = r->Count;
        q = r;

        r = r->Left;
    }
}

template<class T>
bool BST<T>::IsBST()
{
    T key = 0;
    bool firstTime = true;
    return IsBST_Recursive(Root, key, firstTime);
}

template<class T>
bool BST<T>::IsBST_Recursive(Node<T>* p, T& key, bool& firstTime)
{
    bool isBST = true;
    if(p != NULL)
    {
        isBST = IsBST_Recursive(p->Left, key, firstTime);
        if(isBST)
        {
            if(firstTime)
                firstTime = false;
            else if(key >= p->Key)
                isBST = false;
            key = p->Key;
        }
        if(isBST)
            isBST = IsBST_Recursive(p->Right, key, firstTime);
    }
    return isBST;
}

template<class T>
void BST<T>::Clear()
{
    ClearLRN(Root);
}

template<class T>
void BST<T>::ClearLRN(Node<T>*& p)
{
    if(p != NULL)
    {
        ClearLRN(p->Left);
        ClearLRN(p->Right);
        delete p;
        p = NULL;
    }
}
