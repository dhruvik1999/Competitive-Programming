#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* root = NULL;
vector<int> sir;

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
}

void preOrd(struct Node* node){
	if(!node){
	//	cout << "-1 " ;
		sir.push_back(-1);
		return ;
	}

	//cout << node->data << " ";
	sir.push_back(node->data);
	preOrd(node->left);
	preOrd(node->right);
}
int i = 0;
struct Node* deserial(vector<int> &sir,int n){

	if(sir[i]==-1 && i<n)
		return NULL;

	struct Node* temp = newNode(sir[i]);

	i++;
	temp->left = deserial(sir,n);
	i++;
	temp->right = deserial(sir,n);

	return temp;
}

void preOrdNew(struct Node* node){
	cout << "*" << "\n";
	if(!node){
		cout << "-1 " ;
		return ;
	}

	cout << node->data << " ";
	//sir.push_back(node->data);
	preOrdNew(node->left);
	preOrdNew(node->right);
}



int main(){

	root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->left->right->left = newNode(5);
	root->left->right->right = newNode(6);


	preOrd(root);
	

	for(int i=0;i<sir.size();i++){
		cout << sir[i] << " ";
	}
	cout << "\n";

	root = NULL;

	root = deserial(sir,sir.size());

	preOrdNew(root);



	return 0;
}