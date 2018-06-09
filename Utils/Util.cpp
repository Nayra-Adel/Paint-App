#include "Util.h"

int Util :: round (double x){

    return (int)(x + 0.5);
}

void Util :: Swap(int &x, int &y){

    int temp = x;
    x = y;
    y = temp;
}

int Util :: sqrt(int x){

    if (x == 0 || x == 1) { return x; }

    // Do Binary Search for (sqrt(x))
    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // If x is a perfect square
        if (mid*mid == x) { return mid; }

        if (mid * mid < x){

            start = mid + 1;
            ans = mid;
        }
        else { end = mid - 1; }
    }
    return ans;
}
