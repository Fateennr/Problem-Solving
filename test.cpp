#include <bits/stdc++.h>
using namespace std;

#define SIZE 100000
#define fastio                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

void pre() { fastio; }

vector<vector<int>> graph(SIZE + 5);
vector<int> dp(SIZE + 5);

vector<bool> visited(SIZE + 5);

void dfs(int node) {
  visited[node] = true;

  for (int i = 0; i < graph[node].size(); i++) {
    if (!visited[graph[node][i]]) {
      dfs(graph[node][i]);
    }

    dp[node] = max(dp[node], 1 + dp[graph[node][i]]);
  }
}

int findlongestpath(int n) {
  for (int i = 1; i <= n; i++) {
    // cout << "invoked" << "\n";
    if (!visited[i])
      dfs(i);
  }

  // dfs(1);

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }

  return ans;
}

int main() {
  pre();

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
  }

  cout << findlongestpath(N) << "\n";

  return 0;
}
