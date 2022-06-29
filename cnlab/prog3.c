#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int nor;
struct frame
{
    char ack;
    int data;
} frm[10];
void revack(int j);
void resend(int j);
int main()
{
    int i, n;
    printf("\n \n Stop and Wait");
    printf("\n \n \nEnter the no. of packets: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter data for frame[%d]: ", i);
        scanf("%d", &frm[i].data);
        printf("\n \n Waiting for acknowledgement...");
        frm[i].ack = 'y';
        revack(i);
    }
    printf("\n All packets are sent Successfully");
    // getch();
    return 0;
}
void revack(int j)
{
    int i, r, n;
    rand();
    r = rand() % n;
    if (j == r)
    {
        frm[r].ack = 'n';
        printf("\n Packet not recieved");
        resend(j);
    }
    else
    {
        printf("\n \n Acknowledgement Recieved");
        printf("\n Data recieved is %d \n", frm[j].data);
    }
}
void resend(int j)
{
    printf("\n \n Resending the Frame...");
    sleep(2);
    frm[j].ack = 'y';
    printf("\n Data recieved is %d \n", frm[j].data);
}