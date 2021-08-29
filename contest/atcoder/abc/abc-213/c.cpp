#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll H, W, N;
  cin >> H >> W >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  map<ll, ll> amap;
  map<ll, ll> bmap;

  vector<ll> cpA;
  vector<ll> cpB;

  rep(i, 0, N) {
    cin >> A[i];
    cin >> B[i];
    if (!amap[A[i]]) {
      amap[A[i]]++;
      cpA.push_back(A[i]);
    }
    if (!bmap[B[i]]) {
      bmap[B[i]]++;
      cpB.push_back(B[i]);
    }
  }

  sort(cpA.begin(), cpA.end());
  sort(cpB.begin(), cpB.end());

  rep(i, 0, N) {
    auto aidp = lower_bound(cpA.begin(), cpA.end(), A[i]);
    auto aid = aidp - cpA.begin() + 1;
    auto bidp = lower_bound(cpB.begin(), cpB.end(), B[i]);
    auto bid = bidp - cpB.begin() + 1;
    cout << aid << " " << bid << endl;
  }
}