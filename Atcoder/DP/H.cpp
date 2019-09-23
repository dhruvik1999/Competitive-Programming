#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long  doWork(vector< vector<long long > > &dp,long long  x,long long  y){

	if(x>=dp.size() || y>=dp[0].size()){
		return 0;
	}

	if(dp[x][y]==-1)
		return 0;

	if(dp[x][y]!=-1 && dp[x][y]!=0){
		return dp[x][y];
	}

	return (dp[x][y] = (doWork(dp,x+1,y)%mod + doWork(dp,x,y+1)%mod)%mod);
}

int  main(){

	long long  n,m;
	cin >> n >> m;

	char temp;

	vector< vector<long long > > dp( n, vector<long long >(m,0) );
	dp[n-1][m-1]=1;

	for(long long  i=0;i<n;i++){
		for(long long  j=0;j<m;j++){
			cin >> temp;
			if(temp=='#'){
				dp[i][j]=-1;
			}

		}
	}

	//doWork(dp,0,0);

	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(dp[i][j]==-1)
				continue;
			if(i+1<n && dp[i+1][j]!=-1){
				dp[i][j] = (dp[i][j]%mod + dp[i+1][j]%mod)%mod;
			}
			if(j+1<m && dp[i][j+1]!=-1){
				dp[i][j] = (dp[i][j]%mod + dp[i][j+1]%mod)%mod;
			}
		}
	}

	cout << dp[0][0] << "\n";

	return 0;
}