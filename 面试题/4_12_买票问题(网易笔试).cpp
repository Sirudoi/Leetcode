//网易2021C++提前批笔试题
//2.买票问题
//现在有n个人排队买票，已知是早上8点开始卖票，这n个人买票有两种方式：
//第一种是每一个人都可以单独去买自己的票，第 i 个人花费 a[i] 秒。
//第二种是每一个人都可以选择和自己后面的人一起买票，第 i 个人和第 i+1 个人一共花费 b[i] 秒。
//最后一个人只能和前面的人一起买票或单独买票。
//由于卖票的地方想早些关门，所以他想知道他最早几点可以关门，请输出一个时间格式形如：08:00:40 am/pm
//时间的数字要保持 2 位，若是上午结束，是 am ，下午结束是 pm
//

//动态规划
//dp[i]表示前i个人最短用时
//dp[i] = min{前i - 1个人 + 第i个人， 前i - 2个人 + 第i - 1和第i个一起买}
//dp[i] = min(dp[i - 1] + arrA[i], dp[i - 2] + arrB[i - 1]);
//最后需要控制一下初始格式是时间
//12点算am，淦
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int Solution(vector<int>& arrA, vector<int>& arrB) {
    if (arrA.size() == 1)
        return arrA[0];
    if (arrA.size() == 2)
        return min(arrA[0] + arrA[1], arrB[0]);
 
    vector<int> dp(arrA.size(), 0);
    dp[0] = arrA[0];
    dp[1] = min(arrA[0] + arrA[1], arrB[0]);
 
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = min(dp[i - 1] + arrA[i], dp[i - 2] + arrB[i - 1]);
    }
 
    return dp[dp.size() - 1];
}
 
int main() {
    //T组测试数据
    int T;
    cin >> T;
    while (T--) {
        //n个人
        int n = 0;
        cin >> n;
        vector<int> arrA;
        vector<int> arrB;
 
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            arrA.emplace_back(a);
        }
 
        for (int i = 0; i < n - 1; ++i) {
            cin >> b;
            arrB.emplace_back(b);
        }
 
        int useTime = Solution(arrA, arrB);
 
        int h = 8;
        int m = 0;
        int s = 0;
        h += (useTime / 3600) % 24;
        m += (useTime / 60) % 60;
        s += useTime % 60;
        if (h <= 12)
            printf("%02d:%02d:%02d am\n", h, m, s);
        else printf("%02d:%02d:%02d pm\n", h, m, s);
    }
 
    return 0;
}