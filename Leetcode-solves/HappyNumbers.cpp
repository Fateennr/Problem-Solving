#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> arr= {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
        unordered_set<int> storage;
        int score;

        while(n > 1){
            int val = n;
            score = 0;
            while(val > 0){
                int pushval = val%10;
                score += arr[pushval];
                val /= 10;
            }

            if(storage.find(score) == storage.end()){
                storage.insert(score);
                n = score;
            }
            else{
                return false;
            }
        }

        return true;
    }
};


int main() {
    // Write C++ code here
    
    Solution s;
    cout << s.isHappy(2);
    

    return 0;
}