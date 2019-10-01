#include<bits/stdc++.h>
using namespace std;

int main(){


	int n;
	cin >> n;

	vector<int> mod(n+1,0);
	vector<int> a(n+1,0);

	for(int i=1;i<=n;i++){
		cin >> mod[i];
	}

	vector<int> ans;
	for(int i=n;i>=1;i--){
		int j=2;
		int cnt = 0;
		while(j*i<=n){
			if(a[j*i]==1){
				cnt++;
			}
			j++;
		}

		if(mod[i]==1){
			if(cnt%2==0){
				a[i]=1;
				ans.push_back(i);
			}else{
				a[i]=0;
			}
		}else{
			if(cnt%2==0){
				a[i]=0;
			}else{
				a[i]=1;
				ans.push_back(i);
			}
		}

	}

	sort(ans.begin(),ans.end());

	cout  << ans.size() << "\n";

	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	cout << "\n";



	return 0;
}