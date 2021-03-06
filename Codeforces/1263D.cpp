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

void dfs(vector<int> *p, vector<int> *q, vector<bool> &visp,vector<bool> &visq, string type,int node){
	if(type=="p"){
		visp[node]=true;
		for(int i=0;i<p[node].size();i++){
			if( visq[ p[node][i] ]==false ){
				dfs(p,q,visp,visq,"q",p[node][i]);
			}
		}
	}else{
		visq[node]=true;
		for(int i=0;i<q[node].size();i++){
			if( visp[ q[node][i] ]==false ){
				dfs(p,q,visp,visq,"p",q[node][i]);
			}
		}
	}
}


int32_t main(){
	fastio();

	int n;
	cin >> n;

	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector< int > p[26];
	vector< int > q[n];

	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].size();j++){
			p[ (a[i][j]-'a') ].push_back(i);
			q[i].push_back( (a[i][j]-'a') );
		}
	}

	int ans = 0;
	vector<bool> visp(n,false), visq(n,false);

	for(int i=0;i<n;i++){
		if(visq[i]==false){
			ans++;
			dfs(p,q,visp,visq,"q",i);
		}
	}

	cout << ans << "\n";



	return 0;
}




