#include "../headers/queue.h"
#include <iostream>

Q::~Q(){
    while(top != nullptr)
    pop();
};
void Q::push(int val){
    Node* temp = new Node(val);
    temp->setPrev(top);
    this->top = temp;
    return;
};

int Q::pop(){
    Node* temp = top;
    top = top->getPrev();
    int out = temp->getVal();
    delete temp;
    return out;
}

void Q::print(){
    Node* temp = top;
    while(temp != nullptr){
        std::cout << temp->getVal() << " then,\n";
        temp = temp->getPrev();
    }
    return;
}