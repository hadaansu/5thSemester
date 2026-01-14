// selection sort
#include <stdio.h>

int main()
{
    int a[10], n, i, j, min, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nInitial Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Selection Sort with tracing
    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        // Swap
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        // Tracing step
        printf("\nAfter Pass %d: ", i + 1);
        for(j = 0; j < n; j++)
            printf("%d ", a[j]);
    }

    printf("\n\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
