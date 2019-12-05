#include<bits/stdc++.h>
using namespace std;

vector<long long int> prim;
void genPrime(){
	vector<long long int> a(500001,1);
	a[0]=a[1]=-1;

	for(long long int i=2;i<=500000;i++){
		if(a[i]==-1)
			continue;
		prim.push_back(i);
		for(long long int j=i*i;j<=500000;j+=i){
			a[j]=-1;
		}
	}
}

int main(){

	long long int n;
	cin >> n;

	long long int p=0,q=0;
	vector<long long int> a(n);
	int tsum = 0;

	for(long long int i=0;i<n;i++){
		cin >> a[i];
		tsum+=a[i];
		if(a[i]==1){
			p++;
		}else{
			q++;
		}
	}

	genPrime();

	// for(long long int i=0;i<prim.size();i++){
	// 	cout << prim[i] << " ";
	// }
	// cout << "\n";

	int psum=0;
	vector<int> ans;
	int diff,req2,req1;
	queue<int> que;
	for(int i=0;i<prim.size();i++){
		if(prim[i]<=tsum){
			que.push(prim[i]);
		}else{
			if(tsum==1)
				que.push(1);
			break;
		}
	}

	while(que.size()!=0){
		int trg = que.front();
		que.pop();

		while( q!=0 && psum+2<=trg ){
			ans.push_back(2);
			psum+=2;
			q--;

			if(psum>=trg)
				break;

		}

		while(p!=0 && psum+1<=trg){
			ans.push_back(1);
			psum+=1;
			p--;
			if(psum>=trg)
				break;
		}


	}

	while(p!=0){
		ans.push_back(1);
		p--;
	}
	while(q!=0){
		ans.push_back(2);
		q--;
	}

	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	cout << "\n";



	return 0;
}