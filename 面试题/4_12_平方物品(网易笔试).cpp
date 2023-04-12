//网易2021C++提前批笔试题
//1.平分物品
//现在有n个物品，每一个物品都有一个价值，现在想将这些物品分给两个人，
//要求这两个人每一个人分到的物品的价值总和相同（个数可以不同，总价值相同即可），
//剩下的物品就需要扔掉，现在想知道最少需要扔多少价值的物品才能满足要求分给两个人。
//https://www.nowcoder.com/questionTerminal/908255677b6f4c18a9074c12f21acd59?answerType=1&f=discussion

//一个物品有三种状态，给第一个人，给第二个人，都不给
//利用DFS可以遍历所有状态
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;
 
int ans = INT_MAX;
 
void backTrack(vector<int>& value, int sum1, int sum2, const int& maxVal,
               int index) {
    if (sum1 > (maxVal >> 1) || sum2 > (maxVal >> 1))
        return;
     
    if (index == value.size())
    {
        if (sum1 == sum2)
            ans = min(ans, maxVal - sum1 - sum2);
        return;
    }
 
    //给第一个人
    backTrack(value, sum1 + value[index], sum2, maxVal, index + 1);
 
    //给第二个人
    backTrack(value, sum1, sum2 + value[index], maxVal, index + 1);
 
    //都不给
    backTrack(value, sum1, sum2, maxVal, index + 1);
}
 
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> value;
        int input;
        while (n--) {
            cin >> input;
            value.emplace_back(input);
        }
        int maxVal = accumulate(value.begin(), value.end(), 0);
        backTrack(value, 0, 0, maxVal, 0);
        cout << ans << endl;
        ans = INT_MAX;
    }
 
    return 0;
}