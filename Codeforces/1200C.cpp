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
	int n,m,q;
	cin >> n >> m >> q;

	int g = gcd(n,m);
	n = n/g;
	m = m/g;

	int p1,q1,p2,q2,x,y;
	for(int i=0;i<q;i++){
		cin >> p1 >> q1 >> p2 >> q2;
		if( p1==1 ){
			x = (q1-1)/n;
		}else{
			x = (q1-1)/m;
		}

		if( p2==1 ){
			y = (q2-1)/n;
		}else{
			y = (q2-1)/m;
		}
		//cout << x <<" " << y << "\n";
		if(x==y){
			cout << "YES" << "\n";
		}else{
			cout << "NO" << "\n";
		}
	}		
	

	return 0;
}




