#include<bits/stdc++.h>
using namespace std;

int main(){


	priority_queue< pair<int,int> , vector< pair<int,int> > , greater<>> pq;
	pq.push({1,1});
	pq.push({2,2});

	cout << pq.top().first << "\n";



	return 0;
}