#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  set<int> se;
  rep(i, 0, N) {
    int Ai;
    cin >> Ai;
    se.insert(Ai);
  }
  cout << se.size() << endl;
}