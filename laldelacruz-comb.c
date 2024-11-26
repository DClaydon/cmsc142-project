#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 4;  // Number of elements
    int nopts[N + 2];         // Array of top of stacks
    int option[N + 2][N + 2]; // Array of stacks of options
    int start, move, i, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) { // While dummy stack is not empty

        if (nopts[move] > 0) { // If there are candidates for the current move

            nopts[++move] = 0; // Initialize new move

            if (move > N) {
                // Do nothing here; printing happens during backtracking
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
            if (move > 1) { // Print combination if there's at least one element
                for (i = 1; i < move; i++) {
                    printf("%2i ", option[i][nopts[i]]);
                }
                printf("\n");
            }
            nopts[--move]--; // Pop stack
        }
    }

    return 0;
}
