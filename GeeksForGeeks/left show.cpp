#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long

using namespace std;

int ans[10]={0};

void func(vector< vector<int> > &v,int n,int i,int lvl){

   // cout << i << "\n";


    if(i==-1){
        return ;
    }

    if(ans[lvl]==0){
        ans[lvl]=i;
    }



    func(v,n,v[i][0],lvl+1);

    func(v,n,v[i][1],lvl+1);

}



int main(){
    int n;
    cin >> n;

    vector< vector<int> > v(100,vector<int>(2,-1));

    int p,q;
    char c;

    for(int i=0;i<n-1;i++){
        cin >> c >> p >> q;

        if(c=='L'){
            v[p][0]=q;
        }else{
            v[p][1]=q;
        }
    }

    func(v,n,1,1);
 cout  << "*\n";
    int t = 1;
    while(ans[t]!=0){
        cout << ans[t] << "\n";
        t++;
    }

    return 0;
}
