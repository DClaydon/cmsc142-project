#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 4;
    int nopts[N + 2];         // array of top of stacks
    int option[N + 2][N + 2]; // array of stacks of options
    int start, move, i, candidate, k, init;

    k = N;      // number of items in combination
    init = 1;   // bool for options initialization
    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0)
    { // while dummy stack is not empty
        
        // // trace
        // printf("----\n");
        // // j = columns
        // // i = rows
        // for (int m = 1; m <= N; m++) {// print solution
        //     for (int j = 1; j <= N; j++)
        //         if (j*m < N*2)
        //             printf("%2i ", option[j][m]);
        //     printf("\n");
        // }
        // for (int m = 1; m <= N; m++) {// print solution
        //     printf("%2i ", nopts[m]);
        // }
        // printf("\nk:%2i; move: %2i \n", k, move);
        // printf("+++++\n");

        if (nopts[move] > 0)
        { // else backtrack

            nopts[++move] = 0; // initialize new move
            
            // find candidates
            if (init==1) 
            {
                // consider N down to 1 as valid candidates
                for (candidate = N; candidate >= 1; candidate--)
                {
                    for (i = move - 1; i >= 1; i--) // check for duplicates
                        if (option[i][nopts[i]] == candidate)
                            break;

                    if (!(i >= 1))                               // no duplicates found
                        option[move][++nopts[move]] = candidate; // push candidate
                        
                }
            } 
            else 
            {   // reassign top of stack value 
                if (nopts[move-1] > 0) {
                    nopts[move] = nopts[move-1] - 1;
                    // increment number of items if not last backtrack
                    if (nopts[move-1] > 1) { 
                        k++;
                    }
                }
            }
            
            if (move > k)
            {
                // solution found!
                for (i = 1; i <= k; i++) // print solution
                    printf("%2i ", option[i][nopts[i]]);
                printf("\n");
                
                // catch next combination before top of stack reaches 0
                for (i = 1; i <= k-1; i++)
                    printf("%2i ", option[i][nopts[i]]);
                printf("\n");
            }
        }
        else {
            nopts[--move]--; // backtrack
            // decrement number of items if top of stack reaches 0
            if (nopts[move] == 0)
                k--;
            // to stop repopulation after first backtrack
            if (init) 
                init = 0;   
        }
    }
}