#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define mi map<int,int>
#define mll map<ll,ll>
#define si set<int>
#define sll set<ll>
#define usi unordered_set<int>
#define usll unordered_set<ll>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second

#define MOD 1000000007
#define maxlen 100005


int isSum(int *s,int n,int sum){
    int subset[n+1][sum+1];

    for(int i=0;i<=n;i++)
        subset[i][0]=1;

    for(int i=1;i<=sum;i++)
        subset[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){

            if(j<s[i-1]){
                subset[i][j]=subset[i-1][j];
            }else{
                subset[i][j]=(subset[i-1][j] || subset[i-1][j-s[i-1]]);
            }

        }
    }
    return subset[n][sum];
}


int main(){

    int s[]={3,34,4,12,5,2};
    if(isSum(s,6,13)){
            cout << "YES";
    }else{
            cout << "NO";
    }



    return 0;
}
