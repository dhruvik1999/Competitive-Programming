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

	int n;
	cin >> n;

	vector<string> a(n);

	for(int i=0;i<n;i++){
		cin >> a[i];
	}


	unordered_map<string,int> dp;
	string s;

	vector< pair<int, pair< string , int> > > dd[n];
	int ha;

	for(int i=0;i<n;i++){
		unordered_map<string,int> temp;
		for(int j=0;j<9;j++){
			s="";
			ha=0;

			for(int k=j;k<9;k++){
				s+=a[i][k];

				 ha = ( (ha*11)%MOD + (a[i][k]-'0'+1)%MOD )%MOD;
				 dd[i].push_back( { k-j+1 , { s , ha }  } );
				// //cout << s << " " << ha << "\n";

				temp[ s ]++;
			}

		}

		sort( dd[i].begin() , dd[i].end() );

		for(auto kk : temp){
			dp[ kk.first ]++;
		}

	}


	for(int i=0;i<n;i++){
		for(int j=0;j<dd[i].size();j++){
			if(  dp[dd[i][j].second.first]<=1 ){
				cout << dd[i][j].second.first << "\n";
				break;
			}
		}
	}



	
	return 0;
}