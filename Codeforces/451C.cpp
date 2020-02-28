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

bool check( vector< int > *prob, int n, int k, int tc){
	vector<int> a = prob[tc];

	int sum = 0;
	for(int i=0;i<3;i++){
		sum+=a[i];
	}

	if( sum > k ){
		return false;
	}else if(sum==k){
		int mm = max( a[0] , max( a[1] , a[2] ) );
		n-=k;
		n-=(mm-a[0]);
		n-=(mm-a[1]);
		n-=(mm-a[2]);

		if(n%3==0){
			return true;
		}else{
			return false;
		}
	}else{
		k-=sum;
		if(k%3==0){
			int mm = max( a[0] , max( a[1] , a[2] ) );
		n-=k;
		n-=(mm-a[0]);
		n-=(mm-a[1]);
		n-=(mm-a[2]);

		if(n%3==0){
			return true;
		}else{
			return false;
		}
		}else{
			return false;
		}
	}
}


int32_t main(){
	fastio();

	int t;
	cin >> t;

	while(t--){
		int n,k,d1,d2;
		cin >> n >> k >> d1 >> d2;

		vector<int> prob[4];
		for(int i=0;i<4;i++){
			for(int j=0;j<3;j++){
				prob[i].push_back(0);
			}
		}

		prob[0][0]=d1+d2;
		prob[0][1]=d2;
		prob[0][2]=0;

		prob[1][0]=d1;
		prob[1][1]=0;
		prob[1][2]=d2;

		 prob[2][0]=0;
		 prob[2][1]=d1;
		 prob[2][2]=d1-d2;
		 if(prob[2][2]<0){
		 	prob[2][0]+=-1*prob[2][2];
		 	prob[2][1]+=-1*prob[2][2];
		 	prob[2][2]+=-1*prob[2][2];
		 }

		prob[3][0]=0;
		prob[3][1]=d1;
		prob[3][2]=d1+d2;

		int sum = 0;

		bool ans = false;
		for(int i=0;i<4;i++){
			ans = ans || check(prob,n,k,i);
		}

		if(ans){
			cout << "Yes" << "\n";
		}else{
			cout << "No" << "\n";
		}



	}

	
	return 0;
}