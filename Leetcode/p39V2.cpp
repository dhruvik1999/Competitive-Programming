#include<bits/stdc++.h>
using namespace std;



int main(){

	int n,trg;
	cin >> n >> trg;

	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	vector< vector<int> > dp( n+1 , vector<int>(trg+1,0) );

	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=trg;j++){

			if( a[i] > j ){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]];
				int temp = j;
				while(temp-a[i]>0){
					dp[i][j] = dp[i][j] || dp[i][ temp-a[i] ];
					temp-=a[i];
				}
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout << a[i] << "  ";


		for(int j=0;j<=trg;j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}