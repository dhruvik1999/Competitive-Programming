#include<bits/stdc++.h>
using namespace std;
#define ll long long

string con(ll n){
	string ans = "";
	while(n!=0){
		ans = ((char)('0'+n%2))+ans;
		n=n/2;
	}

	return ans;
}


ll doWork(ll a){
	a++;
	ll ans = 0;
	ll t;
	for(ll i=0;i<62;i++){
		t = (a/(1LL<<(i+1)))*(1LL<<i);
		t+= max(0LL,a%(1LL<<(i+1))-((1LL<<(i+1))>>1));

		if(t%2==1){
			ans = ans | (1LL<<i);
		}
	}

	//cout << con(ans) << "\n";
	return ans;
}


int main(){

	ll l,r;
	cin >> l >> r;

	ll t1 = doWork(min(l,r)-1);
	ll t2 = doWork(max(l,r));


	cout << (t1^t2) << "\n";



	return 0;
}