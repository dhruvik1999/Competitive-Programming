#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    pair <int,int> p;
    map <pair<int,int> , int > dp;

    long long int ca=0,cb=0,cc=0,ans=0;

    dp[make_pair(0,0)]=1;

    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            ca++;
        }else if(s[i]=='B'){
            cb++;
        }else{
            cc++;
        }

        int l=cb-ca,r=cc-ca;
        if(dp.find(make_pair(l,r))!=dp.end()){
            ans+=dp[make_pair(l,r)];
        }
        dp[make_pair(l,r)]++;
    }
   // cout << ca << " " << cb << " " << cc << "\n";
    cout << ans << "\n";



    return 0;
}
