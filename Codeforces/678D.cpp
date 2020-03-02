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

vector< vector<int> > mat_mul( vector< vector<int> > a,vector< vector<int> > b, int mod){

	vector< vector<int> > ans( 2 , vector<int>(2,0) );

	ans[0][0] = ((a[0][0]%mod*b[0][0]%mod)%mod+(a[0][1]%mod*b[1][0]%mod)%mod)%mod;
	ans[0][1] = ((a[0][0]%mod*b[0][1]%mod)%mod+(a[0][1]%mod*b[1][1]%mod)%mod)%mod;
	ans[1][0] = ((a[1][0]%mod*b[0][0]%mod)%mod+(a[1][1]%mod*b[1][0]%mod)%mod)%mod;
	ans[1][1] = ((a[1][0]%mod*b[0][1]%mod)%mod+(a[1][1]%mod*b[1][1]%mod)%mod)%mod;

	return ans;

}

vector< vector<int> > solve( vector< vector<int> > a, int n, int mod)
{
	if(n==0){
		vector< vector<int> > ans(2 , vector<int>(2));
		ans[0][0]=1;
		ans[0][1]=0;
		ans[1][0]=0;
		ans[1][1]=1;
		return ans;
	}

	if(n%2==0){
		vector< vector<int> > ans = solve(a,n/2,mod);
		return mat_mul(ans,ans,mod);
	}else{
		return mat_mul(a,solve(a,n-1,mod),mod);
	}
}


int32_t main(){
	fastio();

	int a,b,n,x;
	cin >> a >> b >> n >> x;

	vector< vector<int> > ans(2 , vector<int>(2));
		ans[0][0]=a;
		ans[0][1]=b;
		ans[1][0]=0;
		ans[1][1]=1;
	vector< vector<int> > aa = solve(ans,n,1000000007);

	cout << (aa[0][1]%1000000007+(((aa[0][0]%1000000007)*(x%1000000007))%1000000007))%1000000007 << "\n";

	return 0;
}




