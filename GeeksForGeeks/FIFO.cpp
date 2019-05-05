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

	int pf=0,ph=0;
	map <int,int> tr;
	int t;
	queue<int> q;

	int a[f];


	for(int i=0;i<f;i++){
		cin >> t;
		a[i] = t;

		q.push(t);
		tr[t]=1;
		pf++;
		printStatus(a,f);
		
	}


	for(int i=f;i<n;i++){
		cin >> t;
		if(tr[t]!=0){
			ph++;
		}else{
			int tt = q.front();
			tr[q.front()]=0;
			q.pop();
			for(int i=0;i<f;i++){
				if(a[i]==tt){
					a[i] = t;
				}
			}
			q.push(t);
			tr[t]=true;
			pf++;
		}
		printStatus(a,f);
	}

	cout << pf << " " << ph  << "\n";





	return 0;
}