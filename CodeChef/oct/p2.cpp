	#include<bits/stdc++.h>
	using namespace std;

	int main(){

		int t;
		cin >> t;

		while(t--){

			int n,m,qq;
			cin >> n >> m >> qq;

			vector<int> row(n+10,0),col(m+10,0);
			int p,q;
			for(int i=0;i<qq;i++){
				cin >> p >> q;
				row[p]++;
				col[q]++;
			}

			long long re=0,ro=0,ce=0,co=0;

			for(int i=1;i<=n;i++){
				
					if(row[i]%2==0){
						re++;
					}else{
						ro++;
					}
			}
				
			for(int i=1;i<=m;i++){
				
					if(col[i]%2==0){
						ce++;
					}else{
						co++;
					}
				
			}

			cout << ro*ce+co*re << "\n";
		}


		return 0;
	}