#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int t = 0,temp;
	for(int i=0;i<n;i++){

		if(a[i]<0){
			for(int j=i;j-1>=t;j--){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
			t++;
		}

	}

	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}


	return 0;
}