#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;

	cin >> s;
	s=" "+s;


	int n;
	cin >> n;

	set<int> dp[30];

	for(int i=1;i<s.length();i++){
		dp[ s[i]-'a' ].insert(i);
	}


	int p,q;
	for(int i=0;i<n;i++){
		cin >> p >> q;

		if(p==1){
			char r;
			cin >> r;
			dp[ s[q]-'a' ].erase( dp[s[q]-'a'].find(q) );
			dp[ r-'a' ].insert(q);
			s[q]=r;
			//cout << s << "\n";
		}else{
			int r;
			cin >> r;
			int ans = 0;
			for(int j=0;j<26;j++){
				if( upper_bound( dp[j].begin() , dp[j].end() , q-1 ) != upper_bound( dp[j].begin() , dp[j].end() , r ) ){
					ans++;
				}
			}

			cout << ans << "\n";

		}
	}

	return 0;
}