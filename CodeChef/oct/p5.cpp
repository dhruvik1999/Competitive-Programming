#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;

		vector<int> graph[n+10];
		int p,q;
		vector<int> deg(n+10,0);
		bool lock = false;
		int t1,t2;

		for(int i=0;i<m;i++){
			cin >> p >> q;

			graph[p].push_back(q);
			graph[q].push_back(p);
			deg[p]++;
			deg[q]++;
			t1=p;
			t2=q;

		}

		for(int i=1;i<=n;i++){
			if(deg[i]%2==1){
				lock = true;
				break;
			}
		}

		if(m%2==0){
			cout << 1 << "\n";
			for(int i=0;i<n;i++){
				cout << 1 << " ";
			}
			cout << "\n";
		}else if(lock){
			bool lock1 = true;
            cout << 2 << "\n";
			for(int i=1;i<=n;i++){
				if(lock1 && deg[i]%2==1){
					cout << 2 << " ";
					lock1=false;
				}else{
					cout << 1 << " ";
				}
			}
			cout << "\n";

		}else{
			cout << 3 << "\n";

			for(int i=1;i<=n;i++){
				if(i!=t1 && i!=t2){
					cout << 1 << " ";
				}else if(i==t1){
					cout << 2 << " ";
				}else{
					cout << 3 << " ";
				}
			}
			cout << "\n";

		}


	}


	return 0;
}