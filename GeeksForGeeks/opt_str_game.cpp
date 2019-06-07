#include<bits/stdc++.h>
using namespace std;

int findAns(int *a,int l,int r){
	if(l==r)
		return a[l];
	if(l>r)
		return 0;


	return max(  a[l] + min( findAns(a,l+2,r) , findAns(a,l+1,r-1) ) , a[r] + min( findAns(a,l,r-2) , findAns(a,l+1,r-1) ) );
}


int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	cout << findAns(a,0,n-1) << "\n";



	return 0;
}