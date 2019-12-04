	#include<bits/stdc++.h>
	using namespace std;

	int main(){

		int n,m;
		cin >> n >> m;

		vector< string > a(n);

		for(int i=0;i<n;i++){
			cin >> a[i];
		}

		vector< vector<int> > l( n , vector<int>(m,0) ),r( n , vector<int>(m,0) ),u( n , vector<int>(m,0) ),d( n , vector<int>(m,0) );

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j==0){
					if( a[i][j]=='.' ){
						l[i][j]=1;
					}
				}else{
					if( a[i][j]=='.' ){
						l[i][j]=l[i][j-1]+1;
					}
				}

				if(j==0){
					if( a[i][m-1-j]=='.' ){
						r[i][m-1-j]=1;
					}
				}else{
					if( a[i][m-1-j]=='.' ){
						r[i][m-1-j]=r[i][m-j]+1;
					}
				}

				if(i==0){
					if( a[i][j]=='.' ){
						u[i][j]=1;
					}
				}else{
					if(a[i][j]=='.'){
						u[i][j]=u[i-1][j]+1;
					}
				}

				if(i==0){
					if( a[n-1-i][j]=='.' ){
						d[n-1-i][j]=1;
					}
				}else{
					if(a[n-1-i][j]=='.'){
						d[n-1-i][j]=d[n-i][j]+1;
					}
				}

			}
		}

		int ans = 0;

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ans = max( ans , l[i][j]+r[i][j]+u[i][j]+d[i][j] );
			}
		}

		cout << ans-3 << "\n";




		return 0;
	}