// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    int** matrix = (int**)malloc(n*sizeof(int*));
    *returnColumnSizes = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        matrix[i]=(int*)malloc(n*sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int rowBegin = 0, rowEnd = n-1;
    int colBegin = 0, colEnd = n-1;
    int num = 1;

    while(rowBegin<=rowEnd && colBegin<=colEnd){
        //right
        for(int j = colBegin; j<=colEnd; j++){
            matrix[rowBegin][j] = num++;
        }
        rowBegin++;

        //down
        for(int j = rowBegin; j<=rowEnd; j++){
            matrix[j][colEnd] = num++;
        }
        colEnd--;

        //left
        if(rowBegin <= rowEnd){
            for(int j = colEnd; j>=colBegin; j--){
                matrix[rowEnd][j] = num++;
            }
            rowEnd--;
        }

        //up
        if(colBegin <= colEnd){
            for(int j=rowEnd; j>=rowBegin; j--){
                matrix[j][colBegin] = num++;
            }
            colBegin++;
        }
    }
    return matrix;
}
