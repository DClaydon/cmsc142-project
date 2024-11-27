#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int k = atoi(argv[2]);
    int N = atoi(argv[1]);  // Number of elements
    int nopts[N + 2];         // Array of top of stacks
    int option[N + 2][N + 2]; // Array of stacks of options
    int start, move, i, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) { // While dummy stack is not empty

        if (nopts[move] > 0) { // If there are candidates for the current move

            nopts[++move] = 0; // Initialize new move

            if (move > N) {
                
            } else {
                
                for (candidate = N; candidate >= 1; candidate--) { 
                    // Single condition for acceptance
                    if (move == 1 || candidate > option[move - 1][nopts[move - 1]]) {
                        option[move][++nopts[move]] = candidate; // Push candidate
                    }
                }
            }
        } else {
            // Backtrack: Print combination for current state
            if (move > 1) { 
                // for (i = 1; i < move; i++) {
                //     printf("%2i ", option[i][nopts[i]]);
                // }
                // printf("\n");

                int sum = 0;
                for (i = 1; i < move; i++) {
                    sum += option[i][nopts[i]];
                }

                if (sum == k){
                    for (i = 1; i < move; i++) {
                        printf("%2i ", option[i][nopts[i]]);
                    }
                    printf("\n");
                }
            }
            nopts[--move]--; // Pop stack
        }
    }

    return 0;
}