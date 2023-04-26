//75. 颜色分类
//https://leetcode.cn/problems/sort-colors/
//一、快排
class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int keyi = left;
        int l = left;
        int r = right;

        while (l < r) {
            while (r > l && nums[r] >= nums[keyi])
                --r;
            
            while (r > l && nums[l] <= nums[keyi])
                ++l;
            
            swap(nums[r], nums[l]);
        }
        swap(nums[keyi], nums[l]);

        quickSort(nums, left, l - 1);
        quickSort(nums, l + 1, right);
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};

//双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int cur = 0;

        for (int i = 0; i <= right; ++i) {
			//如果换完还是2，继续换，换到i位置不是2才继续
            while (i <= right && nums[i] == 2) {
                swap(nums[i], nums[right]);
                --right;
            }

			//如果i位置是0，往左边换
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                ++left;
            }
        }
    }
};