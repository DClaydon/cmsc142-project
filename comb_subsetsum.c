#include <stdio.h>
#include <stdlib.h>

// ./a.out <N items> <optional subset sum>
int main(int argc, char *argv[]) {
    int k;
    if (argc > 2) k = atoi(argv[2]);

    int N = atoi(argv[1]);  // Number of elements
    int nopts[N + 2];         // Array of top of stacks
    int option[N + 2][N + 2]; // Array of stacks of options
    int start, move, i, j, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) { // While dummy stack is not empty

        if (nopts[move] > 0) { // If there are candidates for the current move

            nopts[++move] = 0; // Initialize new move

            if (move > N) {
                
            } else {
                // Candidate selection (outer loop unchanged)
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
                if (argc > 2) {
                    // Subset Sum Solver
                    // Get combination sum
                    int sum = 0;
                    for (i = 1; i < move; i++) {
                        sum += option[i][nopts[i]];
                    }

                    // Print combination if combination sum == k
                    if (sum == k){
                        for (i = 1; i < move; i++) {
                            printf("%2i ", option[i][nopts[i]]);
                        }
                        printf("\n");
                    }
                } else {
                    // All combinations
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