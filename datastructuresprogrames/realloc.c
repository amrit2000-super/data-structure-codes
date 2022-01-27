#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int* ptr;
    int n, i,n1;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    ptr = (int*)calloc(n, sizeof(int));
 
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated\n");
        printf("Enter the new size of the array:\n");
        scanf("%d",&n1);
        ptr = realloc(ptr, n * sizeof(int));
        printf("Memory successfully re-allocated using realloc.\n");
 
        for (i = 0; i < n1; i++) {
            ptr[i] = i + 1;
        }
 
        printf("The elements of the array are: ");
        for (i = 0; i < n1; i++) {
            printf("%d ", ptr[i]);
        }
    }
 
    return 0;
}
