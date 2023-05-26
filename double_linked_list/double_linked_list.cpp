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

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "n\list is empty" << endl;
	}

	else {
		cout << "\nRecords is descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << "deleted" << endl;
}

void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nlist is empty" << endl;
	}
	Node* previous, * curr;
	previous = curr = NULL;
	cout << "\nEnter the roll number of the sutedent whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &previous, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;

	}

}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchData();
				break;
			case '6':
				return 0;

			default:
				cout << "\nInvalid option" << endl;
				break;

			}
		}
		catch (exception& e) {
			cout << "check for the values entered." << endl;

		}
	}

}