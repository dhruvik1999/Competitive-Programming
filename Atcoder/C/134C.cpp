#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int fm=0,sm=0,mf=0;

	for(int i=0;i<n;i++){

		if(a[i]==fm){
			mf++;
		}

		if(a[i]>fm){
			mf=1;
			sm=fm;
			fm=a[i];
		}else if(fm!= a[i] && a[i]>sm){
			sm=a[i];
		}



	}

	for(int i=0;i<n;i++){
		if(a[i]!=fm || a[i]==fm && mf!=1){
			cout << fm <<"\n";
		}else{
			cout << sm << "\n";
		}
	}


	return 0;
}