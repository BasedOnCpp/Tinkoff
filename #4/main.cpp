#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct ReplacementPosition
{
    size_t row;
    size_t column;
};

ReplacementPosition get_next_position(vector<string> &nums, size_t column)
{
    // out of bound
    if(column == nums[0].size())
    {
        return {((size_t)-1), 0};
    }

    int cur_value = '9';
    size_t row = 0;
    bool found = false;
    for(size_t i = 0; i < nums.size(); ++i)
    {
        if(nums[i][column] < cur_value)
        {
            found = true;
            cur_value = nums[i][column];
            row = i;
        }
    }
    if(!found)
    {
        return get_next_position(nums, column + 1);
    }
    return {row, column};
}

int64_t solve(vector<string> &nums, int k)
{
    ReplacementPosition coord{((size_t)-1), 0};

    int64_t total_sum = 0;
    while(k)
    {
        coord = get_next_position(nums, coord.column);

        // give up :(
        if(coord.row == -1)
        {
            break;
        }

        total_sum += ('9' - nums[coord.row][coord.column]) * pow(10, nums[coord.row].size() - coord.column - 1);
        nums[coord.row][coord.column] = '9';

        coord.row = -1;
        k--;
    }
    return total_sum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> nums(n);
    stringstream ss;
    for(auto &item : nums)
    {
        cin >> item;
        ss << setw(10) << setfill('9') << item;
        ss >> item;
        ss.clear();
    }
    
    cout << solve(nums, k);
    return 0;
}
