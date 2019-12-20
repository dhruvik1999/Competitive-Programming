#include<bits/stdc++.h>
using namespace std;
#define ll long long

int  main(){

	ll t;
	cin >> t;

	while(t--){

		 ll n,k;
		 cin >> n >> k;

		 vector<ll> a(n);
		 for(ll  i=0;i<n;i++){
		 	cin >> a[i];
		 }

		 vector< vector<ll> > dp( 3, vector<ll > (n,0) );

		 for(ll  i=0;i<n;i++){
		 	dp[0][i]=a[i];
		 	if(i<n/2){
		 		dp[1][i]=( (a[i])^(a[n-i-1]) );
		 		dp[2][i]=a[n-i-1];
		 	}else{
		 		dp[1][i]=a[n-i-1];
		 		dp[2][i]=( (a[i])^(a[n-i-1]) );
		 	}
		 }


		 if(n%2!=0){
		 	dp[1][n/2]=0;
		 	if(k>(n/2)){
		 		dp[0][n/2]=0;
		 	}else{
		 		dp[0][n/2]=a[n/2];
		 	}
		}

		 // for(ll  i=0;i<3;i++){
		 // 	for(ll  j=0;j<n;j++){
		 // 		cout  << dp[i][j] << " ";
		 // 	}
		 // 	cout << "\n";
		 // }

		 ll  i=0,j=0;
		 i=( k/n )%3;

		 for(j=0;j<k%n;j++){
		 	cout << dp[(i+1)%3][j] << " ";
		 }
		 for(;j<n;j++){
		 	cout << dp[i][j] << " "; 
		 }
		 cout << "\n";







	}


	return 0;
}