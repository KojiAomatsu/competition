#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;

  ll root = 1;
  cout << "? " << 1 << endl;
  cout.flush();

  map<ll, ll> vis;
  map<ll, vector<ll>> children;
  map<ll, vector<ll>> depth;
  rep(i, 0, N) {
    ll num;
    cin >> num;
    depth[num].push_back(i + 1);
    if (num == 1) {
      children[1].push_back(i + 1);
    }
  }

  ll c_even = 0;
  ll c_odd = 0;
  ll max;
  rep(i, 1, N) {
    ll cnt = depth[i].size();
    if (cnt > 0) {
      max = i;
    }
    if (i % 2 == 0) {
      c_even += cnt;
    } else {
      c_odd += cnt;
    }
  }

  ll start = max;
  if (c_odd > c_even) {
    if (start % 2 == 1) {
      start--;
    }
  } else if (c_odd < c_even) {
    if (start % 2 == 0) {
      start--;
    }
  }

  while (start > 0) {
    for (auto node : depth[start]) {
      if (vis.count(node) > 0)
        continue;
      cout << "? " << node << endl;
      cout.flush();

      auto chi_cand = depth[node + 1];
      rep(i, 0, N) {
        ll num;
        cin >> num;
        if (num == 1) {
          auto res = find(chi_cand.begin(), chi_cand.end(), i + 1);
          if (res == chi_cand.end()) {
            // i + 1 is parent of node.
            vis[node] = i + 1;
            if (i + 1 != 1) {
              children[i + 1].push_back(node);
            }
          } else {
            // i + 1 is child of node.
            vis[i + 1] = node;
            children[node].push_back(i + 1);
          }
        }
      }
    }
    start -= 2;
  }

  cout << "!" << endl;
  for (auto child : children) {
    for (auto ele : child.second) {
      cout << child.first << " " << ele << endl;
    }
  }
}
