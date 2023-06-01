#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool ispalin(string s, int start, int end)
{
    while (start == end)
    {
        if (s[start] != s[end--])
            return false;
    }
    return true;
}

void palinpart(int ind, string s, vector<string> &path, vector<vector<string>> &ans)
{
    if (s.size() == ind)
    {
        ans.push_back(path);
        return;
    }
    for (int i = ind; i < s.size(); ++i)
    {
        if (ispalin(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1));
            palinpart(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> f(string s)
{
    vector<vector<string>> ans;
    vector<string> path;
    palinpart(0, s, path, ans);
    return ans;
}
int main()
{
    string str;
    cout << "Enter a string." << endl;
    cin >> str;
    vector<vector<string>> res;
    res = f(str);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}