#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long

using namespace std;

void func(int *pre,int *in,int il,int ir,int pl,int pr){

	if(il>ir || pl>pr){

		return;
	}

	int t=il;

	for(;t<=ir;t++){
		if(in[t]==pre[pl]){
			break;
		}
	}

	cout <<il << "-" <<ir << " | " << pl << "-" << pr << "|" << " " <<  pre[pl] << "\n";

	func(pre,in,t+1,ir,pl+t-il+1,pr);
	func(pre,in,il,t-1,pl+1,pl+t-il);

}



int main(){

	int n;
	cin >> n;

	int pre[n],in[n];

	for(int i=0;i<n;i++){
		cin >> in[i];
	}

	for(int i=0;i<n;i++){

		cin >> pre[i];
	}

	func(pre,in,0,n-1,0,n-1);
	return 0;
}

