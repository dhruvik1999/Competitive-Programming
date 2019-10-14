#include<bits/stdc++.h>
using namespace std;
#define ll  long long

ll getVal( ll n ){

	ll k = 2;
	ll kkk=k*k*k;
	ll ans = 0;
	while( n/(kkk)!=0 ){

		ans += n/kkk;
		k++;
		kkk=k*k*k;
	}

	return ans;
}


int main(){


	ll m;
	cin >> m;

	ll l=1,r=LONG_LONG_MAX;
	ll mid;
	ll ans = LONG_LONG_MAX;
	//cout << getVal(54) << "\n";


	while(l<=r){
		mid = (l+r)>>1;

		if( getVal(mid)>=m ){

			ans = min( ans , mid );
			r=mid-1;
		}else{
			l=mid+1;
		}

	}

	//cout << getVal(1e15) << "\n";

	if( getVal(ans)!=m ){
		cout << -1 << "\n";
	}else{
		cout << ans  << "\n";
	}



	return 0;
}