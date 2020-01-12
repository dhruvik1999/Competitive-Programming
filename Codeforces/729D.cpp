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

	int n,a,b,k;
	cin >> n >> a  >> b >> k;
	string s;
	cin >> s;

	s=" "+s;
	vector<int> dp(n+1,0);

	

	vector< pair<int,int> > ans(n+1);
	int pos=-1;
	for(int i=1;i<=n;i++){
		if( s[i]=='0' ){
			pos++;
			ans[pos]={i,0};
			for(;i<=n;i++){
				if( s[i]=='0' ){
					ans[pos]={ ans[pos].first , ans[pos].second+1 };
				}else{
					break;
				}
			}
		}
	}
	deque<int> fa;

	for(int i=0;i<=pos;i++){
//		cout << ans[i].first << " " << ans[i].second << "\n";
		for(int j=ans[i].first+b-1;j<ans[i].first+ans[i].second;j+=b){
			fa.push_back(j);
		}
	}

	for(int i=0;i<a-1;i++){
		fa.pop_front();
	}

	cout << fa.size() << "\n";
	for(int i=0;i<fa.size();i++){
		cout << fa[i] << " ";
	}
	cout << "\n";












	return 0;
}




