#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;
	k--;

	vector<int> a(n);

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int x,y;
	cin >> x >> y;

	if(x<k){
		reverse(a.begin(),a.end());
	}



	return 0;
}