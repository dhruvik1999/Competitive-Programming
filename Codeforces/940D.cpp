#include<bits/stdc++.h>
using namespace std;

int main(){

	long long int n;
	cin >> n;

	vector<long long int> v(n);
	for(long long int i=0;i<n;i++){
		cin >> v[i];
	}

	string s;
	cin >> s;

	vector<long long int> l,r;

	for(long long int i=4;i<n;i++){

		if( s[i] == '1' ){

			if( s[i-1]=='0' && s[i-2]=='0' &&s[i-3]=='0' &&s[i-4]=='0'  ){
				long long int t = max(  max( v[i-1] , v[i-2] ) , max( v[i-3] , v[i-4])  );
				t = max( t , v[i] )+1;
				l.push_back(t);
			}
		}else{
			if( s[i-1]=='1' && s[i-2]=='1' &&s[i-3]=='1' &&s[i-4]=='1'  ){
				long long int t = min(  min( v[i-1] , v[i-2] ) , min( v[i-3] , v[i-4])  );
				t = min( t , v[i] )-1;
				r.push_back(t);
			}
		}
	}
	long long int al=-1000000000,ar=1000000000;
	for(long long int i=0;i<l.size();i++){
		al = max( al , l[i] );
	}

	for(long long int i=0;i<r.size();i++){
		ar = min( ar , r[i] );
	}

	if( al<=ar ){
		cout << al << " " << ar << "\n";
	}else{
		cout << -1 << "\n";
	}



	return 0;
}