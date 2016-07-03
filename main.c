#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_subset(int *subset, int size_subset)
{
    int i;
    
    printf("[*] ");
    for (i = 0; i < size_subset; i++)
    {
        printf("%d ", subset[i]);    
    }
    printf("\n");
}

void print_temp_subset(int *subset, int size_subset)
{
    int i;
    
    printf(" ");
    for (i = 0; i < size_subset; i++)
    {
        printf("%d ", subset[i]);    
    }
    printf("\n");
}

void test_subset(int *subset, int size_subset, int k) {
    int i, j;
    
    for (i = 0; i < size_subset; i++)
        for (j = i + 1; j < size_subset; j++)
        {
            if ((subset[i] + subset[j]) % k == 0) 
            {
                   return;
            }
        }
    printf("%d", size_subset);
    exit(0);
}

int test_temp_subset(int *subset, int size_subset, int k) {
    int i, j;
    
    for (i = 0; i < size_subset; i++)
        for (j = i + 1; j < size_subset; j++)
        {
            if ((subset[i] + subset[j]) % k == 0) 
            {
                   return (0);
            }
        }
    return (1);
}

void create_subset(int *subset, int size_subset, int *set, int size_set, int pos_subset, int pos_set, int k)
{
    int i = 0;

    if (pos_set >= size_set) return;
    if (size_set - pos_set < size_subset - pos_subset) return;
    for (i = pos_set; i < size_set; i++)
    {
        subset[pos_subset] = set[i];
        if (pos_subset + 1 == size_subset)
        {
            /* print_subset(subset, size_subset); */
            test_subset(subset, size_subset, k);
        }
        else
        {
            /* print_temp_subset(subset, pos_set + 1); */
            if (test_temp_subset(subset, pos_subset + 1, k))
            {
                create_subset(subset, size_subset, set, size_set, pos_subset + 1, i + 1, k);
            }
        }
    }
}

void test_subset_of_size(int size, int *set, int n, int k) {
    int *subset;
    
    subset = malloc(sizeof(int) * size);
    create_subset(subset, size, set, n, 0, 0, k);
    free(subset);
}

int main() {
    int n, k;
    int *set;
    int size;
    int i, j;

    scanf("%d %d", &n, &k);
    set = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    for (size = n; size > 0; size--)
    {
        test_subset_of_size(size, set, n, k);
    }
    printf("0");
    free(set);
    return (0);
}
