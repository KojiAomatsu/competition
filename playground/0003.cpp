#include <bits/stdc++.h>
using namespace std;

int main() {
  int num_o = 0;
  int num_q = 0;

  string s;
  cin >> s;
  for (int i = 0; i < 10; i++) {
    char c = s[i];
    if (c == 'o')
      num_o++;
    if (c == '?')
      num_q++;
  }

  int result = 0;
  if (num_o + num_q == 0) {
    result = 0;
  } else if (num_o == 4) {
    result = 24;
  } else if (num_o == 3) {
    result = 12 * 3;
    if (num_q > 0) {
      result += num_q * 24;
    }
  } else if (num_o == 2) {
    result = 4 + 6 + 4;
    if (num_q > 0) {
      result += num_q * 12 * 3;
      if (num_q > 1) {
        int pat = num_q * (num_q - 1) / 2;
        result += pat * 24;
      }
    }
  } else if (num_o == 1) {
    result = 1;
    if (num_q > 0) {
      result += num_q * 14;
      if (num_q > 1) {
        int pat = num_q * (num_q - 1) / 2;
        result += pat * 36;
        if (num_q > 2) {
          int pat = num_q * (num_q - 1) * (num_q - 2) / 6;
          result += pat * 24;
        }
      }
    }
  } else if (num_o == 0) {
    result = num_q * 1 + num_q * (num_q - 1) / 2 * 14 +
             num_q * (num_q - 1) * (num_q - 2) / 6 * 12 * 3 +
             num_q * (num_q - 1) * (num_q - 2) * (num_q - 3);
  }
  cout << result << endl;
}