#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 4;  // Number of elements
    int nopts[N + 2];         // Array of top of stacks
    int option[N + 2][N + 2]; // Array of stacks of options
    int start, move, i, candidate;

    int k = 11;

    int arr[]={7, 4, 5 ,2};

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) { // While dummy stack is not empty

        if (nopts[move] > 0) { // If there are candidates for the current move

            nopts[++move] = 0; // Initialize new move

            if (move > N) {
                
            } else {
                
                for (candidate = N; candidate >= 1; candidate--) { 
                    // Single condition for acceptance
                    // printf("%2i ", arr[candidate-1]);
                    if (move == 1 || arr[candidate-1] > option[move - 1][nopts[move - 1]]) {
                        option[move][++nopts[move]] = arr[candidate-1]; // Push candidate
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
