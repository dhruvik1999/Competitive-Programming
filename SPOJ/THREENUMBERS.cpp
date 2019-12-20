#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a,ll b){
	if( b==0 )
		return a;

	return gcd(b,a%b);
}


bool func(ll n,ll num,ll a,ll b){
	ll t = num/b + num/a - num/((a*b)/gcd(a,b));
	//cout << "T : " << t << "\n";
	if( t>=n ){
		return true;
	}else{
		return false;
	}
}
int main(){

	ll t;
	cin >> t;

	while(t--){

		ll a,b,n;
		cin >> a >> b  >> n;

		ll l=1,r=LONG_LONG_MAX-1;
		ll ans = -1;	

		//cout << func(n,15,a,b) << "\n";
		while(l<=r){
			ll mid = (l+r)>>1;
			//cout << mid << "\n";
			if( func(n,mid,a,b) ){
				//cout << mid  << "\n";
				ans = mid;
				//cout << mid << "\n";
				r=mid-1;
			}else{
				l=mid+1;
			}
		}


		cout <<  ans << "\n";

	}


	return 0;
}