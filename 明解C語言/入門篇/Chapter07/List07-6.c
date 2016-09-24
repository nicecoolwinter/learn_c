/*
��X unsigned ���A���޿�n�B�޿�M�B�ƥL���޿�M�B1���ɼ�
*/

#include  <stdio.h>

/*---�Ǧ^���x�����줸---*/
int count_bits(unsigned x)
{
    int  count = 0;

    while (x) {
        if (x & 1U) {
            count++;
        }

        x >>= 1;
    }

    return (count);
}

/*---�Ǧ^unsigned���A���줸��---*/
int int_bits(void)
{
    return (count_bits(~0U));
}

/*---��Xunsigned���A���줸���e---*/
void print_bits(unsigned x)
{
    int     i;

    for (i = int_bits() - 1; i >= 0; i--) {
        putchar(((x >> i) & 1U) ? '1' : '0');
    }
}

int main(void)
{
    unsigned  na, nb;

    puts("�п�J��ӫD�t�ƪ���ơC");
    printf("���A�G");
    scanf("%u", &na);
    printf("���B�G");
    scanf("%u", &nb);

    printf("\nA   = ");
    print_bits(na);
    printf("\nB   = ");
    print_bits(nb);
    printf("\nA&B = ");
    print_bits(na & nb);     /* �޿�n */
    printf("\nA|B = ");
    print_bits(na | nb);     /* �޿�M */
    printf("\nA^B = ");
    print_bits(na ^ nb);     /* �ƥL���޿�M */
    printf("\n~A  = ");
    print_bits(~na);         /* 1 ���ɼ� */
    printf("\n~B�@= ");
    print_bits(~nb);         /* 1 ���ɼ� */
    putchar('\n');

    return (0);
}
