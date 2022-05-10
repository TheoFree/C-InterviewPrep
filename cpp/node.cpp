#include "../headers/node.h"
#include <iostream>
#include <cstddef>
using namespace std;

Node::Node(int n){
	this->val = n;
	this->Next = nullptr;
	this->Prev = nullptr;
};

int Node::setVal(int n){
	this->val = n;
	return this->val;
};

int Node::getVal(){
	return this->val;
};

bool Node::setNext(Node *N){
	return this->Next = N;
};

Node* Node::getNext(){
	return (this->Next!=nullptr) ? this->Next :nullptr;
};

bool Node::setPrev(Node *N){
	return this->Prev = N;
};

Node* Node::getPrev(){
	return this->Prev;
};

LinkedList::LinkedList(int n){
	Node* N = new Node(n);
	Head = N;
	cur = N;
	Tail =N;
};

void LinkedList::push(int n){
	Node* temp = new Node(n);
	temp->setPrev(Tail);
	Tail->setNext(temp);
	Tail = temp;
	return;
};

bool LinkedList::pop(int n){
	Node* temp = search(n);
	
	if(temp != nullptr){
		if(temp == Head){
			Head = Head->getNext();
			//delete temp;
			return true;
		}

		Node* t_prev = temp->getPrev();
		cout << "get prev\n";
		if(temp != Tail) t_prev->setNext(temp->getNext());
		else Tail = t_prev;
		cout << "halfway\n";
		cout << "past craziness\n";
		return true;
	}
	else cout << "Not found\n";
	return false;
};
void LinkedList::print(){
	Node* temp = Head;
	while(temp != Tail){
		cout << temp->getVal() << " ";
		temp = temp->getNext();
	}
	cout << temp->getVal() <<"\n";
	return;
};
Node* LinkedList::traverseForward(){
	return cur = cur->getNext();
};

Node* LinkedList::traverseBackward(){
	return cur = cur->getPrev();
};

Node* LinkedList::search(int n){
	Node* temp = Head;
	bool searching = true;
	while(temp!=nullptr){
		if(temp->getVal()==n) return temp;
		temp = temp->getNext();	
	}
	return nullptr;
};

LinkedList::~LinkedList(){
	Node* temp = Head;
	while(cur->getNext()!=NULL){
		temp = cur->getNext();
		delete cur;
		cur = temp;
	}
};


spot::spot(int n){
	this->val = n;
	this->Next = nullptr;
	this->Prev = nullptr;
	return;
};
Node::~Node(){
	if(Next != nullptr) Next = nullptr;
	if(Prev != nullptr) Prev = nullptr;
};
spot::~spot(){
	if(Next != nullptr) delete Next;
	if(Prev != nullptr) delete Prev;
};
