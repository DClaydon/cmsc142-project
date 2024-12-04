#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int k = atoi(argv[2]); // sum

    // ARG[1] - array
    char *str = argv[1]; // array arg
    int arr[10];
    int count = 0;
    char *token = strtok(str, ","); // split the string into tokens
    while (token != NULL)
    {
        arr[count++] = atoi(token); // convert each token to an integer
        token = strtok(NULL, ",");
    }

    int a[count];
    for (int i = 0; i < count; i++)
        a[i] = arr[i];

    int N = sizeof(a) / sizeof(a[0]); // size of array

    // ARG[3] - subsolution
    char *str2 = argv[3]; // array arg
    int arr2[10];
    int count2 = 0;
    char *token2 = strtok(str2, ","); // split the string into tokens
    while (token2 != NULL)
    {
        arr2[count2++] = atoi(token2); // convert each token to an integer
        token2 = strtok(NULL, ",");
    }

    int b[count2];
    for (int i = 0; i < count2; i++)
        b[i] = arr2[i];

    int M = sizeof(b) / sizeof(b[0]); // size of array

    // -----------

    int nopts[N + 2];         // Array of top of stacks
    int option[N + 2][N + 2]; // Array of stacks of options
    int start, move, i, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0)
    { // While dummy stack is not empty

        if (nopts[move] > 0)
        { // If there are candidates for the current move

            nopts[++move] = 0; // Initialize new move

            if (move > N)
            {
            }
            else
            {
                for (candidate = N; candidate >= 1; candidate--)
                {
                    // Single condition for acceptance
                    if (move == 1 || a[candidate - 1] > option[move - 1][nopts[move - 1]])
                    {
                        option[move][++nopts[move]] = a[candidate - 1]; // Push candidate
                    }
                }
            }
        }
        else
        {
            // Backtrack: Print combination for current state
            if (move > 1)
            {
                // for debugging
                // for (i = 1; i < move; i++)
                // {
                //     printf("%2i ", option[i][nopts[i]]);
                // }
                // printf("\n");

                int sum = 0;
                for (i = 1; i < move; i++)
                {
                    sum += option[i][nopts[i]];
                }

                if (sum == k)
                {
                    // for (i = 1; i < move; i++)
                    // {
                    //     printf("%2i ", option[i][nopts[i]]);
                    // }
                    // printf("\n");

                    int solu = 0;
                    for (i = 0; i < M; i++)
                    {
                        for (int j = 1; j < move; j++)
                        {
                            if (option[j][nopts[j]] == b[i])
                            {
                                solu++;
                            }
                        }
                    }
                    if (solu == M)
                    {
                        for (int j = 1; j < move; j++)
                        {
                            printf("%2i ", option[j][nopts[j]]);
                        }
                        printf("\n");
                    }
                    solu = 0;
                }
            }
            nopts[--move]--; // Pop stack
        }
    }

    return 0;
}