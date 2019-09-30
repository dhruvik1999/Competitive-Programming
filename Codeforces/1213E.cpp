#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	string a,b;
	cin >> a >> b;

	vector<string> res;

	string abc = "abc";

	do{
		string temp = "";

		for(int i=0;i<n;i++){
			temp+=abc;
		}

		res.push_back(temp);

		temp = "";

		for(int i=0;i<3;i++){
			for(int j=0;j<n;j++){
				temp+=abc[i];
			}
		}

		res.push_back(temp);
	}while(next_permutation(abc.begin(),abc.end()));

	for(int i=0;i<res.size();i++){
		if( res[i].find(a)==string::npos && res[i].find(b)==string::npos ){
			cout << "YES" << "\n";
			cout << res[i] << "\n";
			return 0;
		}
	}

	cout << "NO" << "\n";
	return 0;
}