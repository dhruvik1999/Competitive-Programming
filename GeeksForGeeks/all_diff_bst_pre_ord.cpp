#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data=data;
	node->left=NULL;
	node->right=NULL;

	return node;
}

void preOrder(struct Node *node){
	if(node == NULL)
		return;

	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}


vector<struct Node*> getAllBST(int l,int r){

	vector<struct Node*> ans;

	if(l>r){
		ans.push_back(NULL);
		return ans;
	}

	for(int i=l;i<=r;i++){
		vector<struct Node*> leftList = getAllBST(l,i-1);
		vector<struct Node*> rightList = getAllBST(i+1,r);

		for(int m=0;m<leftList.size();m++){
			struct Node *leftNode = leftList[m];
			for(int n=0;n<rightList.size();n++){
				struct Node *rightNode  = rightList[n];

				struct Node *node = newNode(i);
				node->right = rightNode;
				node->left = leftNode;
				ans.push_back(node);
			}
		}

	}
	return ans;
}

int main(){	
	int n;
	cin >> n;

	vector<struct Node*> list = getAllBST(1,n);

	for(int i=0;i<list.size();i++){
		preOrder(list[i]);
		cout << "\n";
	}

	return 0;
}