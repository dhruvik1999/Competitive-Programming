#include<bits/stdc++.h>
using namespace std;

int  main(){

	long long  n,m;
	cin >> n >> m;

	vector< long long  > dp( n+2  , 0 );

	long long  t;
	for(long long  i=0;i<m;i++){
		cin >> t;
		dp[t]=-1;
	}
	dp[n]+=1;
	for(long long  i=n-1;i>=0;i--){
		if(dp[i]!=-1){
			if( dp[i+1]!=-1 ){
				dp[i] += dp[i+1];
			}
			if(dp[i+2]!=-1){
				dp[i] += dp[i+2];
			}
			dp[i]=dp[i]%1000000007;
		}
	}

	cout << dp[0] << "\n";


	return 0;
}