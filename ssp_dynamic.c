#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Group members:
Roy Allen Fernandez
Jose Enrico Manalac
Precious Anne Ramil
Karl Kenneth Owen Olipas
Laydon Albert L Dela cruz
*/

// Comparator function for qsort to sort in ascending order
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int set[] = {0, 3, 7, 2, 9, 5};  // Added a dummy 0 at index 0 to simulate 1-based indexing
    int target = 10;  // Example target sum
    int n = sizeof(set) / sizeof(set[0]) - 1;  // Exclude the dummy element in size calculation

    // Sort the set using qsort (sorting starts from index 1, skipping the dummy 0)
    qsort(set + 1, n, sizeof(set[0]), compare);

    // Print the sorted set (skipping index 0)
    printf("Sorted Set: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");

    // Create a 2D DP table with 1-based indexing
    bool dp[n + 1][target + 1];

    // Initialize the first column as true, because sum 0 is always possible (empty subset)
    for (int i = 1; i <= n; i++) {
        dp[i][0] = true;
    }

    // Initialize the first row as false (except dp[0][0], which is already true)
    for (int j = 1; j <= target; j++) {
        dp[0][j] = false;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (set[i] <= j) {
                // Include or exclude the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i]]; //Cell = max([i-1],[i-1][j-set[i]])
            } else {
                // Exclude the current element
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print the DP table with row and column labels
    printf("DP Table:\n");

    // Print column labels
    printf("     ");
    for (int j = 0; j <= target; j++) {
        printf("%3d ", j);
    }
    printf("\n");

    // Print each row with row labels
    for (int i = 1; i <= n; i++) {
        printf("%3d |", set[i]);
        for (int j = 0; j <= target; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }

    // If dp[n][target] is true, print the subset
    if (dp[n][target]) {
        printf("A subset with sum %d exists. The subset is: ", target);
        int sum = target;
        for (int i = n; i > 0 && sum > 0; i--) {
            // If current element is included in the optimal subset
            if (dp[i][sum] && !dp[i - 1][sum]) {
                printf("%d ", set[i]);
                sum -= set[i];
            }
        }
        printf("\n");
    } else {
        printf("No subset with sum %d exists.\n", target);
    }

    return 0;
}
