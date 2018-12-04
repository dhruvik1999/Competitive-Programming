#include <bits/stdc++.h>
#define ll long long
#define ii pair<double,double>
#define vi vector<int>
#define vii vector<ii>
using namespace std;

int gcd(int a,int b){
    if(a==0)
        return b;

    gcd(b%a,a);
}

int main(){
    int t;
    cin >> t;
    int a,b,c;
    while(t--){
        cin >> a >> b >> c;

        if(c==a || c==b){
            cout << 1 << "\n";
        }else if(c%gcd(a,b)!=0){
            cout << -1 << "\n";
        }else if(c>a && c>b){
            cout << -1 << "\n";
        }else{
            int x=0,y=0,ans1=0,ans2=0;

            while(x!=c && y!=c){
                if(x==a){
                    x=0;
                    ans1++;
                }else if(y==0){
                    y=b;
                    ans1++;
                }else{
                    int t=min(a-x,y);
                    x+=t;
                    y-=t;
                    ans1++;
                }
            }
            x=0;
            y=0;
            while(x!=c && y!=c){
                if(y==b){
                    y=0;
                    ans2++;
                }else if(x==0){
                    x=a;
                    ans2++;
                }else{
                    int t=min(b-y,x);
                    x-=t;
                    y+=t;
                    ans2++;
                }
            }
            //cout << ans1 << " " << ans2 << "\n";
            cout << min(ans1,ans2) << "\n";
        }
    }
    return 0;
}
