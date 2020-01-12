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

int32_t main(){
	fastio();

	int n,a,b;
	cin >> n >> a >> b;

	int p = min(a,b);
	int q = max(a,b);

	if( p!=1 || q>n || (n==3||n==2) && p==1 && q==1 ){
		cout << "NO" << "\n";
		return 0;
	}

	vector< vector<int> > graph( n , vector<int>(n,0) );

	int comp = n,t=1;
	for(int i=0;i<n-1;i++){
		if( comp == q ){
			break;
		}else{
			graph[i][i+1]=1;
			graph[i+1][i]=1;
			comp--;
		}
	}

	if( q==a ){
		cout << "YES" << "\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << graph[i][j] ;
			}
			cout << "\n";
		}
	}else{
		cout  << "YES" << "\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if( i==j ){
					cout << 0 ;
				}else if( graph[i][j]==0 ){
					cout << 1 ;
				}else{
					cout << 0 ;
				}
			}
			cout << "\n";
		}
	}



	return 0;
}




