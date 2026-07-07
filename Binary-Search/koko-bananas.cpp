#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * We binary search on the eating speed k.
 * Lowest possible speed: 1 banana/hour.
 * Highest possible speed: max pile size.
 * For each k, calculate how many hours it takes:
 * hours += ceil(pile / k)
 * In C++, we can do:
 * hours += (pile + k - 1) / k;
 * If hours <= h, then this speed works, so try a smaller speed.
 * Otherwise, the speed is too slow, so try a larger speed.
 * Time Complexity: O(n log(maxPile))
 * Space Complexity: O(1)
 */


using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
  int l = 1;
  int r = *max_element(piles.begin(), piles.end());
  int res = r;
  while (l <= r) {
    int k = (l + r) / 2;
    int time = 0;
    for (int p : piles) {
      time += ceil((float)p / k);
    }
    if (time <= h) {
      res = min(res, k);
      r = k - 1;
    } else {
      l = k + 1;
    }
  }
  return res;
}

int main() {
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  cout << minEatingSpeed(piles, h) << endl;
  return 0;
}
