#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <unordered_map>

using namespace std;

bool sequence_has_circle(const vector<int> &peoples)
{
    int visited = 1;
    int cur = 0;
    while((cur = peoples[cur]) != 0 && visited < peoples.size() + 1) visited++;
    return visited == peoples.size();
}

string solution(vector<int> peoples)
{
    unordered_map<int, int> unique;

    int dummy = -1, sum = 0;
    bool u = 0;
    for(int i = 0; i < peoples.size(); ++i)
    {
        peoples[i]--;
        sum += peoples[i];
        if(unique.find(peoples[i]) == unique.end())
        {
            unique[peoples[i]] = 1;
        }
        else
        {
            if(u == true)
            {
                return "-1 -1";
            }
            u = true;
            unique[peoples[i]]++;
            dummy = i;
        }
    }
    if(dummy == -1 || unique[peoples[dummy]] != 2)
    {
        return "-1 -1";
    }
    if(unique[peoples[dummy]] != 2)
    {
        return "-1 -1";
    }

    int replacement = ((peoples.size() - 1) * peoples.size() / 2 - (sum - peoples[dummy]));
    vector<int> idx;

    for(int i = 0; i < peoples.size(); ++i)
    {
        if(peoples[i] == peoples[dummy])
        {
            int prev = peoples[i];
            peoples[i] = replacement;
            if(sequence_has_circle(peoples))
            {
                return to_string(i + 1) + " " + to_string(replacement + 1);
            }
            peoples[i] = prev;
        }
    }
    return "-1 -1";
}

int main()
{
    int n;
    vector<int> peoples(n);
    
    cin >> n;
    for(auto &item : peoples)
    {
        cin >> item;
    }
    
    cout << solution(peoples);
    return 0;
}
