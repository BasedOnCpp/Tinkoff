#include <iostream>

using namespace std;

int main()
{
    int traffic, rate, rate_size, additional_cost;
    cin >> traffic >> rate >> rate_size >> additional_cost;
    cout << (traffic + (additional_cost > rate ? additional_cost - rate : 0) * rate_size);
    return 0;
}
