#include<bits/stdc++.h>
using namespace std;

 struct Node{
	struct Node *left,*right;
	int data ;
};

//Node root = NULL;

struct Node* newTreeNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}




int main(){

	Node *node = newTreeNode(100);
	cout << node->data << "\n";


	Node *root = node;
	Node *l = newTreeNode(20);
	root->right = l;

	cout  << root->right->data << "\n";




	return 0;
}
