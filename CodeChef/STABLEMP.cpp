#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> b[n+10],g[n+10];
		vector< vector<int> > match(n+10,vector<int>(n+10,-1));
		vector<int> gpas(n+10,-1);

		int temp;
		
		queue<int> q;

		for(int i=0;i<n;i++){
			q.push(i);
			for(int j=0;j<n+1;j++){
				cin >> temp;
				if(j!=0){
				g[i].push_back(temp-1);
				match[i][temp-1]=j;
			}
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n+1;j++){
				cin >> temp;
				if(j!=0)
				b[i].push_back(temp-1);
			}
		}

		vector<int> ans(n,-1);

		int cb;
		while(q.size()!=0){
			cb = q.front();
			q.pop();


			for(int i=ans[cb]+1;i<n+1;i++){
				if(gpas[b[cb][i]]==-1){
					ans[cb] = i;
					gpas[b[cb][i]] = cb;
					break;
				}else if(match[b[cb][i]][gpas[b[cb][i]]] > match[b[cb][i]][cb] ){
					ans[cb] = i;
					q.push(gpas[b[cb][i]]);
					gpas[b[cb][i]] = cb;
					break;
				}
			}
		}

		for(int i=0;i<n;i++){
			cout << i+1 << " " << b[i][ans[i]]+1 << "\n";
		}
	}

	return 0;
}