#include<bits/stdc++.h>
using namespace std;

int main(){

	long long t;
	cin >> t;

	while(t--){
		long long n;
		cin >> n;

		long long sum = 0;
		long long tt;
		for(long long i=0;i<n;i++){
			cin >> tt;

			sum+=tt;
		}

		if(sum%n==0){
			cout << sum/n << "\n";
		}else{
			cout << (sum/n)+1 << "\n";
		}

	}
 
	return 0;
}