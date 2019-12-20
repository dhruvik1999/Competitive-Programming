// GFG
#include<bits/stdc++.h>
using namespace std;
//Atcoder

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* parent;
	int rank,size;
};

struct Node* newNode(int data, int rank){
	struct Node* node = new Node;
	node->data=data;
	node->parent=node;
	node->rank=rank;
	node->size=1;
}

vector< struct Node* > graph(100005);

void makeSet(int n){
	for(int i=1;i<=n;i++){
		graph[i] = newNode(i,0);
	}
}

struct Node* findParent(struct Node* node){
	if( node->data != node->parent->data ){
		node->parent = findParent(node->parent);
		return node->parent;
	}
	return node;	
}

void unioun(struct Node* node1, struct Node* node2){
	struct Node *par1 = findParent(node1), *par2 = findParent(node2);
	if( par1->data != par2->data ){

		if(par1->rank > par2->rank){
			par2->parent = par1;
			par1->size+=par2->size;
		}else if( par1->rank < par2->rank ){
			par1->parent = par2;
			par2->size+=par1->size;
		}else{
			par2->parent = par1;
			par1->size+=par2->size;
			par1->rank += 1;
		}

	}
}

int main(){

	int n;
	cin >> n;

	makeSet(n);

	int p,q;
	while(true){
		cin >> p >> q;
		cout << "------------------------\n";
		unioun( graph[p],graph[q] );

		for(int i=1;i<=n;i++){
			cout << i << " : " << findParent(graph[i])->data << " : " << graph[i]->rank << " : " << findParent(graph[i])->size <<   "\n";
		}
		cout << "------------------------\n";


	}


	return 0;
}