#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int i=0,j=0;
	int temp;
	while(j<n){
		while(a[i]<0){
			i++;
		}
		j=i;
		while(a[j]>0){
			j++;
		}

		if(i<n && j<n){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}

	cout << "\n";


	return 0;
}