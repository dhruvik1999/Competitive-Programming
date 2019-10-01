#include<bits/stdc++.h>
using namespace std;

int main(){

	string s,a;
	cin >> s >> a;

	vector<int> at(26,0),st(26,0);

	for(int i=0;i<a.size();i++){
		at[ a[i]-'a' ]++;
	}

	for(int i=0;i<s.length();i++){
		st[ s[i]-'a' ]++;
	}

	for(int i=0;i<26;i++){
		if( st[i] <= at[i] ){
			at[i]-=st[i];
		}else{
			cout << "invalid" << "\n";
			return 0;		}
	}
	a="";
	for(int i=0;i<26;i++){

		for(int j=0;j<at[i];j++){
			a+= (i+'a'); 
		}

	}

	char d = 'z';

	for(int i=0;i<s.length();i++){
		if( (d) > (s[i]) ){
			d=s[i];
		}
	}
	//cout << d << "\n";

	int posa=a.size();
	for(int i=0;i<a.size();i++){
		if( d < a[i] ){
			posa=i;
			break;
		}
	}
	cout << s  << "\n";
	cout << a  << "\n";
	cout << d  << "\n";
	cout << posa  << "\n";


	return 0;
}