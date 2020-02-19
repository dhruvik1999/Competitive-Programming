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

	int n;
	cin >> n;
	int s1=0,s2=0;


	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		s1+=a[i];
	}

	int m;
	cin >> m;

	vector<int> b(m);
	for(int i=0;i<m;i++){
		cin >> b[i];
		s2+=b[i];
	}
	if( s1!=s2 ){
		cout << -1 << "\n";
		return 0;
	}
	int p=0,q=0;
	int sum = s1;

	vector<int> a1,a2;

	while(p<n && q<m){
		if( a[p] == b[q] ){
			a1.push_back(a[p]);
			a2.push_back(b[q]);

			//cout << a[p] << " " << b[q] << "\n";
			p++;
			q++;
		}else{
			s1=a[p];
			s2=b[q];
			while( p<n && q<m && s1 != s2 ){
			//cout << s1 <<" " << s2 << "\n";

				if(s1<s2){
					p++;
					if(p<n)
						s1+=a[p];
				}else{
					//cout << "*" << "\n";
					q++;
					if(q<m)
						s2+=b[q];
				}
				//cout << s1 << " " << s2 << "\n";
			}

			if(s1!=s2){
				cout << -1 << "\n";
				return 0;
			}else{
				a1.push_back(s1);
				a2.push_back(s2);
				//cout << s1 << " " << s2 << "\n";
				p++;
				q++;
			}
		}
	}

	// for(auto i : a2){
	// 	cout << i << "\n";
	// }



	for(int i=0;i<a1.size();i++){
		sum-=a1[i];
	}

	if(sum==0){
		cout << a1.size() << "\n";
	}else{
		cout << -1 << "\n";
	}
	

	return 0;
}