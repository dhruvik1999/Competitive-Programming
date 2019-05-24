#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int min_a(int *a,int l,int r){
	int ans = INT_MAX;
	for(int i=l;i<=r;i++){
		ans = min(ans,a[i]);
	}
	return ans;
}

int max_a(int *a,int l,int r){
	int ans = INT_MIN;
	for(int i=l;i<=r;i++){
		ans=max(ans,a[i]);
	}
	return ans;
}

int findMin(int *a,int l,int r){

	if(l>=r)
		return 0;

	if(min_a(a,l,r)*2 > max_a(a,l,r))
		return 0;

	if(dp[l][r]!=-1)
		return dp[l][r];



	return  dp[l][r] = min( findMin(a,l,r-1) , findMin(a,l+1,r) ) + 1;

}

int dp_appr(int* a,int n){

	cout << "called " << n << "\n";

	for(int i=1;i<n;i++){
		if(a[0]*2 > a[i]){
			cout << "*****" << a[0] << " " << a[i] << "\n";
			dp[0][i]=n-i-1;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){

			int temp = INT_MAX;

			if(min_a(a,i,j)*2 > max_a(a,i,j)){
				temp = n-(j-i+1);
			}

			dp[i][j]= min(dp[i][j+1 ]+1 , min( dp[i-1][j]+1 , temp ) );
		}
	}

	return dp[n-2][n-1];

}

int main(){

	int n;
	cin >> n;

	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=-1;
		}
	}



	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "------------------";


	sort(a,a+n);

	for(int j=0;j<n;j++){
		cout << a[j] << " ";
	}

	cout << findMin(a,0,n-1) << "\n";

	


	//cout << dp_appr(a,n) << "\n";

	return 0;
}