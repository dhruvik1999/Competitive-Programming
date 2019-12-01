#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}

	set<int> s;
	for(int i=0;i<n;i++){
		if(s.size()!=10){
			for(int j=0;j<10;j++){
				if( v[i]-j>=0 && (v[i]-j)%k==0 ){
					for(int y=1;y<10;y++){
						if(s.find( j*y )==s.end()){
							s.insert( (j*y)%k );
						}else{
							break;
						}
					}
				}
			}
		}else{
			break;
		}
	}
	cout << s.size() << "\n";
	for( auto i : s ){
		cout << i << " ";
	}
	cout << "\n";


	return 0;
}