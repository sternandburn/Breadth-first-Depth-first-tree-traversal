//*****************************************************
//Noah Stern
//CS 355
//Assignment 12
//11/02/20
//Breadth-first/Depth-first
//*****************************************************
#include <iostream>
#include <cstdlib>
using namespace std;
//BST Header
class BinarySearchTree
{
	public:
		 BinarySearchTree();
		 bool empty();
		 void insert(string);
		 void depthFirst();
		 void breadthFirst();
	private:
	    struct node
	    {
		 node * left;
		 node * right;
		 string data;
	    };
	typedef node * NodePtr;
	NodePtr root;
};
//node header
template <class x>
class Node
{
public:
	 Node(x Date, Node <x> * theLink);
	 void setLink(Node <x> * theLink);
	 void setData(x Data);
	 x getData() const;
	 Node <x> * getLink() const
	 {
		return link;
	 }
private:
	x data;
	Node <x> * link;
};
//stack header
template <class t>
class stack
{
public:
	 stack();
	 void push(t item);
	 t pop();
	 bool isEmpty();
	 bool isFull();
private:
	Node <t> * top;
};
//queue header
template <class x>
class queue
{
public:
	 queue();
	 x dequeue();
	 void enqueue(x);
	 x peek();
	 bool isEmpty();
	 bool isFull();
private:
	 Node <x> * front;
	 Node <x> * rear;
};
//***************************************************
//Name: Node
//Purpose: constructor
//Incoming: x theData, Node <x> * theLink
//Outgoing: N/A
//Return: N/A
//***************************************************
template <class x>
Node <x> ::Node(x theData, Node <x> * theLink)
{
	 data = theData;
	 link = theLink;
}
//***************************************************
//Name: getData
//Purpose: get the data
//Incoming: N/A
//Outgoing: N/A
//Return: data
//***************************************************
template <class x>
x Node <x> ::getData() const
{
	return data;
}
//***************************************************
//Name: setData
//Purpose: set the data
//Incoming: x theData
//Outgoing: N/A
//Return: N/A
//***************************************************
template <class x>
void Node <x> ::setData(x theData)
{
	data = theData;
}
//***************************************************
//Name: setLink
//Purpose: set the link
//Incoming: Node <x> * theLink
//Outgoing: N/A
//Return: N/A
//***************************************************
template <class x>
void Node <x> ::setLink(Node <x> * theLink)
{
	link = theLink;
}
//***************************************************
//Name: queue
//Purpose: constructor
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
template <class x>
queue <x> ::queue()
{
	front = NULL;
	rear = NULL;
}
//***************************************************
//Name: dequeue
//Purpose: dequeues the first element
//Incoming: N/A
//Outgoing: N/A
//Return: value
//***************************************************
template <class x>
x queue <x> ::dequeue()
{
	 x value;
	 Node <x> * temp;
	 if (!isEmpty()) 
	 {
		 temp = front;
		 value = temp -> getData();
		 front = front -> getLink();
		 delete temp;
	 } else {
		 cout << "underflow!";
		 exit(EXIT_FAILURE);
	 }
	 return value;
}
//***************************************************
//Name: enqueue
//Purpose: enqueues items 
//Incoming: x data
//Outgoing: N/A
//Return: N/A
//***************************************************
template <class x>
void queue <x> ::enqueue(x data)
{
 Node <x> * temp = new Node <x> (data, NULL);
 temp = new Node <x> (data, NULL);
 // checks for queue overflow
 if (!isFull())
 {
	 if (isEmpty())
		front = temp;
	 else
		 rear -> setLink(temp);
		 rear = temp;
 } 
 else 
 {
	cout << "overflow!";
	exit(EXIT_FAILURE);
 }
}
//***************************************************
//Name: peek
//Purpose: returns first element
//Incoming: N/A
//Outgoing: N/A
//Return: front
//***************************************************
template <class x>
x queue <x> ::peek()
{
	 if (isEmpty())
	 {
		 cout << "underflow!";
		 exit(EXIT_FAILURE);
	 }
	 return front;
}
//***************************************************
//Name: isEmpty
//Purpose: check if the queue is empty or not
//Incoming: N/A
//Outgoing: N/A
//Return: front == NULL
//***************************************************
template <class x>
bool queue <x> ::isEmpty()
{
	return front == NULL;
}
//***************************************************
//Name: isFull
//Purpose: check if the queue is full or not
//Incoming: N/A
//Outgoing: N/A
//Return: false
//***************************************************
template <class x>
bool queue <x> ::isFull()
{
	return false;
}
//***************************************************
//Name: stack
//Purpose: constructor
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
template <class t>
stack <t> ::stack()
{
	top = NULL;
}
//***************************************************
//Name: push
//Purpose: pushes items into the stack
//Incoming: t x
//Outgoing: N/A
//Return: N/A
//***************************************************
template <class t>
void stack <t> ::push(t x)
{
	 if (!isFull())
	 {
		 Node <t> * temp = new Node <t> (x, top);
		 top = temp;
	 }
	 else
	 {
		 cout << "overflow!";
		 exit(EXIT_FAILURE);
	 }
}
//***************************************************
//Name: pop
//Purpose: pops items from the stack
//Incoming: N/A
//Outgoing: N/A
//Return: item
//***************************************************
template <class t>
t stack <t> ::pop()
{
	 t item;
	 Node < t> * temp = top;
	 if (isEmpty())
	 {
		 cout << "underflow!";
		 exit(EXIT_FAILURE);
	 }
	 else
	 {
		 item = temp -> getData();
		 top = temp -> getLink();
		 delete temp;
	 }
	 return item;
}
//***************************************************
//Name: isEmpty
//Purpose: check if stack is empty or not
//Incoming: N/A
//Outgoing: N/A
//Return: root==NULL
//***************************************************
template <class t>
bool stack <t> ::isEmpty()
{
	return top == NULL;
}
//***************************************************
//Name: isFull
//Purpose: check if stack is full or not
//Incoming: N/A
//Outgoing: N/A
//Return: false
//***************************************************
template <class t>
bool stack <t> ::isFull()
{
	return false;
}
//***************************************************
//Name: BinarySearchTree
//Purpose: constructor
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}
//***************************************************
//Name: empty
//Purpose: check if it is empty
//Incoming: N/A
//Outgoing: N/A
//Return: root==NULL
//***************************************************
bool BinarySearchTree::empty()
{
	return root == NULL;
}
//***************************************************
//Name: insert
//Purpose: inserts strings into binary search tree
//Incoming: string Data
//Outgoing: N/A
//Return: N/A
//***************************************************
void BinarySearchTree::insert(string Data)
{
	 NodePtr temp = new node;
	 temp -> right = NULL;
	 temp -> data = Data;
	 temp -> left = NULL;
	 if (!empty())
	 {
		 NodePtr curr, parent;
		 curr = root;
		 while (curr != NULL)
		 {
			 parent = curr;
			 if (temp -> data > curr -> data)
			 curr = curr -> right;
			 else
			 curr = curr -> left;
		 }
		 if (temp -> data < parent -> data)
			parent -> left = temp;
		 else
			parent -> right = temp;
	 }
	 else
		root = temp;
}
//***************************************************
//Name: depthFirst
//Purpose: uses depth first to display items
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void BinarySearchTree::depthFirst()
{
	 NodePtr p = root;
	 stack < NodePtr > stack;
	 while (p != 0)
	 {
		 while (p != 0)
		 {
			 if (p -> right)
			 stack.push(p -> right);
			 stack.push(p);
			 p = p -> left;
		 }
		 p = stack.pop();
		 while (!stack.isEmpty() && p -> right == 0)
		 {
			 cout << p -> data << " ";
			 p = stack.pop();
		 }
		 cout << p -> data << " ";
		 if (!stack.isEmpty())
			p = stack.pop();
		 else
			p = 0;
	 }
}
//***************************************************
//Name: breadthFirst
//Purpose: uses breadth first to display items
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void BinarySearchTree::breadthFirst()
{
	 NodePtr p = root;
	 queue <NodePtr> q;
	 if (p != 0)
	 {
		 q.enqueue(p);
		 while (!q.isEmpty())
	     {
			 p = q.dequeue();
			 cout << p -> data << " ";
			 if (p -> left != 0)
				q.enqueue(p -> left);
			 if (p -> right != 0)
				q.enqueue(p -> right);
		 }
	 }
}
//driver
int main()
{
	 BinarySearchTree bst;
	 bst.insert("mouse");
	 bst.insert("fish");
	 bst.insert("tiger");
	 bst.insert("dog");
	 bst.insert("gopher");
	 bst.insert("rat");
	 bst.insert("zebra");
	 bst.insert("squirrel");
	 bst.insert("cat");
	 
	 cout << "Breadth First: ";
	 bst.breadthFirst();
	 cout << endl << endl;
	 
	 cout << "Depth First: ";
	 bst.depthFirst();
	 cout << endl << endl;
	 
	 return 0;
}
