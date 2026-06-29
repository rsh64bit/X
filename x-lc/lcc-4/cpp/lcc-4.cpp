/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
  The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= -106
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
class Solution {

    public:
        /*part of merge sort used here*/
        void findmediansortedarrays2(std::vector<int>& n1, std::vector<int>& n2) {
                //std::vector<int> n1 = {1, 3 ,5, 6}, n2 = {4, 9 };
            std::vector<int> sort;
            int l = 0, m = 0;

            while (l < n1.size() && m < n2.size()) {
                if (n1[l] < n2[m])
                    sort.push_back(n1[l++]);
                else 
                    sort.push_back(n2[m++]);
            }

            sort.insert(sort.end(), n1.begin() + l, n1.end());
            sort.insert(sort.end(), n2.begin() + m, n2.end());

            for_each(sort.begin(), sort.end(), [](int x){std::cout << x << " ";});
            std::cout << "\n";
        }
        
        /*buggy function: what not to do*/
        void findmediansortedarrays( std::vector<int>& nums1, std::vector<int>& nums2 ) {
            std::vector<int> sort;

            int l = nums1.size();
            int m = nums2.size();
            if (l > nums2.size()) std::swap(l, m);
            for (int i = 0; i < l; ++i) {

                if (sort.empty()) {
                    int a = nums1[i];
                    int b = nums2[i];
                    if(a > b)std::swap(a, b);
                    sort.push_back(a);
                    sort.push_back(b);
                } else {
                    int a = sort.back();
                    int b = nums1[i];
                    int c = nums2[i];
                    if (a > b) std::swap(a, b);
                    // result: a < b
                    if (b > c) std::swap(b, c);
                    // result: a < temp < b
                    if (a > b) std::swap(a, b);

                    sort.pop_back();
                    sort.insert(sort.end(), {a, b, c});
                }
            }

            if (l == nums1.size())
            sort.insert(sort.end(), nums2.begin() + l, nums2.end());
            else
            sort.insert(sort.end(), nums1.begin() + l, nums1.end());

            for_each(sort.begin(), sort.end(), [](int x){std::cout << x << " ";});
            std::cout << "\n";
        }
};

int main() {
    //this test case fails
    //std::vector<int> n1 = {1, 3 ,5, 6}, n2 = {4, 9 };
    std::vector<int> n1 = {1, 3 ,5}, n2 = {4, 9 };

    for_each(n1.begin(), n1.end(), [](int x){std::cout << x << " "; });
    std::cout << "\n";
    for_each(n2.begin(), n2.end(), [](int x){std::cout << x << " ";});
    std::cout << "\n";
    Solution obj;
    obj.findmediansortedarrays2(n1, n2);
    return 0;
}
