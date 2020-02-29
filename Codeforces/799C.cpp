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

int solve1( vector< pair<int,int> > &tc, vector< pair<int,int> > &td, int c,int d ){
	int ans = 0;

	bool lock = false, lock2=false;
	for( auto a : tc ){
		if(a.second <= c){
			ans+=a.first;
			lock=true;
			break;
		}
	}

	for( auto a : td ){
		if(a.second <= d){
			ans+=a.first;
			lock2=true;
			break;
		}
	}

	if( lock && lock2 ){
		return ans;
	}else{
		return 0;
	}

}

int solve2( vector< pair<int,int> > tc , int c ){
	if(tc.size()==0 || tc.size()==1)
		return 0;
	int t;
	vector<int> dp( tc.size() );

	for(int i=0;i<tc.size();i++){
		t = tc[i].first;
		tc[i].first = tc[i].second;
		tc[i].second = t;
	}

	sort( tc.begin() , tc.end() );
	dp[0] = tc[0].second;
	for(int i=1;i<tc.size();i++){
		dp[i] = max( dp[i-1] , tc[i].second );
	}

	int ans = 0;
	int ind;
	pair<int,int> pp = make_pair(1,2);


	for(int i=1;i<tc.size();i++){
		if( tc[i].first<c ){
			pp = make_pair( c-tc[i].first , maxlen);
			ind = upper_bound( tc.begin() , tc.begin()+i , pp ) - tc.begin() - 1;
			if( ind != -1 ){
				ans = max( ans , tc[i].second + dp[ind]);
			}
		}
	}	

	return ans;

}

int32_t main(){
	fastio();

	int n,c,d;
	cin >> n >> c >> d;

	int b,p;
	char cc;

	vector< pair<int,int> > tc,td;
	for(int i=0;i<n;i++){
		cin >> b >> p >> cc;
		if( cc == 'C' ){
			tc.push_back( {b,p} );
		}else{
			//cout << b << " " << p << "\n";

			td.push_back( {b,p} );
		}
	}



	sort( tc.begin() , tc.end() );
	sort( td.begin() , td.end() );
	reverse( tc.begin() , tc.end() );
	reverse( td.begin() , td.end() );
	


	//cout << solve1(tc,td,c,d) << " " << solve2( tc , c ) << " " << solve2(td,d) << "\n";
	cout << max( solve1(tc,td,c,d) , max( solve2( tc , c ) , solve2(td,d) )) << "\n";

	

	return 0;
}




