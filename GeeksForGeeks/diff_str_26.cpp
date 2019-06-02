#include<bits/stdc++.h>
using namespace std;

int func(int *a,int i){
	if(i<0)
		return 0;
	else if(i==0)
		return 1;
	else if(i==1){
		if(a[0]*10+a[1] <=26){
			return 2;
		}else{
			return 1;
		}
	}

	if( a[i-1]*10 + a[i] <=26 ){
		return func(a,i-2) + func(a,i-1);
	}

	return func(a,i-1);
}

int main(){

	int n;
	cin >> n;
	int a[n];
	char temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		a[i] = temp - '0';
		cout << a[i] << " ";
	}
	cout << "\n";

	cout << func(a,n-1) << "\n";



	return 0;
}