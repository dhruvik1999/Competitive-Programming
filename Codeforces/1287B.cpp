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
    
    int n,k;
    cin >> n >> k;

    vector<string> a(n);

    for(int i=0;i<n;i++){
    	cin >> a[i];
    }

    int ans = 0;

    vector< map<string,int> > dp(n+1);

    for(int i=n-1;i>=0;i--){
    	if(i==n-1){
    		dp[i][ a[i] ]++;
    	}else{
    		dp[i] = dp[i+1];
    		dp[i][ a[i] ]++;
    	}
    }

    string trg = "";
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n-1;j++){
    		trg = "";
    		for(int t=0;t<k;t++){
    			if( a[i][t] == a[j][t] ){
    				trg+=a[i][t];
    			}else{
    				if( 'S'!=a[i][t] && 'S'!=a[j][t] ){
    					trg+='S';
    				}else if('E'!=a[i][t] && 'E'!=a[j][t]){
    					trg+='E';
    				}else{
    					trg+='T';
    				}
    			}
    		}

    		ans += dp[j+1][trg];

    	}
    }

    cout << ans << "\n";

    return 0;
}




