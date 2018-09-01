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
        long long int p1,p2,p3,p4,p5;

        cin >> p1>>p2>>p3>>p4>>p5;

        long long int a[8];

        a[0]=p1+p1+p5+p3;
        a[1]=p1+p3+p4+p5;
        a[2]=p1+p3+p3+p4+p4;
        a[3]=p1+p1+p3+p4;
        a[4]=p1+p3+p3+p5+p5;
        a[5]=p1+p4+p4+p5+p5;
        a[6]=p1+p1+p4+p4+p5;
        a[7]=p1+p1+p4+p5+p5;
        a[8]=p1+p4+p4+p5+p5;

    cout << *min_element(a,a+8)<<"\n";
    }
}
