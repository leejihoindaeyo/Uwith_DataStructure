#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int lowerbound(int arr[], int size, int target)
{
    int lo = 0, hi = size - 1;
    while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;             
        }
    return lo;
}
int upperbound(int arr[], int size, int target)
{
    int lo = 0, hi = size - 1;
    while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] <= target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    return lo;
}
int main() 
{
    int n = 0, arr1[500000] = {0}, m = 0, arr2[500000] = {0}, count[500000] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
            scanf("%d", &arr1[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);
    qsort(arr1, n, sizeof(int), compare);
    for(int i = 0; i < m; i++)
        count[i] = upperbound(arr1, n, arr2[i]) - lowerbound(arr1, n , arr2[i]);
    for(int i = 0 ; i < m; i++)
        printf("%d ", count[i]);
    return 0;
}