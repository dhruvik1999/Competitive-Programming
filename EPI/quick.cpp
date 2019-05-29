#include<bits/stdc++.h>
using namespace std;

int arrange(int *a,int i,int j){

	vector<int> l,r;

	

	for(int k=i;k<=j;k++){
		if(a[k] <= a[j]){
			l.push_back(a[k]);
		}else{
			r.push_back(a[k]);
		}
	}

	for(int k=0;k<l.size();k++){
		a[i+k]=l[k];
	}

	for(int k=0;k<r.size();k++){
		a[i+l.size()+k] = r[k];
	}


	return i+l.size()-1;
}

void getPivot(int *a,int n,int i,int j){
	if(j-i<=1)
		return;

	int piv = arrange(a,i,j);

	getPivot(a,n,i,piv-1);
	getPivot(a,n,piv+1,j);

}


int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	getPivot(a,n,0,n-1);

	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}