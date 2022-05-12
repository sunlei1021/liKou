/*寻找数组的中心索引
给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/array-and-string/yf47s/
来源：力扣（LeetCode）

数组的总和为total 索引i 的值为 nums[i] 左侧总和为 sum 左右两侧总和相同
右侧总和 sum =total-sum-nums[i];
也即是 total == 2*sum + nums[i]

*/
#include<iostream>
#include<numeric>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                std::cout << i << std::endl;
                return i;
            }
            sum += nums[i];
        }

        return -1;
    }
};

int main () {
    vector <int> v1;
    v1.push_back(1);
    v1.push_back(7);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(5);
    v1.push_back(6);

    Solution sl;
    sl.pivotIndex(v1);

    return 0;
}
