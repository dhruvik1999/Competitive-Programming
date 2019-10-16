#include<bits/stdc++.h>
using namespace std;
#define mod 998244353

vector<long long > fact(300001,1);
void pw(){
	for(long long  i=1;i<300001;i++){
		fact[i]= (( i%mod )*( fact[i-1]%mod ))%mod;
	}
}
int  main(){

	
	long long  n;
	cin >> n;

	pw();

	vector< pair<long long ,long long > > v;
	long long  p,q;
	vector<long long > a(300001,0),b(300001,0),ab(300001,0);
	map< pair<long long ,long long > , long long > mp;

	for(long long  i=0;i<n;i++){
		cin >> p >> q;
		v.push_back( {p,q} );
		a[p]++;
		b[q]++;
		mp[ make_pair(p,q) ]++;
	}

	// for(int i=0;i<10;i++){
	// 	cout << i << " " << fact[i] << "\n";
	// }

	long long  ans = fact[n];
	long long  a1=1,b1=1,ab1=0;
	for(long long  i=0;i<300001;i++){

		a1 = ( ( a1 )%mod * ( fact[ a[i] ] )%mod )%mod;
		b1 = ( ( b1 )%mod * ( fact[ b[i] ] )%mod )%mod;
	}
	//cout << a1 << " " << b1 << " " << "\n";
	ans = (ans%mod - a1%mod-b1%mod)%mod;

	sort( v.begin() , v.end() );

	bool lock = true;
	for(int i=1;i<n;i++){
		if( v[i].second < v[i-1].second ){
			lock = false;
			break;
		}
	}

	if(lock){
		ab1=1;
	for( auto i : mp ){
			ab1 = ( ab1%mod * ( fact[ (i.second) ] )%mod )%mod;
	}
}

	
	ans = (ans%mod+ab1%mod)%mod;

	if( ans<0 ){
		cout << ans+mod << "\n";
	}else{
		cout << ans << "\n";
	}









	return 0;
}