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
	
	string s;
	cin >> s;

	int n = s.length();
	vector<int> frq(26,0);
	string uw = "";

	for(int i=0;i<n;i++){
		frq[ s[i]-'a' ]++;
	}
	string l="",m="",r="";


	for(int i=0;i<26;i++){
		if( frq[i]%2!=0 ){
			uw+=(char)('a'+i);
		}
			for(int j=0;j<frq[i]/2;j++){
				l+=(char)('a'+i);
			}
		
	}

	//cout << uw << "\n";

	sort( uw.begin() , uw.end() );

	if(n%2==1){
		m=uw[uw.length()/2];
	}
	for(int i=0;i<uw.length()/2;i++){
		l+=uw[i];
	}
	sort(l.begin(),l.end());
	r=l;
	reverse(r.begin(),r.end());
	cout << l+m+r << "\n";

	return 0;
}




