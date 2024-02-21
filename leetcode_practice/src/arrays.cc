#include "solutions.h"

#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

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
/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/


int Solutions::removeElement(std::vector<int> & nums, int val)
{
    int count = 0;

    for(int i = 0; i < nums.size(); i ++) {
        if (nums[i] != val) count ++;
    } 

    return count;
}
/*
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/


int Solutions::removeDuplicates(std::vector<int> & nums)
{
    int count = 1;
    
    for(int i = 1; i < nums.size(); i ++) {
        if(nums[i - 1] != nums[i]) count++;
    }

    return count;
}
/*
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

int Solutions::removeDuplicatesII(std::vector<int> & nums)
{
    int count = 2;

    if (nums.size() < 2) return nums.size();

    for(int i = 2; i < nums.size(); i ++) {
        if( nums[count - 2] != nums[i]) nums[count++] = nums[i];
    }

    return count;
}
/*
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

int Solutions::majorityElement(std::vector<int> & nums)
{
    int count = 0, major = 0;

    for(int i = 0; i < nums.size(); i++) {
       if(count == 0) major = nums[i];

       major == nums[i] ? count ++: count --;
    }

    return major;
}
/*
Input: nums = [3,2,3]
Output: 3
*/


std::vector<int> Solutions::rotate(std::vector<int> & nums, int k)
{
    std::vector<int> temp = nums;

    for(int i = 0; i < nums.size(); i++)
        nums[(i+k)%nums.size()] = temp[i];

    return nums;
}
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

int Solutions::maxProfitI(std::vector<int> & prices)
{
    int profit = 0, hold = INT_MAX;

    for(int i = 0; i < prices.size(); i++){
        hold = std::min(hold, prices[i]);

        profit = std::max(profit, prices[i] - hold);
    }

    return profit;
}
/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

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
/*
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/

bool Solutions::canJump(std::vector<int> & nums)
{
    int reachable = 0;

    for(int i = 0; i < nums.size(); i ++) {
        if(reachable == nums.size() - 1) return true;
        reachable = std::max(reachable, i + nums[i]);
    }

    return false;
}
/*
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

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
/*
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/


int Solutions::hIndex(std::vector<int> & citations)
{
    std::priority_queue<int> pq(citations.begin(), citations.end());

    int h;
    for(h = 0; !pq.empty() && h < pq.top(); h ++) pq.pop();
    return h;
}
/*
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
*/

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
/*
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

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
/*
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
*/

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
/*
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
*/

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
/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

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
/*
Input: s = "III"
Output: 3
Explanation: III = 3.
*/

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
/*
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
*/


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
/*
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
*/

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
/*
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
*/

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
/*
Input: s = "the sky is blue"
Output: "blue is sky the"
*/

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
/*
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
*/


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
/*
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
*/

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
/*
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/

} /* namespace leetcode */
