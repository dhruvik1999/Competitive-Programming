#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data=data;
	node->next=NULL;

	return node;
}

struct Node* mergeLL(struct Node* node1,struct Node* node2){
	if(node1==NULL)
		return node2;
	if(node2==NULL)
		return node1;

	struct Node* result = NULL;

	if(node1->data < node2->data){
		result = node1;
		result->next = mergeLL(node1->next,node2);
	}else{
		result = node2;
		result->next = mergeLL(node1,node2->next);
	}

	return result;
}

int main(){

	struct Node* head1 = newNode(1);
	head1->next = newNode(4);
	head1->next->next = newNode(7);
	head1->next->next->next = newNode(10);

	struct Node* head2 = newNode(2);
	head2->next = newNode(5);
	head2->next->next = newNode(15);
	

	struct Node* head = mergeLL(head1,head2);

	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";



	return 0;
}