#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> wi( n+1 , 0);
	for(int i=1;i<=n;i++){
		cin >> wi[i];
	}

	vector< pair<int,int> > graph(n+1);
	vector< int > deg(n+1);
	int p,q,r;
	for(int i=0;i<n-1;i++){
		cin >> p  >> q >> r;
		graph[p].push_back( { q , r } );
		graph[q].push_back( { p , r } );
		deg[p]++;
		deg[q]++;
	}




	return 0;
}