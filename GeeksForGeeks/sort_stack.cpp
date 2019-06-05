#include<bits/stdc++.h>
using namespace std;

int sort(stack<int> s,int largest){
	if(s.size()==0)
		return INT_MIN;

	int temp = s.top();
	int ans = INT_MIN;
	s.pop();
	if( temp < largest ){
		ans = max(temp , sort(s,largest) );
	}else{
		ans = sort(s,largest);
	}
	s.push(temp);
	return ans;
}

int main(){
	int n;
	cin >> n;

	stack<int> s,final;
	int temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		s.push(temp);
	}

	temp = INT_MAX;

	for(int i=0;i<s.size();i++){
		temp = sort(s,temp);
		cout << temp << " ";
	}

	cout << "\n";




	return 0;
}