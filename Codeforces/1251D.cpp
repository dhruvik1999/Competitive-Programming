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

bool solve( vector< pair<int,int> > &a , int n, int mid, int s ){

	vector< pair<int,int> > b;
	int p=0,q=0,r=0;
	for(int i=0;i<n;i++){
		if( a[i].second < mid ){
			s-=a[i].first;
			p++;
		}else if( a[i].first > mid ){
			s-=a[i].first;
			q++;
		}else{
			b.push_back(a[i]);
			r++;
		}
	}

	if( p>n/2 || q>n/2 || s<0 ){
		return false;
	}


	for(int i=0;i<b.size();i++){
		if(p+i+1<=n/2){
			s-=b[i].first;
		}else{
			s-=mid;
		}
	}

	if(s>=0)
		return true;
	return false;

}


int32_t main(){
	fastio();

	int t;
	cin >> t;

	while(t--){
		int n,s;
		cin >> n >> s;
		vector< pair<int,int> > a;
		int p,q;

		for(int i=0;i<n;i++){
			cin >> p >> q;
			a.push_back( {p,q} );
		}

		sort( a.begin() , a.end() );


		int l= a[n/2].first ,r=1000000000;
		int ans=a[n/2].first,mid;
		while(l<=r){
			mid = (l+r)>>1;

			if( solve(  a, n,  mid, s ) == true ){
				ans = mid;
				l=mid+1;
			}else{
				r=mid-1;
			}

		}

		cout << ans << "\n";


	}




	return 0;
}




