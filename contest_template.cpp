#include <bits/stdc++.h>
#include <vector>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr);                                                            \
  cout.tie(NULL);

#define SIZE 1000000
#define MOD 1000000000 + 7

using namespace std;

// graphs

// vector<vector<int>> graph(SIZE + 5);
// vector<int> dp(SIZE + 5);

// vector<bool> visited(SIZE + 5);

void dfs(int node, vector<vector<int>> graph, vector<int> visited,
         vector<int> dp) {
  visited[node] = true;

  for (int i = 0; i < graph[node].size(); i++) {
    if (!visited[graph[node][i]]) {
      dfs(graph[node][i], graph, visited, dp);
    }

    dp[node] = max(dp[node], 1 + dp[graph[node][i]]);
  }
}

vector<vector<int>> grid;
vector<vector<int>> dp;

// vector<double> logarr(1000000 + 5);

void precalculate() {}
void solve() {

  int H, W;

  cin >> H >> W;

  grid = vector<vector<int>>(H, vector<int>(W));
  dp = vector<vector<int>>(H, vector<int>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char inp;
      cin >> inp;

      grid[i][j] = inp;
    }
  }

  dp[0][0] = 1;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i + j == 0 && grid[i][j] == '#')
        continue;

      if (!i) // if first row we can only go previous column
      {
        dp[i][j] = dp[i][j - 1];
      } else if (!j) // first column we can only go previous row
      {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] =
            (int)((long long)dp[i - 1][j] + (long long)dp[i][j - 1]) % MOD;
      }
    }
  }

  cout << dp[H - 1][W - 1] << "\n";
}

int main() {

  fastIO;

  int t, caseno = 0;

  cin >> t;
  // t = 1;
  // precalculate();

  while (t--) {

    // fill(arr.begin(), narr.end(), 0);
    // cout << "Case " << ++caseno << ": ";

    solve();
  }
}
