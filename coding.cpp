#include <bits/stdc++.h>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr);                                                            \
  cout.tie(NULL);

#define SIZE 200005
#define MOD 1000000000 + 7
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define min_priority_queue                                                     \
  priority_queue<pll, std::vector<pll>, std::greater<pll>>
using namespace std;

#define desc_sort_paired(begin_ptr, end_ptr)                                   \
  sort(begin_ptr, end_ptr, [](const pii &a, const pii &b) {                    \
    if (a.first != b.first)                                                    \
      return a.first > b.first;                                                \
    return a.second < b.second;                                                \
  })

void precalculate() {}

void solve() {
  int n, count = 1, ind = 1, flag = 0;
  cin >> n;

  int inp;
  cin >> inp;
  vector<int> ans;

  if (n == 1) {
    cout << -1 << "\n";
    return;
  }

  for (int i = 2; i <= n; i++) {
    int j;
    cin >> j;

    if (inp == j) {
      count++;
      // cout << "inp is " << inp << " " << "count " << count << "\n";
    } else {

      if (flag == 0) {

        if (count == 1) {
          flag = 1;
          continue;
        }

        ans.push_back(ind + count - 1);

        for (int i = ind; i < ind + count - 1; i++) {
          ans.push_back(i);
        }

        count = 1;
        ind = i;
        inp = j;
      }
    }
  }

  if (flag == 0) {

    if (count == 1) {
      flag = 1;
    }
    ans.push_back(ind + count - 1);

    for (int i = ind; i < ind + count - 1; i++) {
      ans.push_back(i);
    }
  }

  if (flag) {
    cout << -1 << "\n";
  } else {
    for (auto c : ans) {
      cout << c << " ";
    }

    cout << "\n";
  }
}

int main() {
  fastIO;

  int t, caseno = 0;

  cin >> t;
  // t = 1;
  //  precalculate();

  while (t--) {

    // fill(arr.begin(), narr.end(), 0);
    // cout << "Case " << ++caseno << ": ";

    solve();
  }
}
