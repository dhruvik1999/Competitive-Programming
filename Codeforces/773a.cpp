#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long

using namespace std;

bool func(ll x,ll y,ll p,ll q,ll mid){

    ll tip = mid*q-y;
    if(tip < 0){
        return false;
    }

    if(mid*p - x <=tip && mid*p - x>=0){
        return true;
    }

    return false;

}


int main(){

    fast1;
    fast2;

       ll t;
    cin >> t;

    ll x,y,p,q;

    while(t--){
        cin >> x >> y >> p >> q;
        if(( (p==0 && x!=0 && y!=0)|| (q==0 && y!=0)|| (p==q && x!=y)  )){

            if(y==0 && q==0)
                cout << 0 << "\n";
            else
                cout  << -1 << "\n";
            continue;
        }

        if(q==0 && y==0){
            cout << 0 << "\n";
            continue;
        }

        if(x==y && x==0){
            cout << q << "\n";
            continue;
        }



        ll l =0,r=1000000009;

        ll mid,ans;

        while(l<r){
            mid = (l+r)>>1;

           // cout << l << " " << mid << " " << r << "'\n";

            if(func(x,y,p,q,mid)){
                r=mid;
                ans=r;
            }else{
                l=mid+1;
            }

        }
        cout << ans*q-y << "\n";
        }
    return 0;
}
