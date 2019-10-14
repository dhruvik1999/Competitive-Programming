#include<bits/stdc++.h>
using namespace std;

int main(){

	long long  n,k;
	cin >> n >> k;

	vector<long long > a(n);
	for(long long  i=0;i<n;i++){
		cin >> a[i];
	}

	sort( a.begin() , a.end() );
	long long  ans = 0;
	for(long long  i=0;i<n;i++){
		while( a[i]>k*2 ){
			k=k*2;
			ans++;
		}
		k=max( k , a[i] );
	}

	cout << ans << "\n";



	return 0;
}