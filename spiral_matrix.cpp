// Given an m x n matrix, return all elements of the matrix in spiral order.

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    

    int colBegin = 0, rowBegin = 0;
    int colEnd = matrixColSize[0] - 1, rowEnd = matrixSize - 1;
    int total = matrixSize * matrixColSize[0];
    int* arr = (int*)malloc(total * sizeof(int));
    int i = 0;

    while(rowBegin <= rowEnd && colBegin <= colEnd){
        for(int j = colBegin; j<=colEnd; j++)
            arr[i++]=matrix[rowBegin][j];
        rowBegin++;

        for(int j = rowBegin; j<=rowEnd; j++)
            arr[i++]=matrix[j][colEnd];
        colEnd--;
        
        if(rowBegin <= rowEnd){
            for(int j = colEnd; j>=colBegin; j--)
                arr[i++]=matrix[rowEnd][j];
            rowEnd--;
        }

        if(colBegin <= colEnd) {
            for(int j = rowEnd; j>=rowBegin; j--)
                arr[i++]=matrix[j][colBegin];
            colBegin++;
        }
    }
    *returnSize = total;
    return arr;
}
