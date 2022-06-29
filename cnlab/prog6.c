#include <stdio.h>
#include <string.h>

int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}
int main()
{
    int drop = 0, mini, nsec, cap, count = 0, i, inp[25], process;
    system("clear");
    printf("Enter The Bucket Size\n");
    scanf("%d", &cap);
    printf("Enter The Processing Rate\n");
    scanf("%d", &process);
    printf("Enter The No. Of Seconds Packets are arriving\n");
    scanf("%d", &nsec);
    for (i = 1; i <= nsec; i++)
    {
        printf("Enter Number of packets entering at %d sec\n", i);
        scanf("%d", &inp[i]);
    }
    printf("\nSecond|PacketsRecieved|PacketsSent|PacketsLeft|Packets Dropped|\n");
    printf("-------------------------------------------------------------------------------------------\n");
    for (i = 1; i <= nsec; i++)
    {
        count = count + inp[i];
        if (count > cap)
        {
            drop = count - cap;
            count = cap;
        }
        printf("%d", i);
        printf("\t%d", inp[i]);
        mini = min(count, process);
        printf("\t\t%d", mini);
        count = count - mini;
        printf("\t\t%d", count);
        printf("\t\t%d\n", drop);
        drop = 0;
    }
    for (; count != 0; i++)
    {
        if (count > cap)
        {
            drop = count - cap;
            count = cap;
        }
        printf("%d", i);
        printf("\t0");
        mini = min(count, process);
        printf("\t\t%d", mini);
        count = count - mini;
        printf("\t\t%d", count);
        printf("\t\t%d\n", drop);
    }
}
