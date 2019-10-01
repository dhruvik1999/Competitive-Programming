	#include<bits/stdc++.h>
	using namespace std;

	#define ll long long

	#define mod 1000009

	vector<long long> prime;
	vector<long long> num(mod,1);

	void sive(){
		long long n = (long long)sqrt(mod);

		for(long long i=2;i<=n;i++){
			if(num[i]==1){
				for(long long j=i*i;j<mod;j+=i){
					num[j]=0;
				}
			}
		}

		for(long long i=2;i<mod;i++){
			if(num[i]==1){
				prime.push_back(i);
			}
		}
	}

	long long findAns(ll n){

		long long ind=0,pf=prime[ind];
		long long ans = 0;
		while(pf*pf<=n){
			if(n%pf==0)
				ans++;

			while(n%pf==0)
				n=n/pf;

			ind++;
			pf=prime[ind];
		}	

		if(n!=1)
			ans++;

		return ans;




	}


	int main(){

		ll a,b;
		sive();

		// for(long long i=0;i<100;i++){
		// 	cout << i << " " << prime[i] << "\n";
		// }

		cin >> a >> b;
		a = __gcd(a,b);

		cout  << findAns(a)+1 << "\n";






	}