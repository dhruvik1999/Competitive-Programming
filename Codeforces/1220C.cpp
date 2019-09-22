#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin >> s;

	
	char sc = s[0];
	for(int i=0;i<s.length();i++){
		if(sc < s[i]){
			cout << "Ann" << "\n";
		}else{
			cout << "Mike" <<"\n";
			sc =  s[i];
			
		}
	}


	return 0;
}