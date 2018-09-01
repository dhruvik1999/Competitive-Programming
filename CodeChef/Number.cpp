#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,counter=0;
        cin >> n>>k;
        int a[n];
        for(int i=0;i<n;i++){
        cin>>a[i];
            if(a[i]%k!=0){
                counter++;
            }
        }
        if(counter==1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
return 0;
}
