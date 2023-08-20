#include <stdio.h>

int main(int argc, char *a[]) {
    // Read input values
    int n, x;
    scanf("%d%d", &n, &x);
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // Binary search for minimum energy level P
    long long int low = 1;
    long long int high = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > high) {
            high = arr[i];
        }
    }
    long long int result = -1;
    while (low <= high) {
        long long int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= mid) {
                count++;
            }
        }
        if (count >= x) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Print result
    printf("%lld\n", result);

    return 0;
}
