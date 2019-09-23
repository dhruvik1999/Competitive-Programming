#include<bits/stdc++.h>
using namespace std;

int main(){

	long long  n,w;
	cin >> n >> w;

	vector<long long > a(n),b(n);
	vector< pair< double , pair<int,int> > > dp;


	for(long long  i=0;i<n;i++){
		cin >> a[i] >> b[i];
		dp.push_back( make_pair( ((double)a[i])/b[i] , make_pair( a[i] , b[i] )  ) );
	}

	sort(dp.begin(),dp.end());

	for(int i=0;i<n;i++){
		cout << dp[i].first << " " << dp[i].second.first << " " << dp[i].second.second << "\n";
	}

	long long ans = 0,tw=0;
	int i=0;
	while(tw<=w && i<n){
		ans+=dp[i].second.second;
		tw+=dp[i].second.first;
		i++;
	}

	cout << ans << "\n";



	return 0;
}