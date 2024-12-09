/*
Group members:
Roy Allen Fernandez
Jose Enrico Manalac
Precious Anne Ramil
Karl Kenneth Owen Olipas
Laydon Albert L Dela cruz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findSubsets(int *a, int n, int *b, int m, int k)
{
    int *nopts = (int *)malloc((n + 2) * sizeof(int));      // Array of top of stacks
    int **option = (int **)malloc((n + 2) * sizeof(int *)); // Array of stacks of options
    for (int i = 0; i < n + 2; i++)
    {
        option[i] = (int *)malloc((n + 2) * sizeof(int));
    }

    int start, move, candidate;
    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0)
    { // While dummy stack is not empty
        if (nopts[move] > 0)
        {                      // If there are candidates for the current move
            nopts[++move] = 0; // Initialize new move

            if (move > n)
            {
                // Do nothing, backtrack will handle it
            }
            else
            {
                for (candidate = n; candidate >= 1; candidate--)
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
                int sum = 0;
                for (int i = 1; i < move; i++)
                {
                    sum += option[i][nopts[i]];
                }

                if (sum == k)
                {
                    int solu = 0;
                    for (int i = 0; i < m; i++)
                    {
                        for (int j = 1; j < move; j++)
                        {
                            if (option[j][nopts[j]] == b[i])
                            {
                                solu++;
                            }
                        }
                    }
                    if (solu == m || m == 0)
                    {
                        for (int j = 1; j < move; j++)
                        {
                            printf("%2i ", option[j][nopts[j]]);
                        }
                        printf("\n");
                    }
                }
            }
            nopts[--move]--; // Pop stack
        }
    }

    // Free allocated memory
    for (int i = 0; i < n + 2; i++)
    {
        free(option[i]);
    }
    free(option);
    free(nopts);
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s <array> <sum> <subset>\n", argv[0]);
        return 1;
    }

    int k = atoi(argv[2]); // sum

    // Parse first array argument
    char *str = argv[1]; // array arg
    int arr[100];
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

    int N = count; // size of array

    // Parse second array argument (subsolution)
    char *str2 = argv[3]; // array arg
    int arr2[100];
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

    int M = count2; // size of array

    // Call the function to find subsets
    findSubsets(a, N, b, M, k);

    return 0;
}
