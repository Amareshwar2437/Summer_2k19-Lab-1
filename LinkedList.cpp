#include<iostream>
using namespace std;

class Node{
	public:
	//Insert data
	int data;
	//Pointer to the next node
	Node * next;
	//Constructor that makes the pointer to NULL
	Node(){
		next = NULL;
	}
	
};

class LinkedList{
	public:
	//Declare head
	Node*head;
	Node*tail;
	//Use constructor to point them to NULL first
	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	
	//Insert a new node at beginning
	
	void insert(int value){
		//1st step :- Create a new node
		Node * temp = new Node();
		//Assign value to that node
		temp -> data = value;
		//Use of pointers now
		//First check if the linked list is empty or not
	
// If linked list is empty, then the new node inserted will be the only node annd hence all u need to do, is to point the head to that node.

// If linked list is not empty, then to insert the new node at the beginning, means the first step is new node creation, 2nd step is assigning a value to it, 3rd step is update the head.

		//Use of conditions
		
		if ( head == NULL){
				head = temp;
		}
		
		else {
				temp -> next = head;
				head = temp;
		}
}

//Deletion of the last element
	void delet(){
		//store the tail in temp
		Node * temp = tail;
		//the one before tail has to point to null
		Node * current = head;
		while(current->next != tail){
			current = current->next;
		}
		current->next = NULL;
		//update tail
		tail = current;
		//delete temp
		delete temp;
	}
int countItems()
	{
		int count = 0;
		//Start from head
		Node * current = head;
	
		//Use loops to move till the end now
		
		while (current != NULL)
		{
			count++;
			current = current -> next;
		}
		
		return count;
	}
void insertAt(int pos, int val)
	{
		//1. Reach the appropriate place, so start with the only data u have, i.e Head.

		Node * current = head;
		
		// Use loops now
		int i = 1;
		while ( i <pos-1)
		{
			i++;
			current = current -> next;
		}

		//2. Once you reach the proper position, then create a new node & give it a value.

		Node * temp = new Node;
		temp -> data = val;

		//3. Now make sure you link the nodes together properly

		temp -> next = current -> next;
		current -> next = temp;

		//4. InsertAt now awaits the value and position given by user	
	}

void deleteAt(int pos)
	{
		Node * current = head;
		int i=1;
		while ( i<pos-1)
		{
			i++;
			current = current -> next;		
		}
	//Store the tail in temp
		Node * temp = tail;
		current -> next = NULL;

		//Update tail
		tail = current;
		delete temp;	
	}
void display(){
		//FIND HEAD FIRST then start printing
		Node * current = head;
		//Use conditions now
		while (current != NULL){
		cout << current -> data << " -> ";
		current = current -> next;			
			}
		cout << "NULL" <<endl;
	}
};


int main(){

	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	cout << " The no of items in the linked list is :- " << l1.countItems() <<endl;
	l1.insertAt(2,5);
	l1.display();
	l1.delet();
	l1.display();
	l1.deleteAt(4);
	l1.display();
}
