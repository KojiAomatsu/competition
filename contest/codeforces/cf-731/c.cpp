#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll k, ll n, ll m, vector<ll> &A, vector<ll> &B) {
  vector<ll> ans;
  ll ap = 0;
  ll bp = 0;
  while (!(ap == n && bp == m)) {
    if (ap == n) {
      while (bp != m) {
        if (B[bp] <= k) {
          ans.push_back(B[bp]);
          if (B[bp] == 0) k++;
          bp++;
        } else {
          cout << -1 << endl;
          return;
        }
      }
    }
    if (bp == m) {
      while (ap != n) {
        if (A[ap] <= k) {
          ans.push_back(A[ap]);
          if (A[ap] == 0) k++;
          ap++;
        } else {
          cout << -1 << endl;
          return;
        }
      }
    }

    if (ap == n && bp == m) {
      break;
    }

    if (ap != n && A[ap] <= k) {
      ans.push_back(A[ap]);
      if (A[ap] == 0) k++;
      ap++;
    } else if (bp != m && B[bp] <= k) {
      ans.push_back(B[bp]);
      if (B[bp] == 0) k++;
      bp++;
    } else {
      cout << -1 << endl;
      return;
    }
  }

  for (auto item : ans) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> A(n);
    rep(j, 0, n) { cin >> A[j]; }
    vector<ll> B(m);
    rep(j, 0, m) { cin >> B[j]; }
    solve(k, n, m, A, B);
  }
}