#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,k;
    cin >> n >> k;

    vector<long long> a(n);
    for(long long i=0;i<n;i++){
    	cin >> a[i];
    	//cout << a[i] << " ";
    }
    //cout << "\n";

    deque<long long> dq;

    long long i = 0;
    unordered_set<long long> s;

    while(dq.size()!=k && i<n){
    	if(s.find(a[i])==s.end()){
    		s.insert(a[i]);
    		dq.push_back(a[i]);
    	}
    	i++;
    }

     // for(long long i=dq.size()-1;i>=0;i--){
     // 	cout << dq[i] << " ";
     // }
     // cout << "\n";


    for(;i<n;i++){


    	if(s.find(a[i])==s.end()){

    		if(dq.size()==k){
    		long long y = dq.front();
    		dq.pop_front();
    		s.erase( s.find(y) );
    		//cout << "-" << y << "\n";
    		}

    		s.insert(a[i]);
    		dq.push_back(a[i]);
    	}

    }

    cout << dq.size() << "\n";
    for(long long i=dq.size()-1;i>=0;i--){
    	cout << dq[i] << " ";
    }
    cout << "\n";



    
	return 0;
}