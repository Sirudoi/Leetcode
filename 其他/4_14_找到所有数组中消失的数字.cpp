//448. 找到所有数组中消失的数字
//https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/
//利用nums数组原地标记
//依次取出nums数组的所有元素，对每一个元素x都有：
//x出现过，则标记nums[x - 1]位置（因为x是从1，n）
//这里采用的标记方法就是 + n
//最后遍历nums数组，如果nums[i]的数小于n，则表示i + 1这个数没有出现，因为没有被标记
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 1; i <= nums.size(); ++i) {
            //取出nums第i个元素，标记过需要取模
            int x = (nums[i - 1] - 1) % n;
            //x出现过，则
            nums[x] += n;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= n)
                ans.emplace_back(i + 1);
        }

        return ans;
    }
};