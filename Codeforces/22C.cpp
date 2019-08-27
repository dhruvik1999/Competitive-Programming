#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m,v;
    cin >> n >> m >> v;

    if( m< (n-1) || m>((n-1)*(n-2))/2){
    	cout << -1 << "\n";
    	return 0;
    } 

    int temp;
    if(v!=1){
    	cout << 1 << " "<< v << "\n";
    	m--;

    	for(int i=1;i<n;i++){
    		if(i+1==v){
    			i+=1;
    		}else{
    			if(i==1)
    				temp=v;
    			else
    				temp=i;
    			cout << temp << " " << i+1 << "\n";
    		}
    		m--;
    	}

    	for(int i=1;i<=n;i++){
    		for(int j=i+2;j<=n && m>0;j++){
    			if(i==v){
    				break;
    			}
    			if(j==v)
    				continue;

    			if(i==1)
    				temp=v;
    			else
    				temp=i;

    			cout << temp << " " << j << "\n";
    			m--;
    		}
    	}


    }else{
    	cout << 1 << " " << n  << "\n";
    	m--;
    	n--;
    	for(int i=1;i<n;i++){

    			if(i==1)
    				temp=v;
    			else
    				temp=i;
    			cout << temp << " " << i+1 << "\n";
    		
    		m--;
    	}

    	for(int i=1;i<=n;i++){
    		for(int j=i+2;j<=n && m>0;j++){
    			if(i==v){
    				break;
    			}
    			if(j==v)
    				continue;

    			cout << i << " " << j << "\n";
    			m--;
    		}
    	}
    }



	return 0;
}