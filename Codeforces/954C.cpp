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

bool check( int a, int b, int l ){
	int x1 = a%l,y1 = a/l;
	int x2 = b%l,y2 = b/l;

	int dis = abs( x1-x2 ) + abs( y1-y2 );

	if( dis==1 )
		return true;
	return false;

}


int32_t main(){
	fastio();

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]--;
	}

	int l=1,dis;
	for(int i=1;i<n;i++){


		dis = abs( a[i] - a[i-1] );
		if( dis==0 ){
			cout << "NO" << "\n";
			return 0;
		}
		if( dis!=1 ){
			if( l==-1 ){
				l=dis;
			}else if(l!=dis){
				cout << "NO" << "\n";
				return 0;
			}
		}
	}


	for(int i=1;i<n;i++){
		if( check( a[i-1] , a[i], l ) ==false){
			cout << "NO" << "\n";
			return 0;
		}
	}

	cout << "YES" << "\n";
	cout << 1000000000 << " " << l << "\n";



	return 0;
}




