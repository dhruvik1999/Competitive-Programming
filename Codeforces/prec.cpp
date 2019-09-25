#include<bits/stdc++.h>
using namespace std;
struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};
int main(){

	priority_queue< int  , vector<int> , cmp > pq;
	pq.push(1);
	pq.push(2);
	pq.push(1);

	while(pq.size()!=0){
		cout << pq.top() << "\n";
		pq.pop();
	}




	return 0;
}