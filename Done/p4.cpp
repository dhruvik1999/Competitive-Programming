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

	map< pair<int,int> , pair<int,int> > mp,mp2;

	vector< pair<int,int>  > a,b; 

	int p,q,r,s;
	for(int i=0;i<n;i++){
		cin >> p >> q >> r >> s;
		mp[ {p,q} ] = {r,s};
		mp2[ {r,s} ] = {p,q};
		a.push_back( {p,q} );
		b.push_back( {r,s} );
	}

	vector< pair<int,int> > t1[n+1],t2[n+1];

	sort( a.begin() , a.end() );

	int pos = 0;
	map< pair<int,int> , int > m2,m1;

	for(int i=0;i<n;i++){
			while( t1[pos].size()!=0 && max( t1[pos].back().first,a[i].first ) <= min( t1[pos].back().second,a[i].second ) ){
				pos++;
			}
			t1[pos].push_back(a[i]);
			m1[ a[i] ] = pos;

	}


	for(int i=0;i<=pos;i++){
		for(int j=0;j<t1[pos].size();j++){
			cout << t1[i][j].first << " " << t1[i][j].second <<  "\n";
		}
		//m1[ t1[i][j] ] = pos;
		cout << "\n";
	}


	int pos2 = 0;
	for(int i=0;i<=pos;i++){
		for(int j=0;j<t1[pos].size();j++){
			

			while( t2[pos2].size()!=0 && max( t2[pos2].back().first,mp[t1[i][j]].first ) <= min( t2[pos2].back().second,mp[t1[i][j]].second ) ){
				pos2++;
			}
			t2[pos2].push_back(mp[t1[i][j]]);
			m2[ mp[t1[i][j]] ] = pos2;


		}
	}

	// for(int i=0;i<=pos;i++){
	// 	for(int j=0;j<t2[pos].size();j++){
	// 		cout << t2[i][j].first << " " << t1[i][j].second <<  "\n";
	// 	}
	// 	//m1[ t1[i][j] ] = pos;
	// 	cout << "\n";
	// }


			
	

	bool ans = true;
	int check;
	for(int i=0;i<=pos;i++){
		for(int j=0;j<t1[i].size();j++){
			if( j==0 ){
				check = m2[ mp[ t1[i][j] ] ];
			}else{
				if( check != m2[ mp[ t1[i][j] ] ] ){
					ans = false;
					//cout << "*" << "\n";

					cout << "NO" << "\n";
					return 0;
				}
			}
		}
	}

	for(int i=0;i<=pos2;i++){
		for(int j=0;j<t2[i].size();j++){
			if( j==0 ){
				check = m1[ mp2[ t2[i][j] ] ];
			}else{
				if( check != m1[ mp2[ t2[i][j] ] ] ){
					ans = false;
					cout << "NO" << "\n";
					return 0;
				}
			}
		}
	}

	cout << "YES" << "\n";







	return 0;
}




