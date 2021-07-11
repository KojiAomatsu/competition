#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<ll> nims(220000);
vector<vector<ll>> edges(220000);
bool vis[220000];
ll par[220000];

int main() {
  ll N;
  cin >> N;
  vector<string> s(N);
  rep(i, 0, N) { cin >> s[i]; }
  map<string, vector<ll>> pres;
  map<string, vector<ll>> poss;
  rep(i, 0, N) {
    string pre = s[i].substr(0, 3);
    pres[pre].push_back(i);
    string pos = s[i].substr(s[i].size() - 3, 3);
    poss[pos].push_back(i);
    for (auto wor : pres[pos]) {
      edges[i].push_back(wor);
    }
    if (pre == pos) continue;
    for (auto wor : poss[pre]) {
      edges[wor].push_back(i);
    }
  }
  rep(i, 0, N) {
    if (edges[i].size() == 0) {
      nims[i] = 0;
    } else {
      nims[i] = -1;
    }
  }

  rep(i, 0, N) {
    if (nims[i] == 0) {
      cout << "Takahashi" << endl;
      return 0;
    } else if (nims[i] == -1) {
      cout << "Draw" << endl;
      return 0;
    } else {
      cout << "Aoki" << endl;
      return 0;
    }
  }
}