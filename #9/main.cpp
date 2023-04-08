#include <iostream>
#include <vector>

using namespace std;

int min_cost(size_t i, int tickets, const vector<int> &costs, vector<vector<int>> &dp)
{
    if(i >= costs.size())
    {
        return 0;
    }
    if(dp[i][tickets] != -1)
    {
        return dp[i][tickets];
    }

    if(tickets == 0)
    {
        return dp[i][tickets] = costs[i] + min_cost(i + 1, tickets + (costs[i] > 100), costs, dp);
    }

    int spend = 0 + min_cost(i + 1, tickets - 1, costs, dp);
    int hold = costs[i] + min_cost(i + 1, tickets + (costs[i] > 100), costs, dp);
    
    return dp[i][tickets] = min(spend, hold);
}

int main()
{
    int n;
    cin >> n;
    vector<int> costs(n);
    for(auto &item : costs)
    {
        cin >> item;
    }
    vector<vector<int>> dp(101, vector<int>(101, -1));
    cout << min_cost(0, 0, costs, dp);
    return 0;
}
