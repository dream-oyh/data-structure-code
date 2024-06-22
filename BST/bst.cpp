#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data){
	Node* root = new Node();
	root->data = data;
	root->left = root->right = NULL;
	return root; 
}

void Insert(Node** rootPtr, int data){
	if(*rootPtr == NULL){
		*rootPtr = getNewNode(data);
	}else if (data<=(*rootPtr)->data){
		Insert(&((*rootPtr)->left), data);
	}else{
		Insert(&((*rootPtr)->right), data);
	}
}


bool Search(Node* root, int data){
	if (root == NULL){
		return false;
	}else if (root->data == data){
		return true;
	}else if (root->data > data){
		return Search(root->left, data);
	}else{
		return Search(root->right, data);
	}
}
int findMin(Node* root){
	if (root->left == NULL) return root->data;
	else findMin(root->left);
} 

int findMax(Node* root){
	if (root->right == NULL) return root->data;
	else findMax(root->right);
} 

int findHeight(Node* root){
	if (root == NULL) return -1;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void LevelOrder(Node* root){
	if (root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()){
		Node* current = Q.front();
		cout<<current->data<<endl;
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}


void LDROrder(Node* root){
	if (root==NULL) return;
	LDROrder(root->left);
	cout<<root->data<<" ";
	LDROrder(root->right);
}

void DLROrder(Node* root){
	if (root==NULL) return;
	cout<<root->data<<" ";
	LDROrder(root->left);
	LDROrder(root->right);
}

void LRDOrder(Node* root){
	if (root==NULL) return;
	LDROrder(root->left);
	LDROrder(root->right);
	cout<<root->data<<" ";
}

bool IsSubtreeLesser(Node* root, int value){
	if (root == NULL) return true;
	if (root->data <= value
		&& IsSubtreeLesser(root->left, value)
		&& IsSubtreeLesser(root->right, value)
	) return true;
	else return false;
}

bool IsSubtreeGreater(Node* root, int value){
	if (root == NULL) return true;
	if (root->data > value
		&& IsSubtreeGreater(root->left, value)
		&& IsSubtreeGreater(root->right, value)
	) return true;
	else return false;
}

bool IsBinarySearchTree(Node* root){
	if (root == NULL) return true;
	if(
		IsSubtreeLesser(root->left, root->data)
		&& IsSubtreeGreater(root->right, root->data)
		&& IsBinarySearchTree(root->left)
		&& IsBinarySearchTree(root->right) 
	) return true;
	else return false;
} 

Node* Delete(Node* root, int data){
	if (root==NULL) return root;
	else if (data <= root->data) root->left = Delete(root->left, data);
	else if (data >= root->data) root->right = Delete(root->right, data);
	else {
		if (root->left ==NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if (root->left == NULL){
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL){
			Node* temp = root;
			root = root->left;
			delete temp;
		} 
		else{
			int temp = findMin(root->right);
			root->data = temp;
			root->right = Delete(root->right, temp);
		}
		return root;
	}
	
	
}
int main(){
	Node* root;
	root = NULL;
	Insert(&root, 25);
	Insert(&root, 20);
	Insert(&root, 10);
	Insert(&root, 15);
	Insert(&root, 40);
	Insert(&root, 45);
	Insert(&root, 50);
	Insert(&root, 60);
	Insert(&root, 50);
	cout<<Search(root, 20);
	cout<<findMin(root);
	cout<<findMax(root);
	cout<<findHeight(root)<<endl;
	LDROrder(root);
	cout<<endl<<IsBinarySearchTree(root);

	
} 
