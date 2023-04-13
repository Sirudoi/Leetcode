//4. 寻找两个正序数组的中位数
//https://leetcode.cn/problems/median-of-two-sorted-arrays/
class Solution {
public:
    int getKthLargeNum(vector<int>& nums1, vector<int>& nums2, int k)
    {
        //写不出注释，每天看一遍吧
        int start1 = 0;
        int start2 = 0;
        while (true)
        {
            //边界情况
            //nums1都删掉了，返回nums2第k大的数
            if (start1 == nums1.size())
                return nums2[start2 + k - 1];
            //nums2都删掉了，返回nums1第k大的数
            if (start2 == nums2.size())
                return nums1[start1 + k - 1];
            
            //终止条件，k == 1时找到目标，返回最小的
            if (k == 1)
                return min(nums1[start1], nums2[start2]);

            //调整右边界
            
            int index1 = min(start1 + k / 2 - 1, (int)(nums1.size() - 1));
            int index2 = min(start2 + k / 2 - 1, (int)(nums2.size() - 1));
            //nums1中小于pivot1的数有k/2 - 1个
            //nums2中小于pivot2的数有k/2 - 1个
            int pivot1 = nums1[index1];
            int pivot2 = nums2[index2];
            //1. 取pivot1，则两数组合并后，比pivot1小的数有：
            //   nums1数组中的[0, k/2 - 1]共k/2 - 1个，这k/2 - 1个数一定小于pivot1
            //   nums2数组中的[0, k/2 - 1]共k/2 - 1个，这k/2 - 1个数中，可能有若干个数小于pivot1，但是最多只有k/2 - 1个
            //   因此pivot1最大是(k/2 - 1 + k/2 - 1)即第k-2大的数
            //   所以此时可以排除确切小于等于pivot1的数，即nums1数组中的[0, k/2]
            //
            //2. 取pivot2，则两数组合并后，比pivot2小的数有：
            //   nums2数组中的[0, k/2 - 1]共k/2 - 1个，这k/2 - 1个数一定小于pivot2
            //   nums1数组中的[0, k/2 - 1]共k/2 - 1个，这k/2 - 1个数中，可能有若干个数小于pivot2，但是最多只有k/2 - 1个
            //   因此pivot2最大是(k/2 - 1 + k/2 - 1)即第k-2大的数
            //   所以此时可以排除确切小于等于pivot2的数，即nums2数组中的[0, k/2]
            if (pivot1 <= pivot2)
            {
                //删掉了[start1, index1]的元素，k也减少掉对应个
                //这里要+1，例如删掉[0,1]删了两个
                k -= (index1 - start1 + 1);
                //删掉[start1, index1]的元素，即更新左边界
                start1 = index1 + 1;
            }
            else
            {
                k -= (index2 - start2 + 1);
                start2 = index2 + 1;
            }
        }

        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        //基数
        if (totalSize & 1)
            return getKthLargeNum(nums1, nums2, (totalSize + 1) / 2);
        else
            return (getKthLargeNum(nums1, nums2, totalSize / 2) + getKthLargeNum(nums1, nums2, totalSize / 2 + 1)) / 2.0;
    }
};