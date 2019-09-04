#include<bits/stdc++.h>
using namespace std;

int main(){	
	int n;
	cin >> n;

	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	vector<int> ans(n+10);
	vector<int> fans;
	for(int i=n;i>=1;i--){
		int t = 0;
		for(int j=1;j<=n;j++){
			if(i*j<=n){
				t+=ans[j*i];
			}else{
				break;
			}
		}
		if(t%2==0){
			if(a[i]==1){
				ans[i]=1;
				fans.push_back(i);
			}else{
				ans[i]=0;
			}
		}else{
			if(a[i]==1){
				ans[i]=0;
			}else{
				ans[i]=1;
				fans.push_back(i);
			}
		}
	}

	sort(fans.begin(),fans.end());
	cout << fans.size() << "\n";
	for(int i=0;i<fans.size();i++){
		cout  << fans[i] << " ";
	}
	cout << "\n";



	return 0;
}