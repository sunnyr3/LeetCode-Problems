// Problem is from: https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        vector<vector<string> > ret;
        
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            ret.push_back(it->second);
        }
        
        return ret;
    }
};