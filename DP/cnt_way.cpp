#include<bits/stdc++.h>
using namespace std;
int doWork(int i,vector<int> &dp){
	if(i<0)
		return 0;

	if(dp[i]!=-1)
		return dp[i];

	return (dp[i] = doWork(i-1,dp) + doWork(i-3,dp) + doWork(i-4,dp));
}


int main(){

	int n;
	cin >> n;

	vector<int> dp(n+10,-1);

	dp[0]=1;

	doWork(n,dp);

	cout  << "ANS : " << dp[n] << "\n";



	return 0;
}