#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector< vector<int> > dp( 500 , vector<int> (500 , -1) );

int doWork( ll k, ll sum ){
	if(sum<0)
		return 0;
	if(k==0){

		if(sum==0)
			return (dp[k][sum]=1);
		if(sum>0)
		return (dp[k][sum]=0);
	}

	if(dp[k][sum]!=-1)
		return dp[k][sum];

	int ans = 0;

	for(int i=0;i<=9;i++){
		ans += doWork(k-1,sum-i);
	}

	return ( dp[k][sum] = ans );

}


int main(){

	int k,sum;
	cin >> k >> sum;
	cout << "ANS :: " << doWork(k,sum) << "\n";








	return 0;
}