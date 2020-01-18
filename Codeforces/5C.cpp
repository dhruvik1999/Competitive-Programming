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

	string a;
	cin >> a;

	deque< char > s;
	deque< int > dp;
	int n = a.length();

	dp.push_back(-1);
	for(int i=0;i<n;i++){
		if( s.size() ==0){
			s.push_back( a[i] );
			dp.push_back( i );
		}else{
			if( a[i]==')' && s.back()=='(' ){
				s.pop_back();
				dp.pop_back();
			}else{
				s.push_back( a[i] );
				dp.push_back( i );
			}
		}
	}
	dp.push_back( n );

	vector< int > count;
	for(int i=1;i<dp.size();i++){
		count.push_back( dp[i] - dp[i-1]-1 );
	}

	sort(count.begin() , count.end());
	reverse(count.begin() , count.end());

	if(count[0]==0){
		cout  << 0 << " " << 1 << "\n";
	}else{
		int ans = 0;
		for(int i=0;i<count.size();i++){
			if( count[i] == count[0] ){
				ans++;
			}
		}
		cout << count[0] << " " << ans << "\n";
	}






	return 0;
}




