#include<bits/stdc++.h>
using namespace std;

int tree[100][2];

void printlvl(int lvl,int n,int data){
	if(data==-1)
		return ;

	//cout << data << "\n";
	if(lvl==n-1 ){
		cout << data << "\n";
	}

	printlvl(lvl+1,n,tree[data][1]);
	printlvl(lvl+1,n,tree[data][0]);

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
	printlvl(0,lvl,root);


	return 0;
}