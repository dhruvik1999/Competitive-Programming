//Atcoder

#include<bits/stdc++.h>
using namespace std;

struct Node{
	long long int data;
	struct Node* parent;
	long long int rank,size;
};

struct Node* newNode(long long int data, long long int rank){
	struct Node* node = new Node;
	node->data=data;
	node->parent=node;
	node->rank=rank;
	node->size=1;
}

vector< struct Node* > graph(100005);

void makeSet(long long int n){
	for(long long int i=1;i<=n;i++){
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

long long int findSize(struct Node* node){
	return findParent(node)->size;
}

int main(){

	long long int n,m;
	cin >> n >> m;

	makeSet(n);

	long long int p,q;
	deque<long long int> ans;
	long long int sum = (n*(n-1))/2;
	ans.push_front((n*(n-1))/2);
	vector< pair<long long int,long long int> > aa;
	for(long long int i=0;i<m;i++){
		cin >> p >> q;
		aa.push_back( {p,q} );
	}

	for(long long int i=m-1;i>=0;i--){
		p=aa[i].first;
		q=aa[i].second;

		if( findParent(graph[p])->data!=findParent(graph[q])->data ){
			long long int t1 = findSize(graph[p]), t2 = findSize(graph[q]);
			unioun(graph[p],graph[q]);
			sum-=t1*t2;
		}
		ans.push_front(sum);
	}

	for(long long int i=1;i<=m;i++){
		cout << ans[i] << "\n";
	}



	return 0;
}