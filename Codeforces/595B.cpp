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

int dig( int n ){
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = ans*10+9;
	}
	return ans;
}

int solve( int n, int k ){
	int ans = n;
	for(int i=1;i<k;i++){
		ans = ans*10;
	}
	return ans;
}

int32_t main(){
	fastio();	

	int n,k;
	cin >> n >> k;	

	vector<int> a(n/k),b(n/k);
	for(int i=0;i<n/k;i++){
		cin >> a[i];
	}
	for(int i=0;i<n/k;i++){
		cin >> b[i];
	}


	int ans = 1,nu = dig(k),nm=dig(k-1);
	int lans=0,error;
	for(int i=0;i<n/k;i++){
		lans = 0;
		error = solve( b[i] , k );
		int t = a[i] - error%a[i];

		lans = ( nu/a[i] +1) - ( (error%a[i]==0?1:0) + (nm)/a[i] + ( t<=(nm)%a[i]?1:0 ) );
		//cout << error << " " << ( (nm+1)/a[i] + ( t<=(nm+1)%a[i]?1:0 ) ) << " " << lans << "\n";
		ans = (( (ans%MOD) * (lans%MOD) )%MOD);
	}

	cout << ans << "\n";




	return 0;
}




