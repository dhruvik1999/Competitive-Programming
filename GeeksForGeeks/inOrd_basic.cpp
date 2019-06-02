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

void inOrdWithoutRicu(struct Node* node){
	stack< struct Node* > s1,s2;
	bool lock1 = true,lock2=true;
	struct Node* node2 = node;
	int val1=-1,val2=0;

	int trg;
	cin >> trg;

	while(true){


	if(lock1){
		while(node!=NULL){
			s1.push(node);
			node = node->left;
		}

			if(s1.size()==0)
				lock1=false;
			else{
			node = s1.top();
			s1.pop();
			val1 = node->data;
			node= node->right;
			lock1=false;
			cout << val1 << " ";
		
		}
	}

	if(lock2){
		while(node2!=NULL){
			s2.push(node2);
			node2=node2->right;
		}

			if(s2.size()==0)
				lock2=false;
			else{
			node2 = s2.top();
			s2.pop();
			val2 = node2->data;
			node2 = node2->left;
			lock2=false;
			cout << val2 << "\n";
			}
	}

	cout  << "--"<< val1 << " " << val2 << "\n";


	if(trg == val2 + val1){
		cout << "Found" << "\n";
		return ;
	}else if(trg < val1 + val2){
		lock2 = true;
	}else{	
		lock1 = true;
	}



	if( val1 >= val2 ){
		cout<< "NOT FOUND" << "\n";
		break;
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

	inOrd(root);
	cout << "\n";

	inOrdWithoutRicu(root);
	cout << "\n";



	return 0;
}