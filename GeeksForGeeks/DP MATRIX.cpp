#include<bits/stdc++.h>

using namespace std;

int m0(int x,int y){
    if(x<y){
            return y;
    }else{
            return x;
    }
}

int  fun( vector < vector < int > > &a, vector < vector < int > > &ans,int posi,int posj,int n,int m){

    if(!(posi<n && posj<m)){
        return 0;
    }

    if(ans[posi][posj]!=-1)
    {
    return ans[posi][posj];
    }


    return (ans[posi][posj]=m0(fun(a,ans,posi+1,posj,n,m),fun(a,ans,posi,posj+1,n,m)) + a[posi][posj]);
}


int main(){
    int n,m;
    cin >> n >> m;

    vector < vector < int > > a (n,vector< int >(m,-1));
    vector < vector < int > > ans (n,vector< int >(m,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            ans[i][j]=-1;
        }
    }
    ans[n-1][m-1]=a[n-1][m-1];
    cout << fun(a,ans,0,0,n,m);
    return 0;
}
