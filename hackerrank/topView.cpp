#include<bits/stdc++.h>
using namespace std;
int tree[100][2];
int ind[100];
queue<int> qu;
int l=1,r=-1;
vector<int> ansl,ansr;

void bfs(int node){

	while(qu.size()!=0){
		node = qu.front();
		//cout << node << " " << ind[node] << "\n";

		if( ind[node] < l || r < ind[node]){
			if(ind[node]<l){
				l=ind[node];
				ansl.push_back(node);
			}else{
				r=ind[node];
				ansr.push_back(node);
			}

			cout << node << "\n";
		}
		qu.pop();

		if(tree[node][0]!=-1){
			qu.push(tree[node][0]);
			ind[tree[node][0]] = ind[node]-1;
		}
		if(tree[node][1]!=-1){
			qu.push(tree[node][1]);
			ind[tree[node][1]] = ind[node]+1;
		}
	}

}



int main(){

	int n;
	cin >> n;

	for(int i=0;i<100;i++){
		tree[i][0]=-1;
		tree[i][1]=-1;
	}

	int p,q;
	char d;
	for(int i=0;i<n-1;i++){
		cin >> d >> p >> q;
		if(d=='L'){
			tree[p][0]=q;
		}else{
			tree[p][1]=q;
		}
	}

	memset(ind,-1,sizeof(ind));

	int root;
	cin >> root;

	qu.push(root);
	ind[root]=0;
	bfs(root);


	cout << "ans" << "\n";

	for(int i=0;i<ansl.size();i++){
		cout << ansl[ansl.size()-i-1] << " ";
	}

	for(int i=0;i<ansr.size();i++){
		cout << ansr[i] << " ";
	}

	cout << "\n";








	return 0;
}
