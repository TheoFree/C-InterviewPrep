#include "../cpp/node.cpp"
#include "../cpp/dynamicProblemsSimple.cpp"
#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
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

void linkedListTests(){
	cout<< "Start linked lists tests\n";
	cout<< "Init linked list w/ value 7\n";
	LinkedList* A = new LinkedList(7);
	cout<< "Push 4\n";
	A->push(4);
	cout<< "Push 8\n";
	A->push(8);
	cout<< "Print list\n";
	A->print();
	cout<< "push 9\n";
	A->push(9);
	cout<< "pop 7\n";
	A->pop(7);
	cout<< "Print list\n";
	A->print();
	return;
}
void canSumTest(){
	vector<int> a = {2,3}; // true for 2, 3, 5,....
	vector<int> b = {3,5,7}; // true for 3, 5, 8, 10, 12, ....
	cout << "a = {2,3}, b = {3,5,7}\n";
	cout << "canSum(5, a) returns " << canSum(5,a) << " should be true\n";
	cout << "canSum(1, b) returns " << canSum(1,b) << " should be false\n";
	cout << "canSum(7, b) returns " << canSum(7,b) << " should be true\n";
	cout << "canSum(26, b) returns " << canSum(26,b) << " should be false\n";
	cout << "canSum(15, b) returns " << canSum(15,b) << " should be true\n";
	cout << "canSum(67,b) returns " << canSum(3000, b) << " should be true\n";
	return;
}

void howSumTest(){
	vector<int> a = {2,3};
	vector<int> b = {3,5,7};
	vector<int> temp;
	cout << "a = {2,3}, b = {3,5,7}\n";

	cout << "howSum(5,a)\n";
	auto start = chrono::high_resolution_clock::now();
	temp = howSum(5,a);
	auto end = chrono::high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\n should be 2 3\n";

	cout << "howSum2(5,a)\n";
	start = high_resolution_clock::now();
	temp = howSum2(5,a);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp)cout << " " << num << ",";
	cout << "\n should be 2 3\n";


	cout << "howSum(21,b)\n";
	start = high_resolution_clock::now();
	temp = howSum(21,b);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\n should be 3 3 3 3 3 3 3\n";
	
	cout << "howSum2(21,b)\n";
	start = high_resolution_clock::now();
	temp = howSum2(21,b);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\n should be 3 3 3 3 3 3 3\n";


	cout << "howSum(19,b)\n";
	start = high_resolution_clock::now();
	temp = howSum(19,b);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp)cout << " " << num;
	cout << "\n should be 3 3 3 5 5\n";
	
	cout << "howSum2(19,b)\n";
	start = high_resolution_clock::now();
	temp = howSum2(19,b);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\n should be 3 3 3 5 5\n";


	cout << "howSum(2,b)\n";
	start = high_resolution_clock::now();
	temp = howSum(2,b);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\n should be {}\n";

	cout << "howSum2(2,b)\n";
	start = high_resolution_clock::now();
	temp = howSum2(2,b);
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\n should be {}\n";


	
	cout << "howSum(351,{9,3,8)\n";
	start = high_resolution_clock::now();
	temp = howSum(351,{9,3,8});
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\nshould be {}\n";

	cout << "howSum2(351,{9,3,8)\n";
	start = high_resolution_clock::now();
	temp = howSum2(351,{9,3,8});
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	cout << "\n should be {}\n";


	
	cout << "howSum(1000, {9,8,7,6,5,4,3,2,1})\n";
	start = high_resolution_clock::now();
	temp = howSum(1000, {9,8,7,6,5,4,3,2,1});
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num;
	
	cout << "howSum2(1000, {9,8,7,6,5,4,3,2,1})\n";
	start = high_resolution_clock::now();
	temp = howSum2(1000, {9,8,7,6,5,4,3,2,1});
	end = high_resolution_clock::now();
	duration = duration_cast<microseconds>(end-start);
	cout << "Time taken: " << duration.count() << " milliseconds\nReturned:" ;
	for(auto num : temp) cout << " " << num ;
	
	
	return;
}
void howSum2Test(){
	vector<int> a = {2,3};
	vector<int> b = {3,5,7};
	cout << "a = {2,3}, b = {3,5,7}\n";
	
	
	
	
	
	
	
	

	

	return;
}	

