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

bool comparator(string a,string b){
	
	string ans1=a+b,ans2=b+a;
	int n = ans1.length();

	int s1=0,s2=0,c1=0,c2=0;
	for(int i=0;i<n;i++){
		if( ans1[i]=='s' ){
			s1++;
		}else{
			c1+=s1;
		}
	}

	for(int i=0;i<n;i++){
		if( ans2[i]=='s' ){
			s2++;
		}else{
			c2+=s2;
		}
	}

	if( c1>c2 ){
		return true;
	}
	return false;

}

int32_t main(){
	fastio();

	int n;
	cin >> n;

	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort( a.begin() , a.end() , comparator );

	int ans = 0,s=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].size();j++){
			if( a[i][j] == 's' ){
				s++;
			}else{
				ans+=s;
			}
		}
	}

	cout << ans << "\n";






	return 0;
}




