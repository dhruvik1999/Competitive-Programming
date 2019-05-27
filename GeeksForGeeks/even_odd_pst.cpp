#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};

struct Node* root = NULL;

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data = data;
	node->next = NULL;

	return node;
}

void addNode(int data){
	struct Node* node = newNode(data);
	if(root){
		node->next=root;
		root=node;
	//	cout << "data : " << root->data  << "  --  " << root->next->data << "\n";
	}else{
		root=node;
		//cout << "--" << node->data << "\n";
	}
}

void divide(struct Node* node){
	struct Node* parent = root;

	while(parent->next){
		if(parent->next->data % 2 ==0){
			addNode(parent->next->data);
		//	cout << "----  " << parent->next->data << "  ----\n";
			parent->next = parent->next->next;
		}else{
			parent=parent->next;
		}
	}

}

int main(){

	int n;
	cin >> n;



	int tempo;
	for(int i=0;i<n;i++){
		cin >> tempo;
		addNode(tempo);
	}

	struct Node* temp = root;

	while(temp){
		cout << (temp->data) << " ";
		temp=temp->next;
	}

	divide(root);

	cout << "\n-------------\n";
	temp = root;

	while(temp){
		cout << (temp->data) << " ";
		temp=temp->next;
	}	



	return 0;
}