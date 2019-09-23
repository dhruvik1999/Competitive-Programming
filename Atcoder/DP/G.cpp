#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000000,-1);

int doWork(vector<int> *grp,int node){
	if(dp[node]!=-1)
		return dp[node];

	int ans = 0;
	for(int i=0;i<grp[node].size();i++){
		ans = max(ans , doWork(grp,grp[node][i]));
	}
	dp[node]=ans+1;

	return dp[node];
}


int main(){

	int n , m;
	cin >> n >> m;

	vector<int> grp[n+10];

	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		grp[a].push_back(b);
	}

	for(int i=1;i<=n;i++){

		if(dp[i]==-1){
			doWork(grp,i);
		}
	}

	int ans = 0;


	for(int i=1;i<=n;i++){
		ans = max(ans , dp[i]);
	}
	cout << ans-1 << "\n";
	return 0;
}	