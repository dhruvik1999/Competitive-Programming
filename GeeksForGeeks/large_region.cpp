#include<bits/stdc++.h>
using namespace std;

int cnvrt(vector< vector<int> > &a , int i,int j ,int n,int m ){
	if(i<0 || i>=n || j<0 || j>=m){
		return 0;
	}

	if(a[i][j]==0)
		return 0;
	else if(a[i][j]==1){
		a[i][j]=0;
		return 1+cnvrt(a,i+1,j,n,m) + cnvrt(a,i,j+1,n,m) + cnvrt(a,i,j-1,n,m) + cnvrt(a,i-1,j,n,m);
	}
}

int main(){

	int n,m;
	cin >> n >> m;

	vector< vector<int> > a( n , vector<int>(m,0) );

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];	
		}
	}

	int ans = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans = max(ans , cnvrt(a,i,j,n,m));
		}
	}

	cout << "ANS : " << ans << "\n";





	return 0;
}