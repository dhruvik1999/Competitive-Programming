#include<bits/stdc++.h>

using namespace std;


int  readBIT(int *bit,int *a,int n,int index){
    int ans=0;
    index++;
    while(index>0){
        ans+=bit[index];
        index-=index&(-index);
    }
    return ans;

}

void updateBIT(int *bit,int *a,int n,int index,int val){
    index++;
    while(index<=n){
        bit[index]+=val;
        index+=index&(-index);
    }
}

int main(){

    int bit[1000];
    for(int i=0;i<1000;i++)
        bit[i]=0;
    int n;
    cin >> n;
    int a[n];


    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++)
    updateBIT(bit,a,n,i,a[i]);

    int temp;
    for(int i=0;i<6;i++){
            cin >> temp;
            cout <<readBIT(bit,a,n,temp) << "\n";
    }
    return 0;
}
