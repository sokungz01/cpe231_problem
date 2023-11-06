#include <stdio.h>

int binarySearch(int *arr, int l, int r, int finder)
{

    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == finder)
            return mid;

        if (arr[mid] > finder)
            return binarySearch(arr, l, mid - 1, finder);

        return binarySearch(arr, mid + 1, r, finder);
    }

    return -1;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int L[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &L[i]);
    }

    for (int i = 0; i < k; i++)
    {
        int ki;
        scanf("%d", &ki);

        int index = binarySearch(L, 0, n - 1, ki);

        printf("%d\n", index);
    }

    return 0;
}
