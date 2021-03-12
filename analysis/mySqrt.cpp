#include <algorithm>
#include <array>
#include <iostream>
#include <math.h>
#include <sys/time.h>
#include <vector>

using namespace std;

unsigned ss[16] = {
    4,
    9,
    25,
    81,
    17 * 17,
    33 * 33,
    65 * 65,
    129 * 129,
    257 * 257,
    513 * 513,
    1025 * 1025,
    2049 * 2049,
    4097 * 4097,
    8193 * 8193,
    16385 * 16385,
    32769 * 32769,
};

vector<int> mysqrt(unsigned c) {
  if (c <= 1)
    return vector<int>{static_cast<int>(c), 0};
  unsigned *temp = upper_bound(ss, ss + 16, c);
  unsigned s = temp - ss;
  unsigned x0 = 1 << s;
  unsigned x1 = (x0 + (c >> s)) >> 1;
  int count = 0;
  while (x1 < x0) {
    x0 = x1;
    x1 = (x0 + c / x0) >> 1;
    count++;
  }
  return vector<int>{static_cast<int>(x1), count};
}

vector<int> isqrt2(unsigned x) {
  unsigned a = 1;
  unsigned b = (x >> 5) + 8;
  int count = 0;
  if (b > 65535)
    b = 65535;
  do {
    int m = (a + b) >> 1;
    if (m * m > x)
      b = m - 1;
    else
      a = m + 1;
    count++;
  } while (b >= a);
  return vector<int>{static_cast<int>(a - 1), count};
}

vector<int> isqrt3(unsigned x) {
  if (x <= 1)
    return vector<int>{0, 0};
  int x1 = x - 1;
  int s = 1;
  int count = 0;
  if (x1 > 65535) {
    s += 8;
    x1 >> 16;
  }
  if (x1 > 255) {
    s += 4;
    x1 >> 8;
  }
  if (x1 > 15) {
    s += 2;
    x1 >> 4;
  }
  if (x1 > 3) {
    s += 1;
  }
  int x0 = 1 << s;
  x1 = (x0 + (x >> s)) >> 1;
  while (x1 < x0) {
    x0 = x1;
    x1 = (x0 + x / x0) >> 1;
    count++;
  }
  return vector<int>{x1, count};
}

vector<int> isqrt4(unsigned long M) {
  unsigned int N, i;
  unsigned long tmp, ttp;
  int count = 0;
  if (M == 0) {
    return vector<int>{0, 0};
  }
  N = 0;
  tmp = (M >> 30);
  M <<= 2;
  if (tmp > 1) {
    N++;
    count++;
    tmp -= N;
  }

  for (i = 15; i > 0; i--) {
    N <<= 1;
    tmp <<= 2;
    tmp += (M >> 30);

    ttp = N;
    ttp = (ttp << 1) + 1;
    M <<= 2;
    if (tmp >= ttp) {
      tmp -= ttp;
      N++;
    }
  }
  return vector<int>{static_cast<int>(N), count};
}

double ave(unsigned nums) {
  unsigned high = 1 << 31;
  return nums / high;
}

int main(void) {
  unsigned low = 1, high = 1 << 31;
  unsigned long long cnt = 0;

  struct timeval t1, t2;
  double timeuse;

  // my_isqrt
  gettimeofday(&t1, NULL);
  for (int i = low; i < high; i++) {
    cnt += mysqrt(i)[1];
  }
  cout << ave(cnt) << endl;
  gettimeofday(&t2, NULL);
  timeuse =
      (t2.tv_sec - t1.tv_sec) + (double)(t2.tv_usec - t1.tv_usec) / 1000000.0;
  cout << "time = " << timeuse << endl;

  // isqrt2
  cnt = 0;
  gettimeofday(&t1, NULL);
  for (int i = low; i < high; i++) {
    cnt += isqrt2(i)[1];
  }
  cout << ave(cnt) << endl;
  gettimeofday(&t2, NULL);
  timeuse =
      (t2.tv_sec - t1.tv_sec) + (double)(t2.tv_usec - t1.tv_usec) / 1000000.0;
  cout << "time = " << timeuse << endl;

  // isqrt3
  cnt = 0;
  gettimeofday(&t1, NULL);
  for (int i = low; i < high; i++) {
    cnt += isqrt3(i)[1];
  }
  cout << ave(cnt) << endl;
  gettimeofday(&t2, NULL);
  timeuse =
      (t2.tv_sec - t1.tv_sec) + (double)(t2.tv_usec - t1.tv_usec) / 1000000.0;
  cout << "time = " << timeuse << endl;

  // isqrt4
  cnt = 0;
  gettimeofday(&t1, NULL);
  for (int i = low; i < high; i++) {
    cnt += isqrt4(i)[1];
  }
  cout << ave(cnt) << endl;
  gettimeofday(&t2, NULL);
  timeuse =
      (t2.tv_sec - t1.tv_sec) + (double)(t2.tv_usec - t1.tv_usec) / 1000000.0;
  cout << "time = " << timeuse << endl;

  // sqrt
  gettimeofday(&t1, NULL);
  for (int i = low; i < high; i++) {
    sqrt(i);
  }
  gettimeofday(&t2, NULL);
  timeuse =
      (t2.tv_sec - t1.tv_sec) + (double)(t2.tv_usec - t1.tv_usec) / 1000000.0;
  cout << "time = " << timeuse << endl;

  return 0;
}
