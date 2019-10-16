#include<bits/stdc++.h>
using namespace std;

int  main(){

	long long  t;
	cin >> t;

	while(t--){

		long long  n,k;
		cin >> n >> k;

		vector<long long > a(n);
		for(long long  i=0;i<n;i++){
			cin >> a[i];
		}

		sort( a.begin() , a.end() );
		long long  l,r,d1,d2;
		set< pair<long long ,long long > > s;

		for(long long  i=0;i<n && i+k<n;i++){
			l=i;
			r=i+k;

				d1 = (a[l]+a[r])/2;
				s.insert( {  max( d1-a[l] , a[r]-d1 ) , d1  } );
		}

		cout << (	*s.begin()).second << "\n";


	}

}