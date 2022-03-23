#include "../cpp/node.cpp"
#include <iostream>
using namespace std;
void nodeandSpotTests(){
	Node* A = new Node(5);
        Node* B = new Node(4);
        A->setNext(B);
        Node* C = new Node(A->getVal()*B->getVal());
        B->setNext(C);

        for(Node* temp = A; temp != NULL; temp = temp->getNext()){
                cout<< temp->getVal()<< " is the current node's value.\n";
        }
        cout<< "--------------\n";
        spot* D = new spot(3);
        spot* E = new spot(8);
        D->Next = E;
        spot* F = new spot(D->val+E->val);
        E->Next = F;
        for(spot* foo = D; foo != NULL; foo = foo->Next){
                cout<< foo->val<<" is the current spot's value.\n";
        }
        delete A, B, C, D, E, F;
        delete F;
        try{
                cout<< F->val<<" is F's val after deletion.\n"; 
 	}catch(...){
                cout<< "Didn't think so.\n";
        }

	return;
}
