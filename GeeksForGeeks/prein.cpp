#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long

using namespace std;

int main(){

	int n;
	cin >> n;

	string a;
	cin >> a;

	int dp[26]={0};

	int ans = 0;

	for(int i=0;i<n;i++){
		if(dp[a[i]-'a']==0){
			dp[a[i]-'a']=i;
		}else{
			ans=max(ans,i-dp[a[i]-'a']);
			dp[a[i]-'a']=i;
		}
		for(int j=0;j<26;j++){
			cout <<dp[i] << " ";
		}
		cout << "\n";
	}

	cout << ans << "\n";


	return 0;
}