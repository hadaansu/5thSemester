//insertion sort
#include <stdio.h>

int main()
{
    int a[10], n, i, j, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nInitial Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Insertion Sort with tracing
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        // Tracing step
        printf("\nAfter Pass %d: ", i);
        for(j = 0; j < n; j++)
            printf("%d ", a[j]);
    }

    printf("\n\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
