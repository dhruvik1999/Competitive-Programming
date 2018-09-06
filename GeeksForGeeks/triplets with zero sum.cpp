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
    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
        unordered_set<int> s;
        for(int j=i+1;j<n;j++){
            int x=-(a[i]+a[j]);
            if(s.find(x)!=s.end()){
                //found
                cout << a[i] << " "<< x << " "<< a[j] <<"\n";
            }else{
                //not found
                s.insert(a[j]);
            }
        }
    }


    return 0;
}
