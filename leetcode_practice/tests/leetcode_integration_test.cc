#include <gtest/gtest.h>
#include "solutions.h"
#include "config.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <cstdlib>
#include <cmath>

namespace googletest {

class SolutionsTest : public testing::Test {};

TEST_F(SolutionsTest, minDeletionsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string input = "aaabbccdddtt";
    int expected_value = 6;
    EXPECT_EQ(expected_value, solutions.minDeletions(input));

    input = "ceabaacb";
    expected_value = 2;

    EXPECT_EQ(expected_value, solutions.minDeletions(input));

    input = "aaabbbcc";
    expected_value = 2;

    EXPECT_EQ(expected_value, solutions.minDeletions(input));
}

TEST_F(SolutionsTest, topKFrequentTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    std::vector<int> expected_value = {2,1};
    EXPECT_EQ(expected_value, solutions.topKFrequent(nums, k));

    nums = {1}, k = 1;
    expected_value = {1};
    EXPECT_EQ(expected_value, solutions.topKFrequent(nums, k));

    nums = {1,1,1,2,2,3,4,4,4,4}, k = 3;
    expected_value = {2,1,4};
    EXPECT_EQ(expected_value, solutions.topKFrequent(nums, k));
}

TEST_F(SolutionsTest, closestNumbersTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> input = {4,2,1,3};
    std::vector< std::vector<int> > expected_value = {{1,2},{2,3},{3,4}};
    // EXPECT_EQ(expected_value, solutions.closestNumbers(input));

    input = {1,3,6,10,15};
    expected_value = {{1,3}};
    // EXPECT_EQ(expected_value, solutions.closestNumbers(input));    
}

TEST_F(SolutionsTest, MinSwapTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string input = "mamad";

    EXPECT_EQ(3, solutions.minSwaps(input));
}

TEST_F(SolutionsTest, TwoSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> output = {0, 1};

    for (int i = 0; i < solutions.twoSum(nums, target).capacity(); ++i) {
        EXPECT_EQ(output[i], solutions.twoSum(nums, target)[i]);
    }
}

TEST_F(SolutionsTest, ShortestDistanceTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> > grid = {{1, 0, 2, 0 ,1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};


    EXPECT_EQ( 7, solutions.shortestDistance(grid));
}

TEST_F(SolutionsTest, minStpesTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> piles = {1, 2, 2, 3, 3, 4};
    int minsteps = 9;

    EXPECT_EQ(minsteps, solutions.minSteps(piles));

    piles = {5, 2, 1};
    minsteps = 3;
    EXPECT_EQ(minsteps, solutions.minSteps(piles));   
}

TEST_F(SolutionsTest, maxLengthTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::string> arr {"un", "iq", "ue"};
    int expected_value = 4;
    EXPECT_EQ(expected_value, solutions.maxLength(arr));


    arr = {"abc", "yyy", "def", "csv"};
    expected_value = 6;
    EXPECT_EQ(expected_value,solutions.maxLength(arr));

    arr = {"eva", "jqw", "tyn", "jan"};
    expected_value = 9;
    EXPECT_EQ(expected_value,solutions.maxLength(arr));

    arr = {"photato", "kayak", "banana", "racecar"};
    expected_value = 0;
    EXPECT_EQ(expected_value,solutions.maxLength(arr));

    arr = {"uu"};
    expected_value = 0;
    EXPECT_EQ(expected_value,solutions.maxLength(arr));
}


TEST_F(SolutionsTest, sumZero) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> expected_value = {1,-1,2,-2,0};

    EXPECT_EQ(expected_value, solutions.sumZero(5));
}

TEST_F(SolutionsTest, nextPermutationTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    
    std::vector<int> v = {1, 3, 5, 4, 2};
    std::vector<int> expected_value = {1, 3, 5, 4, 2};

    solutions.nextPermutation(v);
    std::next_permutation(expected_value.begin(), expected_value.end());

    EXPECT_EQ(expected_value, v); 



}

TEST_F(SolutionsTest, arraySignTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {-1,-2,-3,-4,3,2,1};
    int expected_value = 1;

    EXPECT_EQ(expected_value, solutions.arraySign(nums));
}

TEST_F(SolutionsTest, goodNodesTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> v = {3,3,-1,4,2};
    std::unique_ptr<leetcode::TreeNode> root = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(std::move(root), v[i], i);
    }
    int expected_value = 3;
    EXPECT_EQ(expected_value, solutions.goodNodes(std::move(root)));


    v = {-1,5,-2,4,4,2,-2,-1,-1,-4,-1,-2,3,-1,-2,0,-1,-1,-1,-3,-1,-4,-3,3,-1,-1,-1,-1,-1,-1,-1,3,-3};

    root = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(std::move(root), v[i], i);
    }
    expected_value = 5;

//     EXPECT_EQ(expected_value, solutions.goodNodes(root));
}

TEST_F(SolutionsTest, filterStringTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string input = "uuuuxaaaaxum";
    std::string expected_value = "uuxaaxum";

    EXPECT_EQ(expected_value,solutions.filterString(input));
}

TEST_F(SolutionsTest, maxPossibleTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    int input = 7643;
    int expected_value = 76543;

    EXPECT_EQ(expected_value,solutions.maxPossible(input, 5));


    /* Declare the Unit Test object */
    input = -661;
    expected_value =  -5661;

    EXPECT_EQ(expected_value,solutions.maxPossible(input, 5));
}


TEST_F(SolutionsTest, deleteNodeTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> v = {5,3,6,2,4,-1,7};
    int key = 3;
    std::unique_ptr<leetcode::TreeNode> root = nullptr;

    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(std::move(root), v[i], i);
    }

//     std::unique_ptr<leetcode::TreeNode> new_node = solutions.deleteNode(root, key);

//     std::vector<int> actual_value = solutions.PrintBFS(new_node);

//     std::vector<int> expected_value = {5,2,6,4,7}; // {5,2,6,null,4,null,7}

//     EXPECT_EQ(expected_value, actual_value);

}

TEST_F(SolutionsTest, sumFractionTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;;
    std::vector< std::vector<int> > fractions = {{1,4}, {2,5}, {3,4}, {3,5}, {5, 10}, {1,2}, {1,2}};

    int result_value = solutions.sumFraction(fractions);

    int expected_value = 5;

    EXPECT_EQ(expected_value,result_value);
}

TEST_F(SolutionsTest, minCostTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> neededTime = {3,5,10,7,5,3,5,5,4,8,1};
    std::string colors = "aaabbbabbbb";
    int expected_value = 26;

    EXPECT_EQ(expected_value, solutions.minCost(colors, neededTime));
}

TEST_F(SolutionsTest, longestPrefixTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::string> prefix = {"dog","racecar","car"};
    std::string expected_value = "";

    EXPECT_EQ(expected_value, solutions.longestPrefix(prefix));
}

TEST_F(SolutionsTest, getLargestLTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> input {3,2,-2,5,-3};
    int expected_value = 3;

    EXPECT_EQ(expected_value, solutions.getLargestK(input));
}

std::vector<int> parseInts(const std::string & str)
{
    std::vector<int> v;

    std::stringstream ss(str);

    std::string temp;

    while (ss >> temp) {
        std::stringstream st(temp);
        while (st) {
            int i;

            if (st >> i) {
                v.push_back(i);
            } else {
                st.clear();
                st.get();
            }
        }
    }
    return  v;
}

bool is_integer(const std::string & s){
    return std::regex_match(s, std::regex(" *[(-|+)][0-9]+"));
}

void parseDouble(const std::string & str, std::vector<double> & v)
{
    std::stringstream ss(str);
    std::string temp;

    if (!is_integer(ss.str()))
        return;

    while (ss >> temp) {
        std::stringstream st(temp);
        while (st) {
            double i;
            if (st >> i) {
                if(ceil(i) != floor(i) or i > 1000000000)
                    break;
                v.push_back(i);
            } else {
                st.clear();
                st.get();
            }
            }
    }
}

TEST_F(SolutionsTest, balancedStoneTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::ifstream ifs;

    char buffer[256] = {0};

    std::string file = INPUT_FILES_DIR;
    file.append("/balancedstone.txt");
    ifs.open(file);

    std::vector<int> expected_value = {7, 1, 1, 3};
    int index = 0;

    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::vector<int> v = parseInts(line);
    }
}

TEST_F(SolutionsTest, smallestIntTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> input = {1, 3, 6, 4, 1, 2};
    int expected_value = 5;
    EXPECT_EQ(expected_value, solutions.smallestInt(input));


    input = {1, 2, 3};
    expected_value = 4;
    EXPECT_EQ(expected_value, solutions.smallestInt(input));

    input = {-1, -1, -2};
    expected_value = 1;
    EXPECT_EQ(expected_value, solutions.smallestInt(input));
}


TEST_F(SolutionsTest, lengthBinTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int input = 9;
    int expected_value = 2;

    EXPECT_EQ(expected_value, solutions.lengthBin(input));

    input = 15;
    expected_value = 0;
    EXPECT_EQ(expected_value, solutions.lengthBin(input));

    input = 1041;
    expected_value = 5;
    EXPECT_EQ(expected_value, solutions.lengthBin(input));

}

TEST_F(SolutionsTest, montyHallTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
}

TEST_F(SolutionsTest, lowercaseLettersTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int expected_value = 1;

    std::string input = "abccac";

    EXPECT_EQ(expected_value,solutions.lowercaseLetters(input));


    expected_value = 2;

    input = "abcdabcdabcd";

    EXPECT_EQ(expected_value,solutions.lowercaseLetters(input));


    expected_value = 0;
    input = "axaabyab";

    EXPECT_EQ(expected_value,solutions.lowercaseLetters(input));


}



TEST_F(SolutionsTest, scheduleCourseTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> > courses =  {{100,200},{200,1300},{1000,1250},{2000,3200}};
    \

    int expected_value = 3;
    EXPECT_EQ(expected_value, solutions.scheduleCourse(courses));

    courses = {{3,2}, {4,3}};

    expected_value = 0;
}


TEST_F(SolutionsTest, uniqueStringTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string input = "abbbcccd";
    int expected_value = 2;

    EXPECT_EQ(expected_value, solutions.uniqueString( input));
}

TEST_F(SolutionsTest, storeMeetingroomsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector< int> > room = { {0, 30}, {5, 10}, {15, 20} };
    int expected_value = 2;

    EXPECT_EQ(expected_value,solutions.storeMeetingrooms(room));

    room = {{1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13}};
    expected_value = 4;
    EXPECT_EQ(expected_value,solutions.storeMeetingrooms(room));
}

TEST_F(SolutionsTest, findMinArrowShotsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> >  points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int expected_value = 2;

    EXPECT_EQ(expected_value, solutions.findMinArrowShots(points));

    points = {{1,2}, {2,3}, {3,4}, {4,5}};
    expected_value = 2;
    EXPECT_EQ(expected_value, solutions.findMinArrowShots(points));
}

TEST_F(SolutionsTest, maxFullRoundTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string A = "12:01";
    std::string B = "12:44";

    int expected_value = 1;
    EXPECT_EQ(expected_value, solutions.maxFullRound(A, B));


    A = "20:00";
    B = "06:00";
    expected_value = 40;
    EXPECT_EQ(expected_value, solutions.maxFullRound(A, B));

    A = "00:00";
    B = "23:59";
    expected_value = 95;
    EXPECT_EQ(expected_value, solutions.maxFullRound(A, B));


    A = "12:03";
    B = "12:03";
    expected_value = 0;
    EXPECT_EQ(expected_value, solutions.maxFullRound(A, B));

}

TEST_F(SolutionsTest, solutions2Test) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    int expected_value = 1;

    std::vector<int> input = {10, -10, -1, -1, 10} ;

    EXPECT_EQ(expected_value, solutions.solutions2(input));

    input = {-1, -1 , -1, 1, 1, 1, 1};

    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.solutions2(input));
}


TEST_F(SolutionsTest, maximumSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int N = 5;
    std::vector<int> A = {2, 2, 1, 2};
    std::vector<int> B = {1, 3, 4, 4};

    int expected_value = 31;
    EXPECT_EQ(expected_value, solutions.maximumSum(N, A, B));

    A = {1};
    B = {3};
    N = 3;
    expected_value = 5;
    EXPECT_EQ(expected_value, solutions.maximumSum(N, A, B));

    A = {1, 3};
    B = {2, 4};
    N = 4;
    expected_value = 10;
    EXPECT_EQ(expected_value, solutions.maximumSum(N, A, B));
}


TEST_F(SolutionsTest, containDupTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {1, 2, 3, 1};
    bool expected_value = true;

    EXPECT_EQ(expected_value, solutions.containDup(nums));


    nums = {1, 2, 3, 4};
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.containDup(nums));

    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.containDup(nums));
}


TEST_F(SolutionsTest, singleNumberTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {2, 2, 1};
    int expected_value = 1;
    EXPECT_EQ(expected_value, solutions.singleNumber(nums));


    nums = {4, 1, 2, 1, 2};
    expected_value = 4;
    EXPECT_EQ(expected_value, solutions.singleNumber(nums));
}


TEST_F(SolutionsTest, intersectionTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums1 = {4, 9, 5};
    std::vector<int> nums2 = {9, 4, 9, 8, 4};
    std::vector<int> expected_value = {4, 9};

    EXPECT_EQ(expected_value,solutions.intersection(nums1, nums2));

    nums1 = {1, 2, 2, 1};
    nums2 = {2, 2};
    expected_value = {2};
    EXPECT_EQ(expected_value,solutions.intersection(nums1, nums2));
}


TEST_F(SolutionsTest, isHappyTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int n = 2;
    bool expected_value = false;

    EXPECT_EQ(expected_value, solutions.isHappy(n));

    n = 19;
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isHappy(n));

    n = 7;
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isHappy(n));}



TEST_F(SolutionsTest, fourSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    std::vector< std::vector<int> > expected_value = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    // EXPECT_EQ(expected_value, solutions.fourSum(nums, target));

    nums = {2, 2, 2, 2, 2};
    target = 8;
    expected_value ={{2, 2, 2, 2}};
    // EXPECT_EQ(expected_value, solutions.fourSum(nums, target));
}

TEST_F(SolutionsTest, isSameTreeTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> v = {1, 2, 3};
    std::unique_ptr<leetcode::TreeNode> p = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        p = solutions.insertBTNode(std::move(p), v[i], i);
    }

    std::vector<int> y = {1, 2, 3};
    std::unique_ptr<leetcode::TreeNode> q = nullptr;
    for (int i = 0; i < y.size(); ++i) {
        q = solutions.insertBTNode(std::move(q), y[i], i);
    }

    bool expected_value = true;

    EXPECT_EQ(expected_value, solutions.isSameTree(std::move(p), std::move(q)));

    v = {1, 2};
    p = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        p = solutions.insertBTNode(std::move(p), v[i], i);
    }

    y = {1, 0, 2};
    q = nullptr;
    for (int i = 0; i < y.size(); ++i) {
        q = solutions.insertBTNode(std::move(q), y[i], i);
    }
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.isSameTree(std::move(p), std::move(q)));

}


TEST_F(SolutionsTest, replaceWordsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::string > dictionary = {"cat", "bat", "rat"};

    std::string sentence = "the cattle was rattled by the battery";
    std::string expected_value = "the cat was rat by the bat";
    EXPECT_EQ(expected_value, solutions.replaceWords(dictionary, sentence));

    dictionary = {"a", "b", "c"};
    sentence = "aadsfasf absbs bbsb cadsfafs";
    expected_value = "a a b c";
    EXPECT_EQ(expected_value, solutions.replaceWords(dictionary, sentence));

    dictionary = {"e","k","c","harqp","h","gsafc","vn","lqp","soy","mr","x","iitgm","sb","oo","spj","gwmly","iu","z","f","ha","vds","v","vpx","fir","t","xo","apifm","tlznm","kkv","nxyud","j","qp","omn","zoxp","mutu","i","nxth","dwuer","sadl","pv","w","mding","mubem","xsmwc","vl","farov","twfmq","ljhmr","q","bbzs","kd","kwc","a","buq","sm","yi","nypa","xwz","si","amqx","iy","eb","qvgt","twy","rf","dc","utt","mxjfu","hm","trz","lzh","lref","qbx","fmemr","gil","go","qggh","uud","trnhf","gels","dfdq","qzkx","qxw"};

    sentence = "ikkbp miszkays wqjferqoxjwvbieyk gvcfldkiavww vhokchxz dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dco kddxmckhvqifbuzkhstp wc ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy ifvifheoxqlbosfww mengfdydekwttkhbzenk wjhmmyltmeufqvcpcxg hthcuovils ldipovluo aiprogn nusquzpmnogtjkklfhta klxvvlvyh nxzgnrveghc mpppfhzjkbucv cqcft uwmahhqradjtf iaaasabqqzmbcig zcpvpyypsmodtoiif qjuiqtfhzcpnmtk yzfragcextvx ivnvgkaqs iplazv jurtsyh gzixfeugj rnukjgtjpim hscyhgoru aledyrmzwhsz xbahcwfwm hzd ygelddphxnbh rvjxtlqfnlmwdoezh zawfkko iwhkcddxgpqtdrjrcv bbfj mhs nenrqfkbf spfpazr wrkjiwyf cw dtd cqibzmuuhukwylrnld dtaxhddidfwqs bgnnoxgyynol hg dijhrrpnwjlju muzzrrsypzgwvblf zbugltrnyzbg hktdviastoireyiqf qvufxgcixvhrjqtna ipfzhuvgo daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh qzsaobsghgm ichlpsjlsrwzhbyfhm ksenb bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala qmxixtooxtbrzyorn gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn frotscysdyclrc ckcttaceuuxzcghw pxbd oklwhcppuziixpvihihp";

    expected_value = "i miszkays w gvcfldkiavww v dvypwyb bxahfzcfanteibiltins ueebf lqhflvwxksi dc k w ytzzlm gximjuhzfdjuamhsu gdkbmhpnvy i mengfdydekwttkhbzenk w h ldipovluo a nusquzpmnogtjkklfhta k nxzgnrveghc mpppfhzjkbucv c uwmahhqradjtf i z q yzfragcextvx i i j gzixfeugj rnukjgtjpim h a x h ygelddphxnbh rvjxtlqfnlmwdoezh z i bbfj mhs nenrqfkbf spfpazr w c dtd c dtaxhddidfwqs bgnnoxgyynol h dijhrrpnwjlju muzzrrsypzgwvblf z h q i daee r nlipyfszvxlwqw yoq dewpgtcrzausqwhh q i k bqprarpgnyemzwifqzz oai pnqottd nygesjtlpala q gyvukjpc s mxhlkdaycskj uvwmerplaibeknltuvd ocnn f c pxbd oklwhcppuziixpvihihp";
    EXPECT_EQ(expected_value, solutions.replaceWords(dictionary, sentence));
}



TEST_F(SolutionsTest, uncovered_interval) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::pair<int, int> > unservice = {{1, 3}, {5, 6}, {8, 10}, {16, 22}};
    int thirdservice = 5;
    int expected_value = 10;
    EXPECT_EQ(expected_value, solutions.uncovered_interval(unservice, thirdservice));

    unservice = {{1, 2}, {5, 6}, {8, 10}, {16, 22}};
    thirdservice = 5;
    expected_value = 9;
    EXPECT_EQ(expected_value, solutions.uncovered_interval(unservice, thirdservice));

}

TEST_F(SolutionsTest, minSwapsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 1, 0};

    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.minSwapsnums(nums));


    nums = {1, 1, 0, 0, 1};
    expected_value = 0;
    EXPECT_EQ(expected_value, solutions.minSwapsnums(nums));

}


TEST_F(SolutionsTest, minDistanceTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> > edges = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

    int x = 2;
    int n = 4;
    int expected_value = 1;
    EXPECT_EQ(expected_value, solutions.minDistance(edges, n, x));

    edges = {{2, 3, 1}, {2, 1, 3}, {3, 4, 1}};
    expected_value = 2;
    EXPECT_EQ(expected_value, solutions.minDistance(edges, n, x));


    edges = {{2, 3, 1}, {2, 1, 3}, {3, 4, 1}};

    expected_value = 2;
    EXPECT_EQ(expected_value, solutions.minDistance(edges, n, x));

}


TEST_F(SolutionsTest, commonSubstringTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::string > a = {"hello", "hi"};
    std::vector< std::string > b = {"world", "bye"};
    std::vector< std::string > expected_value = {"YES", "NO"};

    EXPECT_EQ(expected_value,solutions.commonSubstring(a, b));
}

TEST_F(SolutionsTest, countDuplicatesTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> input = {6, 1, 1, 2, 2, 2, 3};
    int expected_value = 2;

    EXPECT_EQ(expected_value,solutions.countDuplicates(input));

    input = {6, 1 , 2, 3, 1, 1, 1};
    expected_value = 1;
    //EXPECT_EQ(expected_value,solutions.countDuplicates(input));
}

TEST_F(SolutionsTest, plusMinusTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> arr = {1, 1, 0, -1, -1};

    std::vector<float> expected_value = {0.4, 0.4, 0.2};

    EXPECT_EQ(expected_value, solutions.plusMinus(arr));
}

TEST_F(SolutionsTest, minChangeTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string S = "MLMMLLM";
    int K = 3;
    int expected_value = 1;

    // EXPECT_EQ(expected_value, solutions.minChange(S, K));

    S = "MLMMMLMMMM";
    K = 2;
    expected_value = 2;
    // EXPECT_EQ(expected_value, solutions.minChange(S, K));
}

TEST_F(SolutionsTest, minDeleteCostTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string  S = "abccbd";
    std::vector<int> C = {0, 1, 2, 3, 4, 5};
    int expected_value = 2;

    EXPECT_EQ(expected_value,solutions.minDeleteCost(S, C));


    S = "aaaa";
    C = {3, 4, 5, 6};
    expected_value = 12;
    EXPECT_EQ(expected_value,solutions.minDeleteCost(S, C));


    S = "aabbcc";
    C = {1, 2, 1, 2, 1, 2};
    expected_value = 3;
    EXPECT_EQ(expected_value,solutions.minDeleteCost(S, C));

    S = "ababa";
    C = {10, 5, 10 ,5, 10};
    expected_value = 0;
    EXPECT_EQ(expected_value,solutions.minDeleteCost(S, C));

    S = "aaabbbabbbb";
    C = {3,5,10,7,5,3,5,5,4,8,1};
    expected_value = 26;
    EXPECT_EQ(expected_value,solutions.minDeleteCost(S, C));
}

TEST_F(SolutionsTest, GetNumberofKTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {1, 2, 3, 3, 3, 3, 4, 5};
    int K = 3;
    int expected_value = 4;
    EXPECT_EQ(expected_value, solutions.getNumberofK(nums, K));
}

TEST_F(SolutionsTest, findNumberswithSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {1, 2, 3, 4, 7, 11, 15};
    int sum = 15;

    std::vector<int> expected_value = {4, 11};
    EXPECT_EQ(expected_value, solutions.findNumberswithSum(nums, sum));
}

TEST_F(SolutionsTest, getMedianTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int x = 2, y = 1, z = 3;
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.getMedian(x, y, z));
}

TEST_F(SolutionsTest, almostSortedTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
                            //{1, 3, 3, 5, 5, 3, 3}
                            //{1, 3, 3, 5, 5, 3}
    std::vector<int> nums = {1, 3, 5, 3, 3};
    bool expected_value = true;
    EXPECT_EQ(expected_value, solutions.almostSorted(nums));

    nums = {1, 3, 3, 5, 5, 3, 3};
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.almostSorted(nums));

    nums = {3, 1, 3};
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.almostSorted(nums));

    nums = {3, 1, 2};
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.almostSorted(nums));

    nums = {1, 5, 4, 3, 2, 6};
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.almostSorted(nums));
}


TEST_F(SolutionsTest, judgeCircleTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string moves = "UD";
    bool expected_value = true;
    EXPECT_EQ(expected_value, solutions.judgeCircle(moves));

    moves = "LL";
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.judgeCircle(moves));
}


TEST_F(SolutionsTest, criticalConnectionsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> > connection = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int n = 4;

    std::vector< std::vector<int> > expected_value = {{1, 3}};
    EXPECT_EQ(expected_value, solutions.criticalConnections(n, connection));

    connection = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    n = 5;
    expected_value = {{3, 4} , {1, 3}};
    EXPECT_EQ(expected_value, solutions.criticalConnections(n, connection));


    connection = {{0, 1}};
    n = 2;
    expected_value = {{0, 1}};
    EXPECT_EQ(expected_value, solutions.criticalConnections(n, connection));


}

TEST_F(SolutionsTest, findPeakElementTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {1, 2, 3, 1};
    int expected_value = 2;
//     EXPECT_EQ(expected_value, solutions.findPeakElement(nums));

    nums = {1, 2, 1, 3, 5, 6, 4};
    expected_value = 5;
//     EXPECT_EQ(expected_value, solutions.findPeakElement(nums));

    nums = {1};
    expected_value = 0;
//     EXPECT_EQ(expected_value, solutions.findPeakElement(nums));


    nums = {1, 2};
    expected_value = 1;
//     EXPECT_EQ(expected_value, solutions.findPeakElement(nums));


    nums = {2, 1};
    expected_value = 0;
//     EXPECT_EQ(expected_value, solutions.findPeakElement(nums));

    nums = {3,3,2,4,1};
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.findPeakElement(nums));


    nums = {4,6,5,1,2,3,7,8,9};
    expected_value = 8;
    EXPECT_EQ(expected_value, solutions.findPeakElement(nums));
}

TEST_F(SolutionsTest, addTwoNumbersTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> l1 = {2, 4, 3}, l2 = {5, 6, 4};
    std::vector<int> expected_value = {7, 0, 8};

    std::unique_ptr<leetcode::LinkedListNode> l1_node = nullptr, l2_node = nullptr;

    for (int i = 0; i < l1.size(); ++i) {
        l1_node = solutions.insertLinkedlistNode(std::move(l1_node), l1[i]);
        l2_node = solutions.insertLinkedlistNode(std::move(l2_node), l2[i]);
    }


    std::unique_ptr<leetcode::LinkedListNode> node = nullptr;
    node = solutions.addTwoNumbers(std::move(l1_node), std::move(l2_node));
    std::vector<int> v = solutions.PrintLinkedlist(std::move(node));

    EXPECT_EQ(expected_value, v);
}

TEST_F(SolutionsTest, reverseLinkedListTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> l1 = {2, 4, 3};
    std::vector<int> expected_value = {3, 4, 2};

    std::unique_ptr<leetcode::LinkedListNode> l1_node = nullptr;

    for (int i = 0; i < l1.size(); ++i) {
        l1_node = solutions.insertLinkedlistNode(std::move(l1_node), l1[i]);
    }

    std::unique_ptr<leetcode::LinkedListNode> reversednode = nullptr;

    reversednode = solutions.reversedLinkedList(std::move(l1_node));
    std::vector<int> v = solutions.PrintLinkedlist(std::move(reversednode));

    EXPECT_EQ(expected_value, v);

    l1 = {2, 4, 3, 5, 6};
    expected_value = {6, 5, 3, 4, 2};

    l1_node = nullptr;

    for (int i = 0; i < l1.size(); ++i) {
        l1_node = solutions.insertLinkedlistNode(std::move(l1_node), l1[i]);
    }

    reversednode = nullptr;

    reversednode = solutions.reversedLinkedList(std::move(l1_node));
    v = solutions.PrintLinkedlist(std::move(reversednode));

    EXPECT_EQ(expected_value, v);
}

TEST_F(SolutionsTest, deleteDuplicatesTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> head = {1, 1, 2, 3, 3};

    std::unique_ptr<leetcode::LinkedListNode> node = nullptr;
    for (int i = 0; i < head.size(); i++) {
        node = solutions.insertLinkedlistNode(std::move(node), head[i]);
    }

    // node = solutions.deleteDuplicates(std::move(node));
    // std::vector<int> v = solutions.PrintLinkedlist(std::move(node));

    // std::vector<int> expected_value = {1, 2, 3};

    // EXPECT_EQ(expected_value, v);


    node = nullptr;
    head = {1, 1, 1};
    for (int i = 0; i < head.size(); i++) {
        node = solutions.insertLinkedlistNode(std::move(node), head[i]);
    }
    // node = solutions.deleteDuplicates(std::move(node));
    // v = solutions.PrintLinkedlist(std::move(node));
    // expected_value = {1};
    // EXPECT_EQ(expected_value, v);

    node = nullptr;
    head = {1, 1, 2};
    for (int i = 0; i < head.size(); i++) {
        node = solutions.insertLinkedlistNode(std::move(node), head[i]);
    }
    // node = solutions.deleteDuplicates(std::move(node));
    // v = solutions.PrintLinkedlist(std::move(node));
    // expected_value = {1, 2};
    // EXPECT_EQ(expected_value, v);
}

TEST_F(SolutionsTest, addExpressionTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string S = "()";
    bool expected_value = true;
    EXPECT_EQ(expected_value, solutions.addExpression(S));


    S = "()()";
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.addExpression(S));


    S = "()+()";
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.addExpression(S));

}

TEST_F(SolutionsTest, balancedSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> arr = {1, 2, 3, 3};
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.balancedSum(arr));

    arr = {1, 2, 3, 4, 6};
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.balancedSum(arr));

    arr = {1, 2, 1};
    expected_value = 1;
    EXPECT_EQ(expected_value, solutions.balancedSum(arr));
}


TEST_F(SolutionsTest, arrayNextingTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {5, 4, 0, 3, 1, 6, 2};

    int expected_value = 4;
    EXPECT_EQ(expected_value, solutions.arrayNexting(nums));


    nums = {0, 1, 2};
    expected_value = 1;
    EXPECT_EQ(expected_value, solutions.arrayNexting(nums));

}

TEST_F(SolutionsTest, addOperatorsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string num = "232";
    int target = 8;
    std::vector< std::string > expected_value = {"2+3*2", "2*3+2"};
    EXPECT_EQ(expected_value, solutions.addOperators(num, target));

    num = "123";
    target = 6;
    expected_value = {"1+2+3", "1*2*3"};
    EXPECT_EQ(expected_value, solutions.addOperators(num, target));

    num = "3456237490";
    target = 9191;
    expected_value = {};
    EXPECT_EQ(expected_value, solutions.addOperators(num, target));

    num = "105";
    target = 5;
    expected_value = {"1*0+5","10-5"};
    EXPECT_EQ(expected_value, solutions.addOperators(num, target));


    num = "123456789";
    target = 45;
//     expected_value = {"1*2*3*4*5-6-78+9","1*2*3*4+5+6-7+8+9","1*2*3+4+5+6+7+8+9","1*2*3+4+5-6*7+8*9","1*2*3+4-5*6+7*8+9","1*2*3+4-5*6-7+8*9","1*2*3-4*5+6*7+8+9","1*2*3-4*5-6+7*8+9","1*2*3-4*5-6-7+8*9","1*2*3-45+67+8+9","1*2*34+56-7-8*9","1*2*34-5+6-7-8-9","1*2+3*4-56+78+9","1*2+3+4+5*6+7+8-9","1*2+3+4-5+6*7+8-9","1*2+3+4-5-6+7*8-9","1*2+3+45+67-8*9","1*2+3-45+6+7+8*9","1*2+34+5-6-7+8+9","1*2+34+56-7*8+9","1*2+34-5+6+7-8+9","1*2+34-56+7*8+9","1*2+34-56-7+8*9","1*2-3*4+5+67-8-9","1*2-3+4-5-6*7+89","1*2-3-4*5+67+8-9","1*2-3-4+56-7-8+9","1*2-34+5*6+7*8-9","1*23+4*5-6+7-8+9","1*23-4-56-7+89","1+2*3*4*5+6+7-89","1+2*3*4+5*6+7-8-9","1+2*3*4-5+6*7-8-9","1+2*3+4*5*6+7-89","1+2*3+4*5-6+7+8+9","1+2*3-4-5-6*7+89","1+2*34-5*6+7+8-9","1+2+3*4*5+6-7-8-9","1+2+3*4+5+6*7-8-9","1+2+3*45-6-78-9","1+2+3+4+5+6+7+8+9","1+2+3+4+5-6*7+8*9","1+2+3+4-5*6+7*8+9","1+2+3+4-5*6-7+8*9","1+2+3-4*5+6*7+8+9","1+2+3-4*5-6+7*8+9","1+2+3-4*5-6-7+8*9","1+2+3-45+67+8+9","1+2-3*4*5+6+7+89","1+2-3*4+5*6+7+8+9","1+2-3*4-5+6*7+8+9","1+2-3*4-5-6+7*8"};
//     EXPECT_EQ(expected_value, solutions.addOperators(num, target));

}

TEST_F(SolutionsTest, CodilityTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;


    std::vector<double> v;
    std::filebuf fb;

    std::string file = INPUT_FILES_DIR;
    file.append("/input.txt");
    if (fb.open (file,std::ios::in))
    {
      std::istream is(&fb);
      std::string line;

      while (std::getline(is, line)) {
         parseDouble(line, v);
      }

      fb.close();
    }

    std::vector<double> expected_value = {137, -104, 0, 1, 0, -1};
//     EXPECT_EQ(expected_value, v);
}

TEST_F(SolutionsTest, isBalancedTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> v = {1, 2, 2, 3, 3, -1, -1, 4, 4};
    std::unique_ptr<leetcode::TreeNode> root = nullptr;

    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(std::move(root), v[i], i);
    }

    bool expected_value = false;

    EXPECT_EQ(expected_value, solutions.isBalanced(std::move(root)));


    v = {3, 9, 20, -1, -1, 15, 7};

    root = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(std::move(root), v[i], i);
    }

    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isBalanced(std::move(root)));

    v = {};

    root = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(std::move(root), v[i], i);
    }

    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isBalanced(std::move(root)));

}



TEST_F(SolutionsTest, sortedArrayToBSTTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {-10, -3, 0, 5, 9};

    std::unique_ptr<leetcode::TreeNode> node  = solutions.sortedArrayToBST(nums);

    std::vector<int> actual_value = solutions.PrintBFS(std::move(node));
    std::vector<int> expected_value = {0, -10, 5, -3, 9};

    EXPECT_EQ(expected_value, actual_value);

    nums = {1, 3};
    node = solutions.sortedArrayToBST(nums);

    actual_value = solutions.PrintBFS(std::move(node));
    expected_value = {1, 3};
    EXPECT_EQ(expected_value, actual_value);
}

TEST_F(SolutionsTest, surroundedRegionsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<char> > input = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};


    std::vector< std::vector<char> > expected_value = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};

    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));

    input = {{'X'}};
    expected_value = {{'X'}};
    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));

    input = {{'O','O'},{'O','O'}};
    expected_value = {{'O','O'},{'O','O'}};

    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));

    input = {{'O','O','O'},{'O','X','O'},{'O','O','O'}};
    expected_value = {{'O','O','O'},{'O','X','O'},{'O','O','O'}};
    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));


    input = {{'X','O','X'},{'X','O','X'},{'X','O','X'}};
    expected_value = {{'X','O','X'},{'X','O','X'},{'X','O','X'}};
    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));


    input = {{'X','X','X'},{'X','O','X'},{'X','X','X'}};
    expected_value = {{'X','X','X'},{'X','X','X'},{'X','X','X'}};
    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));


    input = {{'O','X','O','O','O','X'},{'O','O','X','X','X','O'},{'X','X','X','X','X','O'},{'O','O','O','O','X','X'},{'X','X','O','O','X','O'},{'O','O','X','X','X','X'}};
    expected_value = {{'O','X','O','O','O','X'},{'O','O','X','X','X','O'},{'X','X','X','X','X','O'},{'O','O','O','O','X','X'},{'X','X','O','O','X','O'},{'O','O','X','X','X','X'}};
    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));


    // Issue
    input = {{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X','O','O','O','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','O','O','O','X','O','X','O','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','O','X','O','X','O','X','O','O','O','X','X','X','X','X','X'},{'X','X','X','X','X','O','X','O','O','O','X','X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};

    expected_value = {{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','X','X','X','X','O','O','O','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','O','O','O','X','O','X','O','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','O','X','O','X','O','X','O','O','O','X','X','X','X','X','X'},{'X','X','X','X','X','O','X','O','O','O','X','X','X','X','X','X','X','X','X','X'},{'X','X','X','X','X','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};

    EXPECT_EQ(expected_value, solutions.surroundedRegions(input));


}


TEST_F(SolutionsTest, countBitsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int input = 2;
    std::vector<int> expected_value = {0, 1, 1};
    EXPECT_EQ(expected_value, solutions.countBits(input));

    input = 5;
    expected_value = {0, 1, 1, 2, 1, 2};
    EXPECT_EQ(expected_value, solutions.countBits(input));

}

TEST_F(SolutionsTest, hammingWeightTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    uint32_t input  = 00000000000000000000000000001011;
    int expected_value = 3;
    EXPECT_EQ(expected_value, solutions.hammingWeight(input));

    input = 00000000000000000000000010000000;
    expected_value = 1;
    EXPECT_EQ(expected_value, solutions.hammingWeight(input));

    //input = 11111111111111111111111111111101;
    //expected_value = 31;
    //EXPECT_EQ(expected_value, solutions.hammingWeight(input));

}


TEST_F(SolutionsTest, palindromePairsSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;


    std::vector< std::string> input_array = {"adef", "ef", "Lss", "ss", "hJ", "!d!Jh"} ;
    int expected_value = 14;
    EXPECT_EQ(expected_value, solutions.palindromePairsSum(input_array));


    input_array = {"abcd","dcba","lls","s","sssll"};
    expected_value = 13;
    EXPECT_EQ(expected_value, solutions.palindromePairsSum(input_array));

    // Corner case
    input_array = {"ef", "e", "eeeddee", "edHd"};
    expected_value = 8;
    EXPECT_EQ(expected_value, solutions.palindromePairsSum(input_array));

}

TEST_F(SolutionsTest, sumGameTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string num = "5023";
    bool expected_value = false;
    EXPECT_EQ(expected_value, solutions.sumGame(num));


    num = "25??";
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.sumGame(num));

    num = "?3295???";
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.sumGame(num));
}

TEST_F(SolutionsTest, stoneGameTEST) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> piles = {5, 3, 4, 5};

    bool expected_value = true;
    EXPECT_EQ(expected_value, solutions.stoneGame(piles));

    piles = {3, 7, 2, 3};
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.stoneGame(piles));
}

TEST_F(SolutionsTest, solveNQueensTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int input = 4;
    std::vector< std::vector< std::string> >  expected_value = {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}};
    EXPECT_EQ(expected_value, solutions.solveNQueens(input));

    input = 1;
    expected_value = {{"Q"}};
    EXPECT_EQ(expected_value, solutions.solveNQueens(input));
}

TEST_F(SolutionsTest, isSolvableTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::string > words = {"SEND","MORE"};
    std::string result = "MONEY";
    bool expected_value = true;
    EXPECT_EQ(expected_value, solutions.isSolvable(words, result));

    words = {"SIX","SEVEN","SEVEN"};
    result = "TWENTY";
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isSolvable(words, result));

    words = {"LEET","CODE"};
    result = "POINT";
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.isSolvable(words, result));

    // corner case
    words = {"A", "A"};
    result = "AA";
    expected_value = true;
//     EXPECT_EQ(expected_value, solutions.isSolvable(words, result));

    // Corner case
    words = {"CBA","CBA","CBA","CBA","CBA"};
    result = "EDD";
    expected_value = false;
//     EXPECT_EQ(expected_value, solutions.isSolvable(words, result));

}

TEST_F(SolutionsTest, mergeIntervalTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector<int> > intervals = {{1,3}, {2, 6}, {8,10}, {15, 18}};
    std::vector< std::vector<int> > expected_value = {{1, 6}, {8, 10}, {15, 18}};
    EXPECT_EQ(expected_value, solutions.mergeInterval(intervals));

    intervals = {{1,4}, {4, 6}};
    expected_value = {{1, 6}};
    EXPECT_EQ(expected_value, solutions.mergeInterval(intervals));

    intervals = {{1,4}, {5, 6}};
    expected_value = {{1, 4}, {5, 6}};
    EXPECT_EQ(expected_value, solutions.mergeInterval(intervals));

    intervals = {{1,4}, {2, 3}};
    expected_value = {{1, 4}};
    EXPECT_EQ(expected_value, solutions.mergeInterval(intervals));
}

TEST_F(SolutionsTest, addDigitsTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int num = 38;
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.addDigits(num));
}

TEST_F(SolutionsTest, lengthofLastwordTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string s = "   fly me   to   the moon  ";
    int expected_value = 4;
    EXPECT_EQ(expected_value, solutions.lenghtofLastword(s));

    s = "Today is a nice day";
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.lenghtofLastword(s));
}

TEST_F(SolutionsTest, longestCommonPrefixTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<std::string> strs = {"flower","flow","flight"};
    std::string expected_value = "fl";
    EXPECT_EQ(expected_value, solutions.longestCommonPrefix(strs));

    strs = {"dog","racecar","car"};
    expected_value = "";
    EXPECT_EQ(expected_value, solutions.longestCommonPrefix(strs));
}

TEST_F(SolutionsTest, reverseWordsTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string s = "the sky is blue";
    std::string expected_value = "blue is sky the";
    EXPECT_EQ(expected_value, solutions.reverseWords(s));

    s = "  hello world  ";
    expected_value = "world hello";
    EXPECT_EQ(expected_value, solutions.reverseWords(s));
}




TEST_F(SolutionsTest, threeSumClosestTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.threeSumClosest(nums, target));

    nums = {0,0,0};
    target = 1;
    expected_value = 0;
    EXPECT_EQ(expected_value, solutions.threeSumClosest(nums, target));


    nums = {-100, -98, -2, -1};
    target = -101;
    expected_value = -101;
    EXPECT_EQ(expected_value, solutions.threeSumClosest(nums, target));
}

TEST_F(SolutionsTest, removeElementTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {3,2,2,3};
    int val = 3;
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.removeElement(nums, val));
}

TEST_F(SolutionsTest, findMedianSortedArrayTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    double expected_value = 2.5;
    EXPECT_EQ(expected_value, solutions.findMedianSortedArray(nums1, nums2));
}

TEST_F(SolutionsTest, threeSumTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {0,1,1};
    std::vector<std::vector<int>> expected_value = {};
    EXPECT_EQ(expected_value, solutions.threeSum(nums));
}

TEST_F(SolutionsTest, longestConsecutiveTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> nums = {100,4,200,1,3,2};
    int expected_value = 4;
    EXPECT_EQ(expected_value, solutions.longestConsecutive(nums));

    nums = {0,3,7,2,5,8,4,6,0,1};
    expected_value = 9;
    EXPECT_EQ(expected_value, solutions.longestConsecutive(nums));

    nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    expected_value = 7;
    EXPECT_EQ(expected_value, solutions.longestConsecutive(nums));

    nums = {1, 2, 0, 1};
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.longestConsecutive(nums));

}



TEST_F(SolutionsTest, networkDelayTimeTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector<int> > times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.networkDelayTime(times, n, k));

    times = {{1,2,1}};
    n = 2, k = 1;
    expected_value = 1;
    EXPECT_EQ(expected_value, solutions.networkDelayTime(times, n, k));

    times = {{1,2,1}};
    n = 2, k = 2;
    expected_value = -1;
    EXPECT_EQ(expected_value, solutions.networkDelayTime(times, n, k));
}

TEST_F(SolutionsTest, isBipartiteTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;


    std::vector< std::vector<int> > graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    bool expected_value = false;
    EXPECT_EQ(expected_value, solutions.isBipartite(graph));

    graph = {{1,3},{0,2},{1,3},{0,2}};
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isBipartite(graph));



}


TEST_F(SolutionsTest, maximumInvitationsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector< int> >  grid = {{1,0,1,0},{1,0,0,0},{0,0,1,0},{1,1,1,0}};
    int expected_value = 3;
    EXPECT_EQ(expected_value, solutions.maximumInvitations(grid));

    grid = {{1,1,1}, {1,0,1}, {0, 0, 1}};
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.maximumInvitations(grid));

}


TEST_F(SolutionsTest, isPairWithSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int mat[ROW][COLUMN] = {{1, 1, 2, 4},
                        {5, 8, 7, 6},
                        {9, 10, 13, 11},
                        {12, 0, 14, 15}};
 
    int sum = 11;

    std::vector< std::vector<int> > expected_value = {{1, 10}, {2, 9}, { 4, 7}, {11, 0}};
    EXPECT_EQ(expected_value, solutions.isPairWithSum(mat, sum));
}

TEST_F(SolutionsTest, canFinishTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int numCourse = 2;
    std::vector< std::vector<int > > prerequisities = {{1,0}};
    bool expected_value = true;
    EXPECT_EQ(expected_value, solutions.canFinish(numCourse, prerequisities));

    numCourse = 2;
    prerequisities = { {1, 0}, {0, 1} };
    expected_value = false;
    EXPECT_EQ(expected_value, solutions.canFinish(numCourse, prerequisities));

    numCourse = 8;
    prerequisities = { {6, 2}, {6, 1}, {6, 5}, {4, 0} };
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.canFinish(numCourse, prerequisities));

}

TEST_F(SolutionsTest, minimumSemestersTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int courses = 3;
    std::vector< std::vector<int> > relations = {{1, 3}, {2, 3}};
    int expected_value = 2;
    //Explanation: The figure above represents the given graph.
    //In the first semester, you can take courses 1 and 2.
    //In the second semester, you can take course 3.
    EXPECT_EQ(expected_value, solutions.minimumSemesters(courses, relations));

    courses = 3;
    relations = {{1, 2}, {2, 3}, {3, 1}};
    expected_value = -1;
    EXPECT_EQ(expected_value, solutions.minimumSemesters(courses, relations));

    courses = 6;
    relations = { {6, 2}, {6, 1}, {6, 5}, {4, 1} };
    expected_value = 2;
    EXPECT_EQ(expected_value, solutions.minimumSemesters(courses, relations));

}

TEST_F(SolutionsTest, minNumberOfSemestersTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int n = 4;
    int k = 2;
    std::vector< std::vector<int> > dependencies = {{2, 1}, {3, 1}, {1, 4}};
    int expected_value = 3;
    EXPECT_EQ(expected_value, solutions.minNumberOfSemesters(n, dependencies, k));

    n = 11;
    dependencies = {};
    k = 2;
    expected_value = 6;
    EXPECT_EQ(expected_value, solutions.minNumberOfSemesters(n, dependencies, k));

    // Corner case
    n = 13;
    // course prevCoursei has to be taken before course nextCoursei.
    dependencies = {{12,8},{2,4},{3,7},{6,8},{11,8},{9,4},{9,7},{12,4},{11,4},{6,4},{1,4},{10,7},{10,4},{1,7},{1,8},{2,7},{8,4},{10,8},{12,7},{5,4},{3,4},{11,7},{7,4},{13,4},{9,8},{13,8}};
    k = 9;
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.minNumberOfSemesters(n, dependencies, k));

    n = 5;
    dependencies = {{2,1},{3,1},{4,1},{1,5}};
    k = 2;
    expected_value = 4;
    EXPECT_EQ(expected_value, solutions.minNumberOfSemesters(n, dependencies, k));

    n = 14;
    dependencies = {{11, 7}};
    k = 2;
    expected_value = 7;
    EXPECT_EQ(expected_value, solutions.minNumberOfSemesters(n, dependencies, k));
}

TEST_F(SolutionsTest, findCircleNumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector<int> > isConnected = {{1,1,0}, {1, 1, 0}, {0, 0, 1}};
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.findCircleNum(isConnected));

    isConnected =  {{1,0,0},{0,1,0},{0,0,1}};
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.findCircleNum(isConnected));
}

TEST_F(SolutionsTest, minDaysTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector<int> > grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.minDays(grid));

    grid = {{1, 1}};
    expected_value = 2;
    EXPECT_EQ(expected_value, solutions.minDays(grid));


    grid = {{1,1,0,0}, {0,0,0,0}, {0,0,1,1}};
    expected_value = 0;
    EXPECT_EQ(expected_value, solutions.minDays(grid));


}

TEST_F(SolutionsTest, maxProfitITest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> prices = {7,1,5,3,6,4};
    int expected_value = 5;
    EXPECT_EQ(expected_value, solutions.maxProfitI(prices));

    prices = {7,6,4,3,1};
    expected_value = 0;
    EXPECT_EQ(expected_value, solutions.maxProfitI(prices));
}

TEST_F(SolutionsTest, rotatematrixTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> expected_value = { {7,4,1},{8,5,2},{9,6,3} };
    EXPECT_EQ(expected_value, solutions.rotatematrix(matrix));
}





TEST_F(SolutionsTest, maxProfitTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> prices = {1, 2, 3, 4, 5};
    int expected_value = 4;
    EXPECT_EQ(expected_value, solutions.maxProfit(prices));

    prices = {7, 1, 5, 3, 6, 4};
    expected_value = 7;
    EXPECT_EQ(expected_value, solutions.maxProfit(prices));

    prices = {260000, 260500, 264500, 262500, 286000, 272000, 246500, 255000};
    expected_value = 36500;
    EXPECT_EQ(expected_value, solutions.maxProfit(prices));
}


TEST_F(SolutionsTest, minCostClimbingStairsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> cost = {10, 15, 20};
    int expected_value = 15;
    EXPECT_EQ(expected_value, solutions.minCostClimbingStairs(cost));

    cost = {1,100,1,1,1,100,1,1,100,1};
    expected_value = 6;
    EXPECT_EQ(expected_value, solutions.minCostClimbingStairs(cost));
}

TEST_F(SolutionsTest, lengthOfLongestSubstringTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string s = "abcabcbb";
    int expected_value = 3;
//     EXPECT_EQ(expected_value, solutions.lengthOfLongestSubstring(s));

    s = "bbbbb";
    expected_value = 1;
//     EXPECT_EQ(expected_value, solutions.lengthOfLongestSubstring(s));

    s = "pwwkew";
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.lengthOfLongestSubstring(s));

}

TEST_F(SolutionsTest, converToTitleTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int columnNumber = 1;
    std::string expected_value = "A";
    EXPECT_EQ(expected_value, solutions.converToTitle(columnNumber));

    columnNumber = 28;
    expected_value = "AB";
    EXPECT_EQ(expected_value, solutions.converToTitle(columnNumber));

    columnNumber = 701;
    expected_value = "ZY";
    EXPECT_EQ(expected_value, solutions.converToTitle(columnNumber));

}

TEST_F(SolutionsTest, isMatchTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string s = "aa";
    std::string p = "a*";

    bool expected_value = true;
    EXPECT_EQ(expected_value, solutions.isMatch(s, p));

    s = "aaa";
    p = "a*";

    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isMatch(s, p));

    s = "ab";
    p = ".*";

    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isMatch(s, p));

    s = "aaa";
    p = "ab*a*c*a";


    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isMatch(s, p));

}

TEST_F(SolutionsTest, isPalindromeTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string input = "A man, a plan, a canal: Panama";
    bool expected_value = true; 
    EXPECT_EQ(expected_value, solutions.isPalindrome(input));

    input = " " ;
    expected_value = true;
    EXPECT_EQ(expected_value, solutions.isPalindrome(input));


}

TEST_F(SolutionsTest, isPalindromeNumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int  input = 121;
    bool expected_value = true; 
    EXPECT_EQ(expected_value, solutions.isPalindrome(input));

    input = 10;
    expected_value = false; 
    EXPECT_EQ(expected_value, solutions.isPalindrome(input));

    input = 1000030001;
    expected_value = false; 
    EXPECT_EQ(expected_value, solutions.isPalindrome(input));
}

TEST_F(SolutionsTest, findMinTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int>  input = {3,4,5,1,2};
    int expected_value = 1; 
    EXPECT_EQ(expected_value, solutions.findMin(input));

    input = {4,5,6,7,0,1,2};
    expected_value = 0; 
    EXPECT_EQ(expected_value, solutions.findMin(input));
}

TEST_F(SolutionsTest, majorityElementTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int>  input = {1,1,2,2,1};
    int expected_value = 1; 
    EXPECT_EQ(expected_value, solutions.majorityElement(input));

    input = {2,2,1,1,2,4,2};
    expected_value = 2; 
    EXPECT_EQ(expected_value, solutions.majorityElement(input));

    input = {3, 2, 3};
    expected_value = 3; 
    EXPECT_EQ(expected_value, solutions.majorityElement(input));
}

TEST_F(SolutionsTest, rotateTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int>  input = {-1,-100,3,99};
    int k = 2;
    std::vector<int> expected_value = {3,99,-1,-100}; 
    EXPECT_EQ(expected_value, solutions.rotate(input, k));
}

TEST_F(SolutionsTest, removeDuplicatesTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int>  input = {1, 1, 2};
    int expected_value = 2; 
    EXPECT_EQ(expected_value, solutions.removeDuplicates(input));

    input = {0,0,1,1,1,2,2,3,3,4};
    expected_value = 5;
    EXPECT_EQ(expected_value, solutions.removeDuplicates(input));
}

TEST_F(SolutionsTest, removeDuplicatesIITest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int>  input = {1,1,1,2,2,3};
    int expected_value = 5; 
    EXPECT_EQ(expected_value, solutions.removeDuplicatesII(input));

    input = {0,0,1,1,1,1,2,3,3};
    expected_value = 7;
    EXPECT_EQ(expected_value, solutions.removeDuplicatesII(input));

    input = {1, 2, 3};
    expected_value = 3;
    EXPECT_EQ(expected_value, solutions.removeDuplicatesII(input));
}

TEST_F(SolutionsTest, searchTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int>  nums = {4,5,6,7,0,1,2};
    int target = 0;
    int expected_value = 4; 
    EXPECT_EQ(expected_value, solutions.search(nums, target));

    nums = {4,5,6,7,0,1,2};
    target = 3;
    expected_value = -1;
    EXPECT_EQ(expected_value, solutions.search(nums, target));

    nums = {5, 1, 3};
    target = 3;
    expected_value = 2;
    EXPECT_EQ(expected_value, solutions.search(nums, target));


}


TEST_F(SolutionsTest, productExceptselfTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int>  input = {1,2,3,4};
    std::vector<int> expected_value = {24,12,8,6}; 
    EXPECT_EQ(expected_value, solutions.productExceptself(input));

    input = {-1,1,0,-3,3};
    expected_value = {0,0,9,0,0};
    EXPECT_EQ(expected_value, solutions.productExceptself(input));
}


TEST_F(SolutionsTest, diagionalDifferenceTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector<int> > input = {{1, 2, 3}, {4, 5, 6}, {9, 8, 9}};
    int expected_value = 2;
    EXPECT_EQ(expected_value, solutions.diagionalDifference(input));
}

TEST_F(SolutionsTest, insertionSortTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector<int> input = {2, 1, 3, 1, 2};
    int expected_value = 4;
    EXPECT_EQ(expected_value, solutions.insertionSort(input));
}

TEST_F(SolutionsTest, DuplicatesTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string input = "aa";
    std::string expected_value = "aa0";
    EXPECT_EQ(expected_value, solutions.Duplicates(input));

    input = "abc";
    expected_value = "abc";
    EXPECT_EQ(expected_value, solutions.Duplicates(input));

    input = "abhbaca";
    expected_value = "abaca";
    EXPECT_EQ(expected_value, solutions.Duplicates(input));

    input = "abbhccbh";
    expected_value = "abcb";
    EXPECT_EQ(expected_value, solutions.Duplicates(input));
}

TEST_F(SolutionsTest, moveZerosTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> input = {0,1,0,3,12 };
   std::vector<int> expected_value = {1,3,12,0,0};
   EXPECT_EQ(expected_value, solutions.moveZeros(input));
                                                           
   input = {0};
   expected_value = {0};
   EXPECT_EQ(expected_value, solutions.moveZeros(input));
}

TEST_F(SolutionsTest, sortedmergeTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> nums1 = { 1,2,3,0,0,0};
   std::vector<int> nums2 = { 2,5,6 };
   int m = 3;
   int n = 3;
   std::vector<int> expected_value = { 1,2,2,3,5,6};
   EXPECT_EQ(expected_value, solutions.sortedmerge(nums1, m, nums2, n));
}

TEST_F(SolutionsTest, canJumpTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> nums = {2,3,1,1,4};
   bool expected_value = true;
   EXPECT_EQ(expected_value, solutions.canJump(nums));
}

TEST_F(SolutionsTest, jumpTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> nums = {2,3,1,1,4};
   int expected_value = 2;
   EXPECT_EQ(expected_value, solutions.jump(nums));
}

TEST_F(SolutionsTest, hIndexTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> citations = {3,0,6,1,5};
   int expected_value = 3;
   EXPECT_EQ(expected_value, solutions.hIndex(citations));
}

TEST_F(SolutionsTest, canCompleteCircuitTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> gas = {1,2,3,4,5};
   std::vector<int> cost = {3,4,5,1,2};
   int expected_value = 3;
   EXPECT_EQ(expected_value, solutions.canCompleteCircuit(gas, cost));
}

TEST_F(SolutionsTest, candyTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> ratings = {1, 0, 2};
   int expected_value = 5;
   EXPECT_EQ(expected_value, solutions.candy(ratings));
}

TEST_F(SolutionsTest, trapTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
   int expected_value = 6;
   EXPECT_EQ(expected_value, solutions.trap(height));
}

TEST_F(SolutionsTest, romanToIntTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   std::string s = "III";
   int expected_value = 3;
   EXPECT_EQ(expected_value, solutions.romanToInt(s));
}

TEST_F(SolutionsTest, intToRomanTest)
{
   /* Declare the Unit Test object */
   leetcode::Solutions solutions;
                                                           
   int num = 3;
   std::string expected_value = "III";
   EXPECT_EQ(expected_value, solutions.intToRoman(num));
}

} /* namespace googletest */
