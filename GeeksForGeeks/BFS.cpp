#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector< int > graph[ n+1 ];

	int p,qq;
	for(int i=0;i<n-1;i++){
		cin >> p >> qq;
		graph[p].push_back(qq);
		graph[qq].push_back(p);
	}

	int root;
	cin >> root;

	queue<int> q;

	q.push(root);
	vector< bool > vis( n+1 , false );

	while( q.size()!=0 ){
		int t = q.front();
		vis[t]=true;
		cout << t << "\n";
		q.pop();

		for(int i=0;i<graph[t].size();i++){
			if( vis[ graph[t][i] ] == false ){
				q.push(graph[t][i]);
			}
		}

	}


	return 0;
}