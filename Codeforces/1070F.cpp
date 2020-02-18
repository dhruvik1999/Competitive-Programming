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

	int n;
	cin >> n;

	vector<int> a[4];
	string s;
	int t;

	for(int i=0;i<n;i++){
		cin >> s >> t;
		if( s=="11" ){
			a[0].push_back(t);
		}else if(s=="10"){
			a[1].push_back(t);
		}else if(s=="01"){
			a[2].push_back(t);
		}else if(s=="00"){
			a[3].push_back(t);
		}
	}

	int ans = 0;

	for(int i=0;i<4;i++){
		sort( a[i].begin() , a[i].end() );
		reverse( a[i].begin() , a[i].end() );
	}

	for(int i=0;i<min(a[1].size(),a[2].size());i++){
		ans+=a[1][i]+a[2][i];
	}
	vector<int> a1,a2;

	for(int i=min(a[1].size(),a[2].size());i<max(a[1].size(),a[2].size());i++){
		if(i<a[1].size()){
			a[3].push_back(a[1][i]);
		}
		if(i<a[2].size()){
			a[3].push_back( a[2][i] );
		}
	}

	sort(a[3].begin(),a[3].end());
	reverse(a[3].begin(),a[3].end());

	for(int i=0;i<a[0].size();i++){
		ans+=a[0][i];
		if(i<a[3].size()){
			ans+=a[3][i];
		}
	}

	cout << ans << "\n";



	

	return 0;
}