#include<bits/stdc++.h>
using namespace std;
void printStatus(int *a,int n){
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
int main(){
	int n,f;
	cin >> n >> f;

	int a[f];
	map <int,int> ma;


	int pf=0,ph=0;
	int t;

	for(int i=0;i<f;i++){
		cin >> a[i];
		ma[a[i]]=i;
		pf++;
		printStatus(a,f);

	}


	for(int i=f;i<n;i++){
		cin >> t;
		if(ma[t]==0){
			pf++;
			int mn = INT_MAX,mi=0;
			for(int j=0;j<f;j++){
				if(mn > ma[a[j]]){
					mn = ma[a[j]];
					mi = j;
				}
			}
			ma[a[mi]]=0;
			a[mi] = t;
			ma[t]=i;
		}else{
			ph++;
			ma[t]=i;
		}
		printStatus(a,f);
	}

	cout << "pf = " << pf << "\n" << "ph = " << ph << "\n";



	return 0;
}