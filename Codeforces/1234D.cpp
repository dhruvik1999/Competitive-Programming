#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
	#endif

    string a;
    cin >> a;

    set<int> s[30];
    int n;
    cin >> n;

    for(int i=0;i<a.length();i++){
    	s[ a[i]-'a'  ].insert(i+1);
    }
    a=" "+a;

    while(n--){
    	int p;
    	cin >> p;

    	if(p==1){
    		int pos;
    		char r;
    		cin >> pos >> r;
    		s[ a[pos]-'a' ].erase( pos );
    		s[ r-'a' ].insert(pos);
    		a[pos]=r;
    		//cout<< a << "\n";
    	}else{
    		int l,r;
    		cin >> l >> r;
    		int ans = 0;

    		for(int i=0;i<26;i++){
    			if( s[i].upper_bound( l-1 ) != s[i].upper_bound( r ) ){
    				ans++;
    			}
    		}
    		cout << ans << "\n";
    	}



    }



}
