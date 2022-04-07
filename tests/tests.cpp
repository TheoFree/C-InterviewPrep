#include "../cpp/node.cpp"
#include "../cpp/graph.cpp"
#include "../cpp/dynamicProblemsSimple.cpp"
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <stdlib.h>
#include <time.h>
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

void graphTests(){
	Graph* g = new Graph();
	cout << "Add Vertices 7 and 9. Try to re-add 9.\n\t";
	auto a = g->addVertex(7);
	auto b = g->addVertex(9);
	g->addVertex(9); // should have error
	cout << "Add Vertices 3 and 5. Try to print graph, should say no edges. \n\t";
	auto c = g->addVertex(3);
	auto d = g->addVertex(5);
	g->printGraph();
	cout << "Add edges: \n\t7-3 with weight 7\n\t3-5 with weight 9\n\t 9-7 with weight 4\nPrint graph.\n";
	g->addEdge(g->getVertex(7),g->getVertex(3),7);
	g->addEdge(g->getVertex(3),g->getVertex(5),9);
	g->addEdge(g->getVertex(9),g->getVertex(7),4);
	g->printGraph();



	
	return;
}

void graphDijkstrasRand(){
	srand (time(NULL));
	int numV = rand() % 15 + 3; // set number of vertices, minimum 3
	Graph* G = new Graph();
	for(int i = 0; i < numV; i++){
		G->addVertex(i); // add predetermined number of vertices
	}
	for(int i = 0; i < numV; i++){
		auto V = G->getVertex(i);
		for( int j = 0; j < rand() % 3 + 1; j++ )
		G->addEdge(V,G->getVertex(rand() % numV +1), rand()% 10 + 1); 
		// add an edge to each vertex at least once up to 3 times
	}
	auto source = G->getVertex(rand() % numV);// 
	auto dest = source;
	
	while(source == dest){
		auto temp  = G->getVertex(rand() % numV );
		if( temp != source && temp != nullptr) dest = temp;
		// get destination that is not source
	}
	G->printGraph();
	cout << "\nSource is Vertex "<< source->n << "\n";
	cout << "Destination is Vertex " << dest->n << "\n";
	//tuple<int, map< Graph::Vertex*,Graph::Vertex* > > = G->dijkstra(source,dest);
	auto [w, path] = G->dijkstra(source,dest);
	if(path[dest] == nullptr){
		cout << "Did not find a path.\n";
		return;
	}
	cout << "Distance from source: " << source->n << " to dest: " << dest->n <<" is : " << w << ".\n";
	cout << "Path is:\n\t";
	auto temp = dest;
	cout << "start loop\n\t";
	cout << temp -> n;
	while(temp != source){
		cout << "v:" << temp->n << "-";
		temp = path[temp];
	}
	cout << source->n << ".\n";
	return;
};

void graphDijkstras(){
	Graph* G = new Graph();
	for(int i = 0; i < 10; i++){
		G->addVertex(i);
	}
	G->printGraph();
	auto source = G->getVertex(0);
	auto dest= G->getVertex(1);
	G->addEdge(G->getVertex(0),G->getVertex(1),1);
	G->printGraph();
	cout << "------------------------\n";
	auto runAndPrint = [G](auto source, auto dest){
		auto [ w, path] = G->dijkstra(source,dest);
		if(path[dest] == nullptr){
			cout << "Did not find a path.\n";
			return;
		}
		cout << "Distance from source: " << source->n << " to dest: " << dest->n <<" is : " << w << ".\n";
		cout << "Path is:\n\t";
		auto temp = dest;
		while(temp != source && temp != nullptr){
			cout << "v:" << temp->n << "-";
			temp = path[temp];
		}
		cout << "v:" << source->n << ".\n";
	};
	runAndPrint(source,dest);
	G->addEdge(G->getVertex(1),G->getVertex(5),3);
	G->addEdge(G->getVertex(3),G->getVertex(2),5);
	G->addEdge(G->getVertex(4),G->getVertex(8),7);
	G->addEdge(G->getVertex(6),G->getVertex(3),4);
	G->addEdge(G->getVertex(9),G->getVertex(1),2);
	G->addEdge(G->getVertex(4),G->getVertex(2),1);
	G->printGraph();
	cout << "------------------------\n";
	source = G->getVertex(0);
	dest = G->getVertex(5);
	runAndPrint(source,dest);
	G->addEdge(G->getVertex(5),G->getVertex(7),3);
	G->addEdge(G->getVertex(7),G->getVertex(4),7);
	G->printGraph();
	cout << "------------------------\n";
	runAndPrint(G->getVertex(0),G->getVertex(8));
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

