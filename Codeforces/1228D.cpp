#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,m;
	cin >> n >> m;

	vector< int > graph[n+10];
	int p,q;
	for(int i=0;i<m;i++){
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	unordered_set<int> s[3];

	for(int i=1;i<=n;i++){
		bool floack = true;
		for(int j=0;j<3;j++){
			bool lock = true;
			for(int k=0;k<graph[i].size();k++){
				if(s[j].find(graph[i][k])!=s[j].end()){
					lock = false;
					break;
				}
			}
			if(lock){
				floack = false;
				s[j].insert(i);
				break;
			}
		}
		if(floack){
			cout << -1 << "\n";
			return 0;
		}
	}


	for(auto i : s[0]){
		if( graph[i].size()!= ( s[1].size()+s[2].size() ) ){
			cout << -1 << "\n";
			return 0;
		}
	}


	for(auto i : s[1]){
		if( graph[i].size()!= ( s[0].size()+s[2].size() ) ){
			cout << -1 << "\n";
			return 0;
		}
	}


	for(auto i : s[2]){
		if( graph[i].size()!= ( s[1].size()+s[0].size() ) ){
			cout << -1 << "\n";
			return 0;
		}
	}

	if(s[0].size()==0 || s[1].size()==0 || s[2].size()==0){
		cout << -1 << "\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(s[j].find(i)!=s[j].end()){
				cout << (j+1) << " ";
				break;
			}
		}
	}
	cout << "\n";


	return 0;
}