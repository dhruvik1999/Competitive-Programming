#include<bits/stdc++.h>
using namespace std;
int a[100][2];


int main(){

	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		a[i][0]=-1;
		a[i][1]=-1;
	}

	int edge = n-1;
	char direction;
	int from,to;

	for(int i=0;i<edge;i++){
		cin >> direction >> from >> to;
		if(direction=='L'){
			a[from][0]=to;
		}else{
			a[from][1]=to;
		}
	}

	//q_left.push(1);
	int root;
	cin >> root;

	stack<int> left,right;

	left.push(root);
	int temp;
	while(left.size()!=0 || right.size()!=0){
		if(left.size()!=0){
			while(left.size()!=0){
				temp = left.top();
				left.pop();
				cout << temp << " ";
				if(a[temp][0]!=-1)
					right.push(a[temp][0]);
				if(a[temp][1]!=-1)
					right.push(a[temp][1]);
			}
		}else if(right.size()!=0){
			while(right.size()!=0){
				temp = right.top();
				right.pop();
				cout << temp << " ";
				if(a[temp][1]!=-1)
					left.push(a[temp][1]);
				if(a[temp][0]!=-1)
					left.push(a[temp][0]);

			}
		}else{
			break;
		}
	}


}