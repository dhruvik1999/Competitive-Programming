#include<bits/stdc++.h>
using namespace std;
vector< int > v[30];
int inEdge[30];

void addEdge(string a,string b){
	int e = min( a.length() , b.length() );
	for(int i=0;i<e;i++){
		if(a[i] != b[i]){
			v[a[i] - 'a'].push_back(b[i] - 'a');
			if(inEdge[a[i]-'a']==-1){
				inEdge[a[i]-'a']=0;
			}

			if(inEdge[b[i]-'a']==-1){
				inEdge[b[i]-'a']=1;
			}else{
				inEdge[b[i]-'a']++;
			}
			break;
		}
	}	
}

int main(){	
	int n;
	cin >> n;

	string a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];

	memset(inEdge,-1,sizeof(inEdge));


	for(int i=1;i<n;i++){
		addEdge(a[i-1],a[i]);
	}

	stack<int> s;

	for(int i=0;i<26;i++){
		if(inEdge[i]==0){
			s.push(i);
		}
	}
	int temp;
	while(s.size()!=0){
		temp = s.top();
		s.pop();
		cout << (char)(temp+'a') << " ";

		for(int i=0;i<v[temp].size();i++){
			inEdge[v[temp][i]]--;
			if(inEdge[v[temp][i]]==0){
				s.push(v[temp][i]);
			}
		}

	}



	return 0;
}