#include<bits/stdc++.h>
using namespace std;

bool allNine( string s ){
	for(int i=0;i<s.length();i++){
		if( s[i]!='9' ){
			return false;
		}
	}
	return true;
}

string addOne(string s){
	int ch = 0;
	for(int i = s.length()-1;i>=0;i--){
		if(i==s.length()-1){
			ch = ( s[i]-'0'+1 )/10;
			s[i] = (char)('0'+( s[i]-'0'+1 )%10);
		}else{
			int t = ch;
			ch = ( s[i]-'0'+ t )/10;
			s[i] = (char)('0'+( s[i]-'0'+ t)%10);
		}
	}
	return s;
}

int main(){

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		string l="",c="",r="";

		for(int i=0;i<n;i++){
			if( i<n/2 ){
				l+=s[i];
				r = s[i]+r;
			}else if( n%2!=0 && i==n/2 ){
				c=s[i];
			}else{
				break;
			}
		}

		if( (l+c+r) > s  ){
			cout << (l+c+r) << "\n"; 
		}else{
			if(n%2==0){
				if(allNine(l)==true){
					string y = "1";
					for(int i=0;i<n/2-1;i++){
						y+="0";
					}
					string yy = y;
					reverse( yy.begin() , yy.end() );
					cout << y+"0"+yy << "\n";
				}else{
					l = addOne(l);
					string r = l;
					reverse(r.begin(),r.end());
					cout << l+r << "\n";
				}
			}else{
				if(c=="9"){
				
				if(allNine(l)==true){
					string y = "1";
					for(int i=0;i<n/2;i++){
						y+="0";
					}
					string yy = y;
					reverse( yy.begin() , yy.end() );
					cout << y+yy << "\n";
				}else{
					l = addOne(l);
					string r = l;
					//cout << "ADD ONE" << l << "\n";
					reverse(r.begin(),r.end());
					cout << l+"0"+r << "\n";
				}

				}else{
					c=addOne(c);
					cout << l+c+r << "\n";

				}
			}
		}


	}


	return 0;
}