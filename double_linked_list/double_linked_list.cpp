#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
}; 

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of student: ";
	cin >> nm;
	Node* newNode = new Node();	//step1
	newNode->noMhs = nim;	//step2
	newNode->name = nm;	//step2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim << START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;	//step3
		if (START != newNode)	
			START->prev = newNode;	//step4
		newNode->prev = NULL;	//step5
		START = newNode;	//step6
		return;
	}

	/*Inserting a Node Between Two Nodes in the list*/
	Node* current = START;	//step 1.a
	Node* previous = NULL;	//step 1.b
	while (current->next != NULL && current->next->noMhs) 
	{
		previous = current;	//1.d
		current = current->next;	//1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;	//step4
	newNode->prev = current;	//step5
	if (current->next != NULL)
		current->next->prev = newNode;	//step6
	current->next = newNode;	//step7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; //step1.a;
	*current = START; //1.b
	while (*current != NULL && (*current)->noMhs != rollNo) {		//step 1.c
		*previous = *current;
		*current = (*current)->next;
	}
	return;
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;

}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecord in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}