#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row[10][10];
        int col[10][10];
        int square[10][10];

        for(int i =0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int index = charConvert(board[i][j]);
                // int squareIndex = locateSquare(i+1,j+1);
                int squareIndex = (i/3) * 3 + (j/3);

                if(index == 0) continue;

                cout << row[i][j] << "\n";

                if(row[i][index] >= 1) return false;
                else row[i][index]++;

                if(col[j][index] >= 1) return false;
                else col[j][index]++;

                if(square[squareIndex][index] >=1 ) return false;
                else square[squareIndex][index]++;
            }
        }

        return true;
    }

    // int locateSquare(int r, int c){
    //     cout << r << " " << c << "\n";
    //     if(r >= 1 && r<= 3 && c>=1 && c<=3) return 1;
    //     else if(r >= 1 && r<= 3 && c>=4 && c<=6) return 2;
    //     else if(r >= 1 && r<= 3 && c>=7 && c<=9) return 3;
    //     else if(r >= 4 && r<= 6 && c>=1 && c<=3) return 4;
    //     else if(r >= 4 && r<= 6 && c>=4 && c<=6) return 5;
    //     else if(r >= 4 && r<= 6 && c>=7 && c<=9) return 6;
    //     else if(r >= 7 && r<= 9 && c>=1 && c<=3) return 7;
    //     else if(r >= 7 && r<= 9 && c>=4 && c<=6) return 8;
    //     else if(r >= 7 && r<= 9 && c>=7 && c<=9) return 9;
    //     else return -1;
    // }

    int charConvert(char c){
        cout << c << "\n";
        if(c == '1') return 1;
        else if(c == '2') return 2;
        else if(c == '3') return 3;
        else if(c == '4') return 4;
        else if(c == '5') return 5;
        else if(c == '6') return 6;
        else if(c == '7') return 7;
        else if(c == '8') return 8;
        else if(c == '9') return 9;
        else  return 0;
    }
};

int main() {
    // Write C++ code here
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    cout << s.isValidSudoku(board);
    

    return 0;
}