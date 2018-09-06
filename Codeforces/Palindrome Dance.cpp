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

    int n,w,b;
    cin >>n>>w>>b;

    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    int sum=0;
    for(int i=0;i<=(n-1)/2;i++){
        if(a[i]==a[n-i-1]){
            if(a[i]==2){

                if(n%2!=0 && i==(n-1)/2){

                if(w>b)
                    sum+=b;
                else
                    sum+=w;
                }else{

                if(w>b)
                    sum+=b+b;
                else
                    sum+=w+w;
                }
            }
        }else{
            if(a[i]==0&&a[n-i-1]==1){
                cout << -1;
                return 0;
            }else if(a[i]==1&&a[n-i-1]==0){
                cout << -1;
                return 0;
            }else if(a[i]==0&&a[n-i-1]==2){
                sum+=w;
            }else if(a[i]==2&&a[n-i-1]==0){
                sum+=w;
            }else if(a[i]==1&&a[n-i-1]==2){
                sum+=b;
            }else if(a[i]==2&&a[n-i-1]==1){
                sum+=b;
            }
        }

    }
    cout << sum ;
}