#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int knap(int *a,int *b,int n,int w){

	if(n<0 || w<=0)
		return 0;

	if(dp[n][w]!=-1)
		return dp[n][w];

	if(b[n] > w)
		return (dp[n][w] = knap(a,b,n-1,w) );
	else
		return (dp[n][w] = max(knap(a,b,n-1,w) ,a[n] + knap(a,b,n-1,w-b[n])) );

}



int main(){

	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++){
			dp[i][j]=-1;
		}
	}
	int n,w;
	cin >> n >> w;

	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}

	cout << knap(a,b,n-1,w) << "\n";



}