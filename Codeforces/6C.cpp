#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int l=0,r=n-1,ls=0,rs=0,ansl=0,ansr=0;

	while(l<=r){
		if(n-ansl-ansr==1 && ls==rs){
			ansl++;
			l++;
		}else{
			if(ls<rs){
				ls+=a[l];
				ansl++;
				l++;
			}else{
				rs+=a[r];
				ansr++;
				r--;
			}
		}
	}

	cout << ansl << " " << ansr << "\n";


	return 0;
}