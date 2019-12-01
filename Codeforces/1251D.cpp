#include<bits/stdc++.h>
using namespace std;

bool check(vector< pair<long long ,long long > > &v , long long  val , long long  s ){
	long long  n = v.size();

	for(long long  i=0;i<n/2;i++){
		s-=v[i].first;	
	}
	
	if( v[n/2].first <= val && val<= v[n/2].second ){
		s-=val;
	}else{	
		return false;
	}


	for(long long  i=n/2+1;i<n;i++){
		if( v[i].first<=val && val<=v[i].second ){
			s-=val;
		}else if(val<=v[i].first){
			s-=v[i].first;
		}else{
			return false;
		}
	}

	if( s>=0 )
		return true;
	else
		return false;

}


int  main(){

	long long  t;
	cin >> t;


	while(t--){

		long long  n,s;
		cin >> n >> s;

		vector< pair<long long ,long long > > v;
		long long  p,q;
		for(long long  i=0;i<n;i++){
			cin >> p >> q;
			v.push_back( {p,q} );
		}
		sort(v.begin(),v.end());

		long long  l=0,r=2e14;
		long long  mid;
		long long  ans;

		while(l<=r){
			mid = (l+r)>>1;

			if( check( v,mid,s ) ){
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}

		cout << mid << "\n";






	}


	return 0;
}