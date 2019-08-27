#include<bits/stdc++.h>
using namespace  std;

bool check(vector<int> &a,int n){
	vector<int> l(n,0),r(n,0);

	l[0]=-1;
	r[n-1]=-1;
	int mi = 0;

	for(int i=1;i<n;i++){
		if(a[mi] < a[i]){
			l[i]=mi;
		}else{
			l[i]=-1;
			mi = i;
		}
	}

	mi=n-1;

	for(int i=n-2;i>=0;i--){
		if(a[mi] < a[i]  ){
			r[i] = mi;
		}else{
			r[i]=-1;
			mi=i;
		}
	}

	for(int i=1;i<n-1;i++){
		if(l[i]!=-1 && r[i]!=-1){
			cout << 3 << "\n";
			cout << l[i]+1 << " " << i+1 << " " << r[i]+1 << "\n";
			return true;
		}
	}

	return false;
}


int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	if(!check(a,n)){
		for(int i=0;i<n;i++){
			a[i]=a[i]*-1;
		}
			if(!check(a,n)){
				cout << 0 << "\n";
			}
		
	}

	return 0;
}