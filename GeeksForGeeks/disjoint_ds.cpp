#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1000000,-1);


int getRoot(int i){
	if(i!=dp[i]){
		dp[i] = getRoot(dp[i]);
	}
	return dp[i];
}

void unioun(int a,int b){
	int par_a = getRoot(a);
	int par_b = getRoot(b);

	dp[par_b]=par_a;
}



int main(){

	int n,m;
	cin  >> n >> m;

	for(int i=0;i<n;i++){
		dp[i]=i;
	}

	int a,b;
	for(int i=0;i<m;i++){
		cin >> a>>b;
		unioun(a,b);
	}

	for(int i=0;i<n;i++){
		cout << i << " : " << dp[i] << "\n";
	}




	return 0;
}