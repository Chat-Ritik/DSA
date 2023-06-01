#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int f(int n, int x, vector<int> &v)
{
    int temp;
    if (x == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] == temp)
                return -1;
        }
        return temp;
    }
    int maxi = max_element(v, v + n);
    int index = distance(v, maxi);
    temp = v[index];
    v[index] = 0;
    f(n, x - 1, v);
}

int main()
{
    int N, X;
    vector<int> vec;
    cout << "Enter N and X." << endl;
    cin >> N;
    cin >> X;
    cout << "Enter energy levels." << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int res = f(N, X, vec);
    cout << res;
    return 0;
}