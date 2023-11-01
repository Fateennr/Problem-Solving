#include <bits/stdc++.h>

using namespace std;

string dp[3005][3005];

string func(int i, int j, string &text1, string &text2) {
    if (i < 0 || j < 0)
        return ""; // Base case: reached the end of one of the strings.

    if (dp[i][j] != "")
        return dp[i][j]; // Return memoized result.

    string result;
    if (text1[i] == text2[j]) {
        result = func(i - 1, j - 1, text1, text2) + text1[i];
    } else {
        string lcs1 = func(i, j - 1, text1, text2);
        string lcs2 = func(i - 1, j, text1, text2);
        result = (lcs1.length() > lcs2.length()) ? lcs1 : lcs2;
    }

    dp[i][j] = result; // Store the result in dp to avoid redundant computations.
    return result;
}

string longestCommonSubsequence(string text1, string text2) {
    memset(dp, "", sizeof(dp));
    return func(text1.size() - 1, text2.size() - 1, text1, text2);
}

int main() {
    string result = longestCommonSubsequence("abcde", "ace");
    cout << "Longest Common Subsequence: " << result << endl;
    return 0;
}
