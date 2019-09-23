#include<bits/stdc++.h>
using namespace std;

//vector< vector<long long> > dp(101 , vector<long long>(100001,-1));

map< pair<int,int> , long long > dp;

long long  doWork(vector<long long > &a,vector<long long > &b,long long  i,long long  w){
	if(w<=0 || i>a.size())
		return 0;

	if(dp.find(make_pair(i,w))!=dp.end())
		return dp[make_pair(i,w)];

	if(w<a[i])
		return (dp[make_pair(i,w)] = doWork(a,b,i+1,w));

	return (dp[make_pair(i,w)] = max( doWork(a,b,i+1,w) , doWork(a,b,i+1,w-a[i])+b[i] ));
}

int  main(){

	long long  n,w;
	cin >> n >> w;

	vector<long long > a(n),b(n);

	for(long long  i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}

	cout << doWork(a,b,0,w) << "\n";

	return 0;
}