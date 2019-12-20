#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod  1000000007

#define plen 100000
vector<ll> prime;

void seive(ll x){
	int i = 2;

	while(i*i<=x){
		if(x%i==0){
			prime.push_back(i);

			while(x%i==0){
				x=x/i;
			}
		}
		i++;
	}

	if(x>1)
		prime.push_back(x);
}

ll modpow(ll a,ll b){
	if(b==0)
		return 1;

	if(b%2==0){
		ll p = modpow(a,b/2)%mod;
		return (p*p)%mod;
	}else{
		return ((modpow(a,b-1)%mod)*a%mod)%mod;
	}
}

ll getPow(ll n,ll a){
	ll ans = 0;
	while(n){
		ans += n/a;
		n=n/a;
	}

	return ans;
}


void getWork(){

	ll x,n;
	cin >> x >> n;
	//cout << x << " "<< n << "\n";

	vector<ll> fact;
	seive(x);
   


	for(ll i=0;i<prime.size();i++){
		if( prime[i]<=x ){
			if(x%prime[i]==0){
			if( prime[i]*prime[i]!=x ){
				fact.push_back(prime[i]);
				//fact.push_back(x/prime[i]);
			}else{
				fact.push_back(prime[i]);

			}
			}
		}else{
			break;
		}
	}

	if(fact.size()==0 && x!=1){
		fact.push_back(x);
	}


	ll ans = 1,t;

	for(ll i=0;i<fact.size();i++){
		//cout << "&" << "\n";
		//cout << fact[i] << "\n";
		t = getPow(n,fact[i]);
		ans = (ans%mod*modpow(fact[i],t)%mod)%mod;
	}

	cout << ans << "\n";

}


int main(){

    // << "^" << "\n";	

    getWork();
    return 0;
}