#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int l=0,r=n;

	for(int i=0;i<n;i++){
		if( a[i]==i ){
			l=i;
		}
	}

	int mm = a[l];
	r=l;
	for(int i=l;i<n;i++){
		if( a[i] > mm ){
			mm=a[i];
			r=i;
		}
	}

	//cout << l << " " << r << "\n";

	int ans = 0;

	for(int i=0;i<=l;i++){
		ans+= ( i-a[i]  );
	}

	for(int i=r;i<n;i++){
		ans += ( mm-a[i] );
	}

	for(int i=r-1;i>l;i--){
		if( mm > a[l] ){
			mm--;
			ans += ( mm - a[i] );
		}else{
			ans += ( a[l] - a[i] );
		}
	}

	cout << ans << "\n";


	return 0;
}