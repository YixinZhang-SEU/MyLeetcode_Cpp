#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // 77. 组合
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int> > combine(int n, int k) {
    //     ckcktracking(n, k, 1);
    //     return res;
    // }
    // void backtracking(int n, int k, int st_idx) {
    //     if (tmp.size() == k) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = st_idx; i <=  n-(k-tmp.size())+1; i++) {
    //         tmp.push_back(i);
    //         backtracking(n, k, i+1);
    //         tmp.pop_back();
    //     }
    // }

    // 216. 组合总和 III
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> combinationSum3(int k, int n) {
    //     backtracking(n, k, 1, 0);
    //     return res;
    // }
    // void backtracking(int n, int k, int st_idx, int sum) {
    //     for (int i = st_idx; i <= 9-(k-tmp.size())+1; i++) {
    //         if (sum > n) {
    //             return;
    //         }
    //         if (tmp.size() == k) {
    //             if (sum == n) {
    //                 res.push_back(tmp);
    //                 return;
    //             }
    //         }
    //         sum += i;
    //         tmp.push_back(i);
    //         backtracking(n, k, i+1, sum);
    //         tmp.pop_back();
    //         sum -= i;    
    //     }
    //     return;
    // }

    // 17. 电话号码的字母组合
    // vector<vector<string> > alphas = {{}, {}, {"a","b","c"}, {"d", "e", "f"},  {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};
    //
    // string tmp;
    // vector<string> res = {};
    // vector<string> letterCombinations(string digits) {
    //     int length = digits.length();
    //     if (!length) {
    //         return res;
    //     }
    //     int idx = 0;
    //     backtracking(length, idx, digits);
    //     return res;
    // }
    //
    // void backtracking(int length, int idx, string digits) {
    //     if (tmp.length() == length) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for(string s : alphas[(int)digits[idx]-48]) {
    //         tmp += s;
    //         backtracking(length, idx+1, digits);
    //         tmp.erase(tmp.end()-1);
    //     }
    // }

    // 39. 组合总和
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     backtracking(candidates, target, 0, 0);
    //     return res;
    // }
    // void backtracking(vector<int>& candidates, int target, int idx, int sum) {
    //     if (sum > target) {
    //         return;
    //     }
    //     if (sum == target) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = idx; i < candidates.size(); i++) {
    //         sum += candidates[i];
    //         tmp.push_back(candidates[i]);
    //         backtracking(candidates, target, i, sum);
    //         sum -= candidates[i];
    //         tmp.pop_back();
    //     }
    // }

    // 40. 组合总和 II
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     sort(candidates.begin(), candidates.end());
    //     backtracking(candidates, target, 0, 0);
    //     return res;
    // }
    // void backtracking(vector<int>& candidates, int target, int idx, int sum) {
    //     if (sum > target) {
    //         return;
    //     }
    //     if (sum == target) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = idx; i < candidates.size(); i++) {
    //         if (i > idx && candidates[i] == candidates[i-1]) {
    //             continue;
    //         }
    //         sum += candidates[i];
    //         tmp.push_back(candidates[i]);
    //         backtracking(candidates, target, i+1, sum);
    //         sum -= candidates[i];
    //         tmp.pop_back();
    //     }
    // }

    // 131. 分割回文串
    // vector<vector<bool> > is_palindrome;      // is_palindrome[i][j]表示字符串s从i到j闭区间切片是否回文
    // vector<vector<string> > res;
    // vector<string> tmp;
    // vector<vector<string>> partition(string s) {
    //     computePalindrome(s);
    //     backtracking(s, 0);
    //     return res;
    // }
    // // 计算回文
    // void computePalindrome(string s) {
    //     is_palindrome.resize(s.size(), vector<bool>(s.size(), false));
    //     for (int i = s.size()-1; i >= 0; i--) {
    //         for (int j = i; j < s.size(); j++) {
    //             if (i == j) {
    //                 is_palindrome[i][j] = true;
    //             } else if (j-i == 1) {
    //                 is_palindrome[i][j] = (s[i] == s[j]);
    //             } else {
    //                 is_palindrome[i][j] = (s[i] == s[j])&&is_palindrome[i+1][j-1];
    //             }
    //         }
    //     }
    //     return;
    // }
    // // 回溯
    // void backtracking(string s, int idx) {
    //     if (idx >= s.size()) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = idx; i < s.size(); i++) {
    //         if (is_palindrome[idx][i]) {
    //             tmp.push_back(s.substr(idx, i-idx+1));
    //         } else {
    //             continue;
    //         }
    //         backtracking(s, i+1);
    //         tmp.pop_back();
    //     }
    // }

    // 93. 复原 IP 地址
    // vector<string> res;
    // vector<string> restoreIpAddresses(string s) {
    //     backtracking(s, 0, 0);
    //     return res;
    // }
    // void backtracking(string s, int idx, int count) {
    //     if (idx > s.size()) {
    //         return;
    //     }
    //     if (count == 3) {
    //         if (isValid(s, idx, s.size()-1)) {
    //             res.push_back(s);
    //         }
    //         return;
    //     }
    //     for (int i = idx; i < s.size(); i++) {
    //         if (isValid(s, idx, i)) {
    //             s.insert(s.begin()+i+1, '.');
    //             count++;
    //             backtracking(s, i+2, count);
    //             count--;
    //             s.erase(s.begin()+i+1);
    //         } else {
    //             break;
    //         }
    //     }
    // }
    // bool isValid(string s, int st, int ed) {
    //     if (st > ed) {
    //         return false;
    //     }
    //     if (s[st] == '0' && st!=ed) {
    //         return false;
    //     }
    //     int num = 0;
    //     for (int i = st; i <= ed; i++) {
    //         if (s[i] > '9' || s[i] < '0') {
    //             return false;
    //         }
    //         num = num*10 + s[i]-'0';
    //         if (num > 255) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // 78. 子集
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     res.clear();
    //     tmp.clear();
    //     res.push_back(tmp);
    //     backtracking(nums, 0);
    //     return res;
    // }
    // void backtracking(vector<int> nums, int idx) {
    //     if (idx >= nums.size()) {
    //         return;
    //     }
    //     for (int i = idx; i < nums.size(); i++) {
    //         tmp.push_back(nums[i]);
    //         res.push_back(tmp);
    //         backtracking(nums, i+1);
    //         tmp.pop_back();
    //     }
    // }

    // 90. 子集 II
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     res.clear();
    //     tmp.clear();
    //     res.push_back(tmp);
    //     sort(nums.begin(), nums.end());
    //     backtracking(nums, 0);
    //     return res;
    // }
    // void backtracking(vector<int> nums, int idx) {
    //     for (int i = idx; i < nums.size(); i++) {
    //         if (i > idx && nums[i] == nums[i-1]) {
    //             continue;
    //         }
    //         tmp.push_back(nums[i]);
    //         res.push_back(tmp);
    //         backtracking(nums, i+1);
    //         tmp.pop_back();
    //     }
    // }

    // 491. 递增子序列
    // // 去重
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> findSubsequences(vector<int>& nums) {
    //     tmp.clear();
    //     res.clear();
    //     backtracking(nums, 0);
    //     return res;
    // }
    // void backtracking(vector<int> nums, int idx) {
    //     unordered_set<int> uset;
    //     for (int i = idx; i < nums.size(); i++) {
    //         if (uset.find(nums[i]) != uset.end()) {
    //             continue;
    //         }
    //         if (tmp.size() == 0 || nums[i] >= tmp[tmp.size()-1]) {
    //             tmp.push_back(nums[i]);
    //         } else {
    //             continue;
    //         }
    //         if (tmp.size() >= 2) {
    //             res.push_back(tmp);
    //         }
    //         uset.insert(nums[i]);
    //         backtracking(nums, i+1);
    //         tmp.pop_back();
    //     }
    // }

    // 46. 全排列
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<int> flag(nums.size(), 0);
    //     backtracking(nums, flag);
    //     return res;
    // }
    // void backtracking(vector<int> nums, vector<int> flag) {
    //     if (tmp.size() == nums.size()) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (flag[i]) {
    //             continue;
    //         }
    //         flag[i] = 1;
    //         tmp.push_back(nums[i]);
    //         backtracking(nums, flag);
    //         tmp.pop_back();
    //         flag[i] = 0;
    //     }
    // }

    // 47. 全排列 II
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<int> flag(nums.size(), 0);
    //     backtracking(nums, flag);
    //     return res;
    // }
    // void backtracking(vector<int> nums, vector<int> flag) {
    //     if (tmp.size() == nums.size()) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (i > 0 && nums[i] == nums[i-1] && flag[i-1] == 0) {
    //             continue;
    //         }
    //         if (!flag[i]) {
    //             flag[i] = 1;
    //             tmp.push_back(nums[i]);
    //             backtracking(nums, flag);
    //             tmp.pop_back();
    //             flag[i] = 0;
    //         }
    //     }
    // }
}
;

int main() {
    Solution solution;

    // 77. 组合
    // vector<vector<int> > res = solution.combine(4, 2);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 216. 组合总和 III
    // vector<vector<int> > res = solution.combinationSum3(4, 1);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 17. 电话号码的字母组合
    // string digits = "2";
    // vector<string> res = solution.letterCombinations(digits);
    // for (string s : res) {
    //     cout<<s<<" ";
    // }

    // 39. 组合总和
    // vector<int> candidates = {2};
    // vector<vector<int> > res = solution.combinationSum(candidates, 1);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 40. 组合总和 II
    // vector<int> candidates = {10,1,2,7,6,1,5};
    // vector<vector<int> > res = solution.combinationSum2(candidates, 8);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 131. 分割回文串
    // string s = "aaba";
    // vector<vector<string> > res = solution.partition(s);
    // for (vector<string> a : res) {
    //     for (string b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 93. 复原 IP 地址
    // string s = "25525511135";
    // vector<string> res = solution.restoreIpAddresses(s);
    // for (string s : res) {
    //     cout<<s<<endl;
    // }

    // 78. 子集
    // vector<int> nums = {0};
    // vector<vector<int> > res = solution.subsets(nums);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 90. 子集 II
    // vector<int> nums = {1,2,2};
    // vector<vector<int> > res = solution.subsetsWithDup(nums);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 491. 递增子序列
    // vector<int> nums = {1,2,3,1,1};
    // vector<vector<int> > res = solution.findSubsequences(nums);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 46. 全排列
    // vector<int> nums = {1,2,3};
    // vector<vector<int> > res = solution.permute(nums);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 47. 全排列 II
    // vector<int> nums = {1,1, 2};
    // vector<vector<int> > res = solution.permuteUnique(nums);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
}

