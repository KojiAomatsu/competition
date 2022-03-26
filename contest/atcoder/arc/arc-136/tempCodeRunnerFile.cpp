#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  map<int, int> mp;
  rep(i, 0, N) {
    cin >> A[i];
    mp[A[i]]++;
  }
  rep(i, 0, N) {
    cin >> B[i];
    mp[B[i]]--;
  }
  for (auto m : mp) {
    if (m.second != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (mp.size() < N) {
    cout << "Yes" << endl;
    return 0;
  }

  map<int, int> tar;
  map<int, int> cur;
  rep(i, 0, N) {
    tar[B[i]] = i;
    cur[A[i]] = i;
  }
  rep(i, 0, N) {
    int idx = cur[B[i]];
    int dif = idx - i;
    if (dif == 0) continue;
    if (dif % 2 == 0) {
      for (int j = idx - 1; j >= i; j--) {
        A[j + 1] = A[j];
        cur[A[j]] = j + 1;
      }
      A[i] = B[i];
      cur[A[i]] = i;
    } else {
      for (int j = idx - 1; j >= i + 1; j--) {
        A[j + 1] = A[j];
        cur[A[j]] = j + 1;
      }
      A[i + 1] = B[i];
      cur[A[i + 1]] = i + 1;

      if (i + 2 >= N) continue;
      A[i + 1] = A[i + 2];
      A[i + 2] = A[i];
      A[i] = B[i];
    }
  }
  cout << (A == B ? "Yes" : "No") << endl;
}