#include<bits/stdc++.h>
using namespace std;

double findMid(vector<int>& a,vector<int> &b){
	int n = a.size();
	int m = b.size();
	int l=0,r=n-1;
	int i,j;
	int left;
	if((n+m)%2==0){
		left = (n+m)/2;
	}else{
		left = (n+m-1)/2;
	}

	while(l<=r){
	

		i = (l+r)/2;
		j = left - (i+1) - 1;

		if(a[i]<b[j+1] && b[j]<a[i+1]){
			cout << i << " " << j << "\n";
			if((n+m)%2==0){
				return ((double)( max(a[i],b[j]) + min(a[i+1],b[j+1]) ) )/2;
			}else{
				return (double)(min(a[i+1],b[j+1]));
			}
		}else if(a[i]>b[j+1]){
			r=i-1;
		}else if(b[j] > a[i+1]){
			l=i+1;
		}
	}
}


int main(){
	int n,m;
	cin >> n >> m;

	vector<int> a(n),b(m);

	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int j=0;j<m;j++){
		cin >> b[j];
	}




	cout << findMid(a,b) << "\n";



	return 0;
}