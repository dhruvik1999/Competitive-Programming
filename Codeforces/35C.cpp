#include<bits/stdc++.h>
using namespace std;



int main(){

ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,m;
	cin >> n >> m;

	int t;
	cin >> t;

	int p,qq;
	vector< pair<int,int> > v;
	vector< vector<int> > graph( n+1 , vector<int>(n+1 , 1000000) );


	for(int i=0;i<t;i++){
		cin >> p >> qq;
		v.push_back( {p,qq} );
		graph[p][qq]=1;
	}

	for(int k=0;k<v.size();k++){

		queue< pair<int,int> > q;
		queue<int> qqq;
		q.push( v[k] );
		qqq.push(1);
		vector< vector<bool> > vis( n+1 , vector<bool>(n+1 , false) );


		while(q.size()){
			pair<int,int> t = q.front();
			q.pop();
			vis[t.first][t.second]=true;
			graph[t.first][t.second] = min( graph[t.first][t.second] , qqq.front() );
			qqq.pop();

			if(1<=t.first-1 && vis[t.first-1][t.second]==false){
				q.push({t.first-1,t.second});
				qqq.push( graph[t.first][t.second]+1 );
			}
			if(t.first+1<=n&& vis[t.first+1][t.second]==false){
				q.push({t.first+1,t.second});
				qqq.push( graph[t.first][t.second]+1 );

			}
			if(t.second-1>=1&& vis[t.first][t.second-1]==false){
				q.push({t.first,t.second-1});
				qqq.push( graph[t.first][t.second]+1 );

			}
			if( t.second+1<=m && vis[t.first][t.second+1]==false){
				q.push({t.first,t.second+1});
				qqq.push( graph[t.first][t.second]+1 );

			}

		}

	}

	int me = INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if( graph[i][j]>me ){
				me=graph[i][j];
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if( graph[i][j]==me ){
				cout << i << " " << j << "\n";
				return 0;
			}
		}
	}


	return 0;
}