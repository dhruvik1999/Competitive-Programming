#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

	int t;
	cin >> t;


	while(t--){

		int n;
		cin >> n;

		int tt;
		vector< vector<int> > a(2,vector<int>(n+1));
		vector< vector<int> > dp(12,vector<int>(n+10));

		string y1,y2;
		cin >> y1>>y2;

		for(int i=0;i<y1.length();i++){
			if(( y1[i]-'0' )<=2){
				a[0][i]=1;
			}else{
				a[0][i]=2;
			}
		}


		for(int i=0;i<y2.length();i++){
			if(( y2[i]-'0' )<=2){
				a[1][i]=1;
			}else{
				a[1][i]=2;
			}
		}
		int line=0;
		bool lock = true;
		for(int i=0;i<n;i++){
			if(a[line][i]==1){
				continue;
			}else{
				if(a[line][i]==2 && a[(line+1)%2][i]==2 ){
					line=(line+1)%2;
				}else{
					cout << "NO" << "\n";
					lock=false;
					break;
				}
			}
		}
		if(lock){
			if(line==1){
				cout << "YES" << "\n"; 
			}else{
				cout << "NO" << "\n";
			}
		}
	}
		


    return 0;
}