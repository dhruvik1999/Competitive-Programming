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
    string a;
    cin >> a;

    for(int i=0;i<a.size();i++){
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='n'){

        }else{
            if(i!=a.size()-1){
                if(!(a[i+1]=='a' || a[i+1]=='e' || a[i+1]=='i' || a[i+1]=='o' || a[i+1]=='u')){
                    cout << "NO\n";
                    return 0;
                }
            }else{
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
