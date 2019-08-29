#include<bits/stdc++.h>
using namespace std;
vector<int> maxone(vector<int> &a, int b) {
	int n = a.size();
	int l=0,r=0;
	int numzero = 0;
	int diff =0;
	vector<int> ans;
	int p,q;

	while(r<n){

	if(numzero <= b){

		while(numzero + (a[r]==0) <=b){

			if(a[r]==0){
				numzero++;
			}
			r++;
		}

	}else{
		while(numzero>b){
			if(a[l]==0){
				numzero--;
			}
			l++;
		}
	}

	cout << l << " " << r-1 << "\n";

	if(diff < r-l){
		diff = r-l;
		p=l;
		q=r-1;

	}

	}

	for(int i=p;i<=q;i++){
		ans.push_back(i);
	}
	return ans;
}

int main(){
	
	int n;
	cin   >> n;
	int b;

	vector<int> a(n);

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	cin >> b;
	cout << "B : " << b << "\n"; 
	vector<int> ans = maxone(a,b);

	for(int i=0;i<ans.size();i++){
		cout << ans[i] << "\n";
	}




	return 0;
}