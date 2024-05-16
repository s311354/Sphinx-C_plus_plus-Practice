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

bool checkvol(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;

    return false;
}

int Solutions::maxVowels(string s, int k) {
    int count = 0;
    for(int i = 0; i < k ; i ++) {
        if(checkvol(s[i])) count++;
    }
    
    int ans = count;

    int slow = 0, fast = k;

    while(slow < s.length() && fast < s.length()) {
        if(checkvol(s[fast++])) count++;
        if(checkvol(s[slow++])) count--;
    
        ans = max(ans, count);
    }

    return ans;

}
/*
Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
*/

int Solutions::maximumStrongPairXor(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int slow = 0, fast = 1;
    int bitwise = 0, ans = 0;

    while(fast < nums.size() && slow < nums.size()) {
        if(abs(nums[fast] - nums[slow] <= min(nums[fast], nums[slow]))) {
            bitwise = nums[fast] ^ nums[slow];
            ans = max(ans, bitwise);
        } else {
            slow ++;
            fast = slow;
        }

        if(fast == nums.size() - 1 && slow < fast) {
            fast = slow;
            slow++;
        }

        fast++;
    }

    return ans;
}
/*
Example 1:
Input: nums = [1,2,3,4,5]
Output: 7
Explanation: There are 11 strong pairs in the array nums: (1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5) and (5, 5).
The maximum XOR possible from these pairs is 3 XOR 4 = 7.
*/

int Solutions::countGoodSubstrings(string s) {

    int slow = 0, fast = 0;
    int n = s.length(), ans = 0;
    unordered_map<char, int> mp;

    while(fast < n && slow < n) {
        mp[s[fast++]]++;
        
        if(fast - slow == 3) {
            if(mp.size() == 3) ans ++;

            if(mp[s[slow]]-- == 1) mp.erase(s[slow]); // keep it as size 1 
            slow ++;
        }
    }

    return ans;
}
/*
Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
*/


#pragma GCC optimize("O3,unroll-loops")
/*
This pragma allows you to set global optimization options for functions defined later in the source file.
*/
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
/*
The target attribute can be used for instance to have a function compiled with a different ISA (instruction set architecture) 
than the default. ‘#pragma GCC target’ can be used to specify target-specific options for more than one function
*/

auto __unsync_ios_stdio = ios_base::sync_with_stdio(false);
// If the synchronization is turned off, the C++ standard 
// streams are allowed to buffer their I/O independently, which may be considerably faster in some cases.
auto __untie_cin = cin.tie(nullptr); 
/*
The tied stream is an output stream object which is flushed before each i/o operation in this stream object
*/

vector<int> Solutions::decrypt(vector<int>& code, int k) {
    int n = code.size();

    code.insert(code.end(), code.begin(), code.end());

    vector<int> ans(n, 0);

    if(k == 0) return ans;
    else if(k > 0) {
        int slow = 0, fast = 1, sum = 0;

        while (slow < n) {
            sum += code[fast++];
            
            if(fast - slow == k + 1) {
                ans[slow] = sum;
                slow ++;
                sum -= code[slow];    
            }
        }
    } else {
        k *=-1;

        int slow = 2*n - 1, fast = 2*n - 2, sum = 0;

        while(slow >= n) {
            sum += code[fast--];

            if(slow - fast == k + 1) {
                ans[slow - n] = sum;
                slow --;
                sum -= code[slow];
            }
        }
    }

    return ans;
}
/*
Example 1:
Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. 
The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
*/


} /* namespace leetcode */
