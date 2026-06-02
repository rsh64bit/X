/** Longest Substring Without Repeating Characters
Medium


Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include<iostream>
#include<vector>


template<typename T>
std::vector<T> add_result(const T& s, const T& i){
  return {s, i};
}
template<typename T>
class Var_Sli_Window {

private:
std::vector<T> data;
std::vector<std::vector<T>> result;

public:
  Var_Sli_Window (std::vector<T> d) : data(std::move(d)) {}
 void prn_win() {
   for (const auto& x : data)
     std::cout << x << " ";
     std::cout <<  "\n";
     for (const auto& z : result) {
     std::cout <<  " sum and items count ";
     for (const auto& y : z)
      std::cout << y << " ";
     std::cout <<  "\n";
     }
 }

 int32_t min_win(uint32_t val) {
    int32_t l = 0 , r = 0, s = 0;
    int32_t min = INT_MAX;
    for (int32_t r = 0; r < data.size(); ++r) {
        s += data[r];
        while (s >= val) {
          min = std::min(min, r - l + 1);
          s -= data[l];
          l++;
        }
    }
    return min == INT_MAX ? 0 : min;
  }

  void sub_win2(uint32_t val) {
    int32_t l = 0 , r = 0, s = 0;

    for(r = 0; r < data.size(); ++r) {
        s += data[r];;
      while (s >= val) {
        s -= data[l]; ++l;
        if (s == val) {
          std::vector<int> t = add_result(s, r - l + 1);
          result.push_back(t);
        }
      }
    }
  }

  /*inefficient way to print all the size of subarray sum*/
  void sub_win(uint32_t val) {
    int32_t l = 0 , r = 0, s = 0;

    while (r < data.size()) {
      while (r < data.size() && s <= val) {
        s += data[r]; r++;
        if (s == val) {
          auto t = add_result(s, r - l);
          result.push_back(t);
        }
      }
      while (s >= val && l < data.size()) {
        s -= data[l]; ++l;
        if (s == val) {
          std::vector<int> t = add_result(s, r - l);
          result.push_back(t);
        }
      }
    }
  }
};
int main() {


  std::vector<int> v{2, 3, 1, 2, 4, 3};
  std::vector<int> e{2, 3};

  Var_Sli_Window<int> w(v), l(e);
  w.sub_win2(7);
  w.prn_win();

  l.sub_win2(7);
  l.prn_win();

  std::cout << w.min_win(7) <<std::endl;

  return 0;
}

