#include<bits/stdc++.h>

using namespace std;

string int_to_sring(int a){
	
	int temp;
	string ans="";

	//	cout << (char)((int)'0' + 1) << "\n";

	while(a!=0){
		temp = a%10;
		ans = (char)((int)'0' + temp) + ans;

		a=a/10;
	}
	return ans;
}

int string_to_int(string s){
	int a=0;

	for(int i=0;i<s.size();i++){
		a = a*10 + (s[i]-'0');
	}
	return a;
}


int main(){

	cout <<int_to_sring(1234589) << "\n";

	cout <<string_to_int("1234589") << "\n";


	return 0;
}