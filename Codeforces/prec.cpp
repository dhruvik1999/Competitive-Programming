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
    vector<int> a(5);

    for(int i=0;i<5;i++){
        a.push_back(i+10);
    }

    cout << *lower_bound( a.begin() , a.end() , 2  ) << "\n";    
}