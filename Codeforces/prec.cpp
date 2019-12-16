#include<bits/stdc++.h>
using namespace std;

int main(){

	

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int lsum=0,gsum=0;
	int l=-1,r=-1,ll =-1;
	for(int i=0;i<n;i++){

		if( lsum+a[i] <= a[i] ){
			ll = i;
			lsum=a[i];
		}else{
			lsum+=a[i];
		}

		if(gsum < lsum){
			l=ll;
			r=i;
			gsum=lsum;
		}

	}

	cout  << gsum << "\n";
	cout << l << " " << r << "\n";



	return 0;
}