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
	 
		int n,x,y;
		cin >> n >> x >> y;
	 
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
	 
	 	map< double , int > dp;
	 	vector< double > vp;
	 	for(int i=1;i<=x;i++){
	 		dp[ ((double)i/x) ] = 1;
	 		vp.push_back( ( (double)i/x ) );
	 		//cout << ((double)i/x) << " ";
	 	}
	 //	cout << "\n";

	 	for(int j=1;j<=y;j++){
	 		if( dp.find( ((double)j/y) ) == dp.end() ){
	 			dp[ ((double)j/y) ] = 2;
	 		}else{
	 			dp[ ((double)j/y) ] = 3;
	 		}
	 		vp.push_back( ( (double)j/y ) );
	 		//cout << (double)j/y << " ";
	 	}
	 	//cout << "\n\n";

	 	sort( vp.begin() , vp.end() );

	 	int len = vp.size();

	 	for(int i=0;i<n;i++){
	 		a[i]--;

	 		if( dp[ vp[ a[i]%len ] ]==1 ){
	 			cout << "Vanya" << "\n";
	 		}else if(dp[ vp[ a[i]%len ] ]==2){
	 			cout << "Vova" << "\n";
	 		}else{
	 			cout << "Both" << "\n";
	 		}

	 	}

	 
		return 0;
	}
	 