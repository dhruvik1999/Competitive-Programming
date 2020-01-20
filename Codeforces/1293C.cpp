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

	int n,m;
	cin >> n >> m;

	int p,q;
	vector< vector<int> > dp( 2 , vector<int>(n,0) );

	vector<int> count( 10 , 0 );
	count[0] = 2*n;
			int temp;

	for(int i=0;i<m;i++){
		cin >> p >> q;
		p--;
		q--;

		//cout << p << " " << q << "\n";
		if( dp[p][q]==0 ){
			count[ dp[p][q] ]--;

			temp = 0;
			for(int j=max(q-1,0LL);j<n&&j<=q+1;j++){
				//cout << (q+1)%2 <<  " " << j << "\n"; 
				if( dp[(p+1)%2][j]!=0 ){
					//cout << "*" << "\n";
					temp++;
					count[ dp[(p+1)%2][j] ]--;
					dp[(p+1)%2][j]++;
					count[ dp[(p+1)%2][j] ]++;
				}
			}

			dp[p][q]=temp+1;
			count[ dp[p][q] ]++;

		}else{
			count[ dp[p][q] ]--;
			dp[p][q]=0;
			count[ 0 ]++;

			for(int j=max(q-1,0LL);j<n&&j<=q+1;j++){
				if( dp[(p+1)%2][j]!=0 ){
					count[ dp[(p+1)%2][j] ]--;
					dp[(p+1)%2][j]--;
					count[ dp[(p+1)%2][j] ]++;
				}
			}

		}

		bool check = true;

		for(int j=2;j<10;j++){
			if(count[j]!=0){
				check = false;
				cout << "No" << "\n";
				break;
			}
		}

		// for(int y=0;y<2;y++){
		// 	for(int yy=0;yy<n;yy++){
		// 		cout << dp[y][yy] << " ";
		// 	}
		// 	cout << "\n";
		// }

	//	cout << "\n\n";

		if( check ){
			cout << "Yes" << "\n";	
		}

	}



	return 0;
}




