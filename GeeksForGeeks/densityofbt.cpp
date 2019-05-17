#include<bits/stdc++.h>
using namespace std;

int tree[100][2];

int height,size=0;

int getParam(int node){
	if(node==-1)
		return 0;

	size++;

	return max(getParam(tree[node][0]), getParam(tree[node][1])) + 1;
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
	height = getParam(root);
//	cout << height << " " << size << "\n";
	cout << "height : " << height << "\n";
	cout << "size : " << size << "\n";
	cout << "Density : " << ((float)size / height) << "\n";

	return 0;
}