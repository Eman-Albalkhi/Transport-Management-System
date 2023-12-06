#ifndef LINKED_LIST_TEMPLATE_H
#define LINKED_LIST_TEMPLATE_H
#include <iostream>
using namespace std;

#include "Node.h"

template <class T>
class LinkedListTemplate
{
public:
    LinkedListTemplate();
    void insertNewNode(T *data);
    void print();
    Node<T>* Searcher(int ID);
    bool iterate_Curr();
    void reset_Curr();
    Node<T>* get_Curr();
    bool isEmpty();
    bool isThere(int ID);
private:
    Node<T> *Head;
    Node<T> *Prev;
    Node<T> *Curr;
};
template <class T>
LinkedListTemplate<T>::LinkedListTemplate()
{
    Curr=Prev=Head = NULL;
}

template <class T>
bool LinkedListTemplate<T>::isEmpty()
{
    if(Head == NULL)
        return 1;
    else
        return 0;
}

template <class T>
void LinkedListTemplate<T>::insertNewNode(T *dataIn)
{
    Prev = Curr = Head;
    Node<T> * newPtr = new Node<T>;
    newPtr->setData(dataIn);
    newPtr->nextPtr=NULL;
    if(isEmpty())
    {
       Head=newPtr;
    }
    else
    {
            while(Curr != NULL&&Curr->getData()->get_ID()<newPtr->getData()->get_ID())
            {
                Prev = Curr;
                Curr = Curr->nextPtr;
            }
            Prev->nextPtr=newPtr;
            newPtr->nextPtr=Curr;
    }
}


template <class T>
void LinkedListTemplate<T>::print()
{
    if(isEmpty())
    {
        cout << "The LinkedListTemplate is empty" << endl;

    }
    else
    {
        Curr = Head;
        while(Curr != NULL)
        {
            Curr->getData()->print();
            Curr = Curr->nextPtr;
        }
        cout << endl;
    }
}

template <class T>
Node<T>* LinkedListTemplate<T>::Searcher(int ID)
{
    bool found = false;
    Curr = Head;
    while((!found) && (Curr != NULL))
    {
        if(Curr->data->get_ID() == ID)
            found = true;
        else
            Curr = Curr->nextPtr;
    }
    if(found)
    return Curr;
}
template <class T>
bool LinkedListTemplate<T>::iterate_Curr()
{
    if(Curr!=NULL)
    {
        Curr=Curr->nextPtr;
        return 1;
    }
    return 0;
}
template <class T>
void LinkedListTemplate<T>::reset_Curr()
{
    Curr=Head;
}
template <class T>
Node<T>* LinkedListTemplate<T>::get_Curr()
{
    if(Curr!=NULL)
        return Curr;
}
template <class T>
bool LinkedListTemplate<T>::isThere(int ID)
{
    bool found = false;
    Curr = Head;
    while((!found) && (Curr != NULL))
    {
        if(Curr->data->get_ID() == ID)
            found = true;
        else
            Curr = Curr->nextPtr;
    }
    return found;

}

#endif
