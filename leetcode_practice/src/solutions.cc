#include "solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

Solutions::Solutions() {};
Solutions::Solutions(std::istream& s) {};
Solutions::~Solutions() {};


bool Solutions::isPalindrome(std::string s)
{
    /*
    int start = 0, end = s.length() - 1;

    while (start < s.length() / 2) {
            if (s[start] == s[end - start]) {
                start ++;
            } else {
                return false;
            }
    }

    return true;
    */
    int start = 0, end = s.length() - 1;

    while (start <= end) {
        if (!isalnum(s[start])) {
            start ++;
        } else if (!isalnum(s[end])) {
            end --;
        } else if (toupper(s[start]) != toupper(s[end])) {
            return false;
        } else {
            start ++; end --;
        }
    }

    return true;

}

bool Solutions::isValidChar(char c)
{
    return ((c - 'a' >= 0 && c - 'z' <= 0) || (c - 'A' >= 0 && c - 'Z' <= 0));
}

bool Solutions::isValidString(std::string s)
{
    for (auto elem : s) {
        if ((elem - 'a' >= 0 && elem - 'z' <= 0 ) || (elem - 'A' >= 0 && elem - 'Z' <= 0)){
            continue;
        }
        else return false;
    }

    return true;
}

int Solutions::minDeletions(std::string s)
{
    std::vector<int> v(26, 0);

    for (auto it : s)
        v[it - 'a'] ++;

    // Count the frequencies of elements
    // key: the ASCII code of character, value: the frequencies of element
    std::map<int, int> mp;
    for (int i = 0; i < 26; ++i) mp[v[i]] ++;

    int ans = 0;

    // Traverse map from backwards (find the minimum number of character need to delete)
    for (auto it = mp.rbegin();  it!=mp.rend() ; ++it) {
        int key = it->first;
        int val = it->second;

        // not frequencies of elements
        if (key == 0 || val == 1) {
            continue;
        }

        // increase the freqnency count after delete characters
        int new_val = val - 1;
        mp[key -1] += new_val;
        ans += new_val;
    }

    return ans;
}

int Solutions::minSwaps(std::string s)
{
    int start = 0, end = s.length() - 1, ans = 0;

    if (isValidString(s)) {
        while (start < s.length()/2) {

            // Palindrome
            if (s[start] == s[end - start]){
                ++ start;
                continue;
            }

            //  Core begins
            //  track of the left and right points and compare
            int left_index, right_index;

            // Indicate the index which the substring is not palindrome from right and left side
            for (left_index = start; left_index <= end - start && s[left_index] != s[end - start]; ++left_index);
            for (right_index = end - start - 1; right_index >= start && s[right_index] != s[start]; --right_index);

            // Choose minimum distance between left side or right side
            if (left_index - start < end - start - right_index) {
                for (int p = left_index; p > start; --p) {
                    std::swap(s[p], s[p-1]);
                } 
                ans += left_index - start;
            } else {
                for (int p = right_index; p < end - start; ++p) {
                     std::swap(s[p], s[p+1]);
                }
                ans += end - start - right_index;
            }

            ++start;

        }

        if (!isPalindrome(s)) return -1;

    } else {
        return -1;
    }

    return ans;
}

std::vector<int> Solutions::twoSum(std::vector<int>& num, int target)
{
    std::vector<int> indices_two_sum;
    indices_two_sum.clear();

    // O(n^2)
    /*
    for (int i = 0; i < num.capacity(); ++i) {
        for (int j = i + 1; j < num.capacity(); ++j) {
            if( (num[i] + num[j]) == target) {
                indices_two_sum.push_back(i);
                indices_two_sum.push_back(j);
            }
        }
    }
    */

    // time: O(N) space: O(2N)
    std::map<int, int> hashmap;
    hashmap.clear();

    for (int i = 0; i < num.capacity() ; i++)
    {
        const int diff = target - num[i];

        if ( hashmap.count(diff)) {
            indices_two_sum.push_back(hashmap[diff]);
            indices_two_sum.push_back(i);
            return indices_two_sum;
        }

        hashmap.insert( { num[i], i } );
    }

    return indices_two_sum;
}

int Solutions::shortestDistance( std::vector< std::vector<int> > & grid )
{
    int row = grid.size();
    int column = grid[0].size();

    std::vector< std::vector<int> > distance(row, std::vector<int>(column, 0));
    std::vector< std::vector<int> > visit(row, std::vector<int>(column, 0));

    int num_building = 0;
    int ans = INT_MAX;

    // do BFS
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            // parent node (building)
            if (grid[i][j] == 1) {
                num_building ++;
                auto tmp_grid = grid;
                bfs_distance(i, j, tmp_grid, distance, visit);
            }
        }
    }

    // find the shortest distance
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; j++) {
            if (visit[i][j] == num_building)
                ans = std::min(ans, distance[i][j]);
        }
    }

    return ans == INT_MAX ? -1: ans;
}

/*! \brief BFS for Shortest Distance from All Buildings
 *
 *  traversing 2-D grid
 *
 * \return None
 */
void Solutions::bfs_distance(int column, int row, std::vector< std::vector<int> > &grid, std::vector< std::vector<int> > &distance, std::vector< std::vector<int> >  &visit)
{
    // assigns starting point into parent node
    std::queue< std::pair<int, int> > to_visit; // BFS
    to_visit.push({column, row});

    int step = 0;

    // traversing from source (parent node)
//     std::cout << "Boundary " << grid.size() << " "  << grid[0].size() << std::endl;
    while (!to_visit.empty()) {

        // exploring 2D grid
        int curDepth = to_visit.size();
        for (int i = 0; i < curDepth; ++i) {

            int xx = to_visit.front().first;
            int yy = to_visit.front().second;

            to_visit.pop();

            // meet the boundary
            if (xx == grid.size() || xx < 0 || yy == grid[0].size() || yy <0) continue;

            // Only empty land which you can pass by freely
            if (step != 0 && grid[xx][yy] != 0) continue;

            // Update Status
            visit[xx][yy]++; //how many visitor have visited here
            distance[xx][yy] += step;
            grid[xx][yy] = -1; // visited

            to_visit.push(std::pair<int, int>(xx+1, yy)); // Up
            to_visit.push(std::pair<int, int>(xx-1, yy)); // Down
            to_visit.push(std::pair<int, int>(xx, yy+1)); // Right
            to_visit.push(std::pair<int, int>(xx, yy-1)); // Left
        }

        step ++;
    }
}


int Solutions::minStpes( std::vector<int>& num )
{
    int steps = 0;

    // Sorting
    std::sort(num.begin(), num.end(), std::greater<int> ());

    int i = 1;
    while ( i < num.capacity()) {
        // every time meet differernt number, count the step to make piles equal height
        if (num[i] != num[i-1]) {
            steps += i;
        }
        i += 1;
    }

    return steps;
}

int Solutions::maxLength( std::vector< std::string> & arr)
{

    int len = 0;

    if (arr.size() < 0) return 0;

//     if (arr.size() == 1) return arr[0].size();

    checkLen( arr, "", 0, len);
    return len;
}

// undirected DFS ( graph of string )
void Solutions::checkLen( const std::vector<std::string> & arr, std::string graphstr, int index, int & count )
{
    if (isUniqieString(graphstr)) {
        count = graphstr.size() > count ? graphstr.size(): count;
    }

    // recursive DFS
    for (int i = index; i < arr.size(); ++i) {
        checkLen(arr, graphstr+arr[i], i+1, count);
    }
}

bool Solutions::isUniqieString( const std::string s)
{
    /*
    std::unordered_set<char> unique;

    for (auto elem : s) {
        if (unique.count(elem)) return false;

        unique.insert(elem);
    }

    return true;
    */
    for (auto & elem : s) {
        if (std::count(begin(s), end(s), elem) > 1) return false;
    }

    return true;
}

std::vector<int> Solutions::sumZero(int n)
{
    std::vector<int> v;

    for (int i = 1; i <= n/2; ++i) {
        v.push_back(i);
        v.push_back(-i);
    }

    if (n%2 != 0) v.push_back(0);

    return v;
}

void Solutions::nextPermutation( std::vector<int>& nums)
{
    int i = nums.size() - 2;
    // find the first pair of two successive numbers
    while (i >= 0 && nums [i] >= nums[i+1]) {
        i--;
    }

    // find the next larger number and swap the numbers a[i-1] and a[j]
    if (i >= 0) {
        int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
    }

    // reverse the numbers following to get the next smallest lexicographic permutation.
    std::reverse(nums.begin()+i+1, nums.end());
}

int Solutions::arraySign( std::vector<int> & nums)
{
    int sign = 1;

    for (auto elem : nums) {
        if (elem < 0) sign = sign*-1;
        if (elem == 0) {
            sign = 0;
            return sign;
        }
    }

    return sign;
}

int Solutions::goodNodes(TreeNode * root)
{
    int count = 0;

    countGoodNode(root, root->val, count);

    return count;
}

void Solutions::countGoodNode(TreeNode * node, int value, int & count)
{

    /* Proposal 1. Partial Pass
    std::stack< TreeNode *> stack_node; // LIFO
    stack_node.push(node);

    TreeNode * current = nullptr;


    while (!stack_node.empty()) {

        current = stack_node.top();
        stack_node.pop();

        if (current != nullptr) {

            if ( current->val >= value) {
                count ++;
                value = current->val;
            }

            if (current->left != nullptr) stack_node.push(current->left);
            if (current->right != nullptr) stack_node.push(current->right);
        }

    }
    */

    /* Proposal 2 */ 
    if (node == nullptr) return;

    // the condition of good node
    if (node->val >= value) {
        count ++;
        value = node->val;
    }

    countGoodNode(node->left, value, count);
    countGoodNode(node->right, value, count);

}

TreeNode* Solutions::insertBTNode(TreeNode* node, int value, int index)
{
    if (node == nullptr) {
        if (value != -1) node = getNewNode(value);
        return node;
    }

    if ( index % 2) {
        node->left = insertBTNode(node->left, value, index);
    } else {
        node->right = insertBTNode(node->right, value, index);
    }

    return node;
}

TreeNode* Solutions::getNewNode(int value)
{
    TreeNode * node = new TreeNode;
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

LinkedListNode* Solutions::getNewHead(int value)
{
    LinkedListNode * node = new LinkedListNode;
    node->val = value;
    node->next = nullptr;

    return node;
}

LinkedListNode* Solutions::insertLinkedlistNode(LinkedListNode* node, int value)
{
    if (node == nullptr) {

        if (value != -1) node = getNewHead(value);
        return node;
    }

    node->next = insertLinkedlistNode(node->next, value);

    return node;
}

std::vector<int> Solutions::PrintBFS(TreeNode * node)
{
    TreeNode* current;
    std::vector<int> bfsvector;

    std::queue<TreeNode*> node_queue;
    node_queue.push(node);

    while (! node_queue.empty()) {
        current = node_queue.front();
        node_queue.pop();

        if ( current != nullptr ) {
//             std::cout << current->val << std::endl;
            bfsvector.push_back(current->val);
            if(current->left != nullptr) node_queue.push(current->left);
            if(current->right != nullptr) node_queue.push(current->right);
        }
    }

    return bfsvector;
}

std::vector<int> Solutions::PrintLinkedlist(LinkedListNode* node)
{
    LinkedListNode* current_node;
    std::vector<int> contenter;
    std::queue<LinkedListNode*> node_queue;

    node_queue.push(node);

    while (! node_queue.empty()) {
        current_node = node_queue.front();
        node_queue.pop();

        if ( current_node != nullptr ) {
            contenter.push_back(current_node->val);
            if(current_node->next != nullptr) node_queue.push(current_node->next);
        }
    }

    return contenter;
}

std::string Solutions::filterString(std::string &s)
{
    // default string with two characters
    std::string letter(s.begin(), s.begin()+2);

    for (int i = 2; i < s.length(); ++i) {
        if (s[i] != s[i-1] or s[i] != s[i-2])
            letter.push_back(s[i]);
    }

    return letter;
}

int Solutions::maxPossible(int num, int digit)
{
    std::vector<int> nums;

    bool isPos = true; 

    if (num < 0) {
        isPos = false;
        num = num * -1;
    }

    if (num == 0) nums.push_back(0);

    while (num > 0) {
        nums.push_back(num%10);
        num = num/10;
    }

    if (isPos) {
        for (auto it = nums.rbegin() ;  it != nums.rend(); it++) {
            if (*it < digit) {
                //std::cout << *it << std::endl;
                nums.insert(it.base(), digit);
                break;
            }
        }
    } else {
        for (auto it = nums.rbegin() ;  it != nums.rend(); it++) {
            if (*it > digit) {
               //std::cout << *it << std::endl;
                nums.insert(it.base(), digit);
                break;
            };
        }
    }

    // Decimal representation
    int ans = 0;
    for (auto it = nums.rbegin();  it!=nums.rend() ; it++) {
        ans = *it + ans*10;
    }

    return (isPos ? ans : -1*ans);
}

TreeNode* Solutions::deleteNode(TreeNode* node, int key)
{
    if (node == nullptr ) return nullptr;

    if ( key == node->val) {
        if( node->left == nullptr and node->right == nullptr) {
            return nullptr;
        } else if (node->left == nullptr || node->right == nullptr) {
            node = node->right;
        } else {
            // remove Min node from left side
            TreeNode* new_node = node->left;
            while(new_node->right != nullptr) new_node = new_node->right;

            node->val = new_node->val;
            node->left = deleteNode(node->left, node->val); // reconstruct tree
        }
    }

    if ( key < node->val) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->val) {
        node->right = deleteNode(node->right, key);
    }

    return node;
}

TreeNode* Solutions::getMinNode (TreeNode* node) {
    if (node == nullptr) return nullptr;

    if (node->left == nullptr) return node;

    return getMinNode(node->left);
}

int Solutions::sumFraction( std::vector< std::vector<int> > & fraction)
{
    // key: the pair of fraction, value: number of pairs of fraction
    std::map < std::pair<int, int>, int > dict;
    int ans = 0;

    for (auto& elem : fraction) {
        int g = gcd(elem[0], elem[1]);
        dict[ {elem[0]/g, elem[1]/g} ]++;
    }

    for (auto it = dict.begin(); it != dict.end() ; it++) {
        std::pair<int, int> key = it->first;
        int count = it->second;

        if (key.first * 2 > key.second) continue;

        if (key.first * 2 == key.second) {
            ans += count * (count - 1) /2;
        } else {
            auto it_match = dict.find({key.second - key.first, key.second});
            if ( it_match!= dict.end()) ans += count * it_match->second;
        }
    }

    return ans;
}

int Solutions::gcd(int a, int b) {
        while (b > 0) {
        int r = a % b;
            a = b;
            b = r;
        }
        return a;
}

int Solutions::minCost( std::string colors, std::vector<int> & neededTime)
{
    int ans = 0;
    int index = 0;

    for (int i = 1; i < colors.size(); i++)
    {
        if (colors[index] == colors[i]) {
            // minimum time
            if (neededTime[index] < neededTime[i]) {
                ans += neededTime[index];
                index = i;
            } else {
                ans += neededTime[i];
            }
        } else {
            index = i;
        }
    }
    return  ans;
}

std::string Solutions::longestPrefix(std::vector< std::string > & strs)
{
    // O(n log n)
    /*
    std::string ans = "";
    sort(begin(strs), end(strs));
    int last_index = strs.size() - 1;

    for (int i = 0; i < strs[0].size(); i++)
    {
        if( strs[0][i] == strs[last_index][i]) ans += strs[0][i];
        else break;
    }

    return ans;

    */

    // O(2n)
    std::string ans = ""; int min = 0;

    if (strs.empty()) return "";

    // find the index of minimum string
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i].size() < strs[min].size()) min = i;
    }

    // common prefix
    for (int i = 0; i < strs[min].size() ; ++i) {
        for (int k = 0;  k < strs.size() ; ++k) {
            if (strs[k][i] != strs[min][i]) return ans;
        }
        ans += strs[0][i];
    }
    return ans;
}

int Solutions::getLargestK( std::vector<int> & nums){

/*
    std::set<int> largestval;
    int ans = 0, tmp = 0;

    for (int num : nums) {
        if (largestval.count(-num)) {
            if (num > tmp) tmp = num;
            if (num < tmp) tmp = -num;

            ans = std::max(tmp, ans);
        } else {
            largestval.insert(num);
        }
    }

    return ans;
*/
    int ans = 0;

    for (auto & elem : nums) {
        if (elem > 0) continue;

        auto it = std::find(begin(nums), end(nums), elem*-1);

        ans = ans > *it ? ans : *it;
    }

    return ans;
}

int Solutions::smallestInt( std::vector<int> &A )
{

    /*
    std::vector<int> v(A.size(), 0);

    for (auto elem : A) {
        if (elem > 0) v[elem] ++;
    }

    int i;

    for (i = 1 ; i < v.size(); i ++) {
        if (v[i] == 0) return i;
    }

    return i + 1;

    */
    // C++17
    size_t smallest = 0;
    auto maxit = std::max_element(A.begin(), A.end());

    int i;
    for (i = 1; i <= *maxit; ++i) {
        if (std::count(begin(A), end(A), i) == 0){
            return i;
        }
    }

    return i;
}

/*! \brief  Minimum number of changes
 *
 *  Circuit printing, as we call photolithography, is an extremely complex yet rewarding field, and ASML needs the best software engineers in the world to make this magic happen. We work closely with our clients to help them print their circuits in the most effective way. One of our clients requests us to write a method to optimize their circuit efficiency. The circuit is represented as a string consisting of the letters "M" and "L", where M represents Memory units and L represents Logic units. The efficiency of the circuit is measured as the length of the longest interval of letters "M". For example, given input string "LMMMLMMMMLLLM", the longest interval is 4.
 *
 * Our customer wants to change the circuit in such a way that the longest M-interval will be equal to K. We can change any unit at any position in the circuit, i.e. either we can change any "M" to "L" or any "L" to "M". The objective of this challenge is to calculate the minimum number of changes we have to make in order to achieve the desired longest M-interval length K.
 *
 * \return Minimum number of changes
 */
int Solutions::minChange( std::string &S, int k)
{
    int mincharge = 0;

    std::vector<int> numbers(S.size(), 0);
    int slidingwindow = 0;
    for (auto & elem : S) {
        numbers.push_back( elem - 'L');
    }


    return mincharge;
}

int evil (uint32_t N)
{
    return N & (N + 1) ? evil(N | (N >> 1)) + 1 : 0;
}

int Solutions::lengthBin(uint32_t N)
{
    if (N == 0) return 0;

    while(!(N & 1)) N >>= 1;

    return evil(N);

    /*
    std::bitset<16> binary(N) ;

    std::string bit = binary.to_string();

    int ans = INT_MIN, max = 0;

    for (auto elem : bit) {
        if( elem == '0') {
            max ++;
        } else {
            if (max > ans and max != 0 and max < 6) ans = max;
            max  = 0;
        }
    }

    return (ans == INT_MIN) ? 0: ans;
    */
}

/*! \brief The Monty Hall Problem
 *
 *  The Monty Hall problem is a famous conundrum in probability which takes the form of a hypothetical game show. The contestant is presented with three doors; behind one is a car and behind each of the other two is a goat. The contestant picks a door and then the gameshow host opens a different door to reveal a goat. The host knows which door conceals the car. The contestant is then invited to switch to the other closed door or stick with their initial choice.
 *
 * \return probability
 */
float Solutions::montyHall(int guess)
{
    int winningNum = 0;
    int switchedNum = 0;
    int switchedCount = 0;
    int elimNum = 0;

    for (int i = 0; i < 1000; ++i) {
        winningNum = getRandom(1, 3, 0);
        elimNum = getRandom(1, 3, winningNum);
        switchedNum = getRandom(1, 3, elimNum);

        while (switchedNum == guess ) {
            switchedNum = getRandom(1, 3, winningNum);
        }

        if (switchedNum == winningNum) switchedCount ++;

    }

    return 100 - (switchedCount / 10);
}

int Solutions::getRandom(int low, int high, int badNum)
{
    int random = rand() % high + low;

    while ( random == badNum ) {
        random = rand() % high + low;
    }

    return random;
}

int Solutions::lowercaseLetters( std::string &S)
{
    int ans = 0;
    int startnumber = 0;
    int endnumber = S.size();

    if (S.size() == 0 or S.size() == 1) return S.size();

    for (auto it = S.begin() + 1;  it!=S.end() ; it++) {
        if (*it == *S.begin()) {
            startnumber ++;
            if (*(it++) == *(it)) {
                startnumber ++;
            }
            break;
        } else {
            startnumber ++;
        }
    }

    if (startnumber + 1 == S.size()) S.erase(0, startnumber );

    else S.erase(0, startnumber +1 );

    if (S.size() != 1) {
        for (auto it = S.rbegin() + 1;  it!=S.rend() ; it++) {
            if (*it == *S.rbegin()) {
                endnumber --;
                break;
            } else {
                endnumber --;
            }
        }

        S.erase(endnumber - 1, S.size());
    }

    return S.size();
}

/*! \brief Balanced Stone Heaps
 *
 *  There are n heaps of stone. The i-th heap has hi stones. You want to change the number of stones in the heap by performing the following process once:
 *
 *  - You go through the heaps from the 3-rd heap to the n-th heap, in this order.
 *  - Let i be the number of the current heap
 *  - You can choose a number d, move d stones from the i-th heap to the (i-1)th heap, and 2*d stones from the i-th heap to the (i-2)th heap.
 *  - So after that hi is decreased by 3*d, hi-1 is increased by d, and hi-2 is increased by 2*d.
 *  - You can choose different or same d for different operations. Some heaps may become empty, but they still count as heaps.
 *
 * \return the maximum number of stones in the smallest heap after the process.
 */
int Solutions::balancedStone( std::vector<int> &A)
{
    for (int i = 2, p; i < A.size(); ++i) {

        p = A[i]/3;

        if (p == 0){
            return 1;
            break;
        }

        A[i] -= p *3;
        A[i - 1] += p;
        A[i - 2] += p*2;
    }

    return A[0];
}


/*! \brief Course Schedule III
 *
 *  There are n different online courses numbered from 1 to n, You are given an array courses where courses[i] = [duration, lastDayi] indicate that the ith course should be taken continuously for duration days and must be finished before or on lastDayi.
 *
 *  You will start on the 1st day and you cannot take two or more courses simultaneously.
 *
 * \return the maximum number of courses that you can take
 */
int Solutions::scheduleCourse( std::vector< std::vector<int> > & courses)
{
    int totalcourse = 0;
    int time = 0;
    std::priority_queue<int> duration;

    for (int i = 0; i < courses.size(); ++i) {
        if (time + courses.at(i)[0] <= courses.at(i)[1]) {
            time += courses.at(i)[0];
            duration.push(courses.at(i)[0]);
        } else if (!duration.empty() && duration.top() > courses.at(i)[0]) {
            time = (duration.top() - courses.at(i)[0]);
            duration.pop();
            duration.push(courses.at(i)[0]);
        }
    }

    return duration.size();
}

/*! \brief Minimum characters required to be removed to make frequency of each character unique
 *
 *  Given string str, the task is to find the minimum count of characters that need to be deleted from the string such that the frequency of each character of the string is unique
 *
 * \return minimum removals required
 */
int Solutions::uniqueString( std::string &S)
{
    std::vector<int> asciicode(26);

    for (auto elem : S) {
        asciicode[elem - 'a'] ++;
    }

    std::map<int, int> frequencychar;
    for (int i = 0; i < 26; ++i) {
        frequencychar[asciicode[i]] ++;
    }

    int ans = 0;

    for (auto it = frequencychar.rbegin();  it != frequencychar.rend() ; ++it) {
        int ascii = it->first;
        int count = it->second;

        if (ascii == 0 or count == 1) continue; // 

        int new_count = count - 1;
        frequencychar[ascii - 1] = new_count;
        ans += new_count;
    }

    return ans;
}


/*! \brief Meeting rooms
 *
 *  Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
 *  Where:
 *  A[i][0] = start time of the ith meeting.
 *  A[i][1] = end time of the ith meeting.
 *
 *  Find the minimum number of conference rooms required so that all meetings can be done.
 *
 * \return minimum meetings rooms
 */
int Solutions::storeMeetingrooms( std::vector< std::vector<int> > & rooms)
{
    int room = INT_MIN;

    std::vector< std::pair<int, int> > meeting;

    for (int i = 0; i < rooms.size(); ++i) {
        int start = rooms.at(i)[0];
        int end = rooms.at(i)[1];

        meeting.push_back( {start, 0});
        meeting.push_back( {end, 1});
    }

    sort(meeting.begin(), meeting.end());
    int count = 0;
    for (int i = 0; i < meeting.size(); ++i) {
        // start
        if (meeting.at(i).second == 0) {
            count ++;
        } else {
            count --;
        }
//         room = std::max(room, count);
        room = room > count ? room : count;
    }

    return room;
}

/*! \brief Minimum Number of Arrows to Burst Balloons
 *
 *  There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
 *
 *  Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
 *  Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 *
 * Runtime: 555 ms, faster than 66.04% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
 *
 * Memory Usage: 89.7 MB, less than 67.65% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
 *
 *
 * \return minimum number of arrows that must be shot to burst all balloons
 */
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

/*! \brief The Maximum Number of Full Rounds
 *
 * John has recently discovered an online game. In the game, a 15-minute round starts in each quarter-hour period, starting at times notated in the format HH: 00, HH: 15, HH: 30 Or HH: 45, where HH is a number from de to 23. John uses a 24 hour clock, so the earliest time is 00:00 and the latest is 23:59. John starts playing at time A and ends at time B. If B is earlier than A, John has played overnight (from time A to midnight and from midnight to time B). What is the maximum number of full rounds that can be played by John? Write a function: that, given two strings A and B (in HH: MM format), representing the start time and end time, returns an integer denoting the maximum number of full rounds that John can play within the given period of time.
 *
 * Examples:
 * 1. Given A = "12:01" and B = "12:44", the function should return 1. John can play only one round (from 12:15 to 12:30). He starts too late to play the round from 12:00 to 12:15 and he will not be able to finish the 12:30-12:45 round.
 *
 * 2. Given A = "20:00" and B = "06:00", the function should return 40. John can play 16 game rounds from 20:00 to 0:00 and 24 game rounds from 00: 00 to 06:00.
 *
 * 3. Given A = "00:00" and B = "23:59", the function should return 95. John can play four rounds every hour except for the last hour, in which he can play only three rounds (23:00-23:15, 23:15-23:30,23:30-23:45). The next round would be 23:45-00:00 but John has to end 1 minute sooner, so he cannot take part in it.
 *
 * 4. Given A = "12:03" and B = "12:03", the function should return 0. John cannot play any round
during an empty period of time.
 *
 *
 * \return Maximum number of Full Rounds
 */
int Solutions::maxFullRound( std::string &A, std::string &B)
{
    float min_a = boost::lexical_cast<float>( A.substr(3, 2).c_str());
    float hr_a = boost::lexical_cast<float>( A.substr(0, 2).c_str());
    float min_b = boost::lexical_cast<float>( B.substr(3, 2).c_str());
    float hr_b = boost::lexical_cast<float>( B.substr(0, 2).c_str());

    int time = 0;

    if ( hr_a - 12 > 0 and hr_b - 12 > 0) {
        // Count A
        if (min_a == 0) {
            time += (24 - hr_a) * 4;
        }else {
            time += (24 - hr_a - 1) * 4;
            while (min_a < 60) {
                min_a = std::ceil(min_a/15)*15 + 15;
                time ++;
            }
        }

        // Count B
        if (min_b == 0) {
            time += (24 - hr_b) * 4;
        }else {
            time += (24 - hr_b - 1) * 4;
            time += (std::floor(min_b / 15));
        }
    } else if (hr_a - 12 > 0 and hr_b - 12 <= 0) {
        // Count A
        if (min_a == 0) {
            time += (24 - hr_a) * 4;
        }else {
            time += (24 - hr_a - 1) * 4;
            while (min_a < 60) {
                min_a = std::ceil(min_a/15)*15 + 15;
                time ++;
            }
        }

        // Count B
        if (min_b == 0) {
            time += (hr_b) * 4;
        }else {
            time += (24 - hr_b - 1) * 4;
            time += (std::floor(min_b / 15));
        }

    } else if (hr_a - 12 <= 0 and hr_b - 12 > 0) {
        // Count A
        if (min_a == 0) {
            time += (hr_b - hr_a) * 4;
        } else {
            time += (hr_b - hr_a - 1) * 4;
            while (min_a < 60) {
                min_a = std::ceil(min_a/15)*15 + 15;
                time ++;
            }
        }

        // Count B
        if (min_b == 0) {
            time += (24 - hr_b) * 4;
        }else {
            time += (24 - hr_b - 1) * 4;
            time += (std::floor(min_b / 15));
        }


    } else {
        while (min_a < 60) {
            min_a = std::ceil(min_a/15)*15 + 15;
            if (min_a < min_b) time ++;
            else break;
        }

    }

    return time;
}

int Solutions::solutions2( std::vector<int>  &A)
{
    int ans = 0;
    int index = 0;

    for (auto it = A.begin();  it!=A.end() ; it++) {
        ans += *it;

        if (ans < 0) {
            it = A.erase(it);
            index ++;
        }
    }

    return index;
}

/*! \brief Maximum Possible Sum of Values of the Edges' Endpoints
 *
 *  You are given an undirected graph consisting of N vertices, numbered from 1 to N, and M edges. The graph is described by two arrays, A and B, both of length M. A pair (A[K], B[K]), for K from 0 to M-1, describes an edge between vertex A[K] and vertex B[K].
 *
 *  Your task is to assign all values from the range [1..N] to the vertices of the graph, giving one number to each of the vertices. Do it in such a way that the sum over all edges of the values at the edges' endpoints is maximal.
 *
 *  For example, given N = 5, A = [2, 2, 1, 2], B = [1, 3, 4, 4], the graph has four edges: (2, 1), (2, 3), (1, 4), (2, 4). In order to obtain the maximum sum of weights, you can assign the following values to the vertices: 3, 5, 2, 4, 1 (to vertices 1, 2, 3, 4, 5 respectively).
 *
 *  Picture illustrates the first example test
 *
 *  This way we obtain the sum of values at all edges' endpoints equal to 7 + 8 + 7 + 9 = 31:
 *
 *  edge (2, 3): 7 = 5 (vertex 2) + 2 (vertex 3)
 *  edge (2, 1): 8 = 5 (vertex 2) + 3 (vertex 1)
 *  edge (1, 4): 7 = 3 (vertex 1) + 4 (vertex 4)
 *  edge (2, 4): 9 = 5 (vertex 2) + 4 (vertex 4)
 *  Notice that the value assigned to vertex 5 did not have any effect on the final result as it is not an endpoint of any edge.

 * Write a function: function solution($N, $A, $B); that, given a positive integer N and two arrays A, B of M positive integers, returns the maximum possible sum of values of the edges' endpoints.
 *
 *
 * \return maximum possible sum of values of the edges' endpoints
 */
bool cmpmap( std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.second > b.second;
}
int Solutions::maximumSum(int N, std::vector<int> &A, std::vector<int> &B)
{
    /* Solution 1
    int sum = 0;
    std::vector<int> vertexcount (N, 0);

    for (auto elem : A) {
        vertexcount[elem] ++;
    }

    for (auto elem : B) {
        vertexcount[elem] ++;
    }

    std::vector<int> vertex(N, 0);
    for (int i = 0; i < vertexcount.size(); ++i) {
        vertex[i] = vertexcount[i];
    }

    std::vector<int> wightvertex(N, 0);
    while (!vertexcount.empty()) {
        auto maxcount = std::max_element(vertexcount.begin(), vertexcount.end());

        for (int i = 0; i < vertex.size(); ++i) {
            if (vertex[i] == *maxcount and wightvertex[i] == 0) {
                wightvertex[i] = N;
                N--;
            }
        }
        vertexcount.erase(maxcount);
    }

    for (int i = 0; i < A.size(); ++i) {
        sum += wightvertex[A[i]] + wightvertex[B[i]];
    }

    return sum;
    */

    int sum = 0;
    std::map<int, int> vertexcount;

    for (auto &elem : A) {
        vertexcount[elem] ++;
    }

    for (auto &elem : B) {
        vertexcount[elem] ++;
    }

    std::vector< std::pair<int, int> > vertex;

    for (auto &it : vertexcount) {
        vertex.push_back(it);
    }

    std::sort(vertex.begin(), vertex.end(), cmpmap);

    std::vector<int> wightvertex(N+1,0);
    for (auto it = vertex.begin(); it != vertex.end(); it++) {
        wightvertex.at(it->first) = N;
        N --;
    }

    for (int i = 0; i < A.size(); ++i) {
        sum += wightvertex[A[i]] + wightvertex[B[i]];
    }

    return sum;
}


/*! \brief Contains Duplicate
 *
 *  Given an integer array nums, retuen true if any value appears at least twice in the array, and return false if every elements is distinct.
 *
 * Runtime: 150 ms, faster than 29.17% of C++ online submissions for Contains Duplicate.
 *
 * Memory Usage: 53.5 MB, less than 19.10% of C++ online submissions for Contains Duplicate.
 *
 *
 * \return if every elements is distinct return false. Otherwise, return true
 */
bool Solutions::containDup( std::vector<int> & nums)
{
    std::unordered_set<int> set;

    bool isDuplicate = false;
    // Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    for (auto elem : nums) {
        auto it = set.insert(elem);
        if (!it.second) isDuplicate = true;
    }

    return isDuplicate;
}


/*! \brief Single Number
 *
 *  Given a non-empty array of integers nums, every element appears twice expect for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
 *
 *  Runtime: 20 ms, faster than 79.39% of C++ online submissions for Single Number.
 *
 *  Memory Usage: 16.9 MB, less than 85.45% of C++ online submissions for Single Number.
 *
 * \return Single Number
 */
int Solutions::singleNumber( std::vector<int> & nums)
{
    /*
    std::unordered_set<int> set;
    int singlenum = -1;
    for (auto elem : nums) {
        if(set.count(elem)) set.erase(elem);
        else set.insert(elem);
    }

    return *set.begin();
    */

    int num = 0;

    for (auto elem : nums) {
        num ^= elem;
    }

    return num;

}

/*! \brief Intersection of Two Arrays
 *
 * Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
 *
 * \return intersection array
 */
bool binarySearch( std::vector<int> & nums, int target)
{
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left)/2;
        if(nums.at(mid) == target) return true;
        else if (nums.at(mid) < target) left = mid + 1;
        else right = mid;
    }
    return false;
}

/*! \brief intersection of Two Arrays
 *
 *  Given two integer arrays num1 and num2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
 *
 *  Runtime: 4 ms, faster than 88.21% of C++ online submissions for Intersection of Two Arrays.
 *
 *
 *  Memory Usage: 10.6 MB, less than 23.23% of C++ online submissions for Intersection of Two Arrays.
 *
 *
 * \return an array if their intersection
 */
std::vector<int> Solutions::intersection( std::vector<int> & nums1, std::vector<int> & nums2)
{
    std::unordered_set<int> set(nums1.begin(), nums1.end()), intersectionset; // Complexity: Constant.

    for (auto elem : nums2) {
        // Time Complexity: Time Complexity for unordered_set::count() method is O(1) in average cases, but in worst case, time complexity can be O(N) 
        if (set.count(elem)) intersectionset.insert(elem);
    }

    return std::vector<int>(intersectionset.begin(), intersectionset.end()); // The complexity is linear in the number of elements inserted plus the distance to the end of the vector.

    /*
    std::unordered_set<int> intersection;
    std::sort(nums2.begin(), nums2.end());  O(N log N)

    for (auto elem : nums1) {
        if (binarySearch(nums2, elem)) intersection.insert(elem);
    }

    return std::vector<int>(intersection.begin(), intersection.end()) ;
    */
}



/*! \brief Happy Number
 *
 *  Write an algorithm to determine if a number n is happy.
 *
 *  Starting with any positive integer, replace the number by the sum of the squares of its digits.
 *  Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 *  Those numbers for which this process ends in 1 are happy.
 *
 *  Runtime: 3 ms, faster than 55.97% of C++ online submissions for Happy Number.
 *
 *  Memory Usage: 5.9 MB, less than 62.07% of C++ online submissions for Happy Number.
 *
 * \return true if n is a happy number, and false if not
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




/*! \brief Dictionaries and Maps
 *
 *  Given n names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. You will then be given an unknown number of names to query your phone book for. For each name queried, print the associated entry from your phone book on a new line in the form name=phoneNumber; if an entry for name is not found, print Not found instead.
 *
 *  Input Format
 *  The first line contains an integer, n, denoting the number of entries in the phone book. 
 *  Each of the n subsequent lines describes an entry in the form of 2 space-separated values on a single line. The first value is a friend's name, and the second value is an 8-digit phone number.
 *  After the n lines of phone book entries, there are an unknown number of lines of queries. Each line (query) contains a name to look up, and you must continue reading lines until there is no more input.
 *  Note: Names consist of lowercase English alphabetic letters and are first names only.
 *
 *
 *  Output Format
 *  On a new line for each query, print Not found if the name has no corresponding entry in the phone book; otherwise, print the full name and phoneNumber in the format name=phoneNumber.
 *
 * \return None
 */
void Solutions::dictionaries()
{
    
}

/*! \brief 4Sum
 *
 *  Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 *  0 <= a, b, c, d < n
 *  a, b, c, and d are distinct.
 *  nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *  // Reference: https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-18-4sum/
 * \return all the unique quadruplets
 */
std::vector< std::vector<int> > Solutions::fourSum( std::vector<int>& nums, int target)
{
    // Constructs new container from a variety of data sources and optionally using user supplied allocator alloc or comparison function object comp.
    std::set< std::vector<int> > quadruplets;

    std::sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k  < n; ++k ) {
                int t = target - nums.at(i) - nums.at(j) - nums.at(k);
                if (t < nums.at(k)) break;
                if (!std::binary_search( nums.begin() + k + 1, nums.end(), t)) continue;
                quadruplets.insert({ nums.at(i), nums.at(j), nums.at(k), t});
            }
        }
    }

    return std::vector< std::vector<int> >(begin(quadruplets), end(quadruplets));
}


/*! \brief Same Tree
 *
 * Given the roots of two binary trees p and q, write a function to check if they are the same of not.
 *
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value
 *
 *
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Same Tree.
 *
 * Memory Usage: 39.5 MB, less than 93.45% of Java online submissions for Same Tree.
 *
 * \return if they are structurally identical
 */
bool Solutions::isSameTree(TreeNode* p, TreeNode * q)
{
    if (!p and !q) return true;

    if (!p or !q) return false;

    if (p->val != q->val) return false;


    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}


/*! \brief Replace Words
 *
 *  In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
 *
 *  Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
 *
 * Runtime: 106 ms, faster than 45.33% of C++ online submissions for Replace Words.
 *
 *
 * Memory Usage: 20.4 MB, less than 99.19% of C++ online submissions for Replace Words.
 *
 * \return the sentence after the replacement
 */
std::string  Solutions::replaceWords( std::vector< std::string> & dictionary, std::string  sentence)
{
    std::unordered_set< std::string > dict;
    for (auto elem : dictionary) {
        dict.insert(elem);
    }

    bool skip = false;
    std::string result = "", curr = "";

    // iterate to read each of characters 
    for (int i = 0; i < sentence.length(); i++) {
        if( sentence[i] == ' ' || i == sentence.length() - 1 ) {
            // replace Words
            result += curr;
            curr = "";

            if ( i != sentence.length() - 1) result+= " ";
            else {
                if (not skip) {
                    result += sentence.back();
                }
            }

            skip = false;
        } else if (not skip) {
            curr += sentence[i];
            if(dict.find(curr) != dict.end()) skip = true;
        }
    }

    return result;
}

/*! \brief Uncovered interval
 *
 * \return minimum uncovered interval
 */
int Solutions::uncovered_interval( std::vector< std::pair<int, int> > unservice, int thirdservice)
{

    int minuncovertime = INT_MAX;
    int totalunserviced = 0;

    for (int i = 0; i < unservice.size(); ++i) {
        totalunserviced += unservice.at(i).second - unservice.at(i).first + 1;
    }

    int j;
    for( j  = 0; j < unservice.size() - 1; j++ ) {
        int uncovertime = totalunserviced;
        if ( unservice.at(j + 1).first - unservice.at(j).first  > thirdservice ) {
            uncovertime = totalunserviced - (unservice.at(j).second - unservice.at(j).first) + 1;
        } else {
            if ( unservice.at(j + 1).second - unservice.at(j).first > thirdservice) {
                uncovertime = totalunserviced - (unservice.at(j).second - unservice.at(j).first + 1 + (totalunserviced + unservice.at(j).first - unservice.at(j + 1).first + 1) );
            } else {
                uncovertime = totalunserviced - (unservice.at(j).second - unservice.at(j).first + 1) - (unservice.at(j + 1).second - unservice.at(j + 1).first + 1);
            }
        }

        minuncovertime = std::min(minuncovertime, uncovertime);
    }

    minuncovertime = std::min(minuncovertime, totalunserviced - (unservice.at(j).second - unservice.at(j).first) + 1);

    return minuncovertime;
}


/*! \brief Minmum Swaps to Group All 1's Together
 *
 *  A swap is defined as taking two distinct positions in an array and swapping the values in them.
 *  A circular array is defined as an array where we consider the first element and the last element to be adjacent.
 *  Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.
 *
 * \return minimum swap
 */
int Solutions::minSwapsnums( std::vector<int> & nums)
{
    /* Time Limit Exceeded
    int minswap = INT_MAX;

    int slidingwindow = std::count(begin(nums), end(nums), 1);

    for (int i = 0; i < nums.size(); ++i) {
        int count = 0;
        for (int j = i; j < i + slidingwindow; ++j) {
            if (nums.at(j%nums.size()) == 0) count++ ;
        }
        minswap = std::min( minswap, count);
    }

    return minswap;
    */

    int slidingwindow=0;
    for(int i=0;i<nums.size();i++)
        if(nums[i]==1)
            slidingwindow++;
    int result=0;

    // Just check the number of zeroes in each window 
    for(int i=0;i<slidingwindow;i++)
    {
         if(nums[i]==0)
             result++;
    }

    // circular check
    int ans=result;
    for(int i=1;i<nums.size();i++)
    {
        int j=(i+slidingwindow-1)%nums.size();
        if(nums[i-1]==0)
            result--;
        if(nums[j]==0)
            result++;
        ans=std::min(ans,result);
    }
    return ans;
}


/*! \brief Minimum Distance
 *
 * \return minimum step
 */
int Solutions::minDistance( std::vector< std::vector<int> >& edges, int n, int x)
{
    int minstep = 0;
    std::queue<int> parent;
    parent.push(x);

    while (!parent.empty()) {
        int vertex = parent.front();
        parent.pop();

        int step = INT_MAX;

        // exploring minimum distance
        for(int i = 0; i < edges.size(); i++) {
            if ( edges[i][0] == vertex && step > edges[i][2]) { // source
                    parent.push(edges[i][1]); //  dest
                    step = edges[i][2];
                    minstep += step;
            }

        }
    }

    return minstep;
}

std::vector< std::string > Solutions::commonSubstring( std::vector< std::string> a, std::vector<std::string> b )
{
    std::vector< std::string > isCommon;
    for (int i = 0; i < a.size(); ++i) {
        bool common = false;
        for (auto &elem : a[i]) {
            auto it = std::find(b[i].begin(), b[i].end(), elem);
            if (it != b[i].end()) common = true;
        }
        if (common) isCommon.push_back("YES");
        else isCommon.push_back("NO");
    }

    return isCommon;
}

int Solutions::countDuplicates( std::vector<int> input)
{
    int count = 0;
    std::unordered_set<int> numberset;

    for (auto it = input.begin() + 1;  it!= input.end(); it++) {
        auto numberit = numberset.insert(*it);
        if (!numberit.second) {
            count ++ ;
            numberset.erase(*it);
        }
    }
/*
    int count = 0;
    std::vector<int> numbers(input[0], 0);
    for (auto & num : input) {
        numbers[num] ++;
    }

    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] > 1) count ++;
    }
*/
    return count;
}

/*! \brief Complete the 'plusMinus' function below.
 *
 *  Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal value of each fraction on a new line with  places after the decimal.
 *  Note: This challenge introduces precision problems. The test cases are scaled to six decimal places, though answe
 *  s with absolute error of up to  are acceptable.
 *
 * \return Return decimal value of each fraction
 */
std::vector<float> Solutions::plusMinus( std::vector<int> arr)
{
    std::vector<float> Minu(3, 0);
    for (auto & elem : arr) {
        if (elem > 0) Minu[0] ++;
        else if (elem < 0) Minu[1] ++;
        else Minu[2] ++;
    }

    for (int i = 0; i < Minu.size(); ++i) {
        Minu[i] = Minu[i]/arr.size();
    }

    return Minu;
}

/*! \brief Minimum Deletion Cost to Avoid Repeating Letters
 *
 *  Given a string s and an array of integers cost where cost[i] is the cost of deleting the ith character in s.
 *
 * \return the minimum cost of deletions such that there are no two identical letters next to each other.
 */
int Solutions::minDeleteCost( std::string &S, std::vector<int> &C){
    int count = 0;
    int minidex = 0;

    for (int i = 1; i < S.size(); ++i) {
        if (S[minidex] == S[i]) { 
            if (C[minidex] < C[i]) {
                count += C[minidex];
                minidex = i;
            } else {
                count += C[i];
            }

        } else {
            minidex = i;
        }

    }

    return count;
}

int GetFirstK( std::vector<int> &nums, int K , int start, int end)
{
    if (start > end) return -1;

    // Binary search
    int middleIndex =  start + (end - start)/2;
    int middledata = nums[middleIndex];

    if (middledata == K) {
        if ( (middleIndex > 0 && nums[middleIndex - 1] != K) || middleIndex == 0 )
            return middleIndex;
        else 
            end = middleIndex - 1;

    } else if (middleIndex > K) {
        end = middleIndex - 1;
    } else {
        start = middleIndex + 1;
    }

    return GetFirstK(nums, K, start, end);
}

int GetLastK( std::vector<int> &nums, int K, int start, int end)
{
    if(start > end) return -1;

    int middleIndex = start + (end - start)/2;
    int middledata = nums[middleIndex];

    if(middledata == K) {
        if ( (middleIndex < nums.size() - 1 && nums[middleIndex + 1] != K) || middleIndex == nums.size() - 1)
            return middleIndex;
        else
            start = middleIndex + 1;

    } else if (middledata < K) {
        start = middleIndex + 1;
    } else
        end = middleIndex - 1;

    return GetLastK(nums, K, start, end);
}

int Solutions::getNumberofK( std::vector<int>& nums, int K)
{
    int count = 0;

    if ( nums.size() > 0) {
        int first = GetFirstK(nums, K, 0, nums.size() - 1); // O(log(N))
        int last = GetLastK(nums, K, 0, nums.size() - 1); // O(log(N))

        if (first > -1 && last > -1) count = last - first + 1;
    }

    return count;
}

std::vector<int> Solutions::findNumberswithSum(std::vector<int> & nums, int sum)
{
    std::vector<int> sumnums;
    int behind = 0;
    int ahead = nums.size() - 1;

    while ( ahead > behind ) { // O(N)
        int curSum = nums[ahead] + nums[behind];

        if (curSum == sum) {
            sumnums.push_back(nums[behind]);
            sumnums.push_back(nums[ahead]);
            break;
        } else if (curSum > sum) {
            ahead --;
        } else 
            behind ++;

    }

    return sumnums;
}


/*! \brief Middle of three using minimum comparisons
 *
 *  Given three distinct numbers a, b and c find the number with a value in middle.
 *
 * \return middle
 */
int Solutions::getMedian(int x, int y, int z)
{
    /*
    if (x > y && x <= z) return x;
    else if (y > x && y <= z) return y;
    else if (z > x && z <= x) return z;
    else return x;
    */
    
    /*
    if (x > y) {
        if (y > z) return y;
        else {
            if (z > x) return x;
            else return z;
        }
    } else {
        if (y <= z) return y;
        else {
            if (z <= x) return x;
            else return z;
        }
    }
    */

    int a = x - y, b = y - z, c = x - z;

    if ( a*b > 0) return y;
    else if ( a*c > 0 ) return z;
    else return x;

}

/*! \brief Almost Sorted
 *
 *  Given an array of integers, determine whether the array can be sorted in ascending order using only one of the following operations one time.
 *
 *  1. Swap two elements.
 *  2. Reverse one sub-segment.
 *
 *  a. If elements can be swapped,  d[l] and d[r], output swap l r in the second line. l and r are the indices of the elements to be swapped, assuming that the array is indexed from  to .
 *  b. Otherwise, when reversing the segment d[l ... r], output reverse l r in the second line. l and r are the indices of the first and last elements of the subsequence to be reversed, assuming that the array is indexed from  to .
 *
 *  d[l ... r] represents the sub-sequence of the array, beginning at index l and ending at index r, both inclusive.

 *
 *  Determine whether one, both or neither of the operations will complete the task. Output is as follows.
 *
 * \return whether the array is Almost Sorted
 */
bool Solutions::almostSorted( std::vector<int> & nums)
{
    if ( nums.size() > 0 && nums.size() <= 2 ) return true;

    bool issorted = false;
    int maxnum = nums[0];
    for (int i = 2; i < nums.size(); ++i) {
        if ( nums[i - 2] <= nums[i - 1] && nums[i - 1] <= nums[i]) {
            maxnum = nums[i];
            issorted = true;
        } else {
            if (nums[i - 2] > nums[i - 1] && nums[i - 1] < nums[i] && maxnum > nums[i])
                return false;
            else {
//                     maxnum = std::max(maxnum, nums[i - 2]);
                    maxnum = maxnum > nums[i - 2] ? maxnum : nums[i - 2];
                    issorted = true;
            }
        }
    }


    /* recursive check
      bool isSorted( std::vector<int> &nums) {

      }

      std::reverse(nums.begin()+i+1, nums.end());
    */

    return issorted;
}


/*! \brief Robot Return to Origin
 *
 *  There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
 *
 *  You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).
 *
 * Runtime: 10 ms, faster than 79.99% of C++ online submissions for Robot Return to Origin.
 *
 * Memory Usage: 8 MB, less than 76.02% of C++ online submissions for Robot Return to Origin.
 *
 *
 * \return Return parameter description
 */
bool Solutions::judgeCircle( std::string moves)
{
    int x = 0, y = 0;
    for (auto & step : moves) {
        step == 'R' ? x++ : step == 'U' ? y++ : step == 'L' ? x-- : y--;
    }
    return ( x == 0 && y == 0);
}

/*! \brief Critical Connections in Network
 *
 *  There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
 *
 *  A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
 *
 *  Tarjan's Bridge-Finding Algorithm (TBFA) provides a very effective way to find these bridge and articulation points in linear time. It is a bit like a combination of a depth-first search (DFS) approach with recursion and a union-find. In TBFA, doing recursive DFS on graph and for each node to keep track of the earlier node that can circle back around to reach. And then identify whether a given edge is a bridge.
 *
 * Runtime: 833 ms, faster than 62.49% of C++ online submissions for Critical Connections in a Network.
 *
 * Memory Usage: 164.6 MB, less than 89.27% of C++ online submissions for Critical Connections in a Network.
 * 
 * Note that: low link value of a node is defined as the smallest visited time from current node when doing a DFS, including itself.
 *
 *
 * \return all critical connections in the network in any order.
 */
void undirected_dfs(int curr, int parent, int visited, std::vector< std::vector<int> > & undirectedgraph, std::vector<int>& lowlink, std::vector< std::vector<int> > &bridge){

    lowlink[curr] = visited ++;

    // Exploring the neighbor node
    for (auto & nextnode : undirectedgraph[curr]) {

        if ( nextnode == parent)
            continue;

        // unvisited (Depth-first Search)
        if (lowlink[nextnode] == 0) undirected_dfs(nextnode, curr, visited, undirectedgraph, lowlink, bridge);
        // Assign low value to current node (circle back around to reach)
        lowlink[curr] = std::min(lowlink[curr], lowlink[nextnode]);

        // Determine the bridge
        if (lowlink[nextnode] == visited ) bridge.push_back({curr, nextnode});
    }
}

std::vector< std::vector<int> > Solutions::criticalConnections(int n, std::vector< std::vector<int> > & connections)
{
    std::vector< std::vector<int> > undirectedgraph (n);
    std::vector< std::vector<int> > bridge;
    std::vector<int> lowlink(n);

    // constructing undirected graph
    for (auto & elem : connections) {
        undirectedgraph[elem[0]].push_back(elem[1]);
        undirectedgraph[elem[1]].push_back(elem[0]);
    }

    undirected_dfs(0, -1, 1, undirectedgraph, lowlink, bridge);

    // for (int i = 0; i < lowlink.size(); ++i) {
    //     std::cout <<   "node: " << i << "; link: " << lowlink[i] << std::endl;
    // }

    return bridge;
}

/*! \brief Find Peak Element
 *
 *  A peak element is an element that is strictly greater than its neighbor.
 *
 *  Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 *
 *  You may imagine that nums[-1] = nums[n] = -∞.
 *
 *  You must write an algorithm that runs in O(log n) time.
 *
 * Runtime: 7 ms, faster than 41.95% of C++ online submissions for Find Peak Element.
 *
 * Memory Usage: 8.9 MB, less than 5.24% of C++ online submissions for Find Peak Element.
 *
 *
 * \return the index number of peak element
 */
int Solutions::findPeakElement( std::vector<int> & nums)
{
    int start = 0, end = nums.size() - 1;
    if (start > end && end == 0) return -1;

    while (start < end) {
        // Binary search
        int middleIndex = (start + end)/2;

        if (nums[middleIndex] > nums[middleIndex + 1]) {
            end = middleIndex;
        } else {
            start = middleIndex + 1;
        }
    }

    return start;


/*
    int start = 0, end = nums.size() - 1;
    if (start > end && end == 0) return -1;

    // Binary Search
    while (start <= end) {
        int middleIndex = start + (end - start)/2;

        if (nums[middleIndex - 1] < nums[middleIndex] && ( nums[middleIndex] > nums[middleIndex + 1] || middleIndex == nums.size() - 1 ) || middleIndex == 0)
            return middleIndex;
        else if ( middleIndex - 1>= 0 && middleIndex + 1 <= nums.size() - 1 && nums[middleIndex -1] > nums[middleIndex] && nums[middleIndex - 1] > nums[middleIndex + 1]) { 
            end = middleIndex - 1;
        } else start = middleIndex + 1;
    }

    return -1;
*/
}

/*! \brief Add Two Numbers
 *
 *  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 *
 *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Runtime: 33 ms, faster than 81.03% of C++ online submissions for Add Two Numbers.
 *
 * Memory Usage: 71.4 MB, less than 81.12% of C++ online submissions for Add Two Numbers.
 *
 *
 * \return the sum as a linked list.
 */
LinkedListNode* Solutions::addTwoNumbers(LinkedListNode* l1, LinkedListNode* l2)
{
    /*
    int c = 0;
    LinkedListNode* node = nullptr;

    while (c || l1 || l2) {
        c += (l1 ? l1->val : 0) + (l2? l2->val : 0);
        node = insertLinkedlistNode(node, c%10);
        c /= 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return node;
    */

    int c = 0;

    LinkedListNode  node(0);
    LinkedListNode * temp = &node;

    while (c || l1 || l2 ) {
        c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        LinkedListNode * next_node = new LinkedListNode(c%10);
        temp->next = next_node;
        temp = temp->next;
        c /= 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return node.next;
}


/*! \brief Remove Duplicates from Sorted List
 *
 *  Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 *
 * Runtime: 15 ms, faster than 48.52% of C++ online submissions for Remove Duplicates from Sorted List.
 *
 * Memory Usage: 11.6 MB, less than 79.43% of C++ online submissions for Remove Duplicates from Sorted List.
 *
 *
 * \return Return parameter description
 */
LinkedListNode* Solutions::deleteDuplicates(LinkedListNode * head)
{
    if (!head) return head;
    LinkedListNode * tmp = head;

    while (tmp && tmp->next) {
        if (tmp->val == tmp->next->val)
            tmp->next = tmp->next->next;
        else tmp = tmp->next;
    }

    return head;
    /*
	if(!head) return head;
	LinkedListNode* tmp = head;

	while(tmp && tmp -> next)
	{
		if(tmp -> val == tmp -> next -> val)
			tmp -> next = tmp -> next -> next;
		else
			tmp = tmp -> next; 
	}

	return head;
    */
}

int Solutions::balancedSum( std::vector<int> arr)
{
    if (!(arr.size() - 1)) return 0;

    int size = arr.size();
    int target = 0;

    for (int j = size; j > 0; --j) {
        int target =+ arr[j - 1];

        for (size_t i = 0; i < size ; i++)
        {
            if (target == 0) return i;
            target -= arr[i];
        }

    }

    return 0;
}

// isvaildAddexpression
bool Solutions::addExpression( std::string& S)
{
    bool isVaildAdd = false;
    std::vector<int> v (4, 0);

    for (auto & elem : S) {
        v[elem - '('] ++;
    }

    if (v[0] == 1 && v[1] == 1 || v[0]%2 == 0 && v[1]%2 == 0 && v[3] == v[0]/2) isVaildAdd = true;
    
    return isVaildAdd;
}

/*! \brief Array Nesting
 *
 *  You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].
 *  You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:
 *
 *  The first element in s[k] starts with the selection of the element nums[k] of index = k.
 *  The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
 *  We stop adding right before a duplicate element occurs in s[k].
 *
 *
 * Runtime: 146 ms, faster than 83.11% of C++ online submissions for Array Nesting.
 *
 * Memory Usage: 91.7 MB, less than 61.09% of C++ online submissions for Array Nesting.
 *
 *
 * \return the longest length of a set s[k].
 */
int Solutions::arrayNexting( std::vector<int> & nums)
{
    int n = nums.size(), ans = 0;
    std::vector<bool> visited(n, false);

    for (auto & elem : nums) {
        int count = 0;
        while (!visited[elem]) {
            count += 1;
            visited[elem] = true;
            elem = nums[elem];
        }
//         ans = std::max(ans, count);
        ans = ans > count ? ans : count;
    }
    return ans;
}

/*! \brief Expression Add Operators
 *
 *  Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
 *
 * Note: similar as Maximum Length of a Concatenated String with Unique
 *
 * Runtime: 720 ms, faster than 30.65% of C++ online submissions for Expression Add Operators.
 *
 * Memory Usage: 112.4 MB, less than 75.85% of C++ online submissions for Expression Add Operators.
 *
 *
 * \return all possibilities to insert the binary operators 
 */
/*
void checkOperator(std::string num, int target, std::string str, int index, long sum, long prev, std::vector< std::string >& operation)
{

    if (num.size() == index && target == sum) {
        operation.push_back(str);
        return;
    }

    std::string curstr = "";
    long int curnum = 0;
    for (int i = index; i < num.size(); ++i) {
        curnum = curnum*10 + (num[i] - '0');
        curstr.push_back(num[i]);

        if (curstr.size() > 1 && curstr[0] == '0')break;

        if (str[0] == '+') str.erase(0, 1);
        if (str[0] == '*') break;

        if( i == 0) checkOperator(num, target, curstr, i + 1, curnum, curnum, operation);
        else {

            checkOperator(num, target, str + "+" + curstr, i + 1, sum + curnum, +curnum, operation);
            checkOperator(num, target, str + '-' + curstr, i + 1, sum - curnum, -curnum, operation);
            checkOperator(num, target, str + '*' + curstr, i + 1, (sum - prev) + (prev * curnum), prev * curnum, operation);
        }

    }
}
*/

void checkOperator_dfs(std::string num, int target, std::string str, int index, long sum, long prev, 
                        std::vector< std::string> & operation )
{
    if( index == num.size()) {
        if (sum == target) {
            operation.push_back(str);
        }
    }

    for (int i = index + 1 ; i <= num.size() ; ++i) {

        // Extend numbers
        std::string curstr = num.substr(index, i - index);

        if (curstr[0] == '0' && curstr.size() > 1) continue;

        long curnum = atoll(curstr.c_str());


        if (index == 0) {
            str = curstr;
            checkOperator_dfs(num, target, str, i, curnum, curnum, operation);
            str.clear();
        } else {
            str.push_back('+'); // appends a character to the end
            str.append(curstr); // appends characters to the end
            checkOperator_dfs(num, target, str, i, sum + curnum, curnum, operation);

            str[str.length() - curstr.length() - 1] = '-';
            checkOperator_dfs(num, target, str, i, sum - curnum, -curnum, operation);

            str[str.length() - curstr.length() - 1] = '*';
            checkOperator_dfs(num, target, str, i, (sum - prev) + (prev * curnum), prev * curnum, operation);

            str.erase(str.length() - curstr.length() - 1);
        }
    }
}

std::vector< std::string> Solutions::addOperators( std::string num, int target)
{
    std::vector< std::string > operation;

//     checkOperator(num, target, "", 0, 0, 0, operation);

    checkOperator_dfs(num, target, "", 0, 0, 0, operation);

    return operation;
}

/*! \brief Balanced Binary Tree
 *
 *  Given a binary tree, determine if it is height-balanced.
 *
 *  For this problem, a height-balanced binary tree is defined as:
 *
 *      a binary tree in which the left and right substree of every node differ in height by no more than 1.
 *
 * \return determin if it is height-balanced.
 */
int getHeight(TreeNode * root)
{
    if (root == nullptr) return 0;

    int depthleft = getHeight(root->left);
    int depthright = getHeight(root->right);

    if (depthright == -1 || depthright == -1 || std::abs(depthleft - depthright) > 1 ) return -1;


//     return 1 + std::max(depthright, depthleft);
    return 1 + (depthright > depthleft ? depthright : depthleft);
}


/*! \brief Balanced Binary Tree
 *
 *  Given a binary tree, determine if it is height-balanced.
 *
 *  For this problem, a height-balanced binary tree is defined as:
 *
 *  a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 *
 *  Runtime: 19 ms, faster than 49.07% of C++ online submissions for Balanced Binary Tree.
 *
 *  Memory Usage: 20.9 MB, less than 54.37% of C++ online submissions for Balanced Binary Tree.
 *
 * \return whether or not the tree is Balanced Binary Tree
 */
bool Solutions::isBalanced(TreeNode * root)
{
    if (root == nullptr) return true;

    return getHeight(root) != -1;
}

/*! \brief Convert Sorted Array to Binary Search Tree
 *
 *  Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 *
 *  Runtime: 30 ms, faster than 21.49% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
 *
 *  Memory Usage: 21.5 MB, less than 21.73% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
 *
 * \return Return parameter description
 */
TreeNode * helper( std::vector<int> & nums, int low, int high)
{
    if(low <= high) {
        int mid = low + (high - low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, low, mid - 1);
        root->right = helper(nums, mid + 1, high);
        return root;
    }
    return NULL;
}
TreeNode* Solutions::sortedArrayToBST( std::vector<int> & nums)
{
    return helper(nums, 0, nums.size() - 1);
}


/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
/*
void captured_bfs(int row, int column, std::vector< std::vector<char> > &grid, std::vector< std::vector<char> > & output)
{
    std::queue< std::pair<int, int> > to_visit ;
    to_visit.push( {row, column} );
    int step = 0;
    int surrounded = 4;

    while(!to_visit.empty()) {

        int curDepth = to_visit.size();
        for (int i = 0; i < curDepth; ++i) {
            int xx = to_visit.front().first;
            int yy = to_visit.front().second;

            to_visit.pop();

            //// Boundary
            if ( xx == grid.size() || xx < 0 || yy == grid[0].size() || yy < 0) {
                surrounded += 2;
                continue;
            }

            // Check whether 'O' is surrounded by 'X' (bypass  'X' and visted)
            if ( step != 0 && grid[xx][yy] != 'O') {
                if (grid[xx][yy] == 'X') surrounded--;
                grid[xx][yy] = 'D';
                continue;
            }

            if (step != 0) surrounded ++;

            grid[xx][yy] = 'D'; // visited


            to_visit.push( std::pair<int, int>(xx + 1, yy));// RIGHT
            to_visit.push( std::pair<int, int>(xx - 1, yy));// LEFT
            to_visit.push( std::pair<int, int>(xx, yy + 1));// UP
            to_visit.push( std::pair<int, int>(xx, yy - 1));// DOWN
        }
        step ++;
    }

    std::cout  << surrounded  << std::endl;

    if (surrounded > 0) output[row][column] = 'O';
}
*/



/*! \brief  Surrounded Regions
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
 *
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 *
 * Runtime: 14 ms, faster than 71.39% of C++ online submissions for Surrounded Regions.
 *
 * Memory Usage: 10.2 MB, less than 40.17% of C++ online submissions for Surrounded Regions.
 *
 */
std::vector< std::vector<char> > Solutions::surroundedRegions( std::vector< std::vector<char> > & board)
{
    std::vector< std::vector<char> > output;

    std::queue< std::pair<int,int> > to_visit;
    int row = board.size(), column = board[0].size();

    //Getting boundary O's
    for(int i=0; i<row ; i++)
    {
        if(board[i][0]=='O') board[i][0]='U', to_visit.push( {i,0} );
        if(board[i][column-1]=='O') board[i][column-1]='U', to_visit.push( {i,column-1} );
    }

    for(int i=1; i<column-1; i++)
    {
        if(board[0][i]=='O') board[0][i]='U', to_visit.push( {0,i} );
        if(board[row-1][i]=='O') board[row-1][i]='U', to_visit.push( {row-1, i} );
    }


    // 2-D Grid BFS which's parent node starts from boundary unsorrounded node
    while(!to_visit.empty())
    {
        int curDepth = to_visit.size();
        while(curDepth--)
        {
            int xx=to_visit.front().first, yy=to_visit.front().second;
            to_visit.pop();

            if(xx+1 < row) if(board[xx+1][yy] == 'O') board[xx+1][yy] = 'U', to_visit.push( {xx+1, yy} );   // RIGHT
            if(xx-1 >= 0) if(board[xx-1][yy] == 'O') board[xx-1][yy] = 'U', to_visit.push( {xx-1, yy} );    // LEFT
            if(yy+1 < column) if(board[xx][yy+1] == 'O') board[xx][yy+1] = 'U', to_visit.push( {xx, yy+1}); // UP
            if(yy-1 >= 0) if(board[xx][yy-1] == 'O') board[xx][yy-1] = 'U', to_visit.push({xx, yy-1});      // DOWN
        }
    }

    //all the unsorrounded O's are re-entered
    for(int i=0; i < row; i++)
        for(int j=0; j < column; j++)
            board[i][j] = board[i][j] == 'U' ? 'O' : 'X';

    output = board;
    return output;
}


/*! \brief Counting Bits
 *
 *  Given an integer n, return an array ans of length n + 1 such that for each i ( 0 <= i <=n). ans[i] is the number of 1's in the binary representation of i
 *
 * Runtime: 4 ms, faster than 86.13% of C++ online submissions for Counting Bits.
 *
 * Memory Usage: 7.9 MB, less than 74.29% of C++ online submissions for Counting Bits.
 *
 * \return an array ans of length n + 1 such that for each i ( 0 <= i <=n). ans[i] is the number of 1's in the binary representation of i
 */
std::vector<int> Solutions::countBits(int n) {
    std::vector<int> t(n+1);

    t[0] = 0;

    // compute current set bit count using previous count
    for (int i = 1; i <= n; ++i) {
        t[i] = t[i/2] + i%2; // complement + remainder
    }

    return t;
}

/*! \brief Number of Bits
 *
 *  Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
 *
 * Memory Usage: 5.9 MB, less than 48.23% of C++ online submissions for Number of 1 Bits.
 *
 * \return the number of '1' bits it has
 */
int Solutions::hammingWeight(uint32_t n) {
    int cnt=0;  // count of set bit
    while(n>0){  // iterate until all bits are traversed
        ++cnt;
        n=n&(n-1); // change the first set bit from right to 0
    }
    return cnt;
}

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
// undirected DFS ( graph of string )

bool isValidChar(char c)
{
    return ((c - 'a' >= 0 && c - 'z' <= 0) || (c - 'A' >= 0 && c - 'Z' <= 0) || c - '!' == 0);
}


bool isUniqe(std::string s, std::vector< std::string> & palindrome, std::vector< std::string> & arr)
{
    if (std::count(begin(palindrome), end(palindrome), s) > 0) return false;

    if (std::count(begin(arr), end(arr), s) > 0) return false;


    return true;
}

bool isPalindrome(std::string &s)
{
    int start = 0, end = s.length() - 1;

    while (start <= end) {
        if (!isalnum(s[start])) {
            start ++;
        } else if (!isalnum(s[end])) {
            end --;
        } else if (toupper(s[start]) != toupper(s[end])) {
            return false;
        } else {
            start ++; end --;
        }
    }

    return true;
}

void checkUniqueLen( std::vector<std::string> & arr, std::string graphstr, int curindex, int index, int& count, std::vector< std::string>  & palindrome, int size)
{
    if ( graphstr.size() && isPalindrome(graphstr) && isUniqe( graphstr, palindrome, arr)) {

        palindrome.push_back(graphstr);
        if (size == 0) {
            // std::cout << "Palindrome: " << graphstr.c_str() << " " << curindex  - 1 << " " << index - 1 << std::endl;
            int pre_index = curindex - 1;
            int post_index = index - 1;
            count = count + pre_index + post_index;
        } else {
            // std::cout << "Reverse Palindrome: " <<  arr[curindex] << " " << arr[index] << " "  << graphstr.c_str() << " " << size - (curindex  - 1) << " " << size - (index - 1) << std::endl;
            int pre_index = size - (curindex - 1);
            int post_index = size - (index - 1);
            count = count + pre_index + post_index;
        }
    }

    // recursive
    for (int i = index; i < arr.size(); ++i) {
        checkUniqueLen(arr, graphstr+arr[i], i, i+1, count, palindrome, size);
    }

}


/*! \brief Palindrome Pairs (TLE ISSUE)
 *
 *  Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.
 *
 * \return sum of index for the palindrome pairs
 *
 *
 *  Iterate through words, then, each word will possible match another in one of three ways:
 *  - a blank string word will match on either side with any palindrome
 *  - a full word will match on either side with its backwards version
 *  - a partial word will match its backwards version on the opposite side if the leftover portion of the word is a palindrome
 *
 */
int Solutions::palindromePairsSum( std::vector< std::string > & words) {
    /* method 1
    int len = 0, size = input_array.size() - 1;

    if (input_array.size() < 0) return 0;

    if (input_array.size() == 1) return input_array[0].size();

    std::vector< std::string > palindrome;

    checkUniqueLen( input_array, "", 0, 0, len, palindrome, 0);

    std::reverse(input_array.begin(), input_array.end());

    checkUniqueLen( input_array, "", 0, 0, len, palindrome, size);


    */

    // method 2
    std::unordered_map<std::string,int> reverse_mp;
    int sum = 0;

    for(int i = 0; i < words.size(); i++) {
        reverse_mp[std::string( words[i].rbegin(), words[i].rend())] = i;
    }

    // A blank string word will match on either side with any palindrome word.
    if(reverse_mp.count("")) { 
        for(int i = 0; i < words.size(); i++) {
            if(words[i] != "" && isPalindrome(words[i])) sum += i;
        }
    }

    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words[i].size(); j++) {
            std::string l = words[i].substr(0, j), r = words[i].substr(j);

            // A partial word will match its backwards version on the opposite side if the leftover portion of the word is a palindrome
            if(reverse_mp.count(l) && isPalindrome(r) && reverse_mp[l] != i) sum += i + reverse_mp[l];

            // A full word will match on either side with its backwards version.
            if(reverse_mp.count(r) && isPalindrome(l) && reverse_mp[r] != i) sum += reverse_mp[r] + i;
        }
    }

    return sum;
}


/*! \brief Sum Game
 *
 *  Alice and Bob turns playing a game, with Alice starting first
 *
 *  You are given a string num of even length consisting of digits and '?' characters. On each turn, a player will do the following if there is still at least one '?' in num:
 *
 *  1. Choose an index i where num[i] == '?'.
 *  2. Replace num[i] with any digit between '0' and '9'.
 *
 *  The game ends when there are no more '?' characters in num.
 *
 *  For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the digits in the second half. For Alice to win, the sums must not be equal.
 *
 * \return Assuming Alice and Bob play optimally, return true if Alice will win and false if Bob will win.
 *
 *
 *
 *  Strategy
 *  Case 1: only digits
 *  - if (left sum == right sum ) then Bob wins; Otherwise Alice wins
 *  
 *  Case 2: Odd number of '?'
 *  - (before the last turn) Either (left sum == right sum) or (left sum == right sum), Alice replace the last '?' with any digit greater than '0' or with '0' to maintain both sums, respectively. Alice always wins
 *
 *  Case 3: Even number of '?'
 *  - Imagine that each player copies opponent's turn on the opposite side; in this way, we reduce the problem to a string containing '?' marks only on one side, for example "??1 1??" -> "1 1", "?2?? 4?35" -> "?2? 435"
 *  - If Alice replace one '?' to digit x, Bob can always replace one to '9 - x', the n each pair of (Alice, Bob) (x, 9 - x) turns will increase the sum of side by 9. In other words, "??" will increase the sum of side S by 9.
 *  - If the sum od side is equal to the sum of the opposite side, then Bob win. Otherwise, Alice wins.
 *
 *
 * Runtime: 38 ms, faster than 17.01% of C++ online submissions for Sum Game.
 *
 *
 * Memory Usage: 11.2 MB, less than 84.35% of C++ online submissions for Sum Game.
 *
 */
bool Solutions::sumGame( std::string num) {
    const int N = num.length();

    int lDigitSum = 0;
    int lQCount = 0;
    int rDigitSum = 0;
    int rQCount = 0;

    for (int i = 0; i < N; ++i) {
        if (std::isdigit(num[i])) {
            if( i < N / 2) {
                lDigitSum += (num[i] - '0');
            } else {
                rDigitSum += (num[i] - '0');
            }
        } else {
            if (i < N/2) {
                ++ lQCount;
            } else {
                ++ rQCount;
            }
        }
    }


    // Case 0; Only digits (without '?')
    if ( (lQCount + rQCount) == 0 ) {
        return (lDigitSum != rDigitSum);
    }

    // Case 1: Odd number of '?'
    if ( (lQCount + rQCount) % 2 == 1 ) {
        return true;
    }

    // Case 2: Even number of '?'
    int minQCount = std::min(lQCount, rQCount);

    // Each player copies opponent's turn on the opposite side
    lQCount -= minQCount;
    rQCount -= minQCount;
    return (lDigitSum + 9 * lQCount /2 != rDigitSum + 9 * rQCount / 2);
}

/*! \brief Stone Game (dynamic programming)
 *
 *  Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
 *
 *  The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
 *
 *  Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
 *
 * Runtime: 37 ms, faster than 20.57% of C++ online submissions for Stone Game.
 *
 * Memory Usage: 16.5 MB, less than 23.80% of C++ online submissions for Stone Game.
 *
 * \return Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.
 */
int maxStone(int i, int j, std::vector<int>& piles, std::vector< std::vector<int> > & dp) {
    if (dp[i][j] > 0) {
        return dp[i][j];
    } else if ( i + 1 == j ) {
//         return std::max(piles[i], piles[j]);
        return (piles[i] > piles[j] ? piles[i] : piles[j]);
    } else {

        // Alice takes the entire pile of stones from the beginning of the row
        int a = piles[i] + std::min(maxStone(i+2, j, piles, dp), maxStone(i+1, j-1, piles, dp));

        // Alice takes the entire pile of stones from the end of the row
        int b = piles[j] + std::min(maxStone(i+1, j-1, piles, dp), maxStone(i, j-2, piles, dp));

//         dp[i][j] = std::max(a, b);
        dp[i][j] = a > b ? a : b;
        return dp[i][j];
    }
}

bool Solutions::stoneGame( std::vector<int> piles) {
    int sum = 0, first = 0, last = piles.size() - 1;

    for (auto & num : piles) {
        sum += num;
    }

    std::vector< std::vector<int> > dp( piles.size(), std::vector<int>( piles.size(), 0));

    return maxStone( first, last, piles, dp) > sum/2;
}

/*! \brief N-Queens
 *
 *  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 *
 *  Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 *
 * Runtime: 9 ms, faster than 58.05% of C++ online submissions for N-Queens.
 *
 *
 * Memory Usage: 7 MB, less than 95.04% of C++ online submissions for N-Queens.
 *
 * \return Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 */
bool is_safe( std::vector< std::string> & board, int row, int col)
{
    // check column
    for (int i = 0; i < row; ++i) {
        if(board[i][col] == 'Q') return false;
    }

    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if(board[i][j] == 'Q') return false;
    }

    // check right diagonal
    for (int i = row, j = col;  i >= 0 && j < board.size(); --i, ++j) {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void backtracking_dfs( std::vector< std::string> & board, int row, std::vector< std::vector< std::string> > & result)
{
    if ( row == board.size()) {
        result.push_back(board);
        return;
    }

    for (int i = 0; i < board.size(); ++i) {
        if(is_safe(board, row, i)) {
            // make decision
            board[row][i] = 'Q';
            backtracking_dfs(board, row + 1, result);
            // backtrack to move our queen to next col within same row to get other combinations.
            board[row][i] = '.';
        }

    } 
}

std::vector< std::vector< std::string> > Solutions::solveNQueens(int n) {

    if ( n <= 0 ) return {{}};

    std::vector< std::vector< std::string> > result;
    std::vector< std::string> board(n, std::string(n, '.'));

    backtracking_dfs(board, 0, result);

    return result;
}


/*! \brief Verbal Arithmetic Puzzle
 *
 *  Given an equation, represented by words on the left side and the result on the right side.
 *
 *  You need to check if the equation is solvable under the following rules:
 *
 *  - Each character is decoded as one digit (0 - 9).
 *  - Every pair of different characters must map to different digits.
 *  - Each words[i] and result are decoded as one number without leading zeros.
 *
 * \return true if the equation is solvable, otherwise return false.
 */

bool backtracking_verbal( std::vector< std::string> & words, std::string & result, std::vector<int> & chtonum, std::vector<int> & numtoch, std::vector<bool> & nonZeroChars, int wordindex, int pos, int sum)
{
    // reach the end of result
    if (pos == result.size()) return sum == 0;

    // traverse the position and keep adding words
    if (wordindex < words.size()) {
        // there is no applicable positions for words[index], skip and add next word
        if (pos  >= words[wordindex].size())
            return backtracking_verbal(words, result, chtonum, numtoch, nonZeroChars, wordindex + 1, pos, sum);

        char ch = words[wordindex][pos];
        int chindex = ch - 'A';

        // Already selected
        if (chtonum[chindex] != -1) {
            return backtracking_verbal(words, result, chtonum, numtoch, nonZeroChars, wordindex + 1, pos, sum + chtonum[chindex]);
        }

        // Try to decode each character
        for (int i = 0; i < numtoch.size(); ++i) {

            if (numtoch[i] != 0) continue; // number is used
            if (i == 0 && nonZeroChars[chindex]) continue; // can't use position 0 for non zero chars

            numtoch[i] = chindex;
            chtonum[chindex] = i;
            bool found = backtracking_verbal(words, result, chtonum, numtoch, nonZeroChars, wordindex + 1, pos, sum + chtonum[chindex]);
            // backtrack
            numtoch[i] = 0;
            chtonum[chindex] = -1;
            if (found) return found;
        }
        return false;
    } else { // verify whether or not result[pos] and sum % 10 are mapping each other
        int reindex = result[pos] - 'A';


        if (chtonum[reindex] == -1 && numtoch[sum%10] == 0) {
            if (sum % 10 == 0 && nonZeroChars[reindex]) return false;

            chtonum[reindex] = sum % 10;
            numtoch[sum%10] = result[pos];

            bool found = backtracking_verbal(words, result, chtonum, numtoch, nonZeroChars, 0, pos + 1, sum / 10);

            if (found) return found;

            chtonum[reindex] = -1;
            numtoch[sum%10] = 0;

            return false;
        } else if (chtonum[reindex] == sum % 10) {
            return backtracking_verbal(words, result, chtonum, numtoch, nonZeroChars, 0, pos + 1, sum / 10);
        } else {
            return false;
        }
    }
}

bool Solutions::isSolvable( std::vector< std::string> & words, std::string result) {
    std::vector<bool> nonZeroChars(26, false);
    std::vector<int> chtonum(26, -1);
    std::vector<int> numtoch(10);

    for (auto &word : words) {
        if(word.size() > result.size()) return false;
        if(word.size() > 1) nonZeroChars[word[0] - 'A'] = true;
        std::reverse(word.begin(), word.end());
    }

    if (result.size() > 1) nonZeroChars[result[0] - 'A'] = true;

    std::reverse(result.begin(), result.end());
    return backtracking_verbal(words, result, chtonum, numtoch, nonZeroChars, 0, 0, 0);
}

/*! \brief Network Delay Time
 *
 *  You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
 *  
 *  We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal.
 *
 *  Runtime: 174 ms, faster than 47.30% of C++ online submissions for Network Delay Time.
 *
 *
 *  Memory Usage: 39.8 MB, less than 81.48% of C++ online submissions for Network Delay Time.
 *
 * \return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1
 */
int Solutions::networkDelayTime( std::vector< std::vector< int > > & times, int n, int k) {
    // BFS
    /*
    std::vector< std::pair<int, int> > adjacent[n + 1];

    for (int i = 0; i < times.size(); ++i) {
        adjacent[times[i][0]].push_back( {times[i][1], times[i][2]} );
    }

    std::vector<int> distance(n+1, INT_MAX);
    std::queue<int> q;

    // starting node
    q.push(k);
    distance[k] = 0;

    // traverse all the neighbor node
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto &item : adjacent[node]) {
            if (distance[item.first] > distance[node] + item.second) {
                distance[item.first] = distance[node] + item.second;
                q.push(item.first); // next node
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= n; ++i) {
        if (distance[i] == INT_MAX) return -1;
        res = std::max(res, distance[i]);
    }

    return res;
    */


    // Dijkstra
    std::vector< std::pair<int, int> > adjacent[n+1];

    // create weight graph
    for (int i = 0; i < times.size(); ++i) {
        adjacent[times[i][0]].push_back( {times[i][1], times[i][2]} );
    }

    // initially start with infinite distances
    std::vector<int> distance(n+1, INT_MAX);

    // Sorting
    std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;

    // Parent node and set it to zero for our initial node and to infinitely for all other nodes
    pq.push({0, k});
    distance[k] = 0;

    while (!pq.empty()) {
        std::pair<int, int> node = pq.top() ;
        pq.pop();

        for (auto &next_node : adjacent[node.second]) {
            if(distance[next_node.first] > node.first + next_node.second) {
                distance[next_node.first] = node.first + next_node.second;
                pq.push( {distance[next_node.first], next_node.first} );
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if ( distance[i] == INT_MAX ) return -1;
            res = res > distance[i] ? res : distance[i];
    }

    return res;
}

/*! \brief Is Graph Bipartite?
 *
 *  There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
 *
 *  There are no self-edges (graph[u] does not contain u).
 *  There are no parallel edges (graph[u] does not contain duplicate values).
 *  If v is in graph[u], then u is in graph[v] (the graph is undirected).
 *  The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
 *
 *  A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
 *
 * \return Return  true if and only if it is bipartite.
 */

bool colorable_node(int i, std::vector<int> &color, std::vector< std::vector<int> > & graph)
{
    std::queue<int> q;
    q.push(i);
    color[i] = 0; // color the first node

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (auto &node : graph[vertex]) {
            if (color[node] == -1) {
                color[node] = 1 - color[vertex];
                q.push(node);
            } else if (color[node] == color[vertex]) {
                return false;
            }
        }
    }

    return true;

}

bool Solutions::isBipartite( std::vector< std::vector<int> > & graph ) {
    int depth = graph.size();
    std::vector<int> color(depth, -1); // all the node are uncolored

    for (int i = 0; i < depth; ++i) {
        if (color[i] == -1) {
            if (!colorable_node(i, color, graph))
                return false;
        }
    }

    return true;
}

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
bool bitpartiteMatch_dfs(const std::vector< std::vector<int>> & grid, int u, std::vector<bool> visted, std::vector<int> & grils) {
    int n = grid[u].size();

    for (int v = 0; v < n; ++v) {
        if (grid[u][v] && !visted[v]) {
            visted[v] = true;

            if (grils[v] < 0 || bitpartiteMatch_dfs(grid, grils[v], visted, grils)) {
                grils[v] = u; // matching
                return true;
            }
        }
    }
    return false;
}

/*! \brief Maximum Number of Accepted Invitations
 *
 *  There are m boys and n girls in a class attending an upcoming party.
 *  You are given an m x n integer matrix grid, where grid[i][j] equals 0 or 1. If grid[i][j] == 1, then that means the ith boy can invite the jth girl to the party.
 *  A boy can invite at most one girl, and a girl can accept at most one invitation from a boy.
 *
 * \return Return the maximum possible number of acceptable invitation
 */
int Solutions::maximumInvitations( std::vector< std::vector<int> > & grid) {
    int m = grid.size();
    int n = grid[0].size();
    std::vector<int> grils(n, -1); // unmatched (uncolored)
    int matches = 0;

    // matching process
    for (int i = 0; i < m; ++i) {
        std::vector<bool> visted(n, false);
        if( bitpartiteMatch_dfs(grid, i, visted, grils)) {
            matches ++;
        }
    }

    return matches;

}


/*! \brief Pair with given sum in matrix
 *
 *  Given a NxM matrix and a sum S. The task is to check if a pair with given Sum exists in the matrix or not.
 *
 * \return Return whether or not a pair with given Sum exists in the matrix
 */
std::vector< std::vector<int> > Solutions::isPairWithSum(int mat[ROW][COLUMN], int sum) {
    std::set< std::pair<int, int>> pairsum;

    pairsum.clear();
    for (int row = 0; row< ROW; row ++) {
        for (int col = 0; col< COLUMN ; col ++) {
            int diff = sum - mat[row][col];
            // search
            bool ismatch = false;
            for (int i = row + 1 ; i < ROW ; i ++ ) {
                for (int j = 0 ; j < COLUMN ; j ++) {
                    if (!(mat[i][j] - diff)) {
                        ismatch = true;
                        pairsum.insert({mat[row][col], mat[i][j]});
                        break;
                    }
                }
                if (ismatch) break;
            }
        }
    }

    std::vector< std::vector<int> > result;
    for (auto &elem : pairsum) {
        result.push_back({elem.first, elem.second});
    }
    return result;
}

/*! \brief Course Schedule
 *
 *  There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
 *
 *  For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 *
 * \return true if you can finish all courses. Otherwise, return false.
 */
bool Solutions::canFinish(int numCourse, std::vector< std::vector< int> > & prerequisities) {


    std::vector< std::vector<int> > adjacent(numCourse);
    // initial all vertices with indegree 0
    std::vector<int> indegree(numCourse, 0);

    // Creating graph and updates the indegree of the local vertex 
    for (auto &elem : prerequisities) {
        adjacent[elem[0]].push_back(elem[1]);
        indegree[elem[1]]++;
    }


    std::queue<int> q;

    // Parallel topological sorting
    // iterate through all the courses if indegree is zero then add it to queue
    for (int i = 0; i < numCourse; ++i) {
        if(indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto &next_node : adjacent[node]) {
            indegree[next_node] --;
            if(indegree[next_node] == 0) q.push(next_node);
        }
        numCourse --; // finish the course
    }

    return numCourse == 0;
}


/*! \brief Parallel Courses
 *
 * There are N courses, labelled from 1 to N.
 *
 *  We are given relations[i] = [X, Y], representing a prerequisite relationship between course X and course Y: course X has to be studied before course Y.
 *
 *  In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.
 *
 *
 *
 *  The Essence: The dependency relations of the courses can be thought of as a directed graph. First layer of courses to be taken are those without any dependencies. When there is a cycle in the graph, no courses can be taken.
 *
 * \return Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return -1.
 */


int Solutions::minimumSemesters(int numCourse, std::vector< std::vector<int> > & relations) {

    std::vector< std::vector<int> > adjacent(numCourse);
    // initial all vertices with indegree 0
    std::vector<int> indegree(numCourse, 0);

    // Creating graph and updates the indegree of the local vertex 
    for (auto &course : relations) {
        adjacent[course[0] - 1].push_back(course[1] - 1);
        indegree[course[1] - 1]++; // study firstly
    }

    std::queue<int> q;
    int semester = 0, count = 0;

    // Parallel topological sorting
    // iterate through all the courses if indegree is zero then add it to queue
    for (int i = 0; i < numCourse; ++i) {
        if(indegree[i] == 0) q.push(i);
    }

    // BFS
    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; ++i) {
            int node = q.front();
            q.pop();
            count ++;

            for (auto &next_node : adjacent[node]) {
                indegree[next_node] --;
                if(indegree[next_node] == 0) q.push(next_node);
            }
        }
        semester ++;
    }

    return count == numCourse ? semester : -1;
}

/*! \brief Parallel Courses II
 *
 *  You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.
 *
 *  In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semester for the courses you are taking.
 *
 *
 *  Since we cannot decide which courses to schedule based solely on course property we need to try all combinations. It suggests the use of backtracking. We are going to try all of k-length combinations of the available courses.
 * We can also apply an optimization to avoid unnesessary backtracking cycles in some cases. Consider the first semester of the following example (k=2):
 * backtracking tree.
 *
 * \return Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.
 */

/*
void numSemester_bfs( std::vector< std::vector<int> > adjacent, std::vector<int> indegree, int n, int k, int & semester) {
    std::queue<int> q;
    int course = 0;
    // parent node initial pool
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }
    // BFD
    while (!q.empty()) {
        std::unordered_set<int> nextcourse;
        // only take at most k courses (not parallel)
        while (course < k && !q.empty()) {
            int node = q.front();
            q.pop();
            int mindegree = INT_MAX;
            int minnode = 0;
            for (int i = 0; i < adjacent[node].size(); ++ i) {
                int next_node = adjacent[node][i];
                indegree[next_node] --;
                if (indegree[next_node] == 0) nextcourse.insert(next_node);
            }
            course ++;
        }
        course = 0;
        semester ++;
        for (auto &elem : nextcourse) {
            q.push(elem);
        }
    }
}
*/

int find_min_semester( std::vector< std::vector<int> > relations, std::vector<int> & bitmask, int mask, int k, int n) {

    // finish when all courses are taken
    if (mask == ((1 << n) - 1)) return 0;

    // Memorization of taken courses
    if (bitmask[mask] != -1) return  bitmask[mask];

    // Initialize all vertices with indegree 0
    std::vector<int> indegree(n, 0);

    // Update the indegree
    for (int i = 0; i < n; ++i) {
        // skip the courses have been taken
        if (mask & (1 << i)) continue;
        for (auto &elem : relations[i]) {
            indegree[elem] ++;
        }
    }

    // For a mask of all courses with 0-indegree
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        // iterate through all the courses with zero indegree and have't been taken
        if (indegree[i] == 0 && !(mask & (1<<i))) temp = temp | (1<<i);
    }

    int courses = temp;
    // count of courses with 0-indegree
//     std::cout << mask << " " << courses << std::endl;
    int count = __builtin_popcount(courses);
    int semester = INT_MAX;

    if (count > k) {
        // (Overlapping sub-problem) iterate through all submasks (sub-problem) of temp
        while (courses) {
            courses = (courses - 1) & temp;
            count = __builtin_popcount(courses);

            if (count != k) continue;

            semester = std::min(semester, 1 + find_min_semester(relations, bitmask, mask|courses, k, n));
        }
    } else {
        semester = std::min(semester, 1 + find_min_semester(relations, bitmask, mask|courses, k, n));
    }

    return bitmask[mask] = semester;
}

int Solutions::minNumberOfSemesters(int n, std::vector< std::vector<int> > & relations, int k) {
    // No dependencies
    if (relations.size() == 0) return n % k == 0 ? n / k: n/ k + 1;

    std::vector< std::vector<int> > adjacent(n);
    std::vector<int> bitmask;

    // initial bitmask that all of courses haven't been taken
    bitmask.assign(1<<n, -1);

    // Creating graph and updates the indegree of the local vertex 
    for (auto &course : relations) {
        adjacent[course[0] - 1].push_back(course[1] - 1); // graph
    }

    return find_min_semester(adjacent, bitmask, 0, k, n);
}


/*! \brief Number of Provinces
 *
 *  There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
 *
 *  A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 *
 *  You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
 *
 * \return the total number of provinces
 */
void lineartime_dfs(std::vector< std::vector<int> > & isConnected, int index, std::vector<bool> & visted) {

    visted[index] = true;

    // traverse neighbor city
    for (int vertex = 0; vertex < isConnected[index].size(); ++vertex) {
        if (!visted[vertex] && isConnected[index][vertex] == 1) {
            lineartime_dfs(isConnected, vertex, visted);
        }
    }
}

int Solutions::findCircleNum(std::vector< std::vector<int> > & isConnected ){
    int citys = isConnected.size();
    std::vector<bool> visted(citys, false);
    int count = 0;

    for (int i = 0; i < citys; ++i) {
        if (visted[i] == false) {
            count += 1;
            lineartime_dfs(isConnected, i, visted);
        }
    }

    return count;
}

/*! \brief Minimum Number of Days to Disconnect Island
 *
 *  You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
 *
 *  The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
 * In one day, we are allowed to change any single land cell (1) into a water cell (0).
 *
 * \return  the minimum number of days to disconnect the grid.
 */
// 2-D BFS traversal
void connected_bfs(std::vector< std::vector<int> > & grid, std::vector< std::vector<int> > & visited, int i, int j) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    std::queue< std::pair<int, int> > q;
    q.push({i, j});

    visited[i][j] = 1;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];

            // only go through land cell (1)
            if ( xx >=0 && xx < grid.size() && yy >= 0 && yy < grid[0].size() && !visited[xx][yy] && grid[xx][yy] == 1) {
                visited[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }
    return;
}

int connectedComponents_helper( std::vector< std::vector<int> > & grid) {
    int count = 0;
    int row = grid.size(), col = grid[0].size();

    std::vector< std::vector<int> > visited(row, std::vector<int> (col, 0));

    if (row == 0) return 0;

    // count connected land
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                count ++;
                connected_bfs(grid, visited, i, j);
            }
        }
    }

    return count;
}

int Solutions::minDays( std::vector< std::vector<int> > & grid) {

    int connectLand = connectedComponents_helper(grid);

    if (connectLand != 1) return 0;

    int row = grid.size();
    int col = grid[0].size();

    // number of days to disconnect the grid
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            if (grid[x][y] == 1) {
                grid[x][y] = 0;
                connectLand = connectedComponents_helper(grid);
                if (connectLand != 1) return 1;
                grid[x][y] = 1; // backtracking
            }
        }
    }

    return 2; // An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
}


/*! \brief Best Time to Buy and Sell Stock II
 *
 *  You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
 *
 *  On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
 *
 * \return the maximum profit you can achieve.
 */
int Solutions::maxProfit( std::vector<int> & prices) {
    int curHold = INT_MIN, curProfit = 0;

    for (const int stockprice: prices) {
        int prevHold = curHold, preProfit = curProfit;

//         std::cout <<  " stock price "  << stockprice;

        // either keep holding stock in hand, or buy in new stock today at stock price
        curHold = std::max(prevHold, preProfit - stockprice);

//         curHold == prevHold ? std::cout << " Keep hold stock /" : std::cout << " Buy in new stock / ";

        // either keep having no stock in hand, or sell out the stock today at stock price
        curProfit = std::max(preProfit, prevHold + stockprice);

//         curProfit == preProfit ? std::cout << " Keep no stock" << std::endl : std::cout << " Sell out " << std::endl;

    }

    // Max profit must come from notHold
    return curProfit;
}

/*! \brief Min Cost Climbing Stairs
 *
 *  You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
 *
 *  You can either start from the step with index 0, or the step with index 1.
 *
 * \return the minimum cost to reach the top of the floor.
 */
int Solutions::minCostClimbingStairs( std::vector<int> & cost) {
    int n = cost.size();
    std::vector<int> dp = cost;
    for (int i = 2; i < n; i++) {
        dp[i] += std::min(dp[i-2], dp[i-1]);
    }

    return std::min(dp[n-2], dp[n-1]);
}

/*! \brief Longest Substring Without Repeating Character
 *
 *  Given a string s, find the length of the longest substring without repeating characters.
 *
 * \param  std::vector<int> v; string
 * \return Return parameter description
 */
int Solutions::lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> substring;
    int len = 0, start = 0;

    for (int i = 0; i < s.size(); ++i) {
        while (!substring.insert(s[i]).second) {
            substring.erase(s[start]);
            start ++;
        }
        len = len > substring.size() ? len : substring.size();
    }
    return len;
}

/*! \brief Excel Sheet Column Title
 *
 *  Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
 *
 * \return its corresponding column
 */
std::string Solutions::converToTitle(int columnNumber) {
    std::string ans = "";

    while (columnNumber) {
        columnNumber --;
        int k = columnNumber%26;
        ans += 'A' + k;
        columnNumber /= 26;
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}


/*! \brief Regular Expression Matching
 *
 *  Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where,
 *
 *  - '.' Matches any single character.
 *  - '*' Matches zero or more of the preceding element.
 *
 *  The matching should cover the entire input string (not partial)
 *
 * \return Whether or not the matching should cover the entire input string (not partial)
 */
bool Solutions::isMatch( std::string s, std::string p) {

    /*
    return regex_match(s, regex(p));
    */

    int m = s.length();
    int n = p.length();

    std::vector< std::vector<bool> > dp (m + 1, std::vector<bool>(n + 1, false));

    dp[0][0] = true;

    for(int i = 0; i <= m; ++i) { // S
        for(int j = 1 ;j <= n; ++j) { // p
            if(p[j-1] == '*') {
                dp[i][j] = ( dp[i][j-2] )||
                        ( i-1 >= 0 && dp[i-1][j] && ( s[i-1] == p[j-2] || p[j-2] == '.' ) ); 
            } else {
                dp[i][j] = i-1 >= 0 && dp[i-1][j-1] && ( s[i-1] == p[j-1] || p[j-1] == '.' );
            }
        }
    }

    return dp[m][n];
}



} /* namespace leetcode */
