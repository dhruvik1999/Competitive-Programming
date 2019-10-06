#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;

	vector<char> a(n);

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	for(int i=0;i<n && k!=0;i++){
		if(i==0 && n!=1){
			if(a[i]!='1'){
				a[i]='1';
				k--;
			}
		}else{
			if(a[i]!='0'){
				a[i]='0';
				k--;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout << a[i];
	}
	cout << "\n";

	return 0;
}