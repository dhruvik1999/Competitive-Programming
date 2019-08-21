#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> a(n),freq(1000,0);
		for(int i=0;i<n;i++){
			cin >> a[i];
			freq[a[i]]++;
		}

		int ev=0;
		for(int i=0;i<1000;i++){
			if(freq[i]!=0 && freq[i]%2==0){
				ev++;
			}
		}

		a.erase( unique(a.begin(),a.end()) , a.end());
		ev += a.size();

		if(ev%2==0){
			cout << "First" << "\n";
		}else{
			cout << "Second" << "\n";
		}


	}
}