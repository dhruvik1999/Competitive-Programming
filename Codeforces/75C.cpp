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




int32_t main(){
	fastio();

	int a,b;
	cin >> a >> b;

	int t = min( a, b );
	b = max( a,b );
	a = t;

	vector< int > fact;
	for(int i=1;i<=sqrt(a);i++){
		if( a%i==0 && b%i==0 ){
			fact.push_back(i);
		}
		if( a%( a/i ) ==0 && b%(a/i)==0 ){
			fact.push_back(a/i);
		}
	}

	sort( fact.begin() , fact.end() );
	fact.erase( unique( fact.begin() , fact.end() ) , fact.end() );

	int n;
	cin >> n;
	int l,r,check;

	// for(int i=0;i<fact.size();i++){
	// 	cout << fact[i] << " ";
	// }
	// cout  << "\n";

	for(int i=0;i<n;i++){
		cin >> l >> r;
		check = *(upper_bound( fact.begin() , fact.end() , r )-1);
		//cout << r << " --> " << check << "\n";
		if( l<= check  ){
			cout << check << "\n";
		}else{
			cout << -1 << "\n";
		}
	}



	return 0;
}




