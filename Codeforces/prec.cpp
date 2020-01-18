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

    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    
    a.push_back(9);


    cout << *(upper_bound( a.begin() , a.end() , 5  )-1) << "\n";    
}