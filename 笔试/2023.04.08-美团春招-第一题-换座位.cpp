//2023.04.08-美团春招-第一题-换座位
//http://www.codefun2000.com/p/P1166
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int calSum(const string& pre, const string& cur, const int& a)
{
    //不同则++计数
    int cnt = 0;
    for (int i = 0; i < a; ++i)
    {
        if (pre[i] != cur[i])
            ++cnt;
    }
    return cnt;
}

int main()
{
    int n, m, a;
    cin >> n >> m >> a;
    vector<vector<string>> place;
    for (int i = 0; i < n; ++i)
    {
        vector<string> row;
        for (int j = 0; j < m; ++j)
        {
            string in;
            cin >> in;
            row.emplace_back(in);  
        }
        place.emplace_back(row);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        //第i行调整后的行
        int row = (i + 1) % n;
        for (int j = 0; j < m; ++j)
        {
            //第j列调整后的列
            int col = (j + 1) % m;
            //比较调整前[i][j]，和调整后[row][col]
            cnt += calSum(place[row][col], place[i][j], a);
        }
    }
    cout << cnt << endl;

    return 0;
}