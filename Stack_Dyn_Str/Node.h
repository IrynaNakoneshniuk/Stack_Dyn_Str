#pragma once
using namespace std;
template<typename T>
class Node
{
   public:
	T value;
	Node* next;
	Node* prev;
	Node(T value);
	Node();
	T getValue() { return this->value; }
	void setVulue(T value) { this->value = value; }
};

template<typename T>
inline Node<T>::Node(T value)
{
	this->value = value;
	this->next = nullptr;
	this->prev = nullptr;
}

template<typename T>
inline Node<T>::Node()
{
	this->value = 0;
	this->next = nullptr;
	this->prev = nullptr;
}




