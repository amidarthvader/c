#include <stdio.h>
#include <string.h>

int main()
{
    int copy[20][20], dist[20][20], via[20][20];
    int n = 0, i = 0, j = 0, k = 0, count = 0;
    system("clear");
    printf("Enter The Number Of Nodes\n");
    scanf("%d", &n);
    printf("Enter The Cost Matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &dist[i][j]);
            dist[i][i] = 0;
            copy[i][j] = dist[i][j];
            via[i][j] = j;
        }

    do
    {
        count = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                for (k = 1; k <= n; k++)
                    if (copy[i][j] > (dist[i][k] + copy[k][j]))
                    {
                        copy[i][j] = dist[i][k] + copy[k][j];
                        via[i][j] = k;
                        count++;
                    }
    } while (count != 0);
    for (i = 1; i <= n; i++)
    {
        printf("Shortest path from Router %d \n", i);
        for (j = 1; j <= n; j++)
        {
            printf("\t\t To %d Via %d Is %d\n", j, via[i][j], copy[i][j]);
        }
    }
}
