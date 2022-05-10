#include "../tests/tests.cpp"
#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;

int main(int argc, char **argv){
	bool interactive = false;
	if(argc == 2){
		vector<string> options = {"-f","NodesAndSpot","linkedLists","graph","canSum","howSum","dijkstra","dijkstraRand","queue"};
		int selection = -1;
		string input = string(argv[1]);
		for(int i = 0; i<options.size();i++){
			if(input==options[i]){
				selection = i;
				break;
			}
		}
		if(selection >= 0){
			switch (selection){
			
			case 0: // -f
				interactive = true;
				break;
			case 1: // NodesAndSpot
				cout << " ----------\n";
				nodeandSpotTests();
				return 1;
			case 2: // linkedLists
				cout << " ----------\n";
				linkedListTests();
				return 1;
			case 3: // graph
				cout << " ----------\n";
				graphTests();
				return 1;
			case 4: // canSum
				cout << " ----------\n";
				canSumTest();
				return 1;
			case 5: // howSum
				cout << " ----------\n";
				howSumTest();
				return 1;
			case 6: // dijkstras
				cout << " ----------\n";
				graphDijkstras();
				return 1;
			case 7:
				cout << " ----------\n";
				graphDijkstrasRand();
				return 1;
			case 8:
				cout << " ----------\n";
				queueTests();
				return 1;
			default:
				cout << "Invalid input 1: " << input << "\n";
				return 0;
			}
		}
		
	}
	string input;
	while(interactive){
		cout << " ----------\n";
		cout << "Test options are:"; 
		cout << "\n-----Data Structures-----";
		cout << "\n\t\'NodesAndSpot\'- test nodes class and spot struct";
		cout << "\n\t\'linkedLists\'- test linked list class";
		cout << "\n\t\'queue\' - test queue implementation";
		cout << "\n\t\'graph\' - test graph implementation";
		cout << "\n-----Dynamic Programing Problems";
		cout <<	"\n\t\'canSum\' - test canSum implementation";
		cout <<	"\n\t\'howSum\' - test howSum implementation";
		cout << "\n-----Dijkstra tests";
		cout << "\n\t\'dijkstra\' - test dijkstras alg.";
		cout << "\n\t\'dijkstraRand\' - test dijkstras alg. on random set of vertices and edges.";

		cout << "\n\t\'exit\' - quit\n";
		cin >> input;
		if(input == "NodesAndSpot"){
			cout << " ----------\n";
			nodeandSpotTests();
			continue;
		}
		if(input == "linkedLists"){
			cout << " ----------\n";
			linkedListTests();
			continue;
		}
		if(input == "graph"){
			cout << " ----------\n";
			graphTests();
			continue;
		}
		if(input == "canSum"){
			cout << " ----------\n";
			canSumTest();
			continue;
		}
		if(input == "howSum"){
			cout << " ----------\n";
			howSumTest();
			continue;
		}
		if(input == "dijkstra"){
			cout << " ----------\n";
			graphDijkstras();
			continue;
		}
		if(input == "dijkstraRand"){
			cout << " ----------\n";
			graphDijkstrasRand();
			continue;
		}
		if(input == "queue"){
			cout << " ----------\n";
			queueTests();
			continue;
		}
		if(input == "exit"){
			return 0;
		}
		else cout << "Invalid input\n.";
		contin:;
	}
	if(!interactive){
		cout << " ----------\n";
		cout <<"Start nodeandSpotTest()\n";
		nodeandSpotTests();

		cout << " ----------\n";
		cout <<"Start linkedListTests()\n";
		linkedListTests();

		cout << " ----------\n";
		cout <<"Start queueTests()\n";
		queueTests();
		
		cout << " ----------\n";
		cout << "Start graphTests()\n";
		graphTests();

		cout << " ----------\n";
		cout << "Start graphDijkstras()\n";
		graphDijkstras();

		cout << " ----------\n";
		cout <<"Start canSumTest()\n";
		canSumTest();
		
		/*cout << " ----------\n";
		cout<<"Start howSum2Test()\n";
		auto start = chrono::high_resolution_clock::now();
		howSum2Test();
		auto stop = chrono::high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop-start);
		cout<< "Execution of test took:" << duration.count() <<" milliseconds for total test.\n";
		*/

		cout << " ----------\n";
		cout <<"Start howSumTest()\n";
		//start = chrono::high_resolution_clock::now();
		howSumTest();
		//stop = chrono::high_resolution_clock::now();
		//duration = duration_cast<microseconds>(stop-start);
		//cout<< "Execution of test took:" << duration.count() <<" milliseconds for total test.\n";
		
		
	}
	return 1;
}
