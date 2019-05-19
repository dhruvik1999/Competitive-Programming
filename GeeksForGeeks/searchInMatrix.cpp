#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;

	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}

	int key;
	cin >> key;

	int i = 0,j=m-1;

	while(i<n && j>=0){
		cout << i << " " << j << "  ||  " << "\n";
		if(a[i][j] == key ){
			cout << i << " " << j << "\n";
			return 0;
		}else if(a[i][j] < key){
			i++;
		}else{
			j--;
		}
	}

	cout << "Not found" << "\n";
	return 0;
}