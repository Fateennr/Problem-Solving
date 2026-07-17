#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void traverse(int m, int n, vector<vector<bool>> & visited , vector<vector<char>> & grid, int sz_row, int sz_col){
        // cout << m << " " << n << "\n";
        // cout << visited[m][n] << "\n";
        if(visited[m][n] == true || grid[m][n] == '0') return;

        visited[m][n] = true;

        
        if(m+1 != sz_row) traverse(m+1, n, visited, grid, sz_row, sz_col);
        if(m-1 != -1) traverse(m-1, n, visited,grid, sz_row, sz_col);
        if(n+1 != sz_col) traverse(m, n+1, visited,grid, sz_row, sz_col);
        if(n-1 != -1) traverse(m, n-1, visited,grid, sz_row, sz_col);

        return;

    }

    int numIslands(vector<vector<char>>& grid) {
        int val = 0;
        int m = grid.size();
        int n = grid[0].size();
        // cout << "g" << m << " " << n << "\n";

        vector<vector<bool>>visited(m, vector<bool>(n, false));
        // for(auto c : visited){
        //     for(auto d : c){
        //         cout << d << " ";
        //     }
        //     cout << "\n";
        // }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    // cout << i << " " << j << "\n";
                    traverse(i, j, visited, grid, m, n);
                    val++;
                }
            }
        }


        return val;
    }
};

int main() {
    // Write C++ code here
    
    Solution s;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    
    cout << s.numIslands(grid);
    

    return 0;
}