#include<bits/stdc++.h>
using namespace std;

int main(){


	long long int n,m;
	cin >> n >> m;

	vector< vector<long long int> > graph( n+1 , vector<long long int> (n+1 , INT_MAX) );
	long long int p,q,r;
	for(long long int i=0;i<m;i++){
		cin >> p >> q >> r;
		graph[p][q] = r;
		graph[q][p] = r;
	}

	for( long long int k=1;k<=n;k++ ){
		for(long long int i=1;i<=n;i++){
			for(long long int j=1;j<=n;j++){
				if( graph[i][k] + graph[k][j] < graph[i][j] ){
					graph[i][j] = graph[i][k] + graph[k][j];
					graph[j][i] = graph[i][k] + graph[k][j];

				}
			}
		}
	}

	for(long long int i=1;i<=n;i++){
		for(long long int j=1;j<=n;j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}