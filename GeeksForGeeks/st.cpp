#include<bits/stdc++.h>
using namespace std;


int getSum(vector<int> &st,int l,int r,int ql,int qr,int ind){
	if(qr<l || r<ql)
		return 0;
	else if(ql<=l && r<=qr)
		return st[ind];
	else{
		int mid = (l+r)/2;
		return getSum(st,l,mid,ql,qr,ind*2+1) + getSum(st,mid+1,r,ql,qr,ind*2+2);
	}
}


void updateRange(vector<int> &a, vector<int> &st,int l,int r,int ind,int node,int val){
	if(l==r){
		a[ind]+=val;
		st[node]+=val;
	}else{
		int mid = (l+r)/2;

		if(l<=ind && ind<=mid){
			updateRange(a,st,l,mid,ind,node*2+1,val);
		}else{
			updateRange(a,st,mid+1,r,ind,node*2+2,val);
		}

		st[node] = st[node*2+1] + st[node*2+2];
	}
}


void createST(vector<int> &a,vector<int> &st,int l,int r,int ind){
		
		if(l==r){
			st[ind]=a[l];
			return;
		}


		int mid = (l+r)>>1;

		createST(a,st,l,mid,ind*2+1);
		createST(a,st,mid+1,r,ind*2+2);

		st[ind] = st[ind*2+1] + st[ind*2+2];

}

vector<int> md(vector<int> &a){
	int n = a.size();
	int sl = 1<<(  int(ceil( log(n)/log(2) ) +1) )  ;

	vector<int> st(sl,-1);

	createST(a,st,0,n-1,0);

	for(int i=0;i<sl;i++){
		cout << st[i] << " ";
	}
	cout << "\n";

	return st;

}



int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}


	
	vector<int> st = md(a);

	int l,r;

	while(true){
		cout << "*" << "\n";
		cin >> l >> r;

		updateRange(a,st,0,n-1,l,0,r);

		for(int i=0;i<st.size();i++){
			cout << st[i] << " ";
		}
		cout << "\n";
	}



	return 0;
}