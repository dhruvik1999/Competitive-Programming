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

	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	reverse( a.begin() , a.end() );

	int p,q;
	vector< unordered_set<int> > graph(n+1);
	for(int i=0;i<m;i++){
		cin >> p >> q;
		graph[p].insert(q);
		graph[q].insert(p);
	}

	int t=0;
	int ans = 0;

	// while(t<n &&  graph[a[0]].find( a[t] )!=graph[a[0]].end() ){
	// 	ans++;
	// 	t++;
	// }

	// if(t>=n){
	// 	cout << ans << "\n";
	// 	return 0;
	// }

	//cout << ans << "\n";
	unordered_set<int> s1,s2;
	for(auto i : graph[ a[t] ]){
		s1.insert(i);
	}
	t++;

	for(int i=t;i<n;i++){
		if( s1.find( a[i] )!=s1.end() ){
			ans++;
		}
			s2.clear();
			for(auto j : graph[a[i]]){
				if( s1.find( j )!=s1.end() ){
					s2.insert(j);
				}
			}
			s1=s2;
		
	}

	cout << ans << "\n";







	return 0;
}




