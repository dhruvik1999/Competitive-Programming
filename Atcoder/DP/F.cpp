#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > dp(301 , vector<int>(301,-1));
vector<char> ans;
	
int doWork(string s,string t,int x,int y){
	if(x<0 || y<0)
		return 0;

	if(dp[x][y]!=-1)
		return dp[x][y];

	if(s[x]==t[y]){
		return (dp[x][y] = 1+doWork(s,t,x-1,y-1));
	}

	return (dp[x][y] = max(  doWork(s,t,x-1,y) , max ( doWork(s,t,x,y-1), doWork(s,t,x-1,y-1) )));
}


int main(){

	string s,t;
	cin >> s >> t;


	cout << "ANS : " << doWork(s,t,s.length()-1,t.length()-1) << "\n";
	
	for(int i=0;i<t.length();i++)
		cout << t[i] << " ";
	cout << "\n";
	for(int i=0;i<s.length();i++){

		cout << s[i] << " ";
		for(int j=0;j<t.length();j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}