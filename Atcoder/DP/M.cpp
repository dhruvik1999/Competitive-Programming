	#include<bits/stdc++.h>
	using namespace std;
	#define mod 1000000007
	int main(){

		long long n,k;
		cin >> n >> k;

		vector<long long> a(n+1);
		for(long long i=1;i<=n;i++){
			cin >> a[i];
		}
		sort(a.begin(),a.end());

		vector< vector<long long> > dp( n+10,vector<long long>(k+10,0) );

		for(long long i=0;i<=n;i++){
			dp[i][0]=1;
		}

		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=k;j++){
				if( a[i]>=j ){
					dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j]%mod)%mod;
				}else{
					dp[i][j]=(dp[i][j-1]-dp[i-1][j-a[i]-1]);
				}
			}
		}

		 // for(long long i=0;i<=n;i++){
		 // 	for(long long j=0;j<=k;j++){
		 // 		cout << dp[i][j] << " ";
		 // 	}
		 // 	cout << "\n";
		 // }

		cout << dp[n][k]%mod << "\n";
		return 0;
	}