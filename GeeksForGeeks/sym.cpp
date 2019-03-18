#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long

using namespace std;

bool func(vector< vector<int> > &v,int n,int p,int q{

	if(p!=q){
		return false;
	}

	if(p==-1 && q==-1){
		return true;
	}
  
	return func(v,n,v[p][0],v[q][1]) && func(v,n,v[p][1],v[q][0]);

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



	return 0;
}