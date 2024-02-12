#include "solutions.h"

#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

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

bool Solutions::isSubsequence(std::string s, std::string t)
{
    int len1 = 0, len2 = 0;
    
    while( len1 < s.length() && len2 < t.length()) {
       if(t[len2++] == s[len1]) len1++;
    }

    if (len1 == s.length()) return true;

    return false;
}

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


} /* namespace leetcode */
