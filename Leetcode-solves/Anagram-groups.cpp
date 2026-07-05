#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string,string>> library;
        for(int i=0;i<strs.size();i++){
            string gg = "00000000000000000000000000";

            for(int j=0; j< strs[i].size();j++){
                gg[strs[i][j]-'a']++;
            }
            library.push_back({gg, strs[i]});
        }

        
        sort(library.begin(), library.end(), [](pair<string,string> a, pair<string,string> b){
            return a.first < b.first;
        });

        int j=0;
        string compare = library[0].first;
        ans.push_back({library[0].second});

        for(int i=1;i<library.size();i++){
            if(library[i].first == compare){
                ans[j].push_back(library[i].second);
            }
            else{
                j++;
                compare = library[i].first;
                ans.push_back({library[i].second});
            }
        }

        return ans;
    }
};

int main(){
    Solution s;

    vector<string> strs = {"act","pots","tops","cat","stop","hat"};

    s.groupAnagrams(strs);


    return 0;
}