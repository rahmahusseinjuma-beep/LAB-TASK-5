#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax getMinMax(int arr[], int low, int high) {
    struct MinMax result, left, right;
    int mid;

    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);
    
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[50];  
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct MinMax ans = getMinMax(arr, 0, n - 1);

    printf("Minimum element = %d\n", ans.min);
    printf("Maximum element = %d\n", ans.max);

    return 0;
}
