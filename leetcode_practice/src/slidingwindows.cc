#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

int Solutions::minSubArrayLen(int target, std::vector<int> nums)
{
    int slow = 0, fast= 0, sum = 0, ans = INT_MAX;

    while ( fast < nums.size() && slow < nums.size()) {
        sum += nums[fast++];
        while (sum >= target) {
            ans = std::min(fast - slow, ans);
            sum -= nums[slow++];
        }
    }

    return ans == INT_MAX ? 0 : ans;
}
/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/


int Solutions::lengthOfLongestSubstring(std::string s)
{
    std::unordered_set<char> set;

    int slow = 0, fast = 0, ans = 0;

    while(slow < s.size() && fast < s.size()) {
        if(set.find(s[fast]) != set.end()) {
            set.erase(s[slow++]);
        } else {
            set.insert(s[fast++]);
            ans = std::max(ans, fast - slow);
        }
    }

    return ans;
}
/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

std::vector<int> Solutions::findSubstring(std::string s, std::vector<std::string>& words)
{
    int nums = words.size(), wordlen = words[0].size();
  
    if (s.empty() || words.empty() || nums * wordlen > s.size()) return {};

    std::unordered_map<std::string, int> count;
    std::vector<int> ans;
    for(auto & word: words) ++count[word];
    for(int i = 0; i< s.length() - nums*wordlen + 1; i++) {
        std::unordered_map<std::string, int> subcount;
        for(int j = 0; j < nums; j++) {

            std::string word = s.substr(i+j*wordlen, wordlen);

            if(++subcount[word] > count[word]) break;
            if(j == nums -1) ans.push_back(i);

        
        }
    }

    return ans;
}
/*
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.
*/


std::string Solutions::minWindow(std::string s, std::string t)
{
    std::unordered_map<char, int> scnt;
    std::unordered_map<char, int> tcnt;
    int start = 0, requiredlen = t.length();
    int minwin = INT_MAX;
    
    for(auto& c: t) ++tcnt[c];

    for(int left = 0, right = 0; right < s.length() ; right++) {
        if(++scnt[s[right]] <= tcnt[s[right]]) --requiredlen;

        while(requiredlen == 0) {

            if (--scnt[s[left]] < tcnt[s[left]]) {
                ++requiredlen;

                if (minwin > right - left + 1) {
                    minwin = right - left + 1;
                    start = left; 
                }
            }
            ++left;
        }
    }

    return minwin == INT_MAX ? "" : s.substr(start, minwin);
}
/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

} /* namespace leetcode */
