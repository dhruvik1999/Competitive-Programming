#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include<unordered_set>
#include <algorithm>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    int t1,t2,b[n][n]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                cin >> t1  >> t2;
                a[t1][t2]=1;
                a[t2][t1]=1;
            }
        }
    }
    
    
    
    return 0;
}