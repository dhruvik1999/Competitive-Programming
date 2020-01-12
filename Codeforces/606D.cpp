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

	vector< pair<int,int> > edg(m);
	int p,q;

	for(int i=0;i<m;i++){
		cin >> p >> q;
		edg[i] = {p,q};
	}

	
	pair<int,int> temp = *min_element( edg.begin() , edg.end() );

	if( temp.second == 0 ){
		cout << -1 << "\n";
		return 0;
	}

	vector< pair<int,int> > ans(m);
	int u=0,v=1,ou,ov;
	for(int i=0;i<m;i++){

		if( edg[i].second == 1 ){
			u++;
			v++;
			ans[i] = {u,v};

			if( edg[i] == temp ){
				ou = u;
				ov = v;
			}

			

		}

	}

	vector<int> dp(n+10);
	int tt = 0;
	for(int i=1;i<=v;i++){
		for(int j=i+2;j<=v;j++){



			while( tt < m && edg[tt].second==1 ){
				tt++;
			}

			if( tt >= m ){
				break;
			}else{
				ans[tt] = {i,j};
				tt++;
			}
		}
	}

	// int tu=1,tv=2;
	// for(int i=0;i<m;i++){
	// 	if( edg[i].second == 0 ){
	// 		ans[i] = {ou,ov};
	// 	}
	// }

	for(int i=0;i<m;i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}






	return 0;
}




