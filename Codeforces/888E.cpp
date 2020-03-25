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

int ans = -1;
void func(vector<int> &a, int ind, int m, int sum, vector<int> &s){
	
	if( a.size() <= ind ){
		s.push_back( sum%m );
		return ;
	}else{
		func(a,ind+1,m,(sum%m+a[ind]%m)%m,s);
		func(a,ind+1,m,sum%m,s);
	}

}


int32_t main(){
	fastio();

	int n,m;
	cin >> n >> m;

	vector<int> a,b;
	int t;

	for(int i=0;i<n;i++){
		cin >> t;
		if( i<n/2 ){
			a.push_back(t);
		}else{
			b.push_back(t);
		}
	}

	vector<int> dp1,dp2;	

	func(a,0,m,0,dp1);
	//cout << ans1 << "\n";
	ans = -1;
	func(b,0,m,0,dp2);
	//cout << ans2 << "\n";
	sort( dp2.begin() , dp2.end() );
	int ans = 0;
	for(auto i : dp1){
		ans = max( ans , max( (i+*(upper_bound( dp2.begin() , dp2.end() , m-1-i )-1))%m   , (i+*(upper_bound( dp2.begin() , dp2.end() , 2*m-1-i )-1))%m ) );
	}


	cout << ans << "\n";	

	
	return 0;
}