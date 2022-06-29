#include <stdio.h>
#include<math.h>
int phi, M, n, e, d, C;
void encrypt()
{
    int i;
    C = 1;
    for (i = 0; i < e; i++)
        C = C * M % n;
    C = C % n;
    printf("\n\tEncrypted keyword : %d", C);
}
void decrypt()
{
    int i;
    M = 1;
    for (i = 0; i < d; i++)
        M = M * C % n;
    M = M % n;
    printf("\n\tDecrypted keyword : %d \n", M);
}
int main()
{
    int i, p, q, rem;
    printf("\nEnter Two Distinct Prime Numbers\t: ");
    scanf("%d%d", &p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    printf("\n\tPhi\t= %d", phi);
    printf("\n\nEnter e coprime with Phi(1<e<%d)\t: ", phi);
    scanf("%d", &e);
    if ((e < phi) && (e > 1))
    {
        for (i = 2; i < phi; i++)

            if (e % i == 0 && phi % i == 0)
            {
                printf("\nInvalid value of e\n");
                exit(0);
            }

            else
            {
                d = 0;

                do
                {
                    d++;
                    rem = (d * e) % phi;
                } while (rem != 1);
            }
    }
    else
    {
        printf("\nInvalid value of e\n");
        exit(0);
    }

    printf("\n\tPublic Key\t:{%d,%d}", e, n);
    printf("\n\tPrivate Key\t:{%d,%d}", d, n);
    printf("\n\nEnter The Plain Text(0<PT<%d)\t: ", n);
    scanf("%d", &M);
    if (M < n)
    {
        encrypt();
        decrypt();
    }
    else
        printf("\nInvalid Plain text\n");
}