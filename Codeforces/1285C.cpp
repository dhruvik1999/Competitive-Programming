#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007
#define maxlen 1000005

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}

int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
vector< pair<int,int> > ans;
void fact(int n,int t){
	
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if( i*i == n ){
				if( gcd(i,i)==1 )
					ans.push_back({i*t,i*t});
			}else{
				if( gcd( i,n/i )==1 )
					ans.push_back({i*t,(n/i)*t});
				//ans.push_back(n/i);
			}
		}
	}

}


int32_t main(){
	fastio();

	int n;
	cin >> n;

	//vector< pair<int,int> > ans = fact(n);
	
	
	for(int i=1;i<=sqrt(n);i++){
		if( n%i==0 ){
			fact( n/i , i  );
		}
	}

	int aa=n,ab=n,t=10000000000000;

	for(int i=0;i<ans.size();i++){
		if( t > max( ans[i].first , ans[i].second ) ){
			t = max( ans[i].first , ans[i].second );
			aa = ans[i].first;
			ab = ans[i].second;
		}
	}

	cout << aa << " " << ab << "\n";




	return 0;
}




