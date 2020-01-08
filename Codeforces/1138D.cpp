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

bool check( string t, int mid, int m ){
	for(int i=0;i<mid;i++){
		if( t[m-1-i] != t[mid-1-i] ){
			return false;
		}
	}
	return true;
}

int32_t main(){
	fastio();

	string s,t;
	cin >> s >> t;

	int n,m;
	n = s.length();
	m = t.length();

	int l=0,r=m-1;

	int mid,pref=0;

	vector<string> ss(m+1);
	string tt="";

	for(int i=m-1;i>=0;i--){
		tt=t[i] + tt;
		ss[m-1-i]=tt;
	}

	tt = "";
	for(int i=0;i<m-1;i++){
		tt += t[i];
		if( ss[i] == tt){
			pref = i+1;
		}
	}

	int no=0,nz=0,tno=0,tnz=0;

	for(int i=0;i<n;i++){
		if( s[i]=='1' ){
			no++;
		}else{
			nz++;
		}
	}

	for(int i=0;i<m;i++){
		if( t[i]=='1' ){
			tno++;
		}else{
			tnz++;
		}
	}

	string offset = "";
	for(int i=pref;i<m;i++){
		offset += t[i];
	}
	//cout << offset << "\n";
	string ans = "";

	if( no>=tno && nz>=tnz ){
		ans = t;

		no-=tno;
		nz-=tnz;

		tno=0;
		tnz=0;

		for(int i=0;i<offset.length();i++){
			if( offset[i]=='1' ){
				tno++;
			}else{
				tnz++;
			}
		}

		while( no>= tno && nz>=tnz ){
			no-=tno;
			nz-=tnz;			

			ans+=offset;

		}

		for(int i=0;i<no;i++){
			ans+="1";
		}

		for(int i=0;i<nz;i++){
			ans+="0";
		}

		cout << ans << "\n";

	}else{
		string aa = s;
		sort(s.begin(),s.end());
		if( aa == s ){
			reverse(s.begin(),s.end());
		}
		cout << s << "\n";
		return 0;
	}


	return 0;
}




