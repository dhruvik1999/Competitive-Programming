#include<bits/stdc++.h>
using namespace std;

vector<long long > prime;

void seive(){
	long long  n = 100000;
	vector< bool > mark(n+10 , true);
	mark[1]=false;

	for(long long  i=2;i<=n;i++){
		if(mark[i]==false)
			continue;
	//	cout << i << "\n";
		for(long long  j=i*i;j<=n;j+=i){
			mark[j]=false;
		}
	}
	//cout << "*" << "\n";

	for(long long  i=2;i<=n;i++){
		if( mark[i]==true ){
			prime.push_back(i);
		}
	}
}


int  main(){

	long long  t;
	cin >> t;
	seive();

	// for (long long  i = 0; i < prime.size(); ++i)
	// {
	// 	/* code */
	// 	cout << prime[i] << " ";
	// }
	//cout << "\n";
	long long  l,r;
	while(t--){
		cin >> l >> r;

		for(long long  i=l;i<=r;i++){
			bool lock = true;
			for(long long  j=0;prime[j]*prime[j]<=i;j++){
				if(i%prime[j]==0){
					lock=false;
					break;
				}
			}
			if(lock && i!=1){
				cout  << i << "\n";
			}
		}
		cout << "\n";



	}


	return 0;
}