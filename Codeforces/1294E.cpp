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

	vector< vector<int> > a( n , vector<int>(m,0) );
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	int ls = 0;
	int ans = 0;

	vector<int> dp(n,0);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dp[j]=0;
		}
		ls = n;
		for(int j=0;j<n;j++){
			if( a[j][i]%m == i && a[j][i] < n*m ){
				if( a[j][i]/m <= j ){
					dp[ j-a[j][i]/m ]++;
				}else{
					dp[ n-(a[j][i]/m-j) ]++;
				}
			}
		}

		for(int j=0;j<n;j++){
			//cout << dp[j] << " ";
			ls = min( ls , (n-dp[j]) + j);
		}
		//cout << "\n";

		ans += ls;
	}

	cout << ans << "\n";


	return 0;
}




