#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<double> a(n+1);

	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	vector< vector<double> > dp( n+1,vector<double>(n+1,0) );

	for(int i=1;i<=n;i++){
		if(i==1){
			dp[i][0]=1-a[i];
		}else{
			dp[i][0] = dp[i-1][0]*(1-a[i]);
		}
	}
	dp[1][1]=a[1];

	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j] = dp[i-1][j]*(1-a[i]) + (dp[i-1][j-1])*(a[i]);
		}
	}

	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";

	double ans = 0;

	for(int i=1+(n)/2;i<=n;i++){
		ans+= dp[n][i];
	}

	printf("%.10f\n",ans);



	return 0;
}