#include<bits/stdc++.h>
using namespace std;

// we can solve this question using unordered_map usinf O(N) time and O(N) space.

int main(){
	int n;
	cin >> n;


	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int ans;
	int counter=0;

	for(int i=0;i<n;i++){
		if(counter==0){
			ans=a[i];
			counter=1;
		}else if(ans==a[i]){
			counter++;
		}else{
			counter--;
		}
	}

	int temp=0;
	for(int i=0;i<n;i++){
		if(a[i]==ans){
			temp++;
		}
	}

	if(temp > n/2){
		cout << "Yes " << ans << "\n";
	}else{
		cout << "No";
	}


	return 0;
}