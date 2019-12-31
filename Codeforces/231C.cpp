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

bool check( vector<int> &a, int mid, int s ){
	int n = a.size();
	int ls = 0;
	for(int i=0;i<mid;i++){
		ls+= a[i];
	}
	int l=0,r=mid-1;
	while(r<n){

		if( mid*(a[r])-ls <= s ){
			return true;
		}

		r++;
		if(r!=n){
			ls+=a[r];
		}
		ls-=a[l];
		l++;

	}

	return false;
}



int32_t main(){
	fastio();

	int n,s;
	cin >> n >> s;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());

	int l=1,r=n;
	int mid,ans;

	while(l<=r){
		mid = (l+r)>>1;
		if( check(a,mid,s) ){
			ans = mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}

	//cout << ans << "\n";
	int ls = 0;
	r=ans-1;
	for(l=0;l<=r;l++){
		ls+=a[l];
	}	
	l=0;
	r=ans-1;
	while(r<n){
		//cout << ans << " " << ls << "\n";
		//cout << a[l] << " " << a[r] << " " << ls <<  "\n";
		if( ans*a[r]-ls <= s ){
			cout << ans << " " << a[r] << "\n";
			return 0;
		}
		r++;
		if(r<n){
			ls+=a[r];
		}
		ls-=a[l];
		l++;
	}



	return 0;
}




