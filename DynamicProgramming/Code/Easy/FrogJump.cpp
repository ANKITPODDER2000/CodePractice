#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &h){
  // if(n <= 1) return 0;
  // else if(n == 2) return abs(h[1] - h[0]);

  // return min(
  //     abs(h[n-1] - h[n-2]) + frogJump(n-1, h),
  //     abs(h[n-1] - h[n-3]) + frogJump(n-2, h)
  // );

    if(n <= 1) return 0;
    else if(n == 2) return abs(h[1] - h[0]);

    int a = 0, b = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++){
        int temp_a = a;
        a = b;
        b = min(
            abs(h[i] - h[i-1]) + b,
            abs(h[i] - h[i-2]) + temp_a
        );
    }
    return b;
}