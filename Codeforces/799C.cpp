#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007
#define maxlen 9223372036854775807
#define minlen -9223372036854775807


int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

int solve1(vector< pair<int,int> > &C, vector< pair<int,int> > &D,int c,int d){
	int n = C.size();
	int m = D.size();

	sort( C.begin() , C.end() );
	sort( D.begin() , D.end() );
	int ans = 0;

	for(int i=n-1;i>=0;i--){
		if( C[i].second <= c ){
			ans = max( ans , C[i].first );
			break;
		}
	}

	int ans2=0;
	for(int i=m-1;i>=0;i--){
		if( D[i].second <= d ){
			ans2 = max( ans2 , D[i].first );
		}
	}
	if(ans==0 || ans2==0)
		return 0;

	return ans+ans2;
}

int solve2(vector< pair<int,int> > C,int c){
	//cout << c << "\n";	
	int n = C.size();

	for(int i=0;i<n;i++){
		C[i] = { C[i].second , C[i].first };
	}
	sort( C.begin() , C.end() );

	vector<int> p(n),b(n);
	int  ans = 0;
	for(int i=0;i<n;i++){
		p[i] = C[i].first;
		b[i] = C[i].second;
		if( i!=0 ){
			b[i] = max( b[i-1] , b[i] );
		}
		//cout << p[i] << " " << b[i]  << "\n";	
	}



	int p1,q1;
	for(int i=n-1;i>=0;i--){
		if( C[i].first <= c && i!=0 && p[0] >=c-C[i].first ){
			//cout << i << "--\n";
			p1 = C[i].second ;
			q1 = b[lower_bound( p.begin() , p.begin()+i , c-C[i].first ) - p.begin()];
		//	cout << p1 << " " << q1 << "\n";
			if( p1!=0 && q1!=0 ){
				ans = max( ans , p1+q1 );
			}
		}
	}
	//cout << ans << "\n";
	return ans;
}

int32_t main(){
	fastio();

	int n,c,d;
	cin >> n >> c >>d;

	vector< pair<int,int> > C,D;

	int p,q;
	char s;

	for(int i=0;i<n;i++){
		cin >> p >> q >> s;
		if(s=='C'){
			C.push_back( {p,q} );
		}else{
			D.push_back( {p,q} );
		}
	}
	//cout << solve2(C,c) << "\n";
	cout << max( solve1(C,D,c,d) , max(  solve2(C,c) , solve2(D,d) ) ) << "\n";

	return 0;
}




