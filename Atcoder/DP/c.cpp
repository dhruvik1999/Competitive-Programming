#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	vector< vector<int> > a( 3 , vector<int>(n,-1) );
	for(int i=0;i<n;i++){
		cin >> a[0][i] >> a[1][i] >> a[2][i];
	}

	vector< vector<int> > dp( 3 , vector<int>(n,-1) );
	dp[0][n-1] = a[0][n-1];
	dp[1][n-1] = a[1][n-1];
	dp[2][n-1] = a[2][n-1];

	for(int i=n-2;i>=0;i--){
		dp[0][i] = a[0][i] + max( dp[1][i+1] , dp[2][i+1] );
		dp[1][i] = a[1][i] + max( dp[0][i+1] , dp[2][i+1] );
		dp[2][i] = a[2][i] + max( dp[0][i+1] , dp[1][i+1] );
	}

	cout << max( max( dp[0][0] , dp[1][0] ) , dp[2][0] ) << "\n";


	return 0;
}