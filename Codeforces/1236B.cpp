#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod  1000000007

ll po( ll x, ll n ){
	if(n==0)
		return 1;
	if( n%2==0 ){
		ll p = po(x,n/2)%mod;
		return (p*p)%mod;
	}else{
		return ((po(x,n-1)%mod)*x%mod)%mod;
	}

}



int  main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin >> n >> m;

    ll ans = 0;

  //   ans = po(2,n*m)%mod;
  //   cout << ans << "\n";

  //   ans = ( ans%mod - ((n)%mod*po(2,(n-1)*m)%mod)%mod )%mod;

  // //  ans = ( ans+1 )%mod;

  //   if(ans<0){
  //   	ans+=mod;
  //   }
  //   cout << ans << "\n";

    ans = (po( 2,m )%mod-1)%mod;
    if(ans<0)
    	ans+=mod;
    ans = po( ans,n )%mod;
    cout << ans%mod << "\n";


    
  
    return 0;
}
