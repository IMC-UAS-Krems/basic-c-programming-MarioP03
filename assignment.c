#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    int n = argc-1;
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", n);
        exit(EXIT_FAILURE); // so the program doesn't write 'Segmentation fault' for trying to continue with the other stuff
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    if (a <= 0 || b <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
    }


    return 0;
}
