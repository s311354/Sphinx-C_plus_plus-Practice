#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

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

        if(ans.back()[1] >= next.first) {
            if (ans.back()[1] <= next.second)
              ans.back()[1] = next.second;
        } else {
            ans.push_back({next.first, next.second});
        }

        pq.pop();
    }
    
    return ans;
}

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

static bool cmp ( std::vector<int> &a, std::vector<int> &b) { return a.at(1) < b.at(1); }

int Solutions::findMinArrowShots( std::vector< std::vector<int> > & points)
{
    int ans = 0, arrow = 0;

    std::sort(points.begin(), points.end(), cmp);
    for (int i = 0; i < points.size(); ++i) {
        if( ans == 0 or points.at(i)[0] > arrow) {
            ans ++;
            arrow = points.at(i)[1];
        }
    }
    return ans;
}

} /* namespace leetcode */
