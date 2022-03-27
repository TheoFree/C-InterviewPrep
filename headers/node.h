class Node{

		int val;
		Node* Next;
		Node* Prev;
	public:
		int setVal(int n);
		int getVal();
		bool setNext(Node *N);
		Node* getNext();
		bool setPrev(Node *N);
		Node* getPrev();
		Node(int n);
		~Node();

};

class LinkedList{
	Node* cur;
	Node* Head;
	Node* Tail;
	public:
		LinkedList(int n);
		void push(int n);
		bool pop(int n);
		void print();
		Node* traverseForward();
		Node* traverseBackward();
		Node* search(int n);
		~LinkedList();
};

struct spot{
	int val;
	spot* Next;
	spot* Prev;
	spot (int n);
	~spot();
};
