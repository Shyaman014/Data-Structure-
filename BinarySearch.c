#include <stdio.h>

int main()
{
    int i, low, high, mid, n, item, array[100];

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers (in sorted order)\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Enter value to find\n");
    scanf("%d", &item);

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high) {
        if (array[mid] < item)
            low = mid + 1;
        else if (array[mid] == item) {
            printf("%d found at location %d.\n", item, mid + 1);
            break;
        } else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    if (low > high)
        printf("Not found! %d isn't present in the list.\n", item);

    return 0;
}
