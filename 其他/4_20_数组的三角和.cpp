//2221. 数组的三角和
//https://leetcode.cn/problems/find-triangular-sum-of-an-array/
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        //   1  2  3  4  5
        //-> 3] 2  3  4  5
        //-> 3  5] 3  4  5
        //-> 3  5  7] 4  5
        //-> 3  5  7  9] 5
        //从左向右计算，结果存储到左边就不影响
        for (int i = nums.size(); i > 0; --i) {
            for (int j = 0; j < i - 1; ++j) {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }

        return nums[0];
    }
};