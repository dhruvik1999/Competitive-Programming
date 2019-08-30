#include<bits/stdc++.h>
using namespace std;


bool cmp(const pair< pair<int,int> ,  pair< int,double > > a,const pair< pair<int,int> ,  pair< int,double > > b){
	return a.second.first < b.second.first;
}


double dis(int x1,int y1,int x2,int y2){
	double ans = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

	return ans;
}

int main(){
	int n;
	cin >> n;

	vector< pair< pair<int,int> ,  pair< int,double > > > a;
	vector< double > dp(n+10,0);

	int t1,t2,t3;
	double d4;

	for(int i=0;i<n;i++){
		cin >> t1 >> t2 >> t3 >> d4;
		a.push_back( make_pair( make_pair(t1,t2) , make_pair(t3,d4) ) );
		//dp[i]=d4;
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n;i++){
		//cout << a[i].second.first << "\n";
		dp[i] = a[i].second.second;
	}

	for(int i=n-2;i>=0;i--){
		for(int j=i+1;j<n;j++){
			if( dis( a[j].first.first , a[j].first.second , a[i].first.first , a[i].first.second  )  <= a[j].second.first - a[i].second.first){
				dp[i]+=dp[j];
			}
		}
	}



	double ans = 0;

	for(int i=0;i<n;i++){
		if(dp[i]>ans){
			ans = dp[i];
		}
	}

	printf("%0.9f\n",ans);





	return 0;
}