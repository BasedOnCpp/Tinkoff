#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int> &floors, int t, int employer_idx)
{
    // oneway
    if(floors[employer_idx] - floors[0] <= t || floors[floors.size() - 1] - floors[employer_idx] <= t)
    {
        return floors[floors.size() - 1] - floors[0];
    }
    int lhs = floors[employer_idx] - floors[0];
    int rhs = floors[floors.size() - 1] - floors[employer_idx];
    return min(lhs * 2 + rhs, lhs + rhs * 2);
}


int main()
{
    int n, t, last_employer;
    vector<int> floors(n);
    
    cin >> n >> t;
    for(auto &item : floors)
    {
        cin >> item;
    }
    cin >> last_employer;
    
    cout << solve(floors, t, last_employer - 1);
    return 0;
}
