#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;

	struct Node *left,*right;
};

struct Node* newNode(int val){
	struct Node* node = new Node;
	node->val=val;
	node->right=NULL;
	node->left=NULL;
	return node;
}

void addNode(struct Node* Pnode,int a){
	struct Node* node = Pnode;

	for(int i=31;i>=0;i--){
		if((a>>i)&1){
			if(node->right!=NULL){
				node=node->right;
			}else{
				node->right=newNode(a);
				node=node->right;
			}
		}else{
			if(node->left!=NULL){
				node=node->left;
			}else{
				node->left=newNode(a);
				node=node->left;
			}
		}
	}

}

void inorder(struct Node* node){
	if(node==NULL)
		return;
	inorder(node->left);
	if(node->left==NULL && node->right==NULL)
		cout << node->val << "\n";
	inorder(node->right);
}

int checkXor(struct Node* pnode,int a){
	struct Node* node = pnode;

	for(int i=31;i>=0;i--){

		if( (a>>i)&1 ){
			if(node->left!=NULL){
				node=node->left;
			}else{
				node=node->right;
			}
		}else{
			if(node->right!=NULL){
				node=node->right;
			}else{
				node=node->left;
			}
		}

	}

	return node->val;
}

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	struct Node* head = newNode(0);

	for(int i=0;i<n;i++){
		addNode(head,a[i]);
	}

	//inorder(head);

	for(int i=0;i<n;i++){
		int t = checkXor(head,a[i]);
		cout << a[i] << " : "<< t << " " << (a[i]^t) << "\n";  
	}



	return 0;
}