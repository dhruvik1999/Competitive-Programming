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

int bt( vector<int> &a, int l, int r ){
	l=lower_bound(a.begin(),a.end(),l)-a.begin();
	r=upper_bound(a.begin(),a.end(),r)-a.begin();

	return r-l;
}

int32_t main(){
	// fastio();

	int n,m,k;
	cin >> n >> m >> k;

	vector<int> a;
	int t;
	// a.push_back(-1);
	for(int i=0;i<m;i++){
		cin >> t;
		a.push_back(t);
	}
	a.push_back(maxlen);

	int ans = 0;
	int l=1,r = k;

	int ci = 0;

	while(l<=n){

		// cout << l << " " << r << "\n";
		// cout << t << "\n";
		while( (t = bt(a,l,r))!=0 ){
			// cout << l  << "-" << r<< "\n";
			ci+=t;
			ans++;
			l=r+1;
			r=r+t;
			// cout << l  << "-" << r<< "\n";

		}
		// l=r+1;
		// r=r+k;
		if(ci<m){
			l = ((a[ci]-ci-1)/k)*k+1+ci;
			r = l+k-1;
		}else{
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}




