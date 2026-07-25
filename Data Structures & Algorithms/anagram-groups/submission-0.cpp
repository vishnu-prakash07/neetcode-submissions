class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        string key;
        for (string s:strs){
            key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);//key-->strings
        }

        vector<vector<string>> ans;
        for (auto p: mp){//p-->(key,value)==> p.first-- key and p.second-- string..!
            ans.push_back(p.second);
        }
        return ans;
    }
};
