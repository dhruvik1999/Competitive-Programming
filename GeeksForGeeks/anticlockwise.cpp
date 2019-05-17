#include<bits/stdc++.h>
using namespace std;

int tree[100][2];

int getHeight(int node){
	if(node == -1)
		return 0;

	return max(getHeight(tree[node][0]),getHeight(tree[node][1]))+1;
}

void printlvlltor(int lvl,int n,int data){
	if(data==-1)
		return;

	//cout << data << "\n";
	if(lvl==n-1 ){
		cout << data << "\n";
	}

	printlvlltor(lvl+1,n,tree[data][0]);
	printlvlltor(lvl+1,n,tree[data][1]);

}

void printlvlrtol(int lvl,int n,int data){
	if(data==-1)
		return ;

	//cout << data << "\n";
	if(lvl==n-1 ){
		cout << data << "\n";
	}

	printlvlrtol(lvl+1,n,tree[data][1]);
	printlvlrtol(lvl+1,n,tree[data][0]);

}

int main(){

	for(int i=0;i<100;i++){
		tree[i][0]=-1;
		tree[i][1]=-1;
	}

	int n;
	cin >> n;
	char ch;
	int p,q;
	for(int  i=0;i<n-1;i++){
		cin >> ch >> p >> q;
		if(ch=='L'){
			tree[p][0]=q;
		}else{
			tree[p][1]=q;
		}
	}

	int root;
	cin >> root;

	int lvl;
	cin >> lvl;

//	cout << lvl << " " << root << "\n";
	//printlvlltor(0,lvl,root);

	//cout << "\n" << getHeight(root) << "\n";

	int height = getHeight(root);

	int t=1;

	while(t<=height/2){
		printlvlrtol(0,t,root);
		printlvlltor(0,height-t+1,root);
		t++;
	}

	cout << "\n" << height << "\n\n";

	if(height%2==1){
		printlvlltor(0,height/2+1,root);
	}


	return 0;
}