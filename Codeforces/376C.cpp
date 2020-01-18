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

vector< int > rempow(10);
map< int , string > mp;

void preProc(){

	int a = 1;
	for(int i=0;i<10;i++){
		rempow[ i ] = a%7;
		a=a*10;
		cout << i << " " << rempow[i] << "\n";
	}

	string t = "1689";

	for(int i=0;i<24;i++){
		mp[ stoi(t)%7 ]=t;
		next_permutation( t.begin() , t.end() );
	}

	// for( auto i : mp ){
	// 	cout << i.first << " " << i.second << "\n";
	// }

}



int32_t main(){
	fastio();

	preProc();

	string s;
	cin >> s;

	vector< int > a(10,0);
	int n = s.length();

	string ans = "";
	int zero = 0;

	int p1=-1,p6=-1,p8=-1,p9=-1;

	for(int i=0;i<n;i++){
		if( s[i]=='1' ){
			p1=i;
		}else if( s[i]=='6' ){
			p6=i;
		}else if( s[i]=='8' ){
			p8=i;
		}else if( s[i]=='9' ){
			p9=i;
		}
	}
	string zz = "";

	for(int i=0;i<n;i++){
		if( s[i]=='0' ){
			zz +="0";
			zero++;
			continue;
		}
		if(i!=p1 && i!=p6 && i!=p8 && i!=p9  ){
			ans+=s[i];
		}	
	}

	cout << ans << "\n";

	int pos = ans.size()-1+4;
	int rem = 0;
	for(int i=0;i<ans.size();i++){
		rem += (  ( ( ans[i]%7 )*( rempow[pos%6]%7 ) )%7 )%7;
		pos--;
	}
	rem = rem%7;

	cout << rem << " " << mp[ (7-rem)%7 ] << "\n";

	ans = ans + mp[ (7-rem)%7 ] + zz;
	cout << ans << "\n";












	return 0;
}




