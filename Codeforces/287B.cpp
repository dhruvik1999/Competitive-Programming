#include<bits/stdc++.h>
using namespace std;

bool func( long long int mid, long long int a, long long int s ){
	if( s - a*mid + ((mid)*(mid+1))/2 <= a ){
		return true;
	}else{
		return false;
	}
}


int main(){

	long long int n,m;
	cin >> n >> m;

	if(n-1>(m*(m-1))/2){
		cout << -1 << "\n";
		return 0;
	}

	n--;
	m--;
	long long int t;
	if(n==0){
		cout << 0 << "\n";
		return 0;
	}

	if(n<=m){
		cout << 1 <<"\n";
		return 0;
	}

	long long int l=1,r=m;
	long long int ans = 0;
	while(l<=r){
		long long int mid = (l+r)>>1;

		if( func( mid, m, n ) ){
			ans = mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}

	cout << ans+1 << "\n";







	return 0;
}