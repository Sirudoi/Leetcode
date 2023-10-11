class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 需要找到下一个排序, 即要将后面的[大数], 和前面的[小数]交换即可
        // 例如123456 -> 下一个排列就是123465, 交换尾巴两个数
        // 在这个过程, 需要满足一种条件, 即对于交换的两个数nums[i], nums[j], 其中还需要满足两个条件
        // 1. [i + 1, nums.size() - 1]区间的数一定是递增的, 这样才能保证是最小下一个排列
        // 2. 需要保证交换的[大数]尽可能小, 即找最右边的数交换
        // 从后往前找, 如果后面 < 前面, 则继续找, 即找到第一个可以交换的数i时, [i + 1, nums.size() - 1]区间一定是递减的
        // 例如6666132 下一个是 666312, 而不是666312
        // 6661[32]
        //    []内递减, 找到第一个非递减, 和靠右的位置换, 且满足nums[i] < nums[j]
        // 666[1]3[2] --> 666[2]3[1] , 且需要保证换完之后, 尾区间需要递增
        // 666231 --> 666213 此时即为所求

        if (nums.size() <= 1)
            return;
        
        int i = nums.size() - 2;
        int j = nums.size() - 1;
        int k = nums.size() - 1;

        // 找满足后面的[大数], 和前面的[小数]
        // 即nums[j] > nums[i]
        for (; i >= 0 && nums[i] >= nums[j]; --i, --j)
            ;
        
        // 不是最大排列
        if (i >= 0) {
            // nums[i] < nums[k]
            for (; nums[i] >= nums[k]; --k)
                ;
            swap(nums[i], nums[k]);

            // 由上面得知, [i + 1, nums.size() - 1]区间是递增的, 我们需要让这个区间递减
            // 即[j, nums.size() - 1]区间递减, 需要逆置这段区间
            reverse(nums.begin() + j, nums.end());
        }
        // 最大排列直接逆置数组
        else {
            std::reverse(nums.begin(), nums.end());
        }
    }
};