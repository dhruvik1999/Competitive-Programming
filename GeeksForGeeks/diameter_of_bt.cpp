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
}

void inOrd(struct Node* node){
	if(!node)
		return ;

	inOrd(node->left);
	cout  << node->data << " ";
	inOrd(node->right);
}

int findHeight(struct Node* node){
	if(!node)
		return 0;

	return max( findHeight(node->left) , findHeight(node->right) )  + 1;
}

int  diameter(struct Node* node){
	if(!node)
		return 0;

	int h1 = findHeight(node->left);
	int h2 = findHeight(node->right);

//	cout << node->data << " " << h1 << " " << h2 << "\n";

	int dl = diameter(node->left);
	int dr = diameter(node->right);

	return max(h1+h2+1 , max( dl , dr ));
}

int main(){

	Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);

	//	inOrd(root);

	cout  << diameter(root) << "\n";

	return 0;
}