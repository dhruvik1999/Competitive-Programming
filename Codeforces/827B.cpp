#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define maxlen 9223372036854775807
#define minlen -9223372036854775807
#define fin(n) for(int i=0;i<n;i++)

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}



int32_t main(){
	fastio();

	int n,k;
	cin >> n >> k;
	n=n-k;

	int node = 1;

	set< pair<int,int> > s;
	vector< pair<int,int> > ans;
	map<int,int> dis;

	for(int i=0;i<k;i++){
		node++;
		s.insert( {1,node} );
		dis[node]=1;
	}


	for(int i=0;i<n-1;i++){
		node++;
		pair<int,int> temp = *s.begin();
		s.erase( s.begin() );

		ans.push_back( { temp.first , node } );
		s.insert( { node , temp.second } );

		dis[ temp.second ]++;
	}

	for( auto a : s ){
		ans.push_back( a );
	}

	vector<int> y;
	for(auto a : dis){
		y.push_back( a.second );
	}
	sort( y.begin() , y.end() );

	cout << y[ k-1 ] + y[k-2] << "\n";

	for(auto a : ans){
		cout << a.first << " " << a.second << "\n";
	}



	

	return 0;
}




