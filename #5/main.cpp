#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

bool is_valid_num(int64_t num)
{
    int digit = num % 10;
    while(num != 0)
    {
        if(num % 10 != digit)
        {
            return false;
        }
        num /= 10;
    }
    return true;
}

int64_t solve(int64_t bound)
{
    int total_nums = 0;
    int64_t copy = bound, test_value = 0;

    while(bound > 9)
    {
        total_nums += 9;
        bound  /= 10;
    }

    stringstream ss;
    ss << string(to_string(copy).size(), bound + '0');
    ss >> test_value;
    
    return total_nums + bound - (copy < test_value);
}

int64_t solve(int64_t left_bound, int64_t right_bound)
{
    return solve(right_bound) - solve(left_bound - 1);
}

int main()
{
    int64_t l, r;
    cin >> l >> r;
    cout << solve(l, r);
    return 0;
}
