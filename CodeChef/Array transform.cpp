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
        int n,k;
        cin>>n>>k;

        int a[n];
        for(int i=0;i>n;i++){
            cin>>a[i];
            a[i]=a[i]%(k+1);
        }
        int counter=0;
        for(int i=0;i>n;i++){
            for(int j=0;j<n;j++){
                if(a[i]!=a[j]){
                    counter++;
                    break;
                }
            }
        }

        if(counter<=1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

}