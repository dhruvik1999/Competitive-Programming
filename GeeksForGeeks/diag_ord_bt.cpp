#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	int lvl,dir;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	node->lvl=0;
	node->dir=0;

	return node;
}
struct Node* root = NULL;

void inOrd(struct Node* node,struct Node* parent){
	if(!node)
		return ;

	if(parent!=NULL){
		node->lvl = parent->lvl+1;
		if(node == parent->left){
			node->dir = parent->dir - 1;
		}else{
			node->dir = parent->dir + 1;
		}
	}

	inOrd(node->left,node);
	//cout << node->data << " " << node->lvl << " " << node->dir <<  "\n";
	inOrd(node->right,node);
}

int main(){

	root = NULL;

	root = newNode(1);
	root->right = newNode(2);
	root->right->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right->left = newNode(5);
	root->right->right->left->left = newNode(6);
	root->left = newNode(7);
	root->left->right = newNode(8);
	root->left->left = newNode(9);
	root->left->left->right = newNode(10);

	inOrd(root,NULL);
	

	vector<int> v[100];
	queue< struct Node* > s;
	s.push(root);
	struct Node* temp;

	while(s.size()!=0){
		temp = s.front();
		s.pop();

		v[ (temp->lvl - temp->dir)/2 ].push_back(temp->data);

		if(temp->left!=NULL)
			s.push(temp->left);
		if(temp->right!=NULL)
			s.push(temp->right);
	}

	int i=0;

	while(v[i].size()!=0){
		for(int j=0;j<v[i].size();j++){
			cout  << v[i][j] << " ";
		}
		i++;
		cout << "\n";
	}



	return 0;
}