#include<bits/stdc++.h>
using namespace std;

bool check( vector<int> &a,int k,int gap ){
	int sum = 0,ans = 0;

	int l=-1,r=-1;

	for(int i=0;i<gap;i++){
		sum+=a[i];
		r++;
		l=0;
	}

	if(sum>=k)
			return true;

	while(r<a.size()){
		if(sum>=k)
			return true;
		
		sum-=a[l];
		l++;
		r++;
		if(r<a.size())
			sum+=a[r];
	}

	return false;

}


int main(){

	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int l=0,r=n;
	int ans = n;

	while(l<=r){
		int mid = (l+r)>>1;
		cout << mid << "\n";
		if( check(a,k,mid) ){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}

	}

	cout << ans << "\n";


	return 0;
}