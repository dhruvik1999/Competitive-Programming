#include<bits/stdc++.h>
using namespace std;


int findNumOfBst(int n){
	int a[n+5];
	memset(a,0,sizeof(a));
	a[0]=1;
	a[1]=1;
	a[2]=2;

	for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++){
			a[i] += a[j]*a[i-j-1];
		}
	}

	return a[n];

}


int main(){

	int n;
	cin >> n;

	cout << "Num of BST : " << findNumOfBst(n) << "\n";




	return 0;
}