#include<bits/stdc++.h>
using namespace std;

void findAllString(string a,string b,int i,int j,int n,int m,string ans){
	if(i==n && j==m){
		cout << ans << "\n";
	}

	if(i<n)
		findAllString(a,b,i+1,j,n,m,ans+a[i]);
	if(j<m)
		findAllString(a,b,i,j+1,n,m,ans+b[j]);

}


int main(){
	string a,b;
	cin >> a >> b;
	cout << a << " " << b << "\n";

	findAllString(a,b,0,0,a.length(),b.length(),"");


	return 0;
}