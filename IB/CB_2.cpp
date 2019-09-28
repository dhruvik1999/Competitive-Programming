#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007


vector< vector<long long > > dp(5 , vector<long long >(100001,-1));
long long  doWork(long long  l,long long  n,vector<long long > *g){
	if(dp[l][n]!=-1)
		return dp[l][n];

	long long  ans = 0;

	for(long long  i=0;i<g[l].size();i++){
		ans= ( ans%mod + doWork(g[l][i],n-1,g)%mod)%mod;
	}

	return (dp[l][n]=ans%mod);
}

int  main(){

	long long  n;
	cin >> n;

	vector<long long > g[5];

	g[0].push_back(1);
	g[0].push_back(2);

	g[1].push_back(2);

	g[2].push_back(0);
	g[2].push_back(1);
	g[2].push_back(3);
	g[2].push_back(4);

	g[3].push_back(0);
	g[3].push_back(4);

	g[4].push_back(3);
	g[4].push_back(1);

	for(long long  i=0;i<5;i++){
		dp[i][1]=1;
	}


	long long ans = 0;

	for(long long  i=0;i<5;i++){
		ans = ( ans%mod + doWork(i,n,g)%mod)%mod;
	}

	cout << ans << "\n";



	return 0;
}