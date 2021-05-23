#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b);
int gcd(vector<int> l);

int main() {
  int N;
  cin >> N;
  vector<int> li(N);
  for (int i = 0; i < N; i++) {
    cin >> li[i];
  }

  int g;
  g = gcd(li);

  int couter = 0;
  while (g % 2 == 0) {
    g = g / 2;
    couter++;
  }
  cout << couter << endl;
}

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int gcd(vector<int> li) {
  int n = li.size();
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return li[0];
  }
  int a;
  a = gcd(li[0], li[1]);
  if (n == 2) {
    return a;
  }

  for (int i = 2; i < n; i++) {
    a = gcd(a, li[i]);
  }
  return a;
}