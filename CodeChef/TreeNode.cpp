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
    int n;
    cin >> n;
    int sum=0;
    while(n--){
        int n1,n2;
        cin >> n1 >> n2;
        sum+=n1-n2;
    }
    cout << sum << "\n";



}

    return 0;
}