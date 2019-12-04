#include<bits/stdc++.h>
using namespace std;



int main(){


	int n,m;
	cin >> n >> m;

	vector<int> graph[n+1];
	vector< vector<bool> > eg (1000 , vector<bool>(1000,false));
	int p,q;

	for(int i=0;i<m;i++){
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
		eg[p][q]=true;
		eg[q][p]=true;
	}

	unordered_set<int> ab,c,a,b;

	unordered_set<int> t1,t2;
	t1.insert(1);
	vector<int> cnt(n+1,0);

	for(int i=0;i<graph[1].size();i++){
		t1.insert( graph[1][i] );
	}

	for(auto i : t1){
		if(cnt[i]<0)
			continue;
		cnt[i]+=1;
		for(int j=0;j<graph[i].size();j++){
			cnt[graph[i][j]]++;
		}
		int me = *max_element(cnt.begin(),cnt.end());
		for(int i=1;i<=n;i++){
			if(cnt[i]!=me){
				cnt[i]=INT_MIN;
			}
		}
	}

	int me = *max_element(cnt.begin(),cnt.end());

	for(int i=1;i<=n;i++){
		if( cnt[i]==me ){
			ab.insert(i);
		}else{
			c.insert(i);
		}
	}



	// ab.insert(1);
	// unordered_set<int> s;
	// for(int i=0;i<graph[1].size();i++){
	// 	ab.insert(graph[1][i]);

	// }

	// for(int i=1;i<=n;i++){
	// 	if( ab.find(i)==ab.end() ){
	// 		c.insert(i);

	// 	}
	// }

	// cout << "ab" << "\n";
	// for(auto i : ab){
	// 	cout << i << "\n";
	// }

	// cout << "c" << "\n";
	// for( auto i : c ){
	// 	cout << i << "\n";
	// }


	for( auto i : ab ){
		for( auto j : ab ){
			if( i!=j && eg[i][j]==false ){
				cout << "No" << "\n";
				return 0;
			}
		}
	}

	for( auto i : c ){
		for( auto j : c ){
			if(i!=j && eg[i][j]==false ){
				cout << "No" << "\n";
				return 0;
			}
		}
	}	



	for( auto i : ab ){
		
		if( c.size()!=0 && eg[i][*c.begin()]==true ){
			for( auto k : c ){
				if(eg[i][k]==false){
					cout << "No" << "\n";
					return 0;
				}
			}
			b.insert(i);
		}else{
			for( auto k : c ){
				if(eg[i][k]==true){
					cout << "No" << "\n";
					return 0;
				}
			}
			a.insert(i);
		}	
	}

	cout << "Yes" << "\n";
	for(int i=1;i<=n;i++){
		if( a.find(i)!=a.end() ){
			cout << "a";
		}else if(b.find(i)!=a.end()){
			cout << "b";
		}else{
			cout << "c";
		}
	}
	cout << "\n";





	return 0;
}