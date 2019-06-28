#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data=data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void inOrder(struct Node* node){
	if(node == NULL)
		return;

	inOrder(node->left);
	cout << node->data << "\n";
	inOrder(node->right);
}
int l=1,r=0;
void topView(struct Node* node,int dir){

	if(node == NULL)
		return;

	if(dir < l){
		l=dir;
		cout << node->data << " ";
	}else if(dir > r){
		r=dir;
		cout << node->data << " ";
	}
	topView(node->left,dir-1);
	topView(node->right,dir+1);

}


int main(){

	struct Node* root = newNode(4);
	root->left = newNode(10);
	root->left->left = newNode(20);
	root->left->right = newNode(30);
	root->left->right->left = newNode(40);
	root->left->right->left->left = newNode(50);
	root->left->right->left->left->left = newNode(-50);

	root->right = newNode(100);
	root->right->left = newNode(870);

	topView(root,0);
	cout << "\n";









	return 0;
}