#include<stdio.h>
#include<limits.h>

int maximum(int a,int b,int c){
	if(a>=b && a>=c) return a;
	if(b>=a && b>=c) return b;
	return c;
}

struct Subarray{
	int total;
	int start;
	int end;
};

struct Subarray findCombineSum(int arr[], int low, int mid, int high){
	int sum = 0;
	int best_leftSum = INT_MIN; 
	int best_rightSum = INT_MIN;
	int best_leftIndex = mid; 
	int best_rightIndex = mid; 
	
	for(int i=mid; i>=low; i--){
		sum+=arr[i];
		if(sum>best_leftSum){
			best_leftSum = sum;
			best_leftIndex = i;
		}
	}
	
	sum = 0;
	for(int j=mid+1; j<=high; j++){
		sum+=arr[j];
		if(sum>best_rightSum){
			best_rightSum = sum;
			best_rightIndex = j;
		}	
	}
	
	struct Subarray combine;
	combine.total = best_leftSum + best_rightSum;
	combine.start = best_leftIndex;
	combine.end = best_rightIndex;
	return combine;
}

struct Subarray solveMaxSubarray(int arr[], int low, int high){
	if(low == high){
		struct Subarray base = {arr[low],low,low};
		return base;
	}
	int mid = (low+high)/2;
	
	struct Subarray left = solveMaxSubarray(arr,low,mid);
	struct Subarray right = solveMaxSubarray(arr,mid+1,high);
	struct Subarray combine = findCombineSum(arr,low,mid,high);
	
	if (left.total>=right.total && left.total>=combine.total)
	return left;
	else if(right.total>=left.total && right.total>=combine.total)
	return right;
	else
	return combine;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  
    }

    struct Subarray answer = solveMaxSubarray(arr, 0, n - 1);

    printf("\nMaximum Subarray elements: ");
    for (int i = answer.start; i <= answer.end; i++) {
        printf("%d ", arr[i]);  
    }

    printf("\nMaximum Subarray sum = %d\n", answer.total);
       return 0;
}
