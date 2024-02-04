#pragma warning (disable: 4996)
#include<iostream>
#include <sstream>
#include<cassert>
using namespace std;


struct Node {
	struct Node* next;
	struct Node* prev;
	int data;
};

class Deque {
private:
	struct List {
		Node* head;
		Node* tail;
		int count;
	};
	List* list;

public:
	Deque() {
		list = DequeInit();
	}

	List* DequeInit() {
		List *newList = new List;
		newList->count = 0;
		newList->head = nullptr;
		newList->tail = nullptr;
		return newList;
	}
	
	bool DQIsEmpty() {
		if (this->list->head == nullptr) {
			return true;
		}
		else
			return false;
	}

	void DQAddFirst(int data) {
		Node* NewNode = new Node;
		NewNode->data = data;
		if (this->list->head == nullptr) {
			this->list->head = NewNode;
			this->list->tail = NewNode;
			this->list->head->next = nullptr;
			this->list->head->prev = nullptr;
		}
		else {
			NewNode->next = this->list->head;
			this->list->head->prev = NewNode;
			this->list->head = NewNode;
			this->list->head->prev = nullptr;
		}
		(this->list->count++);

	}
	void DQAddLast(int data) {
		Node* NewNode = new Node;
		NewNode->data = data;
		if (this->list->head == nullptr) {
			this->list->head = NewNode;
			this->list->tail = NewNode;
			this->list->head->next = nullptr;
			this->list->head->prev = nullptr;
		}
		else {
			this->list->tail->next = NewNode;
			NewNode->prev = this->list->tail;
			this->list->tail = NewNode;
			this->list->tail->next = nullptr;
		}
		(this->list->count++);
	}
	int DQRemoveFirst() {
		assert(this->DQIsEmpty() == false);
		Node* delNode = this->list->head;
		int delData = delNode->data;
		if (this->list->head == this->list->tail) {
			this->list->head = nullptr;
		}
		else {
			this->list->head = this->list->head->next;
		}
		delete delNode;
		(this->list->count--);
		return delData;
	}

	int DQRemoveLast() {
		assert(this->DQIsEmpty() == false);
		Node* delNode = this->list->tail;
		int delData = delNode->data;
		if (this->list->head == this->list->tail) {
			this->list->tail = nullptr;
		}
		else {
			this->list->tail = this->list->tail->prev;

		}
		delete delNode;
		(this->list->count--);
		return delData;
	}
	int DQGetFirst() {
		assert(this->DQIsEmpty() == false);
		return this->list->head->data;
	}
	int DQGetLast() {
		assert(this->DQIsEmpty() == false);
		return this->list->tail->data;
	}
	int DQGetCount() {
		return this->list->count;
	}
	//~Deque() {
	//	delete this->list->head;
	//	delete this->list->tail;
	//	delete this->list;
	//}


};

void Answer(string a, int b, Deque* list) {
	if (a == "push_back") {
		list->DQAddLast(b);
	}
	else if (a == "push_front") {
		list->DQAddFirst(b);
	}
	else if (a == "front") {
		if (list->DQIsEmpty()) {
			cout << -1 << endl;
		}
		else {
			cout << list->DQGetFirst()<<endl;
		}

	}
	else if (a == "back") {
		if (list->DQIsEmpty()) {
			cout << -1 << endl;
		}
		else {
			cout << list->DQGetLast() << endl;
		}
	}
	else if (a == "size") {
		cout << list->DQGetCount();
	}
	else if (a == "empty") {
		if (list->DQIsEmpty()) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	else if (a == "pop_back") {
		if (list->DQIsEmpty()) {
			cout << -1 << endl;
		}
		else {
			cout << list->DQRemoveLast() << endl;
		}
	}
	else if (a == "pop_front") {
		if (list->DQIsEmpty()) {
			cout << -1 << endl;
		}
		else {
			cout << list->DQRemoveFirst() << endl;
		}
	}



}

int main() {
	Deque list;
	int N, i;
	char order[100];
	char* Order;
	string a;
	int b;
	cin >> N;
	getchar();
	for (i = 0; i < N; i++) {
		cin.getline(order, 100);
		istringstream ss1(order);
		ss1 >> a >> b;
		Answer(a, b, &list);
		
	}

	

	

	return 0;
}