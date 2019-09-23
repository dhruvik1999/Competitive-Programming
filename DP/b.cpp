#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector<int> dp(n,INT_MAX);
	dp[n-1]=0;


	for(int i=n-2;i>=0;i--){
		for(int j=i+1;j<=i+k && j<n;j++){
			dp[i] = min(dp[i] , abs(a[i]-a[j])+dp[j]);
		}
	}

	cout << dp[0] << "\n";


	return 0;
}