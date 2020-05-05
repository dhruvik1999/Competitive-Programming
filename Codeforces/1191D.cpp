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

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a.begin(),a.end());

	int t=0;
	for(int i=0;i<n-1;i++){
		if( a[i] == a[i+1] ){
			t++;
		}
	}

	if( t>=2 || ( n>=2&&a[0]==0&&a[1]==0 ) ){
		cout << "cslnb" << "\n";
		return 0;
	}

	int ans = 0;

	for(int j=n-2;j>=0;j--){
		if(j==0){
			if(a[j]==a[j+1]){
				a[j]--;
				ans++;
			}
		}else{
			if( a[j]==a[j+1] && a[j-1]+1==a[j] ){
				if(ans%2==0){
		cout << "cslnb" << "\n";
	}else{
		cout << "sjfnb" << "\n";
	}
	return 0;
				// break;
			}else if(a[j]==a[j+1]){
				a[j]--;
				ans++;
			}
		}
	}

	for(int i=0;i<n;i++){
		ans+= (i-a[i]);
	}

	if(ans%2==0){
		cout << "cslnb" << "\n";
	}else{
		cout << "sjfnb" << "\n";
	}


	return 0;
}