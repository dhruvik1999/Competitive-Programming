#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector< int > graph[n+5];
	int t1,t2;
	for(int i=0;i<n-1;i++){
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	vector< int > parent(n+5,-1);
	vector< int > color(n+5,-1);
	vector< bool > vis(n+5,false);

	queue< int > q;
	q.push(1);
	color[1]=1;
	vis[1]=true;

	int temp,cc=0;
	int ans=0;

	while(q.size()!=0){
		temp = q.front();
		q.pop();


		for(int i=0;i<graph[temp].size();i++){

			if(vis[graph[temp][i]]==false){
				vis[graph[temp][i]]=true;
			cc++;
			while(cc == color[temp] || cc == color[ parent[temp] ]){
				cc++;
			}

			color[ graph[temp][i] ]=cc;
			ans = max(ans,cc);
			parent[ graph[temp][i] ] = temp;

			q.push(graph[temp][i]);
		}
		}
		cc=0;
	}

	cout << ans << "\n";
	for(int i=1;i<=n;i++){
		cout << color[i] << " ";
	}
	cout << "\n";

	return 0;
}