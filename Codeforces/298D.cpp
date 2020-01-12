#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007
#define maxlen 1000005

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

int32_t main(){
	fastio();

	int n,m,k;
	cin >> n >> m >> k;

	vector<int> a(n),b(m),c;
	unordered_map< int,int > mp;

	for(int i=0;i<n;i++){
		cin >> a[i];
		c.push_back(a[i]);
		mp[ a[i] ]++;
	}

	for(int i=0;i<m;i++){
		cin >> b[i];
		c.push_back(b[i]);
		mp[ b[i] ]--;
	}

	sort( c.begin() , c.end() );
	//unique( c.erase( c.begin() , c.end() ) , c.end() );
	c.erase( unique( c.begin() , c.end() ) , c.end() );
	reverse( c.begin() , c.end() );

	int ls = 0;
	for(int i=0;i<c.size();i++){
		ls += mp[ c[i] ];  
		//cout << c[i]  << " " << mp[c[i]] << "\n";
		if( ls>0 ){
			cout << "YES" << "\n";
			return 0;
		}
	}

	cout << "NO" << "\n";






	return 0;
}




