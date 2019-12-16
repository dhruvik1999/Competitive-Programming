#include<bits/stdc++.h>
using namespace std;

int main(){

long long int n,l,r;
	cin >> n >> l >> r;

	if( 6*n <= l*r ){
		cout << l*r << "\n";
		cout << l << " " << r <<"\n";
		return 0;
	}

	long long int nl,nr;
	long long int ra = ceil((float)sqrt( 6*n ));
	//cout << ra*ra << "\n";	
	long long int ans = LONG_LONG_MAX,a1,a2;
	if( l<r ){
		for(long long int i=l;i<=ra;i++){
			long long int j = ( ceil( (float)6*n/i ) );
			if( j>=r ){
				if( i*j<ans && i*j>=6*n ){
					a1=i;
					a2=j;
					ans = i*j;
				}
				//ans = min( ans , i*j );
			}
		}
	}else{
		for(long long int i=r;i<=ra;i++){
			long long int j = ( ceil( (float)6*n/i ) );
			//cout << i << " " << j << "\n";
			if( j>=l ){
				if( i*j<ans && i*j>=6*n){
					a1=j;
					a2=i;
					ans = i*j;
				}
			}
		}
	}

	cout << ans << "\n";
	cout << a1 << " " << a2 << "\n";

	return 0;
}