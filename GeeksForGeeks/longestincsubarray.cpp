#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int temp = 1;
	int ans = 0;

	for(int i=1;i<n;i++){
		if(a[i] > a[i-1]){
			temp++;
		}else{
			temp=1;
		}

	//	cout << temp << "\n";
		ans = max(ans,temp);
	}

	cout << ans << "\n";


	return 0;
}