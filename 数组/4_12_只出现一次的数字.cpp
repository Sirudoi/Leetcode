//136. 只出现一次的数字
//https://leetcode.cn/problems/single-number/
//位运算，相同的数异或为0，和0异或等于本身
//把数组全部数异或一下，相同的都会抵消掉，最终得到的就是答案
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 2)
            return nums[0];

        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            ans ^= nums[i];
        }

        return ans;
    }
};