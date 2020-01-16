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

	int n;
	cin >> n;

	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i] = a[i];
	}

	sort(a.begin(),a.end());
	a.erase( unique( a.begin() , a.end() ) , a.end() );

	unordered_set<int> s;
	for(int i=0;i<a.size();i++){
		s.insert( a[i] );
	}
	int ansl =0 ;
	for(int i=2;i<=n;i++){
		if( s.find( i-1 ) != s.end() && s.find( i+1 ) != s.end() ){
			ansl++;
			//cout << "&" << "\n";
			s.erase( s.find( i-1 ) );
			s.erase( s.find( i+1 ) );

			if( s.find( i ) != s.end() ){
				s.erase( s.find(i) );
			}
		}else if( s.find(i-1)!=s.end() && s.find(i)!=s.end() ){
			ansl++;
			//cout << "*" << "\n";
			s.erase( s.find(i-1) );
			s.erase( s.find(i) );
		}
	}

	ansl+= s.size();

	s.clear();

	vector<int> frq( n+10 , 0 );
	for(int i=0;i<n;i++){
		frq[ b[i] ] ++;
	}

	int ansr = 0;
	for(int i=0;i<=n+1;i++){
		if( i==0 ){
			if( frq[ i+1 ]!=0 ){
				frq[ i+1 ]--;
				s.insert(i);				
			}
		}else if( i==n+1 ){
			if( frq[ n ]!=0 ){
				frq[n]--;
				s.insert(i);
			}
		}else{
			if( frq[i]!=0 ){
				frq[i]--;
				s.insert(i);
			}else if( frq[i-1]!=0 ){
				frq[i-1]--;
				s.insert(i);
			}else if( frq[i+1]!=0 ){
				frq[i+1]--;
				s.insert(i);
			}
		}
	}

	cout << ansl << " " << s.size()  << "\n";



	return 0;
}




