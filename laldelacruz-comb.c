#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 4; // Total numbers
    int nopts[N + 2];         // Array of top of stacks
    int option[N + 2][N + 2]; // Array of stacks of options
    int start, move, i, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) { // While dummy stack is not empty

        if (nopts[move] > 0) { // Continue exploring

            nopts[++move] = 0; // Initialize new move

            // Print the combination at this point (if not empty)
            for (i = 1; i < move; i++) {
                printf("%2i ", option[i][nopts[i]]);
            }
            if (move > 1) {
                printf("\n"); // Print a newline if there's something to display
            }

            // Generate candidates for the next step
            int start_candidate = (move == 1) ? 1 : option[move - 1][nopts[move - 1]] + 1;

            for (candidate = start_candidate; candidate <= N; candidate++) {
                option[move][++nopts[move]] = candidate; // Push candidate
            }

        } else {
            nopts[--move]--; // Backtrack
        }
    }

    return 0;
}
