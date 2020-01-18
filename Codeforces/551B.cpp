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

	string f,p,q;
	cin >> f >> p >> q;

	int n,m,r;
	n=f.length();
	m=p.length();
	r=q.length();

	vector< int > s(26,0) , a(26,0) , b(26,0), ss(26,0);

	for(int i=0;i<n;i++){
		s[ f[i] - 'a' ] ++;
		ss[ f[i] - 'a' ] ++;

	}

	for(int i=0;i<m;i++){
		a[ p[i]-'a' ]++;
	}
	for(int i=0;i<r;i++){
		b[ q[i]-'a' ]++;
	}

	int a1=0,a2=0,l1,l2;
	bool lock= false;

	for(int i=0;i<=100000;i++){
		l1= 0;
		if(i!=0){
			for(int j=0;j<26;j++){
				s[j] -= a[j];
				if(s[j]<0){
					lock=true;
					break;
				}else{
					l1 = i;
				}
			}
		}


		if(lock)
			break;

		l2 = 100001;
		for(int j=0;j<26;j++){
			if( b[j]!=0 )
				l2 = min( l2 , (int)s[j]/b[j] );
			//cout << (s[j])/(b[j]) << "\n";
		}

		if( a1+a2 < l1+l2 ){
			a1=l1;
			a2=l2;
		}


	}

	for(int i=0;i<26;i++){
		ss[i] -= a1*a[i] + a2*b[i];
	}

	string ans = "";

	for(int i=0;i<a1;i++){
		ans+=p;
	}
	for(int i=0;i<a2;i++){
		ans+=q;
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<ss[i];j++){
			ans+= (char)( i+'a' ) ;
			//cout << (char)( i+'a' );
		}
	}
	//cout << "\n";

	cout << ans << "\n";


	return 0;
}




