
#include <stdio.h>
#include <stdbool.h>

#define N 4
int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++)
    {
        for (int j = i + 1; j < N * N; j++)
        {
         
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}


int findXPosition(int puzzle[N][N])
{
    
    for (int i = N - 1; i >= 0; i--)
       {
       	 for (int j = N - 1; j >= 0; j--)
            {
            	if (puzzle[i][j] == 0)
                return N - i;
            }
       }
       return -1;
}

bool isSolvable(int puzzle[N][N])
{
   
    int invCount = getInvCount((int *)puzzle);
    if (N & 1)
        return !(invCount & 1);
    else 
    {
        int pos = findXPosition(puzzle);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}


int main()
{

    int puzzle[N][N] =
        {
            {12, 1, 10, 2},
            {7, 11, 4, 14},
            {5, 0, 9, 15},
            {8, 13, 6, 3},
        };

    isSolvable(puzzle) ? printf("Solvable\n") : printf("Not Solvable\n");
    return 0;
}
