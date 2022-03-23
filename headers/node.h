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

struct spot{
	int val;
	spot* Next;
	spot* Prev;
	spot (int n);
	~spot();
};
