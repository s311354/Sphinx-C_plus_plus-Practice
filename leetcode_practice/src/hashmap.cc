#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

bool Solutions::canConstruct(std::string ransomNote, std::string magazine)
{
    std::unordered_map<char, int> mp;

    for(auto & it : magazine) mp[it] ++;

    for(auto & it : ransomNote) {
        if(mp.find(it) != mp.end() && mp[it] > 0) mp[it]--;
        else return false;
    }

    return true;
}
/*
Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
*/

bool Solutions::isIsomorphic(std::string s, std::string t)
{
    std::unordered_map<char, char> mp, mp2;

    for(int i = 0; i < s.length(); i ++) {
        if (mp[s[i]] && mp[s[i]] != t[i]) return false;
        if (mp2[t[i]] && mp2[t[i]] != s[i]) return false;

        mp[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }

    return true;
}
/*
Example 1:

Input: s = "egg", t = "add"
Output: true
*/

bool Solutions::wordPattern(std::string pattern, std::string s)
{
    std::vector<std::string> words;
    std::string word = "";

    for(auto & it: s) {
        if (it != ' ') word+= it;
        else {
            words.push_back(word);
            word = "";
        }
    }
    words.push_back(word);

    std::unordered_map<char, std::string> mp;
    std::unordered_map<std::string, char> mp2;

    if(pattern.length() != words.size()) return false;

    for(int i = 0; i < words.size(); i ++) {
        if ( mp[pattern[i]] != "" && mp[pattern[i]] != words[i]) return false;
        if ( mp2[words[i]] && mp2[words[i]] != pattern[i]) return false;

        mp[pattern[i]] = words[i];
        mp2[words[i]] = pattern[i];
    }

    return true;
}
/*
Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
*/

bool Solutions::isAnagram(std::string s, std::string t)
{
    std::unordered_map<char, int> count;

    if(s.length() != t.length()) return false;

    for(int i = 0; i < s.length(); i ++) {
        ++count[s[i]];
        --count[t[i]];
    }

    for(auto & it: count) {
        if (it.second != 0) return false;
    }

    return true;
}
/*
Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
*/

std::vector<std::vector<std::string>> Solutions::groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> groups;

    for(auto & str: strs) {
        std::string sorted = str;
        std::sort(sorted.begin(), sorted.end());
        groups[sorted].push_back(str);
    }
    
    std::vector<std::vector<std::string>> ans;

    for (const auto& pair : groups) {
        ans.push_back(pair.second);
    }

    return ans;
}
/*
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

bool Solutions::isHappy(int n)
{   
    while ( n != 1 and n != 4 ) {
        int sum = 0, digit = 0;
        while (n > 0) {
            digit = n%10;
            sum += digit*digit;
            n = n/10;
        }
        n = sum;
    }

    return n == 1 ? true: false;
}
/*
Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

bool Solutions::containsNearbyDuplicate(std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> mp;

    for(int i = 0; i < nums.size(); i ++) {
        if (mp.find(nums[i]) != mp.end()) {
            if (i - mp[nums[i]] <= k) return true;
        }
        mp[nums[i]] = i;
    }

    return false;
}
/*
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
*/

int Solutions::longestConsecutive(std::vector<int>& nums)
{
    if (!nums.size()) return 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int count = 1, longest = 1;

    for(auto & num : nums) {
        pq.push(num);
    }
    
    int order = pq.top(); pq.pop();
    while (!pq.empty()) {
        const int tmp = pq.top();
        if (tmp == order) {pq.pop();continue;}
        if (tmp == order + 1) count ++;
        else count = 1;
 
        longest = longest > count ? longest : count;
        order = tmp;
        pq.pop();
    }
 
    return longest;
}
/*
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

// Hard!!
std::vector<std::vector<std::string>> Solutions::word_count_engine(std::string document)
{
    unordered_map<string, int> mp;

    for(int i = 0; i < document.length(); i++) {
        string word = "";
        
        while(i < document.length() && document[i] != ' ') { 
            if((document[i] >= 'a' && document[i] <= 'z') || (document[i] >= 'A' && document[i] <= 'Z'))
                word += tolower(document[i++]);
            else i++;
        }
        
        if(word != "") mp[word] ++;
    }

    priority_queue<pair<int, std::string>> pq;

    for(auto& it: mp) {
        pq.push({it.second, it.first});
    }

    vector<vector<string>> ans;
    while(!pq.empty()) {

        pair<int, string> node = pq.top(); pq.pop();

        vector<string> wcnt;

        wcnt.push_back(node.second);
        wcnt.push_back(to_string(node.first));
        ans.push_back(wcnt);
    }

    return ans;

}


} /* namespace leetcode */
