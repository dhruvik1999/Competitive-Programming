#include<bits/stdc++.h>
using namespace std;

int a[100][2];

bool checkBST(int node,int l,int r){

	if(node == -1)
		return true;

	if(l <= node && node <=r){
		return checkBST(a[node][0],l,node) && checkBST(a[node][1],node,r);
	}

	return false;
}



int main(){

	for(int i=0;i<100;i++){
		a[i][0]=-1;
		a[i][1]=-1;
	}

	int n;
	cin >> n;


	char ch;
	int p,q;

	for(int i=0;i<n-1;i++){
		cin >> ch >> p >> q;

		if(ch == 'L'){
			a[p][0]=q;
		}else{
			a[p][1]=q;
		}
	}

	int root;
	cin >> root;

	if(checkBST(root,INT_MIN,INT_MAX)){
		cout << "this is bst" << "\n";
	}else{
		cout << "This is not bst" << "\n";
	}

	return 0;
}