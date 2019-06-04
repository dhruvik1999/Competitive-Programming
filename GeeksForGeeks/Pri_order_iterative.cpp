#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;

	return node;
}

struct Node* root = NULL;

void PriOrderIterative(struct Node* node){
	stack<struct Node*> s;
	s.push(node);
	while(s.size()!=0){
		struct Node* temp = s.top();
		s.pop();
		cout << temp->data << " ";
		if(temp->right != NULL) {
			s.push(temp->right);
		}

		if(temp->left != NULL){
			s.push(temp->left);
		}
	}
}

int main(){

	root = newNode(15);
	root->right = newNode(20);
	root->right->right = newNode(25);
	root->right->left = newNode(16);
	root->left=newNode(10);
	root->left->left=newNode(8);
	root->left->right=newNode(12);

	PriOrderIterative(root);
	return 0;
}