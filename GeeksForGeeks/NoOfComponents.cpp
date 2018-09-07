#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include<unordered_set>
#include <algorithm>
#include<vector>
using namespace std;
bool vis[10]={false};
vector<int> a[10];


void check(int i){
    vis[i]=true;
    for(int j=0;j<a[i].size();j++){
        if(vis[a[i][j]]==false)
            check(a[i][j]);
    }
}



int main(){
        int n,e;
        cin >> n >> e;


        int t1,t2;
        for(int i=0;i<e;i++){
            cin >> t1 >> t2;
            a[t1].push_back(t2);
            a[t2].push_back(t1);
        }
        int counter=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==false){
                //cout << i << " ";
                check(i);
                counter++;
            }
        }
        cout << counter;
    return 0;
}
