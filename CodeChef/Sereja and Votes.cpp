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
    cin>>t;

    while(t--){
        int n;
        cin >> n;
        double t,sum;

        for(int i=0;i<n;i++){
            cin >> t;
            sum+=t;
        }

        if(sum>=100){
            if(sum-100<n){
                cout << "YES\n";
            }else{
                cout <<"NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }
return 0;
}