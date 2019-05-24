#include<bits/stdc++.h>
using namespace std;

struct Node{
	struct Node* next;
	int data;
};

struct Node* head = NULL;

struct Node* addLast(int data){
	
	if(head == NULL){
		head = new Node;
		head->data = data;
		head->next = NULL;
	}else{
		Node* temp  = head;
	//	cout << "\n-------" << data << "--------\n";
		while(head->next != NULL){
		
			head = head->next;

		}
	//	cout << "\n---------------\n";

		Node* node = new Node;
		node->data = data;
		node->next = NULL;

		head->next = node;
		head = temp;
	}

	//cout << "head : " << head->data << "\n";
 
	return head;
}




int main(){

	int n;
	cin >> n;	

	struct Node* head = NULL;

	int temp;
	for(int i=0;i<n;i++){
		cin >> temp;

		head = addLast(temp);

	}
	int t=0;
	head->next->data=2;
	Node* lol = head;
	while(lol != NULL && t<n){
		cout << lol->data << "\n";
		lol = lol->next;
		t++;
	}




	return 0;
}

