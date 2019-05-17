#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];


	int ans = 0,min_unt=a[0];;

	int temp;

	for(int i=1;i<n;i++){

		if(a[i]-min_unt > ans){
			ans = a[i] - min_unt;
			temp = a[i];
		}

		min_unt = min(min_unt,a[i]);
	}
	cout << min_unt << " " << temp << "\n";
	cout << "max profit " << ans << "\n"; 


	return 0;
}