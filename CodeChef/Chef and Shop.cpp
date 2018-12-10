#include<bits/stdc++.h>

using namespace std;

map<pair<int,int> , int> dp;

long long int fun(long long int *weight,long long int *cost,long long int n,long long int k,long long int i,long long int ccost){

    if(ccost>k || i>=n)
        return dp[make_pair(i,ccost)]=0;

        if(dp.find(make_pair(i,ccost))!=dp.end()){
            return dp[make_pair(i,ccost)];
        }

    if(cost[i] > k-ccost)
        return dp[make_pair(i,ccost)]=fun(weight,cost,n,k,i+1,ccost);


    return dp[make_pair(i,ccost)]=max(weight[i] + fun(weight,cost,n,k,i+1,ccost+cost[i]),fun(weight,cost,n,k,i+1,ccost));
}




int main(){
    long long int t;
    cin  >> t;


    while(t--){
        long long int n,k;
        cin >> n >> k;
        dp.clear();
        long long int cost[n],weight[n];

        for(int i=0;i<n;i++){
            cin >> cost[i] >> weight[i];
        }

        cout << fun(weight,cost,n,k,0,0) << "\n";
    }



    return 0;
}
