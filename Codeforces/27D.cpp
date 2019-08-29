    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
     
    	int n,k;
    	cin >> n >> k;
     
    	vector< pair<int,int> > a(n);
    	int t1,t2;
    	for(int i=0;i<k;i++){
    		cin>>t1>>t2;
    		if(t2<t1)
    			t2+=n;
    		a[i] = make_pair(t1-1,t2-1);
    	}
     
    	vector<int> go(n,0),gi(n,0);
     
    	string ans = "";
    	for(int i=0;i<k;i++){
    		cout << ans  << "\n";
    		go[ a[i].first ]=(i+1);
    		int j=a[i].first+1;
    		stack<int> s;
    		for(;j<a[i].second;j++){
    			if(go[j%n]!=0){
    				if(s.size()!=0 && s.top()==go[j%n]){
    					s.pop();
    				}else{
    					s.push(go[j%n]);
    				}
    			}
    		}
     
    		if(s.size()==0){
    			go[(j)%n]+	=i+1;
    			ans+="o";
    			continue;
    		}
    		go[ a[i].first ]=0;
     
     
    		gi[ a[i].first ]=(i+1);
    		j=a[i].first+1;
    		stack<int> ss;
    		for(;j<a[i].second;j++){
    			if(gi[j%n]!=0){
    				if(ss.size()!=0 && ss.top()==gi[j%n]){
    					ss.pop();
    				}else{
    					ss.push(gi[j%n]);
    				}
    			}
    		}
     
    		if(ss.size()==0){
    			gi[(j)%n]=i+1;
    			ans+="i";
    		}else{
    			cout << "Impossible" << "\n";
    			return 0;
    		}
    	}
     
    	cout << ans << "\n";
     
    	return 0;
    }