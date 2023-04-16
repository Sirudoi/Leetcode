//461. 汉明距离
//https://leetcode.cn/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
		//异或，结果二进制位为1则不相同
        int ans = x ^ y;
        int cnt = 0;
		//求有几个1
        while (ans)
        {
            if (ans & 1)
                ++cnt;
            ans = ans >> 1;
        }

        return cnt;
    }
};

//使用c++内置库函数计算1的个数
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};