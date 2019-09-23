#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > dp(1000 , vector<int>(1000 , -1));
int stp = 0;

int doWork(vector<int> a,int l,int r,int year){
	stp++;
	if(l>r)
		return 0;



	if(dp[l][r]!=-1)
		return dp[l][r];

	return (dp[l][r] = max( doWork(a,l+1,r,year+1)+a[l]*year , doWork(a,l,r-1,year+1)+a[r]*year ));
}


int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	cout << "ANS : " << doWork(a,0,n-1,1) << "\n";
	cout << stp << "\n";




	return 0;
}