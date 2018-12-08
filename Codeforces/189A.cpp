#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    int dp[4005];
    for(int i=0;i<4005;i++)
        dp[i]=-1;
    sort(a,a+3);

    dp[a[0]]=1;
    dp[a[1]]=1;
    dp[a[2]]=1;
    for(int i=a[0]+1;i<=n+1;i++){
        if(dp[i]==-1 || dp[i]==1){
                int t1=-1,t2=-1,t3=-1;
            if(i-a[0] >= 0 && dp[i-a[0]]!=-1){
                t1=dp[i-a[0]];
            }

            if(i-a[1] >= 0 && dp[i-a[1]]!=-1){
                t2=dp[i-a[1]];
            }


            if(i-a[2] >= 0 && dp[i-a[2]]!=-1){
                t3=dp[i-a[2]];
            }
            if(t1!=-1 || t2!=-1 || t3 !=-1)
            dp[i]=max(t1,max(t2,t3))+1;
        }
    }
    cout << dp[n] << "\n";


    return 0;
}
