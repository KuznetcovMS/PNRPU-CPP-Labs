#include "Stack.h"
Stack::Stack() {
	top = nullptr;
	size = 0;
}
Stack::~Stack() {
	Node* temp = top;
	while (temp != nullptr) {
		Pop();
	}
}
double Stack::Top() {
	return top->data;
}
void Stack::Push(double value) {
	Node* temp = new Node;
	temp->data = value;
	temp->prev = top;
	top = temp;
	size++;
}
void Stack::Pop() {
	Node* temp = top;
	top = top->prev;
	delete temp;
	size--;
}
int Stack::Size() {
	return size;
}
void Stack::Show(){
	cout << "\nСтек:\n";
	Node* temp = top;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}
