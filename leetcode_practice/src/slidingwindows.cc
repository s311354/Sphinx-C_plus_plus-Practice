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

int Solutions::lengthOfLongestSubstring(std::string s)
{
    std::unordered_set<char> set;

    int slow = 0, fast = 0, ans = 0;

    while (fast < s.length() && slow < s.length()) {
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
    int slow = 0, fast = 0, start = 0, requiredlen = t.length();
    int ans = INT_MAX;
    
    for(auto& c: t) ++tcnt[c];

    while (fast < s.length() && slow < s.length()) {
        if(++scnt[s[fast]] <= tcnt[s[fast]]) --requiredlen;

        while(requiredlen == 0) {
            if (--scnt[s[slow]] < tcnt[s[slow]]) {
                ++requiredlen;

                if (ans > fast - slow + 1) {
                    ans = fast - slow + 1;
                    start = slow; 
                }
            }
            ++slow;
        }

        ++fast;
    }

    return ans == INT_MAX ? "" : s.substr(start, ans);
}
/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

string getShortestUniqueSubstring( const vector<char>& arr, const string &str ) 
{
  unordered_map<char, int> acnt;
  unordered_map<char, int> scnt;
  int slow = 0, fast = 0;
  int start = 0, requiredlen = arr.size();
  int ans = INT_MAX;
  
  for(auto const &c: arr) ++acnt[c];
  
  while(fast < str.length() && slow < str.length()) {
    
    if(++scnt[str[fast]] <= acnt[str[fast]]) --requiredlen;
    
    while(requiredlen == 0) {
      if(--scnt[str[slow]] < acnt[str[slow]]) {
        ++requiredlen;
        
        if(ans > fast - slow + 1) {
          ans = fast - slow + 1;
          start = slow;
        }
      }
      ++slow;
    }
    ++fast;

  }
  
  return ans == INT_MAX ? "" : str.substr(start, ans);
  
}
/*
input:  arr = ['x','y','z'], str = "xyyzyzyx"
output: "zyx"
*/

/*
Approach
Native Approach: …
Second Approach: sliding window approach
Third Approach: …

Explanation (Step by Step)
Step 1. We would try to use a hash map to track the count of characters in arr and iterate through a string with two pointers, fast and slow.
Step 2. At each step, we keep expand the window by moving the fast pointer until the window contains all characters.
Step 3. Once the window is valid, we try to shrink it by moving the slow pointer to find the smallest window, and keep track of the start point.
…

Dry Run (pseudo code)

requiredlen = arr.size()

for(auto const &c: arr) ++acnt[c]

if(++scnt[str[fast]] <= acnt[str[fast]]) --requiredlen

while(requiredlen == 0) {
    if(--scnt[str[slow]] < acnt[str[slow]]) {
        ++requiredlen;
    
        if(ans > fast - slow + 1) {
          ans = fast - slow + 1;
          start = slow;
        }
    }
}

Implementation
...
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

    while (fast < s.length() && slow < s.length()) {
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

    int slow = 0, fast = 0;
    int ans = 0;

    while(fast < nums.size() && slow < nums.size()) {
        if(abs(nums[fast] - nums[slow]) <= min(nums[fast], nums[slow])) {
            int bitwise = nums[fast] ^ nums[slow];
            ans = max(ans, bitwise);
        } 

        if(fast == nums.size() - 1 && slow < fast) {
            ++slow;
            fast = slow;
        }

        ++fast;
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
    int ans = 0;
    unordered_map<char, int> mp;

    while(fast < s.length() && slow < s.length()) {
        mp[s[fast++]]++;
        
        if(fast - slow == 3) {
            if(mp.size() == 3) ans ++;

            mp[s[slow]]--;

            if(mp[s[slow]] == 0) mp.erase(s[slow]);
            
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
        int slow = 0, fast = 1;
        int sum = 0;

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

        int slow = 2*n - 1, fast = 2*n - 2;
        int sum = 0;

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

int Solutions::maximumLengthSubstring(string s) {
    int slow = 0, fast = 0;
    int ans = 0;
    unordered_map<char, int> mp;

    while(fast < s.length() && slow < s.length()) {
        mp[s[fast]]++;

        while(mp[s[fast]] == 3)
            mp[s[slow++]]--;
        
        ans = max(ans, fast - slow + 1);
        fast ++;
    }

    return ans;
}
/*
Example 1:
Input: s = "bcbbbcba"
Output: 4
Explanation:
The following substring has a length of 4 and contains at 
most two occurrences of each character: "bcbbbcba".
*/

int Solutions::divisorSubstrings(int num, int k) {
    string s = to_string(num);
    int slow = 0, fast = 0;
    int ans = 0;
    string substring = "";

    while(fast < s.length() && slow < s.length()) {
        substring += s[fast++];

        if (fast - slow == k) {
            int nums = stoi(substring);
            
            if(nums != 0 && num%nums == 0) {
                ans++;
            }

            substring.erase(substring.begin());
            slow ++;
        }
    }

    return ans;
}
/*
Example 1:
Input: num = 240, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.
*/

int Solutions::minimumRecolors(string blocks, int k) {
    int slow = 0, fast = 0;
    int ans = INT_MAX, count = 0;

    while(fast < blocks.length() && slow < blocks.length()) {
        if(blocks[fast++] == 'W') count++;

        if(fast - slow == k) {
            ans = min(ans, count);

            if(blocks[slow] == 'W') count--;

            slow++;
        }
    }
    
    return ans;
}
/*
Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
*/

int Solutions::minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int slow = 0, fast = k - 1;
    int ans = INT_MAX;

    while(fast < nums.size() && slow < nums.size()) {

        int diff = nums[fast++] - nums[slow++];
        ans = min(ans, diff);

    }
    
    return ans;
}
/*
Example 2:

Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.
*/

int Solutions::findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int slow = 0, fast = 1
    int ans = 0;

    while(fast < nums.size() && slow < nums.size()) {
        
        if(nums[fast] - nums[slow] == 1) {
            ans = max(ans, fast - slow + 1);
        }

        while(nums[fast] - nums[slow] > 1) {
            ++slow;
        }

        ++fast;
    }

    return ans;
}
/*
Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

bool Solutions::containsNearbyDuplicate(vector<int>& nums, int k) {
    int slow = 0, fast = 0;
    unordered_set<int> set ;
    
    while( fast < nums.size() && slow < nums.size())
    {   
        if( fast - slow > k) {
            set.erase(nums[slow++]);
        }
        
        if(set.count(nums[fast]) > 0) {
            return true;
        }

        set.insert(nums[fast++]);
    }
    return false ;
}
/*
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
*/

double Solutions::findMaxAverage(vector<int>& nums, int k) {
    double ans = 0, temp = 0;
    
    for(int i=0; i<k; i++) {
        temp += (double)nums[i];
    }

    ans = temp;

    int slow = 0, fast = k;

    while(fast < nums.size() && slow < nums.size()){
        temp += (double)nums[fast++];
        temp -= (double)nums[slow++]; 
            
            ans = max(ans, temp);
    }

    return ans/k; 
}
/*
Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
*/

int Solutions::minimumSubarrayLength(vector<int>& nums, int k) {
    int slow = 0, fast = 0, n = nums.size();;
    int ans = INT_MAX;

    while(fast < n && slow < n) {
        
        int special = 0;
        fast = slow;

        while(special <= k && fast < n) {
            
            special |= nums[fast];

            if(special >= k) {
                ans = min(ans, fast - slow + 1);
                break;
            }
            ++fast;
        }
        ++slow;
    }

    return ans == INT_MAX ? -1 : ans;
}
/*
Example 1:
Input: nums = [1,2,3], k = 2
Output: 1
Explanation:
The subarray [3] has OR value of 3. Hence, we return 1.
*/

int Solutions::longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int slow = 0, fast = 0;
    int ans = 0;

    while(fast < nums.size() && slow < nums.size()) {
        
        if(fast > 0 && (nums[fast - 1 ] % 2 == nums[fast] % 2 || nums[fast]  > threshold) ) {
            slow = fast;
        }

        if(nums[slow] % 2 != 0 || nums[slow] > threshold) 
            ++slow;

        ans = max(ans, fast - slow + 1);

        ++fast;
    }

    return ans;
}
/*
Example 2:
Input: nums = [1,2], threshold = 2
Output: 1
Explanation: In this example, we can select the subarray that starts at l = 1 and ends at r = 1 => [2]. 
It satisfies all the conditions and we can show that 1 is the maximum possible achievable length.
*/

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string Solutions::findSubstring(string s, int k) {
    // Edge case: if k is greater than the string length
    if (k > s.size()) {
        return "Not found!";
    }

    int slow = 0, fast = 0;
    int maxVowelCount = 0, currentVowelCount = 0;
    int bestStart = -1;

    for (fast = 0; fast < k; ++fast) {
        if (isVowel(s[fast])) {
            currentVowelCount++;
        }
    }

    maxVowelCount = currentVowelCount;
    bestStart = 0;

    // Slide the window across the string
    while (fast < s.size()) {

        if (isVowel(s[slow])) {
            currentVowelCount--;
        }
        ++slow;

        if (isVowel(s[fast])) {
            currentVowelCount++;
        }
        ++fast;

        if (currentVowelCount > maxVowelCount) {
            maxVowelCount = currentVowelCount;
            bestStart = slow;
        }
    }

    return s.substr(bestStart, k);
}
/*
Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
*/

} /* namespace leetcode */
