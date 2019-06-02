#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}


struct Node* root = NULL;


void inOrd(struct Node* node){
	if(!node)
		return;

	inOrd(node->left);
	cout << node->data << " ";
	inOrd(node->right);
}

int main(){

	root = newNode(15);
	root->right = newNode(20);
	root->right->right = newNode(25);
	root->right->left = newNode(16);
	root->left=newNode(10);
	root->left->left=newNode(8);
	root->left->right=newNode(12);



	return 0;
}