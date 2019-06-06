#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data = data;
	node->next = NULL;

	return node;
}

struct Node* top = NULL;

void spush(int data){
	struct Node* node = newNode(data);
	node->next=top;
	top=node;
}

int spop(){
	if( top != NULL )
		top = top->next;
}

int stop(){
	if( top != NULL )
		return top->data;

}

int main(){
	int n;
	cin >> n;

	int temp;

	for(int i=0;i<n;i++){
		cin >> temp;

		spush(temp);
	}

	while( top != NULL ){
		cout << stop() << "\n";
		spop();
	}




	return 0;
}