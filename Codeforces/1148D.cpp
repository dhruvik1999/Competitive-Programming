#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector< pair<int,int> > a,b;
	int p,q;
	map< pair<int,int> , int > mp;

	for(int i=0;i<n;i++){
		cin >> p >> q;
		mp[ {p,q} ] =i+1;
		if( p<q ){
			a.push_back( {p,q} );
		}else{
			b.push_back( {p,q} );
		}
	}

	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sort(b.begin(),b.end());

	if( a.size()>b.size() ){
		cout << a.size() << "\n";
		for(int i=0;i<a.size();i++){
			cout << mp[ a[i] ] << " ";
		}
		cout << "\n";
	}else{
		cout << b.size() << "\n";
		for(int i=0;i<b.size();i++){
			cout << mp[ b[i] ] << " ";
		}
		cout << "\n";
	}






	return 0;
}