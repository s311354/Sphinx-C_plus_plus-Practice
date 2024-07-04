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
    // time: O(N) space: O(1)

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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. we would try to iterate through the vector from the end once it a single array sorted in non-decreasing order
Step 2. we would try to iterate through the vector from the rest of integer in non-decreasing order
…

Dry Run (pseudo code)
k = m + n - 1

while(i >= 0 && j >= 0) {..}

while( j >= 0 ) {...}

Implementation
...
*/

int Solutions::removeElement(std::vector<int> & nums, int val)
{
    // time: O(N) space: O(1)

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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. we would try to iterate through the vector to check all elements from i to the end of array. And 
we can count the number of elements in array which are not equal to value
…

Dry Run (pseudo code)
if (nums[i] != val) count ++

Implementation
...
*/

int Solutions::removeDuplicates(std::vector<int> & nums)
{
    // time: O(N) space: O(1)
    if (!nums.size()) return 0;
    
    int count = 1;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] != nums[i+1]) {
            nums[count++] = nums[i+1];
        }
    }
    return count;
}
/*
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. we would try to iterate through the vector to check all elements from i to the end - 1 of array
we can count the number of elements in array which are unique elements in array
Step 2. …
…

Dry Run (pseudo code)
if(nums[i - 1] != nums[i]) count++

Implementation
...
*/

int Solutions::removeDuplicatesII(std::vector<int> & nums)
{
    // time: O(N) space: O(1)
    if (nums.size() < 2) return nums.size();

    int count = 2;

    for(int i = 2; i < nums.size(); i ++) {
        if( nums[count - 2] != nums[i] ) { 
            nums[count++] = nums[i];
        }
    }

    return count;
}
/*
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. we would try to iterate through the vector to check all elements 
Step 2. …
…

Dry Run (pseudo code)
if( nums[count - 2] != nums[i]) nums[count++] = nums[i]

Implementation
...
*/

int Solutions::majorityElement(std::vector<int> & nums)
{
    // time: O(N) space: O(1)

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

/*
Approach
Native Approach: Sorting (more than n/2 times in the array)
Second Approach: Moore Voting Algorithm
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to adopt the Moore's Voting Algorithm that is based on the fact that if there is a majority element in an array,
it will always remain in the lead, even after encountering other elements.
Step 2. ...
…

Dry Run (pseudo code)
if(count == 0) major = nums[i]

major == nums[i] ? count ++: count --

Implementation
...
*/

std::vector<int> Solutions::rotate(std::vector<int> & nums, int k)
{
    // time: O(N) space: O(N)

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
    // time: O(N) space: O(1)

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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to adopt straightforward approach that iterates through the array of stock prices. 
Step 2. At each step, we keep track of the minimum stock price and calculated the potentially maximum profit.
…

Dry Run (pseudo code)
hold = std::min(hold, prices[i])
profit = std::max(profit, prices[i] - hold)

Implementation
...
*/

int Solutions::maxProfit(std::vector<int> & prices)
{
    // time: O(N) space: O(1)

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
    // time: O(N) space: O(1)

    int reachable = 0;

    for(int i = 0; i < nums.size(); i ++) {
        if(reachable == nums.size() - 1) return true;

        reachable = max(reachable, i + nums[i]);
    }

    return false;
}
/*
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. we would try to iterate through the vector to check if we can reach the last index.
Step 2. …
…

Dry Run (pseudo code)
if(reachable == nums.size() - 1) return true

reachable = std::max(reachable, i + nums[i])

Implementation
...
*/

int Solutions::jump(std::vector<int> & nums)
{
    // time: O(N) space: O(1)

    int reach = 0, max_reach = 0;
    int step = 0;

    for(int i = 0; i < nums.size() - 1; i++) {
    
        max_reach = max(max_reach, i + nums[i]);

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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. we would try to iterate through the vector to find the minimum number of jumps required to reach the end of a given
array of non-negative integers. 
Step 2. At each step, we keep track of the farthest reachable position and update the number of jumps 
needed to reach that farthest position.
…

Dry Run (pseudo code)
max_reach = max(max_reach, i + nums[i])

if(reach == i) {
    step++
    reach = max_reach
}

Implementation
...
*/

int Solutions::hIndex(std::vector<int> & citations)
{
    // time: O(N * log(N)) space: O(N)

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
    // time: O(N) space: O(N)

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

/*
Approach
Native Approach: ...
Second Approach: dynamic programming approach
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to adopt dynamic programming that iterates through the array of nums.
Step 2. …
…

Dry Run (pseudo code)
ans[i] = front
front *= nums[i]

ans[i] *= back
back *= nums[i]

Implementation
...
*/

int Solutions::canCompleteCircuit(std::vector<int> & gas, std::vector<int>& cost)
{
    // time: O(N) space: O(1)

    int total_gas = 0, total_cost = 0, count = 0;
    int start = 0;

    for(int i = 0; i < gas.size(); i ++) {
        total_gas += gas[i];
        total_cost += cost[i];
        count += gas[i] - cost[i];

        if (count < 0) {
           count = 0; 
           start = i + 1;
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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. we would try to iterate through the vector to caculate gas tank and it costs of gas 
Step 2. At each step, we keep track of the amount of gas and it costs, and update the starting index to travel around the circuit
…

Dry Run (pseudo code)
total_gas += gas[i];
total_cost += cost[i];
count += gas[i] - cost[i];

if (count < 0) {
    count = 0; 
    start = i + 1;
}

Implementation
...
*/

int Solutions::candy(std::vector<int>& ratings)
{
    // time: O(N) space: O(N)

    int n = ratings.size();

    std::vector<int> candies(n, 1);

    for(int i = 1; i < n; i ++) {
        if( ratings[i-1] < ratings[i] ) {
            candies[i] = candies[i-1] + 1;
        }
    }

    for(int i = n - 2; i >= 0; i --) {
        if( ratings[i+1] < ratings[i] ) {
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }

    int ans = 0;

    ans = accumulate(candies.begin(), candies.end(), 0);

    return ans;
}
/*
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
*/

/*
Approach
Native Approach: …
Second Approach: greedy algorithm
Third Approach: …

Explanation (Step by Step)
We would try to adopt greedy algorithm that iterates through the array of ratings with two-pass method. At each pass,
we ensure that each child gets the appropriate amount of candy.
…

Dry Run (pseudo code)
std::vector<int> candies(n, 1);

if( ratings[i-1] < ratings[i] ) {
    candies[i] = candies[i-1] + 1;
}

if( ratings[i+1] < ratings[i] ) {
    candies[i] = max(candies[i], candies[i+1] + 1);
}

Implementation
...
*/

int Solutions::romanToInt(std::string s)
{
    // time: O(N) space: O(N)

    std::unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                            {'C', 100}, {'D', 500}, {'M', 1000}};

    int ans = 0;

    for(int i = 0; i < s.length(); i ++) {
        if (map[s[i]] < map[s[i+1]]) ans -= map[s[i]];
        else ans += map[s[i]];
    }

    return ans;
}
/*
Input: s = "III"
Output: 3
Explanation: III = 3.
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to store a bunch of Roman and the mapped value in unordered map and iterate through a key character within a map. 
Step 2. At each step, we keep track of whether a smaller mapped value appears before a larger mapped
 value and then represent the integer conversion of the Roman numeral string.
…

Dry Run (pseudo code)
unordered_map  {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
               {'C', 100}, {'D', 500}, {'M', 1000}}

if((i-1)> 0 && s[i-1] < s[i])  ans += mp[s[i]] - mp[s[i-1]]
else  ans += mp[s[i]]

Implementation
...
*/

std::string Solutions::intToRoman(int num)
{
    // time: O(N) space: O(N)

    std::vector<std::pair<int, std::string>> mp{{1000, "M"}, {900, "CM"}, {500, "D"},
                                                {400, "CD"}, {100, "C"}, {90, "XC"},
                                                {50, "L"}, {40, "XL"}, {10, "X"},
                                                {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string ans = "";

    for(auto & it : mp) {
        while (num >= it.first) {
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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to store a bunch of Roman numeral string and the mapped character in unordered map and iterate through a number within a map. 
Step 2. At each step, we keep track of whether the input integer is greater than or equal to the Roman numeral value 
and then represent the Roman numeral string conversion of the integer.
…

Dry Run (pseudo code)
std::vector<std::pair<int, std::string>> mp{{1000, "M"}, {900, "CM"}, {500, "D"},
                                            {400, "CD"}, {100, "C"}, {90, "XC"},
                                            {50, "L"}, {40, "XL"}, {10, "X"},
                                            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

while (num >= it.first) {
    ans += it.second;
    num -= it.first;
}

Implementation
...
*/

int Solutions::lenghtofLastword(std::string s)
{
    // time: O(N) space: O(1)

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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
We would try to iterate through the string. At each step, we keep track of splitting the string into words.
…

Dry Run (pseudo code)
if(ans == 0 && s[i] == ' ' ) continue;

if(s[i] != ' ') ans++;
else break;

Implementation
...
*/

std::string Solutions::longestCommonPrefix(std::vector<std::string> & strs)
{
    // time: O(N Log N) space: O(1)

    std::sort(strs.begin(), strs.end());
    std::string ans = "";

    for(int i = 0; i < strs.size(); i ++) {
        if(strs[0][i] != strs[strs.size()-1][i]) break;
        
        ans += strs[0][i];
    }

    return ans;
}
/*
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
We would try to sort an array and iterate through the string. At each step, we keep track of the
 smallest and longest strings with a common prefix in a word.
…

Dry Run (pseudo code)
sort(strs.begin(), strs.end());

if(strs[0][i] != strs[strs.size()-1][i]) break;

ans += strs[0][i];

Implementation
...
*/

std::string Solutions::reverseWords(std::string s)
{

    // time: O(N) space: O(1)

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

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to iterate through the string from last to first.
Step 2. At each step, we keep track of a sequence of non-space characters in a word and reverse the word into a list of words.
Step 3. At end step, we remove the last element in the vector.
…

Dry Run (pseudo code)
word += s[i--];
reverse(word.begin(), word.end());

if (word != "") ans += word + ' ';

ans.pop_back();

Implementation
...
*/

std::string Solutions::convert(std::string s, int numRows)
{

    // time: O(N) space: O(N)

    std::vector<std::string> patterns(numRows, "");

    int rows = 0, direction = 1;

    for(int i = 0; i < s.length(); i ++) {
        
        patterns[rows] += s[i];

        if(rows == 0) direction = 1;
        if(rows == numRows - 1) direction = -1;

        rows += direction;
    }

    std::string ans = "";

    for(auto const & pattern : patterns) {

        ans += pattern;
    }

    return ans;
}
/*
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: …
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to iterate through the string.
Step 2. At each step, we keep track of string in a array and would try to store a bunch of string in a array with zigzag pattern.
Step 3. We represent zigzag pattern string.
…

Dry Run (pseudo code)
std::vector<std::string> patterns(numRows, "");
int rows = 0, direction = 1;

patterns[rows] += s[i];

if(rows == 0) direction = 1;
if(rows == numRows - 1) direction = -1;

rows += direction;

Implementation
...
*/

int Solutions::strStr(std::string haystack, std::string needle)
{
    // time: O(N * M) space: O(1)

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

/*
Approach
Native Approach: straightforward approach
Second Approach: … 
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to iterate through the haystack from the beginning up to the point where there are enough characters with needle.
Step 2. At each step, we keep track of whether the starting index of characters in the haystack matches the character in needle.
…

Dry Run (pseudo code)

if(haystack[i+j] != needle[j]) break;

if (j == len2 - 1) return i;

Implementation
...
*/

vector<int> Solutions::getConcatenation(vector<int>& nums) {

    // time: O(N) space: O(1)

    int n = nums.size();

    for(int i = 0; i < n ; i ++) {
        nums.push_back(nums[i]);
    }

    return nums;
}
/*
Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: … 
Third Approach: …

Explanation (Step by Step)
We would try to iterate through the array and store a bunch of number to the end of the vector nums.
…

Dry Run (pseudo code)

nums.push_back(nums[i]);

Implementation
...
*/

vector<int> Solutions::buildArray(vector<int>& nums) {

    // time: O(N) space: O(N)

    vector<int> ans;

    int n = nums.size();

    for(int i = 0; i < n ; i ++) {
        ans.push_back(nums[nums[i]]);
    }

    return ans;
}
/*
Example 1:

Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
*/

/*
Approach
Native Approach: straightforward approach
Second Approach: … 
Third Approach: …

Explanation (Step by Step)
We would try to iterate through the array and store a bunch of number specified by the current element to the result vector.
…

Dry Run (pseudo code)

ans.push_back(nums[nums[i]]);

Implementation
...
*/

int Solutions::minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int ans = 0;

    for(int i = 0; i < seats.size(); i ++) {
        ans += abs(seats[i] - students[i]);
    }

    return ans;
}
/*
Example 1:

Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from from position 2 to position 1 using 1 move.
- The second student is moved from from position 7 to position 5 using 2 moves.
- The third student is moved from from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
*/


int Solutions::numIdenticalPairs(vector<int>& nums) {
    int ans = 0;
    vector<int> count(101,0);

    for(auto const & num: nums) {
        ans += count[num];
        count[num] ++;
    }

    return ans;
}
/*
Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
*/

int Solutions::finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;

    for(auto const & operation : operations) {
        if(operation == "--X" || operation == "X--") {
            ans--;
        } else {
            ans++;
        }
    }

    return ans;
}
/*
Example 1:
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
*/

vector<int> Solutions::shuffle(vector<int>& nums, int n) {
    vector<int> ans;
    for(int i = 0; i < n; i ++) {
        ans.push_back(nums[i]);
        ans.push_back(nums[i+n]);
    }

    return ans;
}
/*
Example 1:
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
*/

vector<int> Solutions::findWordsContaining(vector<string>& words, char x) {
    int n = words.size();
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(count(words[i].begin(), words[i].end(), x) > 0) {
            ans.push_back(i);
        }
    }

    return ans;
}
/*
Example 1:

Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
*/

int Solutions::maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    for(auto const & account: accounts) {
        ans = max(ans, accumulate(account.begin(), account.end(), 0));
    }

    return ans;
}
/*
Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
*/

int Solutions::subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    
    for(int i = 0 ; i <  n; i++) sum |= nums[i];

    return sum << (nums.size()-1); 
}
/*
Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
*/

int Solutions::numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int count = 0;
    for(auto const & hour: hours) {
        if(hour >= target) count ++;
    }

    return count;
}
/*
Example 1:

Input: hours = [0,1,2,3,4], target = 2
Output: 3
Explanation: The company wants each employee to work for at least 2 hours.
- Employee 0 worked for 0 hours and didn't meet the target.
- Employee 1 worked for 1 hours and didn't meet the target.
- Employee 2 worked for 2 hours and met the target.
- Employee 3 worked for 3 hours and met the target.
- Employee 4 worked for 4 hours and met the target.
There are 3 employees who met the target.
*/

vector<bool> Solutions::kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxcandy = 0;

    vector<bool> ans;

    for(auto& candy: candies) maxcandy = max(maxcandy, candy);

    for(auto& candy: candies) {
        if(candy + extraCandies >= maxcandy) ans.push_back(true);
        else ans.push_back(false); 
    } 

    return ans;
}
/*
Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
*/

int Solutions::maxWidthOfVerticalArea(vector<vector<int>>& points) {
    priority_queue<int> pq;
    for(auto const & point: points) {
        pq.push(point[0]);
    }

    int node = pq.top(), ans = 0;

    while(!pq.empty()) {
        int next = pq.top();
        pq.pop();

        ans = max(ans, node - next);
        node = next;
    }

    return ans;
}
/*
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.
*/

int Solutions::countPairs(vector<int>& nums, int target) {
    int ans = 0;

    for(int i = 0; i < nums.size(); i ++) {
        for(int j = i+1; j < nums.size(); j ++) {
            if(nums[i] + nums[j] < target) ans++;
        }
    }

    return ans;
}
/*
Example 1:

Input: nums = [-1,1,2,3,1], target = 2
Output: 3
Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
- (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target 
- (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target.
*/

int Solutions::numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int ans = 0;

    for(auto const & num1: nums1) {
        for(auto const & num2: nums2) {
            int div = num2 * k;
            if(num1 % div == 0) ans++;
        }
    }

    return ans;
}
/*
Example 1:
Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1
Output: 5
Explanation:
The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).
*/

vector<int> Solutions::runningSum(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i ++) {
        nums[i] += nums[i-1];
    }

    return nums;
}
/*
Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
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

bool isValidSegment(const string &segment) {

    if (segment.empty() || segment.length() > 3) return false;

    if (segment.length() > 1 && segment[0] == '0') return false;

    for (char ch : segment) {
        if (!isdigit(ch)) return false;
    }

    int num = std::stoi(segment);

    if (num < 0 || num > 255) return false;

    return true;
}

bool Solutions::validateIP(const std::string &ip) {
    vector<std::string> segments;
    string segment;

    for(auto & ch: ip) {
        if(ch == '.') {
            segments.push_back(ch);
            segment = "";            
        } else {
            segment += ch;
        }
    }
    segments.push_back(segment);

    if (segments.size() != 4) return false;

    for (const std::string &seg : segments) {
        if (!isValidSegment(seg)) return false;
    }

    return true;
}


} /* namespace leetcode */
