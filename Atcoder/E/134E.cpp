#include<bits/stdc++.h>
using namespace std;
#define mod 1000009
int main(){

	long long n;
	cin >> n;

	vector<long long> a(n);
	for(long long i=0;i<n;i++){
		cin >> a[i];
	}

	vector<long long> bb(mod,1000000000000);

	long long ans = 0;
	for(long long i=n-1;i>=0;i--){
		long long ind = upper_bound(bb.begin(),bb.end(),a[i])-bb.begin();
		if(bb[ind]==1000000000000)
			ans++;
		bb[ind]=a[i];
	}

	 // for(long long i=0;i<n;i++){
	 // 	cout << bb[i] << " ";
	 // }
	 // cout << "\n";

	cout << ans << "\n";


	return 0;
}