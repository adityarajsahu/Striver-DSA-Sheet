#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m) {
  if(m == 1 || n == 1) {
    return m;
  }

  int s = 2, e = m - 1, mid;
  while(s <= e) {
    mid = s + (e - s) / 2;
    if(pow(mid, n) == m) {
      return mid;
    } else if(pow(mid, n) > m) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return -1;
}