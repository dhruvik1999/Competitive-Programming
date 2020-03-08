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

vector<int> dp(1000005);

string solve( string a, string b ){
	
	return a;

}


int32_t main(){

	fastio();
	int n;
	cin >> n;


	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	string ans = a[0];
	int nn,mm,val,val2,mnp;

	for(int i=1;i<n;i++){
	//	ans = solve( ans , a[i] );



	nn = ans.size();
	mm = a[i].size();
	
	//cout << "*" << "\n";
	// dp.push_back(-1);

	val = 0,val2=0;
	mnp=0;

	for(int j=nn-1;j>=max(0LL,nn-mm);j--){
		val = ((101*val%MOD)%MOD+(ans[j]-'!')%MOD)%MOD;
		val2 = (val2%MOD + ((a[i][nn-1-j]-'!')%MOD*powerr(101,nn-1-j,MOD)%MOD)%MOD)%MOD;

		if(val==val2){
			mnp=nn-j;
		}

	}

	for(int j=mnp;j<mm;j++){
		string ss(1, a[i][j]); 
		ans.append(ss);
	}
	}

	cout << ans << "\n";
	
	return 0;
}