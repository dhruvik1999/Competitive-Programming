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

int solve(vector<int> &a,int n){

	int ls=INT_MIN,gs1=INT_MIN,gs2=INT_MIN;

	for(int i=0;i<n-1;i++){
		ls = max( a[i] , ls+a[i] );
		gs1 = max( ls , gs1 );
	}

	ls = INT_MIN;

	for(int i=1;i<n;i++){
		ls = max( a[i] , ls+a[i] );
		gs2 = max( ls , gs2 );
	}

	return max( gs1,gs2 );





}

int32_t main(){
    fastio();

    int t;
    cin >> t;

    while(t--){
    	int n;
    	cin  >> n;

    	int s1=0,s2=0;
    	vector<int> a(n);
    	for(int i=0;i<n;i++){
    		cin >> a[i];
    		s1+=a[i];
    	}

    	s2 = solve( a , n );

    	if( s1 > s2 ){
    		cout << "YES" << "\n";
    	}else{
    		cout << "NO" <<"\n";
    	}





    }



    return 0;
}




