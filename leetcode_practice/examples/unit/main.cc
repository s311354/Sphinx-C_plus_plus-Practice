#include "solutions.h"

int main(int argc, char *argv[])
{
    leetcode::Solutions solution;

    // brief Minimum Deletions to Make Character Frequencies Unique
    std::string s = "aaabbccdddtt";
    std::cout << "Min Deletions: " << solution.minDeletions(s) << std::endl;

    // brief Minimum Adjacent Swaps to Make Palindrome
    s = "mamad";
    std::cout << "Min Swaps: " << solution.minSwaps(s) << std::endl;

    // brief Two Sum
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::cout << "Two Sum: <";
    for (int i = 0; i < solution.twoSum(nums, target).capacity(); ++i) {
        std::cout << solution.twoSum(nums, target)[i] << ", ";
    }
    std::cout << ">" << std::endl;

    // brief 
    std::vector< std::vector<int> > grid = {{1, 0, 2, 0 ,1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};

    std::cout << "Shortest Distance: " << solution.shortestDistance(grid) <<std::endl;


    return 0;
}
