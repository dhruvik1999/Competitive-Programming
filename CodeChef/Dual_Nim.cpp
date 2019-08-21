#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){

		int ne=0,no=0;
		int n,temp,k=0;
		vector<int> dp(1000,0);

		cin >> n;
		bool first=true;

		for(int i=0;i<n;i++){
			cin >> temp;
			dp[temp]++;
		}




		for(int i=0;i<1000;i++){
			if(dp[i]!=0){
				if(dp[i]%2==0){
					first=!first;
					k+=dp[i]-1;
				}else{
					k+=dp[i];
				}
			}
		}

		if(ne%2!=0){
			first=false;
		}

		if(k%2!=0){
				first=!first;
		}

		if(first){
			cout << "First" << "\n";
		}else{
			cout << "Second" << "\n";
		}


	}

	return 0;
}