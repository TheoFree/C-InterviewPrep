## C++ Interview Preper Suite


### This is a project I started to refresh my c++, datastructures, algorithms, and try to solve some fun problems.

#### File Tree Structure
```
ROOT -- README.md
     -- build.sh
     -- bin/ (excluded from git tracking) 
          -- built (executable binary produced by running build.sh)
     -- cpp/ 
	     -- main.cpp
	     -- Nodes.cpp
          -- Graph.cpp
          -- dynamicProblemsSimple.cpp
     -- headers/
	     -- Nodes.h
          -- Graph.h
     -- tests/
	     -- tests.cpp
```

#### Use
running build.sh recompiles main.cpp, and runs it based on options provided:
	Default (None) = Run every test.
	-f = Run interactively, can specify what test to run.

#### Currently Implemented

#####	Node
A class with int value, pointers to Next and Prev Nodes, and methods to access Int, Prev, Next and modify Int, Prev, Next.

#####	Spot
A struct with int value, pointers to Next and Prev Spots. No get/set methods needed.

#####     Linkedlists (Doubly linked)
Uses the previously implemented Node class. Includes Head and Tail pointers, and methods for pushing and poping new Nodes, traversal in both directions and printing.

#####      Graph
Graph implementation made using structs. Might add onto later.

#####     canSum
An algorithm for solving the problem: given a target and array of numbers, can you add some of the number in the array to equal the target? 

#####     howSum
Modified problem from the previous where now you must return the combination of numbers that sums to the target. I created my own solution as well as implemented a solution following a lecture on dynamic programming.

#####     Dijkstras
Implemented as memeber function inside Graph class. Uses priority queue that populates as vertices are discovered as neighbors. 

#### Current Tests
#####	NodesAndSpot   - tests simple implementation of Nodes and Spots.
#####     linkedLists    - tests implementation of linked list.
#####     graphTests     - tests implementation of graph class.
#####     graphDijkstras - tests dijkstras on different graphs. 
#####     canSum         - tests can sum algorithm on some sample inputs.
#####     howSum         - tests two implementations of howSum, with timing comparisons.