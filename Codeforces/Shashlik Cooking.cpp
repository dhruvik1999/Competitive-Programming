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
    int n,k;
    cin >> n >> k;


bool mlock=false;

    for(int t=1;t<=2*k+1;t++){
        int rep=t;
        int count=0;
        bool lock=false;
        while(rep<=n-2*k-1 || rep>=n-k-1){
            rep+=2*k+1;
            count++;
            if(rep>n)
            {
                lock=true;
                break;
            }
        }
        if(lock){
            cout << count << "\n";
            while(t<=n){
                cout << t <<" ";
                mlock=true;
                t+=2*k+1;
            }

        }
        if(mlock)
        break;
    }
    return 0;
}
