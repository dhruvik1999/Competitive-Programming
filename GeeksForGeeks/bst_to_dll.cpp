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
struct Node* head = NULL;
struct Node* temp = NULL;
struct Node* tail = NULL;

void inOrd(struct Node* node){
	if(!node)
		return;


	inOrd(node->left);
	if(head==NULL){
		head=node;
		temp=node;
	}else{
		temp->right = node;
		temp=temp->right;
	}
	inOrd(node->right);
}

void trans_sing_to_dub(struct Node* node){
	if(node == NULL)
		return;
	trans_sing_to_dub(node->right);

	//cout << node->data  << " ";
	if(tail==NULL){
		tail = node;
		temp = tail;
	}else{
		temp->left = node;
		temp = temp->left;
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

	inOrd(root);
	trans_sing_to_dub(head);

	temp = tail;

	int trg;

	cin >> trg;

	while(head!=NULL && tail!=NULL){
		cout << head->data << " " << tail->data << "\n";
		if(trg == head->data + tail->data){
			cout << "Found" << "\n";
			break;
		}else if( trg > head->data + tail->data){
			head=head->right;
		}else if(trg <  head->data + tail->data){
			tail=tail->left;
		}else{
			cout << "NOT FOUND\n";
		}
	}


	return 0;
}