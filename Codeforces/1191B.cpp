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

int check(vector<string> s,string t1,string t2,string t3){
	int ans = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]==t1){
			s.erase( s.begin()+i );
			ans++;
			break;
		}
	}


	for(int i=0;i<s.size();i++){
		if(s[i]==t2){
			s.erase( s.begin()+i );
			ans++;
			break;
		}
	}


	for(int i=0;i<s.size();i++){
		if(s[i]==t3){
			s.erase( s.begin()+i );
			ans++;
			break;
		}
	}
	return 3-ans;
}

int32_t main(){
	fastio();

	vector<string> s(3);
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	s.push_back(s1);
	s.push_back(s2);
	s.push_back(s3);


	string p = "";
	int ans = 2;
	for(int i=0;i<3;i++){
		if(i==0){
			p="m";
		}else if(i==1){
			p="p";
		}else{
			p="s";
		}
		for(int i=1;i<=9;i++){
			ans = min( ans , check(s, ((char)('0'+i)+p),((char)('0'+i)+p),((char)('0'+i)+p) )  );
		}

		for(int i=1;i<=7;i++){
			ans = min( ans , check(s, ((char)('0'+i)+p),((char)('0'+i+1)+p),((char)('0'+i+2)+p) )  );
		}
	}
	cout << ans << "\n";


	return 0;
}




