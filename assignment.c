#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "assignment.h"

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    int n = argc-1;
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", n);
        return 1; // so the program doesn't write 'Segmentation fault' for trying to continue with the rest of the code
    }   

    int r = atoi(argv[1]);
    int c = atoi(argv[2]);
    if (r <= 0 || c <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }

    int* pMatrix = malloc((r * c) * sizeof(int)); 
    
    printf("The matrix you created has %d rows and %d columns.\n", r, c);

    for (int i = 0; i < (r*c); i++) {
        int randn = minrand + rand() % (maxrand - minrand + 1);
        pMatrix[i] = randn;
    }
    
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d ", pMatrix[i * c + j]);
        }
        printf("\n");
    }

    FILE *pFile = NULL;
    pFile = fopen("matrix.txt", "w");

    if (pFile == NULL) {
        printf("Failed to open file %s\n", "'matrix.txt'");
        return -1;
    }

    // fprintf(pFile, "%d\n", *pMatrix);
    // printf("Write completed successfully\n");

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (j == c-1)
            {
                fprintf(pFile, "%d", pMatrix[i * c + j]);
            }
            else
            {
                fprintf(pFile, "%d ", pMatrix[i*c + j]);
            }
        }
        if (i == r-1)
            {
                fprintf(pFile, "\r");
            }
        else
            {
                fprintf(pFile, "\n");
            }
    }
    printf("Write completed successfully\n");

    fclose(pFile);

    free(pMatrix);
    pMatrix = NULL;
    return 0;
}
