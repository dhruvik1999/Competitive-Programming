#include<bits/stdc++.h>
using namespace std;
int main(){

	long long int n;
	cin >> n;

	vector< vector<long long int> > dis(n , vector<long long int>(n,0));

	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<n;j++){
			cin >> dis[i][j];
		}
	}

	long long int k;
	cin >> k;

	long long int p,q,r;
	for(long long int l=0;l<k;l++){
		cin >> p >> q >> r;
		p--;
		q--;
		long long int ans = 0;
		if( dis[p][q] >r ){
			dis[p][q]=r;
			dis[q][p]=r;
			for(long long int i=0;i<n;i++){
				for(long long int j=0;j<n;j++){
					dis[i][j] = min( dis[i][j] , min( dis[i][p]+r+dis[q][j] , dis[i][q]+r+dis[p][j] ) );
					ans+=dis[i][j];
				}
			}
			cout  << ans/2 << " ";
		}else{
			for(long long int i=0;i<n;i++){
				for(long long int j=0;j<n;j++){
					ans+=dis[i][j];
				}
			}
			cout << ans/2 << " ";
		}

	}
	cout << "\n";



	return 0;
}