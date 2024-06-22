#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* link;
}; 

Node* top;

void push(int x);
void Print(Node*);
void pop();
int Top();
bool IsEmpty();
int main(){
	top = NULL;
	push(5);
	push(7);
	push(8);
	pop();
	cout<<Top()<<endl;
	cout<<IsEmpty()<<endl;
	cout<<"Stack is:";
	Print(top);
} 

void push(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL; 
	if (top != NULL)temp->link = top;
	top = temp;
}

void Print(Node* top){
	if(top == NULL){
		cout<<endl;
		return;
	}else{
		cout<<top->data<<" ";
		Print(top->link);
	}
}

void pop(){
	Node* temp = top;
	top = top->link;
	delete temp;
}

int Top(){
	return top->data;
}

bool IsEmpty(){
	return (top==NULL) ?true:false;
}
