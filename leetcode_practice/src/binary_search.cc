#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

int Solutions::searchInsert(vector<int>& nums, int target) {
    
    int start = 0, end = nums.size() - 1;

    if (target > nums[end]) return end + 1;

    while(start <= end) {

        int mid = start + (end - start)/2;
        
        if (nums[mid] == target) return mid;
        else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return start;
}
/*
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
*/

bool Solutions::searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    
    int start = 0, end = m * n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (matrix[mid/n][mid%n] == target) return true;
        else if(matrix[mid/n][mid%n] < target) 
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}
/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

int Solutions::findPeakElement( std::vector<int> & nums)
{
    if (nums.size() == 1) {
        return 0;
    }
    if (nums.size() == 2) {
        if (nums[0] > nums[1]) {
            return 0;
        }
        return 1;
    }
    
    int start = 0, end = nums.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if ((mid == 0 || nums[mid] > nums[mid - 1] ) &&
            (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
            return mid;
        }
        else if (mid > 0 && nums[mid - 1] > nums[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    return -1;

/*
    int start = 0, end = nums.size();

    while (start <= end) {
        int mid = start + (end - start)/2;

        if (mid == start) break;

        if (nums[mid] > nums[mid - 1]) start = mid;
        else end = mid;
    }

    return start;
*/
}
/*
Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

int Solutions::search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[start] <= nums[mid]) {
            if (nums[start] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}
/*
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

vector<int> Solutions::searchRange(vector<int>& nums, int target) {
    int first = -1, last = -1;
    int start = 0, end = nums.size() - 1;

    // find first
    while(start <= end) {
        int mid = start + (end - start)/2;

        if(nums[mid] == target) {
            first = mid;
            end = mid - 1;
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else start = mid + 1;
    }

    start = 0, end = nums.size() - 1;

    // find last
    while(start <= end){
        int mid = start + (end - start)/2;

        if (nums[mid] == target) {
            last = mid;
            start = mid + 1;
        } else if(nums[mid] > target) {
            end = mid - 1;
        } else start = mid + 1;
    }

    return {first, last};
}
/*
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

int Solutions::findMin(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    int ans = INT_MAX;
    
    while(start <= end) {
        int mid = start + (end - start)/2;
        
        if(nums[start] <= nums[mid]) {
            ans = min(ans, nums[start]);
            start = mid + 1;
        } else {
            ans = min(ans, nums[mid]);
            end = mid - 1;
        }
    }
    return ans;
}
/*
Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/

int Solutions::indexEqualsValueSearch(const vector<int> &arr) 
{
    int start = 0, end = arr.size() -1;
    
    while(start <= end){
        int mid = start + (end - start)/2;
        
        if(mid == arr[mid])
            return mid;
        else if(mid < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
/*
input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2
*/

// Hard!!
double Solutions::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    if (m > n) {
        swap(nums1, nums2);
        swap(m, n);
    }
    
    int start = 0, end = m;
    
    while (start <= end) {
        int mid1 = start + (end - start) / 2;
        int mid2 = (m + n + 1) / 2 - mid1;
        
        int max1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int min1 = (mid1 == m) ? INT_MAX : nums1[mid1];

        int max2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int min2 = (mid2 == n) ? INT_MAX : nums2[mid2];
        
        if (max1 <= min2 && max2 <= min1) {
            if ((m + n) % 2 == 0) {
                return (max(max1, max2) + min(min1, min2)) / 2.0;
            } else {
                return max(max1, max2);
            }
        } else if (max1 > min2) {
            end = mid1 - 1;
        } else {
            start = mid1 + 1;
        }
    }

    return 0.0;
}
/*
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
*/

} /* namespace leetcode */
