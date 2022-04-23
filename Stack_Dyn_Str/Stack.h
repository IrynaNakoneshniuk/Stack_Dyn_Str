#pragma once
#include "Node.h"
#include <string>

using namespace std;

template <typename T>
class Stack
{
  private:
    Node<T>* head;
    Node<T>* tail;
	size_t length;
	public:
     Stack();
     ~Stack();
	T Top()const  { return tail->getValue(); }
	size_t getSize() { return (this->lenght>0)? this->length: 0; }
    void  Push(T elem);
    void  Pop();
    bool Empty() { return (length == 0) ? true : false; }
    bool ChekLine(string& str);
};

template<typename T>
inline Stack<T>::Stack()
{
    head=nullptr;
    tail= nullptr;
    length=0;
}

template<typename T>
inline Stack<T>::~Stack()
{
    int k = length;
    Node<T>* node_elem = new Node<T>();
    node_elem = tail;
    for (size_t i = 1; i <=k; i++) {
        if (node_elem->prev == nullptr)
        {
            tail = head = nullptr;
        }
        else {
            tail = node_elem->prev;
            tail->next = nullptr;
        }
        length--;
        delete node_elem;
    }
}

template<typename T>
inline void Stack<T>::Push(T elem)
{
    Node<T>* node_elem = new Node<T>(elem);
    if (length == 0)
    {
        head = tail = node_elem;
    }
    else {
        tail->next = node_elem;
        node_elem->prev = tail;
        tail = node_elem;
    }
    length++;
}

template<typename T>
inline void Stack<T>::Pop()
{
    Node<T>* node_elem = new Node<T>();
    node_elem = tail;
    if (length==1)
    {
        tail = head = nullptr;
    }
    else {
        tail = node_elem->prev;
        tail->next = nullptr;
    }
    length--;
    delete node_elem;
}

template<typename T>
inline bool Stack<T>::ChekLine(string& str)
{
    Push(str[0]);
    for (size_t i = 1; i <=str.length(); i++) {
        if (str[i] == 125|| str[i] == 93
            || str[i] == 41) {
            if (Top() == 123&& str[i] == 125||
                Top() == 91&& str[i] == 93 ||
                Top() == 40&& str[i] == 41) {
                Pop();
            }
        }
        else if(str[i] == 123 || 
            str[i] == 91
            || str[i] == 40) {
            
           Push(str[i]);
             }
    }
    return (Empty()) ? true : false;
}
