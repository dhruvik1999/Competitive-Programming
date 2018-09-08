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

bool check(int n,int m,int x,int y){
    if((n-1)%x==0&&(m-1)%y==0)
        return true;

    return false;
}



int main(){
    int t;
    cin >>t;

    while(t--){
        int n,m,x,y;
        cin >> n >> m >> x >> y;

        int n1,m1;
        if(n==1 || m==1){
            if(check(n,m,x,y)){
                cout << "Chefirnemo" << "\n";
            }else{
                //no
                cout << "Pofik" << "\n";
            }
        }else{
            if(check(n,m,x,y)){
                cout << "Chefirnemo" << "\n";
            }else{
                if(check(n-1,m-1,x,y)){
                    cout << "Chefirnemo" << "\n";
                }else{
                    //no
                    cout << "Pofik" << "\n";
                }
            }
        }

    }
}