#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* link;
};
Node* front = NULL;
Node* rear = NULL;
bool IsEmpty(){
	if (front == NULL && rear == NULL){
		return true;
	}else{
		return false;
	}
}
void Enqueue(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;
	if (IsEmpty()) {
	front = temp;
	}else {
		Node* temp1 = front;
		while (temp1->link != NULL){
			temp1 = temp1->link;
		}
		temp1->link = temp;
	}
	rear = temp;
}

void Dequeue(){
	Node* temp = front;
	if (IsEmpty()){
		return;
	}else if (front == rear){
		front = NULL;
		rear = NULL; 
	}else {
		front = front->link;
		delete temp; 
	}
	
}

void Print(Node* p){
	if (p == NULL){
		cout<<endl;
		return;
	}
	cout<<p->data<<" ";
	Print(p->link);
}

int main(){
	Enqueue(2);
	Enqueue(5);
	Enqueue(6);
	Dequeue();
	Dequeue();
	Dequeue();
	cout<<"List is: ";
	Print(front);
	
} 
