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

int main(){
    int t;
    cin >> t;

    while(t--){
            int n,bn,s;
            cin >> n >> bn >> s;
            int b1,b2;
            for(int i=0;i<s;i++){
                cin >> b1 >> b2;

                if(b1==bn){
                    bn=b2;
                }else if(b2==bn){
                    bn=b1;
                }else{

                }
            }
            cout << bn << "\n";
    }


    return 0;
}