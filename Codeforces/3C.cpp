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


bool solve( vector< string > &a , char x ){
	int n = 3;
	vector< bool > ans(8,true);
	for(int i=0;i<n;i++){
		if( a[0][i]!=x ){
			ans[0]=false;
			break;
		}
	}

for(int i=0;i<n;i++){
		if( a[1][i]!=x ){
			ans[7]=false;
			break;
		}
	}


	for(int i=0;i<n;i++){

		if( a[2][i]!=x ){
			ans[1]=false;
			break;
		}
		
	}


	for(int i=0;i<n;i++){
		
		if( a[i][0]!=x ){
			ans[2]=false;
			break;
		}
	}


	for(int i=0;i<n;i++){
		
		if( a[i][2]!=x ){
			ans[3]=false;
			break;
		}
	}

	for(int i=0;i<n;i++){
		
		if( a[i][1]!=x ){
			ans[6]=false;
			break;
		}
	}


	for(int i=0;i<n;i++){
		
		if( a[i][i]!=x ){
			ans[4]=false;
			break;
		}
	}


	for(int i=0;i<n;i++){
		
		if( a[i][3-i-1]!=x ){
			ans[5]=false;
			break;
		}
	}

	for(int i=0;i<8;i++){
		if( ans[i] == true )
			return true;
	}
	return false;
}


int32_t main(){
	fastio();

	vector< string > a(3);
	for(int i=0;i<3;i++){
		cin >> a[i];
	}	

	int o=0,c=0;
	int n = 3;


	bool full = true;


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if( a[i][j] == '0' ){
				o++;
			}else if(a[i][j]=='X'){
				c++;
			}else{
				full=false;
			}
		}
	}

	bool fp = solve(a,'X');
	bool sp = solve(a,'0');

	if( o>c || c-o>1 || fp==true && sp==true || sp==true&&c!=o || fp==true&&c-1!=o ){
		cout << "illegal" << "\n";
		return 0;
	}

	
	if( sp==true ){
		cout << "the second player won" << "\n";
		return 0;

	}

	if(fp == true){
		cout << "the first player won" << "\n";
		return 0;
	}


	if( full==true ){
		cout << "draw" << "\n";
		return 0;
	}

	if(o<c){
		cout << "second" << "\n";
	}else{
		cout << "first" << "\n";
	}








	return 0;
}




