#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n;

    vector< vector<int> > a(n , vector<int>(n));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin >> a[i][j];
    	}
    }

    int ans = 0;
        for(int i=2;i<=10;i++){
            for(int j=0;j<i;j++){
            	int lock = false;
                for(int k=0;k<i;k++){
                    if( a[j][k]==0 ){
                    	lock = true;
                    	break;
                    }
                }
                if(lock)
                	break;
            }
        }
        

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "size" << endl;
}