#include <iostream>
#include <vector>
#include <algorithm>


// FUNCTION countPaths(matrix, m, n, cost):
int countPaths(const std::vector<std::vector<int>>& matrix, int m, int n, int cost) {

    /* Base Case 1: Out of matrix boundaries or negative remaining cost
     IF m < 0 OR n < 0 OR cost < 0 THEN
       RETURN 0 */


    if (m < 0 || n < 0 || cost < 0) {
        return 0;
    }

    /* Base Case 2: Reached starting cell (0,0)
    IF m == 0 AND n == 0 THEN
        IF cost == matrix[0][0] THEN
            RETURN 1
        ELSE
            RETURN 0 */

    if (m == 0 && n == 0) {
        if (cost == matrix[0][0]) {
            return 1;
        } else {
            return 0;
        }
    }

    /* Recursive Step: Sum paths coming from Top (m-1, n) and Left (m, n-1)
    remainingCost = cost - matrix[m][n]
    */

    int remainingCost = cost - matrix[m][n];
    /* RETURN 
        countPaths(matrix, m - 1, n, remainingCost) + 
        countPaths(matrix, m, n - 1, remainingCost)
    END */
    return countPaths(matrix, m - 1, n, remainingCost) + countPaths(matrix, m, n - 1, remainingCost);


}

int main() {
    // Initialize the 4x4 Vector
    // Insert the given Values
    std::vector<std::vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    // Get rows
    int rows = matrix.size();
    // Get Colums
    int columns = matrix[0].size();
    // Initialize the target Cost
    int targetCost = 26;

    // Initialize the Path to get the target cost
    int Paths = countPaths(matrix, rows - 1, columns - 1, targetCost);

    std::cout << "Matrix Path Cost Problem" << std::endl;
    std::cout << "Number of paths with cost " << targetCost << " is: " << Paths << std::endl;


    return 0;
}