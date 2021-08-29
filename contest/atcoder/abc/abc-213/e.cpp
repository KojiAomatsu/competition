#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll inf = 1E9;
ll H, W;
vector<string> town(1100);
vector<vector<ll>> minways(1100, vector<ll>(1100, inf));
vector<vector<bool>> vis(1100, vector<bool>(1100, false));
vector<P> fours = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

set<P> nxt;

void dfs(P pt) {
  vis[pt.first][pt.second] = true;

  for (auto ele : fours) {
    P pnt = {pnt.first + ele.first, pnt.second + ele.second};
    if (vis[pnt.first][pnt.second]) {
      continue;
    }
    if (pnt.first >= 0 && pnt.first < H && pnt.second >= 0 && pnt.second < W) {
      if (town[pnt.first][pnt.second] == '.') {
        minways[pnt.first][pnt.second] = min(minways[pnt.first][pnt.second], minways[pt.first][pt.second]);
        dfs(pnt);
      } else {
        nxt.insert(pnt);
      }
    }
  }
  return;
}

int main() {
  cin >> H >> W;
  rep(i, 0, H) { cin >> town[i]; }
  set<P> rem;
  rep(i, 0, H) {
    rep(j, 0, W) { rem.insert({i, j}); }
  }

  dfs({0, 0});
}