## C++ Interview Preper Suite


### This is a project I started to refresh my c++, datastructures, algorithms, and try to solve some fun problems.

#### File Tree Structure
```
ROOT -- README.md
     -- build.sh
     -- bin (excluded from git tracking) 
        -- built (executable binary produced by running build.sh)
     -- cpp 
	-- main.cpp
	-- Nodes.cpp
     -- headers
	-- Nodes.h
     -- tests
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

#### Current Tests
#####	NodesAndSpot - tests simple implementation of Nodes and Spots
