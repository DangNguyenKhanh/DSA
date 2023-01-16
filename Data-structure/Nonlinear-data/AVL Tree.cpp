#include<iostream>
using namespace std;

template<class T>
class Node
{
    public:
        int Key;
        int Height;
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
    this->Key = theKey;
    this->Height = 1;
    this->Count = 1;
    this->Left = NULL;
    this->Right = NULL;
}

template<class T>
void Node<T>::Display()
{
    cout << "(" <<this->Key << " " << this->Height << ")" << " ";
}

template<class T>
class AVL
{
    private:
        Node<T>* Root;
    public:
        AVL();
        bool IsEmpty();
        void Insert(T);
        Node<T>* Find(T);
        void Remove(T);
        void TraverseNLR();
        void print2D();
        bool IsBalanced();
        void Clear();
        ~AVL();
    private:
        int GetHeight(Node<T>*);
        void NLR(Node<T>*);
        void ComputeHeight(Node<T>*);
        
        void SingleWithLeftChild(Node<T>*&);
        void DoubleWithLeftChild(Node<T>*&);
        void RotateWithLeftChild(Node<T>*&);

        void SingleWithRightChild(Node<T>*&);
        void DoubleWithRightChild(Node<T>*&);
        void RotateWithRightChild(Node<T>*&);

        void InsertAVL(Node<T>*&, T);
        void print2DUtil(Node<T>*, int);
        Node<T>* Find_Recursive(Node<T>*, T);
        void RemoveRightMostNode(Node<T>*&, Node<T>*&);
        void RemoveAVL(Node<T>*&, T);
        bool IsAVL(Node<T>*, int&);
        void ClearLRN(Node<T>*&);
};

template<class T>
AVL<T>::AVL()
{
    this->Root = NULL;
}

template<class T>
bool AVL<T>::IsEmpty() 
{
    return Root == NULL;
}

template<class T>
int AVL<T>::GetHeight(Node<T>* p)
{
    if(p == NULL)
        return 0;
    else
        return p->Height;
}

template<class T>
void AVL<T>::NLR(Node<T>* p)
{
    if(p != NULL)
    {
        p->Display();
        NLR(p->Left);
        NLR(p->Right);
    }
    else
        cout << "NULL" << " ";
}

template<class T>
void AVL<T>::TraverseNLR()
{
    if(this->IsEmpty())
        cout << "Tree is empty..." << endl;
    else
        NLR(this->Root);
}

template<class T>
void AVL<T>::print2DUtil(Node<T>* root, int space)
{
    if (root == NULL)
    {
        for (int i = 0; i < space; i++)
            cout << " ";
        cout << "NULL" << " ";
        return;
    }
    
    space += 10;
 
    print2DUtil(root->Right, space);
 
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->Key << "\n";
 
    print2DUtil(root->Left, space);
}

template<class T>
void AVL<T>::print2D()
{
    print2DUtil(this->Root, 0);
}

template<class T>
void AVL<T>::ComputeHeight(Node<T>* p)
{
    int hl = GetHeight(p->Left);
    int hr = GetHeight(p->Right);
    if(hl >= hr)
        p->Height = hl + 1;
    else   
        p->Height = hr + 1;
}

template<class T>
void AVL<T>::SingleWithLeftChild(Node<T>*& p)
{
    Node<T>* q = p->Left;
    p->Left = q->Right;
    q->Right = p;
    ComputeHeight(p);
    ComputeHeight(q);
    p = q;
}

template<class T>
void AVL<T>::DoubleWithLeftChild(Node<T>*& p)
{
    Node<T>* q = p->Left;
    Node<T>* r = q->Right;
    q->Right = r->Left;
    p->Left = r->Right;
    r->Left = q;
    r->Right = p;
    ComputeHeight(q);
    ComputeHeight(p);
    ComputeHeight(r);
    p = r;
}

template<class T>
void AVL<T>::RotateWithLeftChild(Node<T>*& p)
{
    Node<T>* q = p->Left;
    if(this->GetHeight(q->Left) >= this->GetHeight(q->Right))
        this->SingleWithLeftChild(p);
    else
        this->DoubleWithLeftChild(p);
}

template<class T>
void AVL<T>::SingleWithRightChild(Node<T>*& p)
{
    Node<T>* q = p->Right;
    p->Right = q->Left;
    q->Left = p;
    ComputeHeight(p);
    ComputeHeight(q);
    p = q;
}

template<class T>
void AVL<T>::DoubleWithRightChild(Node<T>*& p)
{
    Node<T>* q = p->Right;
    Node<T>* r = q->Left;
    q->Left = r->Right;
    p->Right = r->Left;
    r->Left = p;
    r->Right = q;
    ComputeHeight(q);
    ComputeHeight(p);
    ComputeHeight(r);
    p = r;
}

template<class T>
void AVL<T>::RotateWithRightChild(Node<T>*& p)
{
    Node<T>* q = p->Right;
    if(this->GetHeight(q->Right) >= this->GetHeight(q->Left))
        this->SingleWithRightChild(p);
    else
        this->DoubleWithRightChild(p);
}

template<class T>
void AVL<T>::InsertAVL(Node<T>*& p, T theKey)
{
    if(p == NULL)
        p = new Node<T>(theKey);
    else if(theKey < p->Key)
    {
        InsertAVL(p->Left, theKey);
        if(this->GetHeight(p->Left) - this->GetHeight(p->Right) == 2)
            RotateWithLeftChild(p);
        ComputeHeight(p);
    }
    else if(p->Key == theKey)
        p->Count = p->Count + 1;
    else
    {
        InsertAVL(p->Right, theKey);
        if(this->GetHeight(p->Right) - this->GetHeight(p->Left) == 2)
            RotateWithRightChild(p);
        ComputeHeight(p);
    }
}

template<class T>
void AVL<T>::Insert(T theKey)
{
    this->InsertAVL(Root, theKey);
}

template<class T>
Node<T>* AVL<T>::Find_Recursive(Node<T>* p, T theKey)
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
Node<T>* AVL<T>::Find(T theKey)
{
    return Find_Recursive(Root, theKey);
}

template<class T>
void AVL<T>::RemoveRightMostNode(Node<T>*& r, Node<T>*& q)
{
    if(r->Right != NULL)
    {
        RemoveRightMostNode(r->Right, q);
        ComputeHeight(r);
    }
    else
    {
        q->Key = r->Key;
        q->Count = r->Count;
        q = r;
        r = r->Left;
    }
}

template<class T>
void AVL<T>::RemoveAVL(Node<T>*& p, T theKey)
{
    if(p != NULL)
    {
        if(theKey < p->Key)
        {
            RemoveAVL(p->Left, theKey);
            if(this->GetHeight(p->Right) - this->GetHeight(p->Left) == 2)
                RotateWithRightChild(p);
            ComputeHeight(p);
        }
        else if(p->Key == theKey)
        {
            Node<T>* q = p;
            if(p->Left == NULL && p->Right == NULL)
                p = NULL;
            else if(p->Left != NULL && p->Right == NULL)
                p = p->Left;
            else if(p->Left == NULL && p->Right != NULL)
                p = p->Right;
            else
            {
                RemoveRightMostNode(p->Left, q);
                if(this->GetHeight(p->Right) - this->GetHeight(p->Left) == 2)
                    RotateWithRightChild(p);
                ComputeHeight(p);
            }
            delete q;
        }
        else
        {
            RemoveAVL(p->Right, theKey);
            if(this->GetHeight(p->Left) - this->GetHeight(p->Right) == 2)
                RotateWithLeftChild(p);
            ComputeHeight(p);
        }
    }
}

template<class T>
void AVL<T>::Remove(T theKey)
{
    RemoveAVL(this->Root, theKey);
}

template<class T>
bool AVL<T>::IsAVL(Node<T>* p, int& height)
{
    bool avl;
    height = 0;
    if(p == NULL)
        avl = true;
    else
    {
        int leftHeight = 0;
        int rightHeight = 0;
        avl = IsAVL(p->Left, leftHeight);
        if(avl)
            avl = IsAVL(p->Right, rightHeight);
        if(avl)
            if(leftHeight == rightHeight + 2 || rightHeight == leftHeight + 2)
                avl = false;
            else
            {
                if(leftHeight > rightHeight)
                    height = leftHeight + 1;
                else   
                    height = rightHeight + 1;
            }
    }
    return avl;
}

template<class T>
bool AVL<T>::IsBalanced()
{
    int height = 0;
    return IsAVL(this->Root, height);
}

template<class T>
void AVL<T>::ClearLRN(Node<T>*& p)
{
    if(p != NULL)
    {
        ClearLRN(p->Left);
        ClearLRN(p->Right);
        delete p;
        p = NULL;
    }
}

template<class T>
void AVL<T>::Clear()
{
    this->ClearLRN(this->Root);
}

template<class T>
AVL<T>::~AVL()
{
    this->Clear();
}

#include<unistd.h>
int main()
{
    AVL<int> tree;
    int n = 50;
    for(int i = 0; i < n; i++)
        tree.Insert(i);
    // cout << (tree.Find(9) != NULL ? "True" : "False") << endl;
    int i = n - 1;
    while(1)
    {
        system("cls");
        if(tree.IsEmpty())
            break;
        tree.print2D();
        cout << endl;
        cout << "Next element removing: " << i << endl;
        cout << "Is AVL: " << (tree.IsBalanced() ? "True" : "False") << endl;
        sleep(0.1);
        tree.Remove(i);
        i--;
    }
}
