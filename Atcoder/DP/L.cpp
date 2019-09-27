#include<bits/stdc++.h>
using namespace std;

vector< vector<long long> > dp( 3001 , vector<long long>(3000,-1) );
vector< vector<long long> > dp1( 3001 , vector<long long>(3000,-1) );


long long doWork(vector<long long> &a,long long l,long long r,long long turn){
	if(l>r)
		return 0;
	if(dp[l][r]!=-1 && turn==1)
		return dp[l][r];

	if(dp1[l][r]!=-1 && turn==0)
		return dp1[l][r];

	if(turn==1){
		return (dp[l][r] = max(doWork(a,l+1,r,0)+a[l],doWork(a,l,r-1,0)+a[r]));
	}else{
		return (dp1[l][r]=min(doWork(a,l+1,r,1),doWork(a,l,r-1,1)));
	}
}

int main(){

	long long n;
	cin >> n;

	long long sum = 0;

	vector<long long> a(n+1);

	for(long long i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}

	cout << 2*doWork(a,0,n-1,1)-sum << "\n";


	return 0;
}