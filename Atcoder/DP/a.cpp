#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector<int> dp(n,INT_MAX);
	dp[n-1]=0;


	for(int i=n-2;i>=0;i--){
		if(i+1<n){
			dp[i] = min(dp[i] , abs(a[i]-a[i+1])+dp[i+1]);
		}
		if(i+2<n){
			dp[i] = min(dp[i] , abs(a[i]-a[i+2])+dp[i+2]);
		}
	}

	cout << dp[0] << "\n";


	return 0;
}