#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int t;
	while(true){
		cin >> t;
		cout << *( lower_bound( a.begin() , a.end() , t ) ) << "\n";
		cout << *( upper_bound( a.begin() , a.end() , t ) ) << "\n";
	}


	return 0;	
}