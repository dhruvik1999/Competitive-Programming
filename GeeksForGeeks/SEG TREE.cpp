#include<bits/stdc++>

using namespace std;

void buildtree(int *tree,int *a,int s,int e,int index){
    if(s>e)
    return ;    

    if(s==e){
        tree[index]=a[i]
    }

    int mid=(s+e)/2;
    buildtree(tree,a,s,mid,index*2);
    buildtree(tree,a,mid+1,e,index*2+1)

    tree[index]=min(tree[2*index+1],tree[2*index])
}

int main(){
    int a[]={1,2,-1,3,4,5}
    int n=sizeof(a)/sizeof(a[0])

    int tree[4n+1];

    buildtree(tree,a,0,n-1,0);

    for(int i=0;i<n;i++){
        cout  << tree[i] << "\n";
    }
    return 0;
}