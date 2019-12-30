#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin >> s;

	if(s[0]=='?')
		s[0]='(';

	long long  n = s.length();


	if(s[0]=='?')
		s[0]='(';
	if(s[n-1]=='?')
		s[n-1]=')';

	vector< vector<long long > > dp(n+1 , vector<long long > (n+1));

	long long  ans = 0;
	for(long long  i=0;i<n;i++){
		long long  l=0,r=0,ob=0;

		for(long long  j=i;j<n;j++){
			if(s[i]==')'){
				break;
			}

				if(s[j]=='(' || (i==j&&s[j]=='?')){
					dp[i][j] = dp[i][max(j-1,0LL)] + 1;
					ob++;
				}else if(s[j]=='?'){
					dp[i][j] = dp[i][max(j-1,0LL)];
				}else{
					dp[i][j] = dp[i][max(j-1,0LL)] - 1;
				}

			if(i!=j && s[j]=='?' ){
				r++;
			}
			l = min(ob,r);
			l=l*-1;

			if( l <= dp[i][j] && dp[i][j] <=r && r%2==0 && dp[i][j]%2==0 ){
				ans++;
				//cout << ".";
			}else if(l <= dp[i][j] && dp[i][j] <=r && r%2!=0 && dp[i][j]%2!=0 ){
				ans++;
				//cout << ".";

			}

			//cout << dp[i][j] << " ";



			
		}
		//cout << "\n";
	}


	cout << ans << "\n";

	return 0;
}