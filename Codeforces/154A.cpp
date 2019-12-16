#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	int k;
	cin >> k;

	string t;
	set< pair<char,char> > ss;

	for(int i=0;i<k;i++){
		cin >> t;
		ss.insert( { t[0] , t[1] } );
		ss.insert( { t[1] , t[0] } );

	}
	int n = s.length();
	vector< char > a[n+1];
	int ind = 0;
	a[0].push_back(s[0]);

	for(int i=1;i<n;i++){
		if( (ss.find( make_pair(a[ind][0] , s[i]) ) != ss.end() ) || a[ind][0] == s[i] ){
			a[ind].push_back(s[i]);
		}else{
			ind++;
			a[ind].push_back(s[i]);
		}
	}

	int ans = 0,l=0,r=0;
	for(int i=0;i<=ind;i++){
		l=0;
		r=0;
		for(int j=0;j<a[i].size();j++){
			if( a[i][0] == a[i][j]  ){
				l++;
			}else{
				r++;
			}
		}
		ans += min(l,r);
	}

	cout << ans << "\n";



	return 0;
}