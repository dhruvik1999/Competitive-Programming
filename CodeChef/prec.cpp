#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> a(n);
		vector<int> neg;
		int nn=0;
		int ans = 1;

		for(int i=0;i<n;i++){
			cin >> a[i];
			ans*=a[i];

			if(a[i]<0){
				nn++;
				neg.push_back(i);
			}
		}


		if(nn%2==1){
			cout << ans << "\n";
			return 0;
		}else if(nn!=0 && nn%2==0){
			int temp=1;
			ans = INT_MAX;
			for(int i=0;i<neg.size();i++){
				temp = 1;
				for(int j=0;j<n;j++){
					if(j==neg[i]){
						if(i%2==0){
							temp += a[i];
						}else{
							temp -= a[i];
						}
					}else{
						temp *= a[j];
					}
				}

				ans = min(ans , temp);
			}

			cout << ans << "\n";
			return 0;
		}else{
			cout << "ALL  POS" << "\n";
		}


	}
	return 0;
}