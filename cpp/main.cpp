#include "../tests/tests.cpp"
#include <iostream>
#include <chrono>
using namespace std::chrono;

int main(int argc, char **argv){
	bool testing = true;
	// cout << "Start\n";	
	if(argc == 2){
	//	cout << " Argc ==2\n";
	        if(string(argv[1]) == "-f"){
	//	       	cout << " Argv[1] == -f\n";
			testing = false;
		}
	        else{
	//		cout << "Start\n";
			cout << "Invalid input 1: " << argv[1] << "\n";
		}
	}
	string input;
	while(!testing){
		cout << " ----------\n";
		cout << "Test options are:"; 
		cout << "\n\t\'NodesAndSpot\'- test nodes class and spot struct";
		cout << "\n\t\'linkedLists\'- test linked list class";
		cout <<	"\n\t\'canSum\' - test canSum implementation";
		cout <<	"\n\t\'howSum\' - test howSum implementation";
		cout << "\n\t\'exit\' - quit\n";
		cin >> input;
		if(input == "NodesAndSpot"){
			cout << " ----------\n";
			nodeandSpotTests();
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
		if(input == "linkedLists"){
			cout << " ----------\n";
			linkedListTests();
			continue;
		}

		if(input == "exit"){
			testing = true;
			return 0;
		}
		else cout << "Invalid input\n.";
		contin:;
	}
	if(testing){
		cout << " ----------\n";
		cout<<"Start nodeandSpotTest()\n";
		nodeandSpotTests();
		
		cout << " ----------\n";
		cout<<"Start canSumTest()\n";
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
		cout<<"Start howSumTest()\n";
		//start = chrono::high_resolution_clock::now();
		howSumTest();
		//stop = chrono::high_resolution_clock::now();
		//duration = duration_cast<microseconds>(stop-start);
		//cout<< "Execution of test took:" << duration.count() <<" milliseconds for total test.\n";
		cout << " ----------\n";
		cout<<"Start linkedListTests()\n";
		linkedListTests();
		
	}
	return 1;
}
