#include<bits/stdc++.h>
using namespace std;



int  main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	long long  t;
	cin >> t;

	while(t--){
		long long  n;
		cin >> n;

		vector< pair<long long ,long long > > a(n);
		for(long long  i=0;i<n;i++){
			cin >> a[i].first >> a[i].second;
		}

		vector< vector<long long > > dp(3, vector<long long >(n+1,-1) );

		dp[0][0]=0;
		dp[1][0]=a[0].second;
		dp[2][0]=a[0].second*2;


		for(long long  i=1;i<n;i++){
			for(long long  j=0;j<3;j++){
				long long  mm = 9223372036854775807;
				//cout << mm << "\n";
				for(long long  k=0;k<3;k++){
					if( a[i-1].first + k != a[i].first+j ){
						mm = min(mm , dp[k][i-1] );
					}
				}
				dp[j][i]=mm+a[i].second*j;
			}
		}  

		// for(long long  i=0;i<3;i++){
		// 	for(long long  j=0;j<n;j++){
		// 		cout <<	dp[i][j] << " "; 
		// 	}
		// 	cout << "\n";
		// }

		cout << min( min( dp[0][n-1] , dp[1][n-1] ) , dp[2][n-1] ) << "\n";

	}


	return 0;
}