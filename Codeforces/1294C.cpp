#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define maxlen 9223372036854775807
#define minlen -9223372036854775807

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}


pair<int,int> solve( int n , int a1 ){
		pair<int,int> ans;
		//int t = 

	for(int i=2;i<=(int)sqrt( n ) ; i++){
		if( n%i==0 ){
			if( i!=n/i && i!=a1 && n/i!=a1 ){
				ans = {i,n/i};
				return ans;
			}
		}
	}

	ans = {-1,-1};

	return ans;
}


int32_t main(){
	//fastio();

	//cout << pow( 64 , 1/3 ) << "\n";
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int a1,a2,a3;
	pair<int,int> ans;
	bool lock = true;


		for(int i=2;i<=1000;i++){
			if( n%i==0 ){
				a1=-1;
				a1 = i;

				ans = solve(n/i , a1);
				if( ans.first!=-1 ){
					cout << "YES" << "\n";
					cout << a1 << " " << ans.first << " " << ans.second << "\n";
					lock = false;
					break;
				}
			}
		}

		if(lock){
			cout << "NO" << "\n";
					}



	}




	

	return 0;
}




