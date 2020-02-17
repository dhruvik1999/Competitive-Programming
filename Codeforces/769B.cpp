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

vector< pair<int,int> > ans;
void dfs( vector< pair<int,int> >&a, int node, vector<bool> &vis,int n){

	vis[node]=true;
	int t = 0;
	for(int i=0;i<a[node].first;i++){
		t = node+1;
		while(vis[t]==true && t<n){
			t++;
		}
		if(t<n){
			ans.push_back( {a[node].second , a[t].second} );
			dfs(a,t,vis,n);
		}else{
			break;
		}

	}

	a[node].first=0;

}


int32_t main(){
	fastio();
	int n;
	cin >> n;

	vector< pair<int,int> > a;
	int p;

	for(int i=0;i<n;i++){
		cin >> p;
		a.push_back( {p,i+1} );
	}

	sort( a.begin()+1 , a.end() );
	reverse( a.begin()+1 , a.end() );

	// for(int i=0;i<n;i++){
	// 	cout << a[i].first << " " << a[i].second << "\n";
	// }

	vector<bool> vis(n+10,false);
	dfs(a,0,vis,n);

	for(int i=0;i<n;i++){
		if( vis[i]==false ){
			cout << -1 << "\n";
			return 0;
		}
	}

	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}




	

	return 0;
}