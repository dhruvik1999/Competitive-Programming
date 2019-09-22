#include<bits/stdc++.h>
using namespace std;

int main(){

	long long ll,rr;
	cin >> ll>> rr;

	

	long long l=INT_MAX,r=0;

	for(int i=0;i<2020;i++){
		if(i+ll>rr)
			break;

		if(l>(i+ll)%2019){
			l=(i+ll)%2019;
		}

	}

	for(int i=0;i<2020;i++){
		if(rr-i<ll)
			break;

		if(r<(rr-i)%2019){
			r=(rr-i)%2019;
		}

	}


	long long ans = INT_MAX;
	for(int i=l;i<r;i++){
		for(int j=i+1;j<=r;j++){
			if(ans > (i*j)%2019){
				ans = (i*j)%2019;
			}
		}
	}

	cout << ans << "\n";


	return 0;
}