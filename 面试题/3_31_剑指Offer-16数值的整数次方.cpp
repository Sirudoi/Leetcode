//剑指Offer16 - 数值的整数次方
//https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/submissions/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 1.0 || x == 0.0) return x;
        
        // n取值是[-2^31, 2^31-1]
        // 如果n是-2^31，取反会越界，因此用long存储
        long power = n;
        if (n < 0)
        {
            x = 1 / x;
            power = -power;
        }

        // 以2^10为例子：
        // 指数是偶数，直接底数平方，指数 / 2：2^10 = (2^2)^5 = 4^5
        // 指数是基数，拆掉一个底数，指数 - 1：4^5 = (4^4) * 4 
        // 指数是偶数，直接底数平方，指数 / 2：(4^4) * 4 = (4^2)^2 * 4 = 16^2 * 4
        // 指数是偶数，直接底数平方，指数 / 2：16^2 * 4 = 256^1 * 4 = 1024

        double base = x;  // 底数
        double other = 1;
        while (power > 1)
        {
            // 为基数，幂次-1，乘多一个底数
            if ((power & 1))
            {
                other *= base;
                power -= 1;
            }

            // 幂次 / 2
            power >>= 1;

            // 底数平方
            base = base * base;
        }
        base *= other;

        return base;
    }
};