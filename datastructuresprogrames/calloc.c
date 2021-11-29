#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int* ptr;
    int n,n1,i;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
 
    ptr = (int*)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated using calloc.\n");
 
        for (i = 0; i < n; i++) {
            ptr[i] = i + 1;
        }
        
 
        printf("The elements of the array are:\n ");
        for (i = 0; i < n; i++) {
            printf("%d ", ptr[i]);
        }
        }
        return 0;
}