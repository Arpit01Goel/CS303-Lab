// sort1.c
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    int arr[MAX], n = 0;
    while (fscanf(fp, "%d", &arr[n]) == 1 && n < MAX) {
        n++;
    }
    fclose(fp);

    qsort(arr, n, sizeof(int), compare);

    printf("Sorted numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
