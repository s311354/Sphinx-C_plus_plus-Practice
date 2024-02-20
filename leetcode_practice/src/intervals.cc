#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

using namespace std;

std::vector<std::string> Solutions::summaryRanges(std::vector<int>& nums)
{
    std::vector<std::string> ans;

    int len = nums.size();
    std::string temp = "";

    for (int i = 0; i < len ; i ++) {
        int start = nums[i];
        while(i + 1 < len && nums[i+1] == nums[i] + 1) {
            ++i;
        }
        temp = start == nums[i] ? std::to_string(start) : std::to_string(start) + "->" + std::to_string(nums[i]);
        ans.push_back(temp);
    }

    return ans;
}
/*
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
*/

std::vector< std::vector<int> > Solutions::mergeInterval( std::vector< std::vector<int> > &intervals)
{
    if (intervals.size() == 1 ) return intervals;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, \
    std::greater<std::pair<int, int>>> pq;

    for(auto& interval : intervals) {
        pq.push({interval[0], interval[1]});
    }

    std::vector<std::vector<int>> ans;

    std::pair<int, int> top = pq.top();
    ans.push_back({top.first, top.second});
    pq.pop();

    while(!pq.empty()) {
        std::pair<int, int> next = pq.top();

        if(top.second >= next.first) {
            if (top.second <= next.second)
                ans.back()[1] = next.second;
        } else {
            ans.push_back({next.first, next.second});
        }
        pq.pop();
    }
    
    return ans;
}
/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/

std::vector<std::vector<int>> Solutions::insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
    intervals.push_back(newInterval);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, \
    std::greater<std::pair<int, int>>> pq;

    for (auto & interval: intervals) {
        pq.push({interval[0], interval[1]});
    }

    std::pair<int, int> top = pq.top();
    pq.pop();
    std::vector<std::vector<int>> ans;
    ans.push_back({top.first, top.second});

    while(!pq.empty()){
        std::pair<int, int> next = pq.top();

        if(ans.back()[1] >= next.first) {
            if( ans.back()[1] <= next.second )
                ans.back()[1] = next.second;
        } else {
            ans.push_back({next.first, next.second});
        }

        pq.pop();
    }

    return ans;
}
/*
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/

static bool cmp ( std::vector<int> &a, std::vector<int> &b) { return a[1] < b[1]; }

int Solutions::findMinArrowShots( std::vector< std::vector<int> > & points)
{
    int ans = 0, arrow = 0;

    std::sort(points.begin(), points.end(), cmp);
    for (int i = 0; i < points.size(); ++i) {
        if( ans == 0 || points[i][0] > arrow) {
            ans ++;
            arrow = points[i][1];
        }
    }

    return ans;
}
/*
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

[[1, 10], [3, 9], [4, 11], [6, 7], [6, 9], [8, 12], [9, 10]]
Output: 2
*/

} /* namespace leetcode */
