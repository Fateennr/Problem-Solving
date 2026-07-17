#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        deque<string> arr;
        for(int i=0;i<path.size();i++){
            if(path[i] != '/'){
                token += path[i];
            }
            else if(token == ".." ){
                if(!arr.empty()) arr.pop_back();
                token="";
            }
            else if(token == "."){
                token = "";
            }
            else if(path[i] == '/' && token != ""){
                cout << token << "\n";
                arr.push_back(token);
                token = "";
            }
            // cout << token << "\n";
        }

        if(token != "" && token != "." && token != ".."){
            arr.push_back(token);
        }
        else if(token == ".." ){
            if(!arr.empty()) arr.pop_back();
            token="";
        }

        if(arr.empty()) return "/";

        string ans = "";
        while(!arr.empty()){
            // cout << arr.front() << "\n";
            if(arr.front() != "."){
                ans += '/';
                ans += arr.front();
            }
            if(!arr.empty()) arr.pop_front();
        }

        return ans;
    }

};

int main() {
    // Write C++ code here
    
    Solution s;

    cout << s.simplifyPath("/home/");
    

    return 0;
}