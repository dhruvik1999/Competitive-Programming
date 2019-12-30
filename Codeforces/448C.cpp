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

	int n;
	cin >> n;

	vector<int> a(n),b(n);
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i] = a[i];
		mp[a[i]]++;
	}

	sort(b.begin(),b.end());
	// for(int i=0;i<b.size();i++){
	// 	cout << b[i] << " ";
	// }
	// cout << "\n";
	b.erase( unique( b.begin() , b.end() ) , b.end() );
	int len = b.size();
	// for(int i=0;i<b.size();i++){
	// 	cout << b[i] << " ";
	// }
	//cout << "\n";
	vector<int> l(len),r(len);

	int pl = 0;
	for(int i=0;i<len;i++){
		int temp = 0;
		for(int j=0;j<n;j++){
			
				if( j==0 && a[j] >= b[i] || j!=0 && a[j-1]<b[i] && a[j]>=b[i]){
					temp++;
				}
			
		}
		// cout << i << " " << temp << "\n";
		l[i] = temp*(b[i]-pl);
		pl = b[i];
	}
	// cout << "\n";

	// for(int i=0;i<len;i++){
	// 	cout << l[i] << " ";
	// }
	// cout << "\n";

	//reverse( b.begin() , b.end() );

	for(int i=0;i<len;i++){
		r[i] = mp[b[i]];
	}

	
	r.push_back(0);

	for(int i=1;i<len;i++){
		l[i] += l[i-1];
		r[len-i-1] += r[len-i];
	}
	// for(int i=0;i<len;i++){
	// 	cout <<l[i] << " " << r[i] << "\n";
	// }
	int ans = r[0];
		//cout << ans << "\n";

	for(int i=0;i<len;i++){
		ans = min( ans , l[i] + r[i+1] );
		//cout << ans << "\n";
	}

	cout << ans << "\n";









	return 0;
}




