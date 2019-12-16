#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
	if( (a+b) <= (b+a) ){
		return true;
	}else{
		return false;
	}
}


int main(){

	int n;
	cin >> n;

	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	//cout << "*" << "\n";

	sort( s.begin() , s.end() , cmp);

	string ans = "";
	for(int i=0;i<n;i++){
		//cout << s[i] << "\n";
		ans += s[i];
	}

	cout << ans << "\n";

	return 0;
}