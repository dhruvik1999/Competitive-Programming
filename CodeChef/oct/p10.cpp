#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int t = 0;
	vector<int> ans(n+10);

	while( a[t] == (t+1) ){
		ans[t]=a[t];
		t++;

	}

	int bicchu = t+1;


	for(int i=0;i<n;i++){
		if(i==t){
			cout << bicchu << " ";
		}
		if(a[i]!=bicchu)
			cout << a[i] << " ";	
	}
	cout << "\n";




	return 0;
}