#include<bits/stdc++.h>
using namespace std;
int a[100][2];
queue <int> q_left,q_right;
bool vis[100];


int main(){

	int n;
	memset(vis,false,sizeof(vis));
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

	q_left.push(a[root][0]);
	q_right.push(a[root][1]);

	int temp1,temp2;

	//cout << root << " ";

	stack <int> ord;
	ord.push(root);

	while(q_left.size()!=0 || q_right.size()!=0){
		temp1=-1;
		temp2=-1;

		if(q_left.size()!=0){
			temp1 = q_left.front();
			q_left.pop();
			if(a[temp1][0]!=-1)
				q_left.push(a[temp1][1]);

			if(a[temp1][1]!=-1)
				q_left.push(a[temp1][0]);
		}
		if(q_right.size()!=0){


			temp2 = q_right.front();
			q_right.pop();
			if(a[temp2][0]!=-1)
				q_right.push(a[temp2][0]);

			if(a[temp2][1]!=-1)
				q_right.push(a[temp2][1]);

		}

		ord.push(temp2);
		ord.push(temp1);
		//cout << temp1 << " " << temp2 << " ";
	}

	while(ord.size()!=0){
		cout << ord.top() << " ";
		ord.pop();
	}

	cout << "\n";


	


	return 0;
}