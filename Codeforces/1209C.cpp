#include<bits/stdc++.h>
using namespace std;

struct comparator{

	bool operator()(char a,char b){
		return a>b;
	}

};

int main(){

	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;

		string s;
		cin >> s;

		priority_queue< char , vector<char> , comparator> p;
		for(int i=0;i<n;i++){
			p.push(s[i]);
		}
		// p.push('a');
		// p.push('b');

		// //cout << p.top() << "\n";

		vector<int> ans( n , -1 );

		for(int i=0;i<n;i++){
			if( s[i] == p.top() ){
				p.pop();
				ans[i]=1;
			}
		}

		bool lock = true;
		for(int i=0;i<n;i++){
			if( ans[i]!=1 && s[i] == p.top() ){
				p.pop();
				ans[i]=2;
			}else if( ans[i]==-1 ){
				lock = false;
				cout << "-" << "\n";
				break;
			}
		}

		if(lock){
			for(int i=0;i<n;i++){
				cout << ans[i];
			}
			cout << "\n";
		}




	}


	return 0;
}