#include<bits/stdc++.h>
using namespace std;

void Bfs( int node , vector<int> *graph , vector<bool> &vis ){

	queue<int> q;
	q.push(node);
	vector<int> lvl( vis.size() , 0);
	lvl[node]=1;

	while(q.size()!=0){
		int t = q.front();
		q.pop();

		cout << t << " " << lvl[t] << "\n"	;
		vis[t]=true;

		for(int i=0;i<graph[t].size();i++){

			if( vis[ graph[t][i] ]==false ){
				q.push(graph[t][i]);
				lvl[ graph[t][i] ] = lvl[t]+1;
			}

		}




	}

 
}


int main(){

	int n,m;
	cin >> n;

	vector<int> graph[n+1];
	int p,q;

	for(int i=0;i<n-1;i++){
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	vector<bool> vis( n+1 , false);

	Bfs(1,graph,vis);
	cout << "\n";


	return 0;
}