#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,m;
	cin >> n >> m;

	int a[n];

	for(int i=0;i<n-m;i++){
		cin >> a[i];
	}

	priority_queue<int,vector<int>,greater<int>> pq;
	int temp;
	for(int j=0;j<m;j++){
		cin >> temp;
		pq.push(temp);
	}

	for(int i=0;i<n-m;i++){
		if(pq.top() < a[i]){
			pq.push(a[i]);
			a[i]= pq.top();
			pq.pop();
		}
	}

	for(int i=n-m;i<n;i++){
		a[i] = pq.top();
		pq.pop();
	}


	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}




	return 0;
}