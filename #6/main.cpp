#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

string solution(const vector<int> &peoples)
{
    int even_misscount = 0, odd_miscount = 0;
    int a = -1, b = -1;
    for(int i = 0; i < peoples.size(); ++i)
    {
        if(peoples[i] % 2 == 0 && i % 2 == 0)
        {
            even_misscount++;
            a = i + 1;
        }
        else if(peoples[i] % 2 != 0 && i % 2 != 0)
        {
            odd_miscount++;
            b = i + 1;
        }
    }
    if(even_misscount == 0 && peoples.size() > 2)
    {
        return "1 3";
    }
    if(even_misscount == 1 && odd_miscount == 1)
    {
        return to_string(a) + ' ' + to_string(b);
    }
    return "-1 -1";
}

int main()
{
    int n;
    cin >> n;
    vector<int> peoples(n);
    peoples.reserve(n);
    for(auto &item : peoples)
    {
        cin >> item;
    }
    cout << solution(peoples);
    return 0;
}
