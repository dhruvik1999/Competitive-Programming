#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long

using namespace std;

bool func(int *a,int n,int l,int r){

	if(l>=r){
		if(l==r && a[l]==l){
			cout << l << " " << a[l] <<  "\n";
			return true;
		}else{
			return false;			
		}
	}

	int mid = (l+r)>>1;

	cout << mid << " " << a[mid] << "\n";	
	if(a[mid] > mid){
		return func(a,n,mid+1,r);
	}else if(a[mid] < 0){
		return func(a,n,mid+1,r);
	}else{
		return func(a,n,l,mid);
	}


}



int main(){

	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	if(func(a,n,0,n-1)){
		cout << "Find\n";
	}else{
		cout << "Not Found\n";
	}





	return 0;
}