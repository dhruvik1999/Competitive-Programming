#include <bits/stdc++.h>
#define ll long long
#define ii pair<double,double>
#define vi vector<int>
#define vii vector<ii>
using namespace std;
//Segmenttree implementation, +update,deletation,insert.

void buildTree(int* arr,int* tree,int s,int e,int index){

    if(s>e){
        return;
    }

    if(s==e){
        tree[index]=arr[s];
        return;
    }

    int mid=(s+e)/2;

    buildTree(arr,tree,s,mid,2*index);
    buildTree(arr,tree,mid+1,e,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);
}

int quary(int* arr,int* tree,int s,int e,int l,int r,int index){
    if(s>e)
        return INT_MAX;

    if(r<s || l>e){
        return INT_MAX;
    }
    if(s>=l && r>=e){
        return tree[index];
    }
    int mid=(s+e)/2;
    return min(quary(arr,tree,s,mid,l,r,index*2),quary(arr,tree,mid+1,e,l,r,index*2+1));
}

void update(int *tree,int s,int e,int index,int i,int value){
    if(i < s || i > e){
        return ;
    }

    if(s==e){
        tree[index]=value;
        return ;
    }
    int mid=(s+e)/2;
    update(tree,s,mid,2*index,i,value);
    update(tree,mid+1,e,2*index+1,i,value);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}


int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int tree[25];

    buildTree(arr,tree,0,8,1);

    for(int i=1;i<18;i++){
        cout << tree[i] << "\n";
    }

    update(tree,0,8,1,1,8);

    while(true){
        int l,r;
        cin >> l >> r;
        cout << "Minimum is " <<quary(arr,tree,0,8,l,r,1) << "\n";

        if(l==-1 && r==-1)
            break;
    }
    return 0;
}
