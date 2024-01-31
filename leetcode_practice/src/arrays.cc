#include "solutions.h"

#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

std::vector<int> Solutions::sortedmerge(std::vector<int> & nums1, int m , std::vector<int> & nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;

    while(i >= 0 && j >= 0) {
        nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }

    while( j >= 0 ) {
        nums1[k--] = nums2[j--];
    }

    return nums1;

}

int Solutions::removeElement(std::vector<int> & nums, int val)
{
    int count = 0;

    for(int i = 0; i < nums.size(); i ++) {
        if (nums[i] != val) count ++;
    } 

    return count;
}

int Solutions::removeDuplicates(std::vector<int> & nums)
{
    int count = 1;
    
    for(int i = 1; i < nums.size(); i ++) {
        if(nums[i - 1] != nums[i]) count++;
    }

    return count;
}

int Solutions::removeDuplicatesII(std::vector<int> & nums)
{
    int count = 2;

    if (nums.size() < 2) return nums.size();

    for(int i = 2; i < nums.size(); i ++) {
        if( nums[count - 2] != nums[i]) nums[count++] = nums[i];
    }

    return count;
}

int Solutions::majorityElement(std::vector<int> & nums)
{
    int count = 0, major = 0;

    for(int i = 0; i < nums.size(); i++) {
       if(count == 0) major = nums[i];

       major == nums[i] ? count ++: count --;
    }

    return major;
}

std::vector<int> Solutions::rotate(std::vector<int> & nums, int k)
{
    std::vector<int> temp = nums;

    for(int i = 0; i < nums.size(); i++)
        nums[(i+k)%nums.size()] = temp[i];

    return nums;
}

int Solutions::maxProfitI(std::vector<int> & prices)
{
    int profit = 0, hold = INT_MAX;

    for(int i = 0; i < prices.size(); i++){
        hold = std::min(hold, prices[i]);

        profit = std::max(profit, prices[i] - hold);
    }

    return profit;
}

int Solutions::maxProfit(std::vector<int> & prices)
{
    int cur_profit = 0, cur_hold = INT_MIN;

    for(int i = 0; i < prices.size(); i++) {
        int pre_hold = cur_hold, pre_profit = cur_profit;

        cur_hold = std::max(pre_hold, pre_profit - prices[i]);
        cur_profit = std::max(pre_profit, prices[i] + pre_hold);
    }

    return cur_profit;
}

bool Solutions::canJump(std::vector<int> & nums)
{
    int reachable = 0;

    for(int i = 0; i < nums.size(); i ++) {
        if(reachable == nums.size() - 1) return true;
        reachable = std::max(reachable, i + nums[i]);
    }

    return false;
}

int Solutions::jump(std::vector<int> & nums)
{
    int reach = 0, step = 0, max_reach = 0;

    for(int i = 0; i < nums.size() - 1; i++) {
    
        max_reach = std::max(max_reach, i + nums[i]);

        if(reach == i) {
           step++;
           reach = max_reach;
        }
    }

    return step;
}

int Solutions::hIndex(std::vector<int> & citations)
{
    std::priority_queue<int> pq(citations.begin(), citations.end());

    int h;
    for(h = 0; !pq.empty() && h < pq.top(); h ++) pq.pop();
    return h;
}

std::vector<int> Solutions::productExceptself(std::vector<int> & nums)
{
    int front = 1, back = 1;
    std::vector<int> ans(nums.size(), 1);

    for(int i = 0; i < nums.size(); i++) {
        ans[i] = front;
        front *= nums[i];
    }

    for(int i = nums.size() - 1; i >=0; i--) {
        ans[i] *= back;
        back *= nums[i];
    }
    return ans;
}  

int Solutions::canCompleteCircuit(std::vector<int> & gas, std::vector<int>& cost)
{
    int total_gas = 0, total_cost = 0, count = 0;
    int start = 0;

    for(int i = 0; i < gas.size(); i ++) {
        total_gas += gas[i];
        total_cost += cost[i];

        count += gas[i] - cost[i];

        if (count < 0) {
           count = 0; start = i + 1;
        }
    }

    if(total_gas < total_cost) return -1;

    return start;
}

int Solutions::candy(std::vector<int>& ratings)
{
    std::vector<int> candies(ratings.size(), 1);
   
    for(int i = 1; i < ratings.size(); i ++) {
        ratings[i-1] > ratings[i] ? candies[i -1]++: candies[i]++;
    }

    int ans = 0;

    for(auto & candy: candies) ans+= candy;

    return ans;
}

int Solutions::trap(std::vector<int>& height)
{
    int left = 0, right = height.size() -1;
    int level = 0, water = 0;

    while(left < right) {
        int lower = height[height[left] < height[right] ? left ++ : right --];
        level = std::max(lower, level);
        water += level - lower;
    }

    return water;
}

int Solutions::romanToInt(std::string s)
{
   std::unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                              {'C', 100}, {'D', 500}, {'M', 1000}};

   int ans = 0;

   for(int i = 0; i < s.length(); i ++) {
      if((i-1)> 0 && s[i-1] < s[i]) ans += mp[s[i]] - mp[s[i-1]];
      else ans += mp[s[i]];
   }

   return ans;
}

std::string Solutions::intToRoman(int num)
{
    std::unordered_map<int, char> mp = {{1000, 'M'}, {500, 'D'}, {100, 'C'}, 
                                        {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'}};

    std::string ans = "";

    for(auto & it: mp) {
        while(it.first <= num) {
            ans += it.second;
            num -= it.first;
        }
    }

    return ans;
}

int Solutions::lenghtofLastword(std::string s)
{
    int ans = 0;

    for(int i = s.length() - 1; i >= 0; i--) {
        if(ans == 0 && s[i] == ' ' ) continue;

        if(s[i] != ' ') ans++;
        else break;
    }

    return ans;
}

std::string Solutions::longestCommonPrefix(std::vector<std::string> & strs)
{
    std::sort(strs.begin(), strs.end());
    std::string ans = "";

    for(int i = 0; i < strs.size(); i ++) {
        if(strs[0][i] != strs[strs.size()-1][i]) break;
        ans += strs[0][i];
    }
    return ans;
}

std::string Solutions::reverseWords(std::string s)
{
    std::string ans = "";

    for(int i = s.length() - 1; i >=0 ; i --) {
        std::string word = "";

        while( i >= 0 && s[i] != ' ') {
            word += s[i--];
        }

        std::reverse(word.begin(), word.end());

        if (word != "") ans += word + ' ';
    }

    ans.pop_back();

    return ans;
}

std::string Solutions::convert(std::string s, int numRows)
{
    std::vector<std::string> patterns(numRows, "");

    int rows = 0, direction = 1;

    for(int i = 0; i < s.length(); i ++) {
        
        patterns[rows] += s[i];

        if(rows == 0) direction = 1;
        if(rows == numRows - 1) direction = -1;

        rows += direction;
    }

    std::string ans = "";

    for(auto & pattern : patterns) {

        ans += pattern;
    }

    return ans;
}

int Solutions::strStr(std::string haystack, std::string needle)
{
   int len1 = haystack.length(), len2 = needle.length();

   for(int i = 0; i < len1 - len2 + 1; i ++ ){
       for(int j = 0; j < len2 ; j ++) {
           if(haystack[i+j] != needle[j]) break;

           if (j == len2 - 1) return i;
       }
   }

   return -1;
}

// Hard!!!
std::vector<std::string> Solutions::fullyJustify(std::vector<std::string> & words, int maxWidth)
{
    int n = words.size(); std::vector<std::string> ans;

    for(int i = 0; i < n; i ++) {
        // Step1. begin on the each line
        int start = i, length = words[i].size();

        // Step2. max length
        while( (i + 1) < n && (length + words[i+1].size() + 1) <= maxWidth)
            length += words[++i].size() + 1;

        // Step3. caculate the number of words, spaces and extra spaces
        int numword = i - start + 1, spaces = 1, extraspaces = 0;
        
        // why need i + 1 < n ? @@
        if ( (numword  - 1) > 0 && (i + 1) < n) {
            int remain = maxWidth - length;
            spaces = remain / (numword - 1) + 1;
            extraspaces = remain % (numword - 1);
        }

        // Step4. each line
        std::string line = words[start];

        for(int j = 1; j < numword; j ++) {
            line.append(spaces, ' ');
            if (j <= extraspaces) line.push_back(' ');
            line += words[start + j];
        }
                
        // Step5. rest of spaces
        if (line.size() < maxWidth) line.append(maxWidth - line.size(), ' ');

        ans.push_back(line);
    }    

    return ans;
}

} /* namespace leetcode */
