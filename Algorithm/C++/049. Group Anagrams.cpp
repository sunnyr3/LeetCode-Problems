// Problem is from: https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<stirng>> anagrams;
        for (auto m : mp) {
            vector<string> temp(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
}