#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int i = 2;
	vector<int> prime;

	while(i*i<=n){
		if(n%i==0)
			prime.push_back(i);
		while( n%i==0 )
			n=n/i;
		i++;
	}

	if(n>1)
		prime.push_back(n);

	for(int i=0;i<prime.size();i++){
		cout << prime[i] << " ";
	}
	cout << "\n";


	return 0;
}