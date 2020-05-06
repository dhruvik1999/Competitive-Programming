#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector<int> dp(n+10,INT_MAX);
	dp[0]=INT_MIN;

	int ind;
	vector<int> L(n+1,0);
	for(int i=0;i<n;i++){
		ind = lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
		L[i]=ind;
		dp[ind]=a[i];
	}

	// for(auto aa : L){
	// 	cout << aa << " ";
	// }
	// cout << "\n";
	int l=0,s; 
	for(int i=n-1;i>=0;i--){
		
		
		if(l<L[i]){
			l=L[i];
			s=a[i];
		}
	}
	s=INT_MAX;
	for(int i=n-1;i>=0;i--){
		if(L[i]==l && a[i]<s){
			cout << a[i] << "\n";
			s=a[i];
			l--;
		}
	}

	return 0;
}