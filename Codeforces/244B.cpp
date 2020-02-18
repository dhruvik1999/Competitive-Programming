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


unordered_set<int> s;

void solve(int a, int b, int n, int len, int num){

	if(len==n){
		s.insert(num);
		return;
	}

	if(len!=0 || len==0&&a!=0)
		solve(a,b,n,len+1,num*10+a);

	if(len!=0 || len==0&&b!=0)
		solve(a,b,n,len+1,num*10+b);
}


int32_t main(){
	fastio();
	int n;
	cin >> n;

	int t=n;
	int pos = 0;
	while(t){
		t=t/10;
		pos++;
	}
	if(pos==10)
		pos--;

	for(int i=0;i<=9;i++){
		for(int j=i;j<=9;j++){
			for(int k=1;k<=pos;k++){
				solve(i,j,k,0,0);
			}
		}
	}

	vector<int> aa;
	int ans = 0;
	for(auto i : s){
		//cout << i << "\n";
		 //aa.push_back(i);
		if( i <= n ){
			ans++;
		}
	}

	if(1000000000 <= n){
		ans++;
	}

	// sort(aa.begin(),aa.end());

	// for(auto i : aa){
	// 	cout << i << "\n";
	// }

	cout << ans << "\n";




	return 0;
}