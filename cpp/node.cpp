#include "../headers/node.h"
#include <cstddef>
Node::Node(int n){
	this->val = n;
	this->Next = NULL;
	this->Prev = NULL;
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
	return this->Next;
};

bool Node::setPrev(Node *N){
	return this->Prev = N;
};

Node* Node::getPrev(){
	return this->Prev;
};
spot::spot(int n){
	this->val = n;
	this->Next = NULL;
	this->Prev = NULL;
	return;
};
Node::~Node(){
	if(Next != NULL) delete Next;
	if(Prev != NULL) delete Prev;
};
spot::~spot(){
	if(Next != NULL) delete Next;
	if(Prev != NULL) delete Prev;
};
