#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int>ans;

        // int dir[] = {1, 2, 3, 4};
        int direction = 0;
        int i=0, j=0;

        // cout << m << " " << n << "\n";

        if((n==1) || ( m == 1 && n>1 ) ){
            for(auto c : matrix){
                for(auto g : c){
                    cout << g << "\n";
                    ans.push_back(g);
                }
            }

            return ans;
        }


        while(1){

            if(visited[i][j] == false) {
                visited[i][j] = true;
                ans.push_back(matrix[i][j]);

                // for(auto c : visited){
                //     for(auto g : c ){
                //         cout << g << " ";
                //     }
                //     cout << "\n";
                // }
                // cout << i << " " << j << "\n";
            }
            else{
                // cout << i << " " << j << "\n";
                break;
            }

            if(direction == 0){
                j = min(j+1,n-1);
                if(j == n-1 || visited[i][j+1] == true) direction = (direction + 1)%4;
            }
            else if(direction == 1){
                i = min(i+1, m-1);
                if(i == m-1 || visited[i+1][j] == true) direction = (direction+1)%4;
            }
            else if(direction == 2){
                j = max(j-1, 0);

                if(j == 0 || visited[i][j-1] == true) direction = (direction+1)%4;
            }
            else if(direction == 3){
                i = max(i-1, 0);
                if(i == 0 || visited[i-1][j] == true) direction = (direction+1)%4;
            }
        }

        // for(auto c : ans) cout << c << " ";
        // cout << "\n";
        
        return ans;
        
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1,2},
        {5,4},
        {0,1},

    } ;

    Solution s;
    vector<int> ans = s.spiralOrder(matrix);
    for(auto c : ans){
        cout << c << " ";
    }
    cout <<"\n";

    
    return 0;
}