#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ll n,k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	ll ans = 0;
	int l=0,r=0;
	ll sum = 0;

	for(;r<n;r++){
		sum+=a[r];
		while( sum>=k ){
			ans += ( n-r );
			sum-=a[l];
			l++;
		}
	}

	cout << ans << "\n";

	return 0;
}