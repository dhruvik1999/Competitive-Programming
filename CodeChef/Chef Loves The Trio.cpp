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
        int l,r;
        cin >> l>>r;
        int count=0;

        if(l==r){
            cout << "0\n";
        }else if(l>r){
            cout << l-r<<"\n";
        }else{
            while(r>l){
                r=r/3;
                count++;
            }
            count+=l-r;
            cout << count << "\n";
        }
    }
}