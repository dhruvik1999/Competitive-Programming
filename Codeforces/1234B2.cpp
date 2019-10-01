#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

	int t;
	cin >> t;


	while(t--){

		int n;
		cin >> n;

		int tt;
		vector< vector<int> > a(2,vector<int>(n+1));
		vector< vector<int> > dp(12,vector<int>(n+10));

		string y1,y2;
		cin >> y1>>y2;

		for(int i=0;i<y1.length();i++){
			if(( y1[i]-'0' )<=2){
				a[0][i]=1;
			}else{
				a[0][i]=2;
			}
		}


		for(int i=0;i<y2.length();i++){
			if(( y2[i]-'0' )<=2){
				a[1][i]=1;
			}else{
				a[1][i]=2;
			}
		}

		for(int i=0;i<2;i++){
			for(int j=0;j<=n;j++){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}

		int p=-1;
		
		dp[0][0]=1;

		for(int i=0;i<n;i++){
			for(int ff=0;ff<4;ff++){
			for(int j=0;j<2;j++){
				if(dp[j][i]==1){

					if(a[j][i]==1){
						if(p==-1){
							dp[j][i+1]=1;
							p=-1;
						}
					}else{
						if(p==-1){
							if(j==0){
								//cout << "*" << "\n";
								dp[j+1][i]=1;
								p=2;
							}else{
								dp[j-1][i]=1;
								p=-2;
							}
						}else if(p==2){
							dp[j][i+1]=1;
							p=-1;
						}else if(p==-2){
							dp[j][i+1]=1;
							p=-1;
						}
					}


				}
			}
			}
		}

		for(int i=0;i<2;i++){
			for(int j=0;j<=n;j++){
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}

		if(dp[1][n+1]==1){
			cout << "YES" << "\n";
		}else{
			cout << "NO" << "\n";
		}





	}



    return 0;
}