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

vector< vector<int> > dp(101 , vector<int> (100001 , INT_MAX ));

int doWork( vector<int> &val, vector<int> &wi, int n, int w, int valLim ){

	for(int i=0;i<=100;i++){
		dp[i][0]=0;
	}


	for(int i=1;i<=n;i++){
		for(int j=0;j<=100000;j++){
			//cout << i << " " << j  <<"\n";
			if(val[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				//cout << dp[i-1][j-val[i-1]] + wi[i-1] << "\n";
				dp[i][j] = min( dp[i-1][j-val[i-1]] + wi[i-1] , dp[i-1][j] );
			}

		}
	}
	int ans = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=100000;j++){
			//if( dp[i][j] < INT_MAX )
			//cout << dp[i][j] << " ";
			if( dp[i][j] <= w ){
				ans= max( ans , j );
			}
		}
		//cout << "\n";
	}

	return ans;

}


int32_t main(){
	//fastio();
		


	int n,w;
	cin >> n >> w;

	vector< int > val(n),wi(n);
	int valLim = 0;

	for(int i=0;i<n;i++){
		cin >> wi[i]  >> val[i];
		valLim = max( valLim , val[i] );
	}

	//cout << valLim << "\n";

	cout << doWork(val,wi,n,w,valLim) << "\n";





	return 0;
}




