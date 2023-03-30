//剑指Offer14 - 剪绳子Ⅱ
//https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/
//这里因为C++会溢出，不好用动规，建议用贪心
//但是为了和剪绳子Ⅰ一起，所以放到了动规里
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        
        long sum = 1;
        while (n > 0)
        {
			//除非遇到4和2
            if (n == 4 || n == 2)
            {
                n -= 2;
                sum = (sum * 2) % 1000000007;
            }
			//否则每次都分3
            else
            {
                n -= 3;
                sum = (sum * 3) % 1000000007;
            }
        }

        return sum;
    }
};