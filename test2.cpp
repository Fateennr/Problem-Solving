#include <bits/stdc++.h>
#include <vector>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr);                                                            \
  cout.tie(NULL);

#define SIZE 1000000000000001
#define MOD 1000000000 + 7
#define ll long long

using namespace std;

void precalculate() {}
void solve() {

  int n, sum = 0;
  cin >> n;

  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int inp;
    cin >> inp;

    arr.push_back(inp);
    sum ^= inp;
  }

  for (int i = 0; i < n; i++) {
    cout << (sum ^ arr[i]) << " ";
  }

  cout << "\n";

  //
  // cout << (3 ^ 5) << "\n";
}

int main() {

  fastIO;

  int t, caseno = 0;

  // cin >> t;
  t = 1;
  // precalculate();

  while (t--) {

    // fill(arr.begin(), narr.end(), 0);
    // cout << "Case " << ++caseno << ": ";

    solve();
  }
}
