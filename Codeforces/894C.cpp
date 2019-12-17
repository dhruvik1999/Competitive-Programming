#include<bits/stdc++.h>
using namespace std;

int gcd( int a, int b ){
	if(b==0)
		return a;

	return gcd( b , a%b );
}


int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans = a[0];

	for(int i=1;i<n;i++){
		ans = gcd( ans , a[i] );
	}

	if( ans != a[0] ){
		cout << -1 << "\n";
		return 0;
	}

	cout << 2*n-1 << "\n";
	for(int i=0;i<n;i++){
		if( i==0 ){
			cout << a[0] << " ";
		}else{
			cout << ans << " ";
			cout << a[i] << " ";
		}
	}
	cout << "\n";


	return 0;
}