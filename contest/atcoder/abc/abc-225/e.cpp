#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// p/q 分数のstruct
struct fraction {
  ll p, q;
  fraction(ll pi, ll qi) : p(pi), q(qi) {}
  bool operator<(const fraction &other) const { return p * other.q < other.p * q; }
  bool operator<=(const fraction &other) const { return p * other.q <= other.p * q; }
};

using P = pair<fraction, fraction>;

int main() {
  ll N;
  cin >> N;
  vector<P> arcs;
  rep(i, 0, N) {
    ll xi, yi;
    cin >> xi >> yi;
    P a = {fraction(yi - 1, xi), fraction(yi, xi - 1)};
    arcs.push_back(a);
  }
  sort(arcs.begin(), arcs.end(), [](P a, P b) { return a.second < b.second; });

  ll cnt = 0;
  fraction cur = fraction(0, 1);
  rep(i, 0, arcs.size()) {
    if (cur <= arcs[i].first) {
      cnt++;
      cur = arcs[i].second;
    }
  }
  cout << cnt << endl;
}