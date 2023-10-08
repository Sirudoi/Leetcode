// https://leetcode.cn/problems/3sum/?envType=featured-list&envId=2cktkvj?envType=featured-list&envId=2cktkvj

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        if (nums.size() < 3 || nums[0] > 0)
            return ret;

        // 外层循环控制起始位置, 用于去重, 保证左指针指向数据不重复
        for (int i = 0; i < nums.size(); ++i) {
            // 跳过重复, 排序就是为了去重, 保证左边开始每次都是不重复的值
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                // 三数之和 == 0, 插入结果
                if (nums[i] + nums[left] + nums[right] == 0) {
                    ret.push_back({nums[i], nums[left], nums[right]});

                    // 跳过左右指针的重复值
                    while (left < right && nums[left + 1] == nums[left]) ++left;
                    while (left < right && nums[right - 1] == nums[right]) --right;

                    // 更新左右指针, 继续往下找
                    ++left;
                    --right;
                }
                // 三数之和 > 0, 说明右指针值太大, 移动右指针
                else if (nums[i] + nums[left] + nums[right] > 0) {
                    --right;
                }
                // 三数之和 < 0, 说明左指针值太小, 移动左指针
                else {
                    ++left;
                }
            }
        }

        return ret;
    }
};