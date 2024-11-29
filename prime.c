#include <stdio.h>

// function to check if a number is prime
int is_prime(int num) 
{
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) 
        {
            return 0; 
        }    
    }
    return 1;  
}

int main()
 {
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int a[row][col];
    // input array elements
    printf("Enter the elements:\n");
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // print original array
    printf("Array:\n");
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // replace each element with the 5th prime starting from itself
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            int count = 0;
            int num = a[i][j];

            while (count != 5) 
            {
                if (is_prime(num)){
                    count++;
                }
                if (count != 5) {
                    num++;
                }
            }
            a[i][j] = num; 
        }
    }
    // Print modified array
    printf("After replacing with 5th prime:\n");
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
