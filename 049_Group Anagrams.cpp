class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>m;
        for(auto s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        for(auto x : m) {
            ans.push_back(x.second);
        }
        return ans;
    }
};