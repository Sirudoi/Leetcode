// https://leetcode.cn/problems/container-with-most-water/?envType=featured-list&envId=2cktkvj?envType=featured-list&envId=2cktkvj

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针, 左右两个指针, 每一次移动垂线长度更小的哪一方, 不断维护一个最大值
        int left = 0;
        int right = height.size() - 1;
        int ret = 0;

        while (left < right) {
            int len = right - left;
            int high = height[left] > height[right] ? height[right--] : height[left++];
            ret = std::max(ret, len * high);
        }

        return ret;
    }
};