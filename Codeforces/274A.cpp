#include<bits/stdc++.h>
using namespace std;

int main(){

	//declaration
	int n,k;

	cin >> n >> k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a.begin(),a.end());

	unordered_set< int > s;

	for(int i=0;i<n;i++){
		if(a[i]%k==0){
			if( s.find( a[i]/k )==s.end() ){
				s.insert(a[i]);
			}
		}else{
			s.insert(a[i]);
		}
	}

	cout << s.size() << "\n";

	return 0;
}