#include "../tests/tests.cpp"
#include <iostream>
using namespace std;

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
		cout << "Test options are: \n\t\'NodesAndSpot\' - test nodes class and spot struct\n\t\'exit\' - quit\n";
		cin >> input;
		if(input == "NodesAndSpot")nodeandSpotTests();
		if(input == "exit"){
			testing = true;
			return 0;
		}
		else cout << "Invalid input\n.";
	}
	if(testing){
		cout<<"Start nodeandSpotTest()\n";
		nodeandSpotTests();

	}
	return 1;
}
