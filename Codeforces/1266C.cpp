#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,m;
	cin >> n >> m;

	if( n==1 && m==1 ){
		cout << 0 << "\n";
		return 0;
	}


	vector< vector<int> > ans ( n , vector<int>(m,0));


	if( n==1 || m==1 ){
		if(n==1){
			for(int i=0;i<m;i++){
				cout << i+2 << " ";
			}		
			cout << "\n";
			return 0;
		}else{
			for(int i=0;i<n;i++){
				cout << i+2 << "\n";
			}
			return 0;
		}
	}

	int mul;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if( i==0 ){
				ans[i][j]=j+2;
			}else{
				ans[i][j]=ans[0][j]*(2+m+i-1);
			}
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}