#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,w;
	cin >> n >> w;

	vector<int> dp(w+1,0);

	int ww,vv;
	for(int i=0;i<n;i++){
		cin  >> ww >> vv;

		for(int j=w-ww;j>=0;j--){
			dp[j+ww] = max( dp[j+ww] , dp[j]+vv );
		}
	}

	int ans = 0;

	for(int i=0;i<=w;i++){
		ans = max(ans , dp[i]);
	}

	cout << "ANS : " << ans << "\n";


	return 0;
}