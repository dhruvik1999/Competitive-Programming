#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ll sum=0,xr=0;

	cin >> sum >> xr;

	vector<ll> a,b;
	for(int i=0;i<62;i++){
		if( ((sum)>>i)&1==1 ){
			a.push_back(1);
		}else{
			a.push_back(0);
		}

		if( ((xr)>>i)&1==1 ){
			b.push_back(1);
		}else{
			b.push_back(0);
		}
	}

	ll check = 0;
	ll ans = 0;
	bool lock= true;

	for(int i=0;i<62;i++){
		if(a[i]==1&&b[i]==1 || a[i]==0&&b[i]==0){
			if(a[i]==1&&b[i]==1)
				check=0;
			else
				check=1;
		}else{
			if(check==0){
				ans=0;
				lock=false;
				break;
			}else{
				check=1;
			}
		}
		if(b[i]==1){
			if(ans==0){
				ans+=2;
			}else{
				ans = ans*2;
			}
		}
	}


	if(lock && xr==0){
		ans+=2;
	}

	if(sum==xr && ans>=2){
		ans-=2;
	}

	if( sum%2==0&&( ((sum/2)^(sum/2))==xr) && ans>0){
		ans--;
	}


	cout  << ans << "\n";


	return 0;
}