#include<bits/stdc++.h>
using namespace std;

vector<int> fact;
void doWork(int n){
	int lim = ceil(sqrt(n));
	//fact.push_back(1);
	for(int i=1;i<=lim;i++){
		if( n%i==0 ){

			if( n==i*i ){
				fact.push_back(i);
			}else{
				fact.push_back(i);
				fact.push_back(n/i);
			}


		}
	}
	//fact.push_back(n);
}


int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	doWork(n);
	sort(fact.begin(),fact.end());

	for(int i=0;i<fact.size();i++){
			//cout << fact[i] << "\n";

		if( n/fact[i]>2 ){
			//cout << "*" << "\n";
			vector<int> dim(fact[i],1);
			for(int j=0;j<n;j++){
				if( dim[j%fact[i]]==1 ){
					dim[j%fact[i]] = a[j];
				}
			}
			bool ans = false;
			for(int j=0;j<fact[i];j++){
				if( dim[j]==1 ){
					ans = true;
					break;
				}
			}
			if( ans ){
				cout  << "YES" << "\n";
				return 0;
			}
		}
	}

	cout << "NO" << "\n";






	return 0;
}