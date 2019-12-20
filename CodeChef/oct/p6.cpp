#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector<int> sec[n];
	int t = 0;
	sec[0].push_back( a[0] );
	for(int i=1;i<n;i++){
		if( a[i]>=a[i-1] ){
			sec[t].push_back(a[i]);
		}else{
			if( i+1==n || a[i-1]<a[i+1] ){
				sec[t].push_back(a[i]);
				if(i+1!=n)
					t++;
			}else{
				t++;
				sec[t].push_back(a[i]);
			}
		}
	}

	
		set< pair<int,int> > s;
		for(int i=0;i<=t;i++){
			s.insert( { sec[i][0] , i } );
		}

		//cout << t << "\n";
		vector<int> ans;
		if(k>=t+1){

			pair<int,int> temp = *s.begin();

			for(int i=0;i<sec[temp.second].size();i++){
					//cout << sec[temp.second][i] << " ";
					ans.push_back(sec[temp.second][i]);
				}
			for(int i=0;i<t && i!=temp.second;i++){
				for(int j=0;j<sec[i].size();j++){
					//cout << sec[i][j] << " ";
					ans.push_back(sec[i][j]);
				}
			}
			//cout << "\n";
			k-=(t+1);
			if(k>=3){
				int tt = 0;
				while( ans[tt] == (tt+1) ){
					tt++;
				}

				int bicchu = tt+1;


				for(int i=0;i<n;i++){
					if(i==tt){
						cout << bicchu << " ";
					}
					if(a[i]!=bicchu)
						cout << ans[i] << " ";	
				}
					cout << "\n";
			}else{
				for(int i=0;i<n;i++){
					cout << ans[i] << " ";
				}
				cout << "\n";
			}

		}else{


			int t = 0;
			while( a[t] == (t+1) ){
				t++;
			}

			int bicchu = t+1;


			for(int i=0;i<n;i++){
				if(i==t){
					cout << bicchu << " ";
				}
				if(a[i]!=bicchu)
					cout << a[i] << " ";	
			}
				cout << "\n";
		}




	return 0;
}