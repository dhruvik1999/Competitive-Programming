#include<bits/stdc++.h>
using namespace std;

int main(){

	vector<int> a(4);
	int sum = 0;
	int n = 4;

	for(int i=0;i<4;i++){
		cin >> a[i];
		sum+=a[i];
	}

	if(sum%2!=0){

		cout << "NO" << "\n";
		return 0;
	}

	for(int i=0;i<n;i++){
		if(a[i]==sum/2){
			cout << "YES" << "\n";
			return 0;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(a[i]+a[j]==sum/2){
					cout << "YES" << "\n";
					return 0;
				}
			}
		}
	}


	cout << "NO" << "\n";




	return 0;
}