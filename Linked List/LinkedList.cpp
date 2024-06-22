#include<iostream>
struct Node{
	int data;
	Node* link; 
}; 

Node* head = NULL;
void Insert(int index, int x);
void remove(int index);
void Reverse_nonrecursive();
void Print(Node* p);
using namespace std;


int main(){
	head = NULL;
	int number, i, x;
	cout<<"How many number in your linked list?";
	cin>>number;
	for (i=0;i<number;i++){
		cout<<"Input next number: ";
		cin>>x;
		Insert(1, x);
		Print(head);
	}
	int insert_num, insert_index;
	cout<<"Insert position";
	cin>>insert_index;
	cout<<"Insert x:";
	cin>>insert_num;
	Insert(insert_index, insert_num);
	Print(head);
	
	int remove_index;
	cout<<"remove position";
	cin>>remove_index;
	remove(remove_index);
	Print(head);
	cout<<"Do Reserve"<<endl;
	Reverse_nonrecursive();
	Print(head);
}


void Print(Node* p){
	//recursive print
	if (p==NULL) {
	cout<<endl;
	return;
	}
	Print(p->link);
	cout<<p->data<<" ";
	
//	Node* temp1 = head;
//	while(temp1->link != NULL){
//		cout<<(temp1->data)<<" ";
//		temp1 = temp1->link;
//	}
//	cout<<(temp1->data)<<" ";
//	cout<<endl;
}

void Insert(int index, int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;
	if (index == 1){
		if (head!=NULL) temp->link = head;
		head = temp;
	}else{
		Node* temp1 = head;
		for(int i=0; i<index-2;i++){
			temp1=temp1->link;
		}
		temp->link = temp1->link;
		temp1->link = temp;
	}
	
}

void remove(int index){
	if(index == 1){
		if(head->link==NULL) head=NULL;
		else{
			head = head->link;
		}
	}else{
		Node* temp1;
		temp1 = head;
		for (int i=0;i<index-2;i++){
			temp1 = temp1->link;	
		}
		Node* temp2 = temp1->link;
		temp1->link = temp2->link;
		delete temp2;
	}
}

void Reverse_nonrecursive(){
	Node *prev, *current, *next;
	prev = NULL;
	current = head;
	while(current != NULL){
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void Reverse_recursive(Node* temp){
	
	if(temp->link==NULL){
		head = temp;
		return;
	}
	Reverse_recursive(temp->link);
	Node* q = temp->link;
	q->link = temp;
	temp->link = NULL;
}

