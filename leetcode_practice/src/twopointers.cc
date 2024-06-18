#include "solutions.h"

#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

int Solutions::trap(std::vector<int>& height)
{
    // time: O(N) space: O(1)

    int start = 0, end = height.size() -1;
    int level = 0, water = 0;

    while(start <= end) {
        int lower = height[height[start] < height[end] ? start ++ : end --];
        level = max(lower, level);
        water += level - lower;
    }

    return water;
}
/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

/*
We would try to adopt two pointers approach that iterates through the array of height from both the left and right. At each pass,
we ensure that the water trapped would be dependent on the tower's height in the direction from right to left.
*/

bool Solutions::isPalindrome(std::string s)
{
    int start = 0, end = s.length() - 1;

    while(start <= end) {
        if ( !isalnum(s[start])) start++;
        else if( !isalnum(s[end])) end--;
        else if( tolower(s[start]) != tolower(s[end])) return false;
        else {start ++; end --;}
    }

    return true;
}
/*
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/


bool Solutions::isSubsequence(std::string s, std::string t)
{
    int len1 = 0, len2 = 0;
    
    while( len1 < s.length() && len2 < t.length()) {
       if(t[len2++] == s[len1]) len1++;
    }

    if (len1 == s.length()) return true;

    return false;
}
/*
Input: s = "abc", t = "ahbgdc"
Output: true
*/


std::vector<int> Solutions::twoSum(std::vector<int>& num, int target)
{
    std::sort(num.begin(), num.end());

    int start = 0, end = num.size() - 1;
    std::vector<int> ans;

    while(start < end) {
        if(num[start] + num[end] == target) return {start, end};
        else if (num[start] + num[end] < target) start ++;
        else end --;
    }

    return {-1, -1};
}
/*
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/

std::vector<std::vector<int>> Solutions::threeSum(std::vector<int> & nums)
{

    std::sort(nums.begin(), nums.end());

    if(nums.size() < 3) return {};
    std::vector<std::vector<int>> ans;

    for(int i = 0; i < nums.size()  - 2; i ++) {

        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i], start = i + 1, end = nums.size() -1;

        while(start < end) {
            int sum = nums[start] + nums[end];
            if (sum == target) {
                ans.push_back({nums[i],nums[start], nums[end]});

                while (start < end && nums[start] == nums[start + 1]) start ++;
		        while (start < end && nums[end] == nums[end - 1]) end --; 
                start ++; end --;
            } else if (sum > target) end --;
            else start ++;
        }
    }

    return ans;
}
/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

int Solutions::maxArea(std::vector<int>& height)
{
    int start = 0, end = height.size() - 1;
    int ans = 0;

    while(start < end) {
         int water = std::min(height[start], height[end])*(end - start); 
         ans = std::max(ans, water);
         if(height[start] < height[end]) start ++;
         else end --;
    }

    return ans;
}
/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/


std::vector<int> Solutions::moveZeroes(vector<int>& nums)
{
    int fast = 0, slow = 0;
    while( slow < nums.size() && fast < nums.size() ) {
        
        if(nums[fast] != 0){
            swap(nums[slow++],nums[fast++]);
        }
        else{
            fast++;
        }
    }

    return nums;
}
/*
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/


vector<int> Solutions::findArrayQuadruplet(const vector<int> &arr, int s) 
{
  vector<int> tmp = arr;
  sort(tmp.begin(), tmp.end());
  int n = arr.size() - 1;

  for(int i = 0; i <= n - 3; i ++) {
    for(int j = i + 1; j <= n - 2; j ++) {
      
      int target = s - tmp[i] - tmp[j], start = j + 1, end = n;
      
      while (start < end) {
        int sum = tmp[start] + tmp[end];  
        if ( sum == target) {
            return {tmp[i], tmp[j], tmp[start], tmp[end]};
        } else if ( sum >= target) end --;
        else start ++;
      }
    }
  }
  
  return {};
}
/*
input:  arr = [2, 7, 4, 0, 9, 5, 1, 3], s = 20
output: [0, 4, 7, 9] 
*/

} /* namespace leetcode */
