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

	int n,m;
	cin >> n >> m;

	vector< pair< pair<int,int> , int> > a;
	vector< pair<int,int> > ans(m);
	int p,q;
	for(int i=0;i<m;i++){
		cin >> p >> q;
		a.push_back( {{p,-1*q},i} );
	}

	sort( a.begin() , a.end() );

	int l=0,r=1;
	p=1;
	q=3;


	for(int i=0;i<m;i++){
		if( a[i].first.second == -1 ){
			r++;
			l++;
			ans[ a[i].second ] = { l,r };
		}else{
			if(p+1==q){
				q++;
				p=1;
			}
			if(q<=r){
				ans[ a[i].second ] = {p,q};
			}else{
				cout << -1 << "\n";
				return 0;
			}
			p++;
		}
	}

	for(int i=0;i<m;i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}


	

	return 0;
}