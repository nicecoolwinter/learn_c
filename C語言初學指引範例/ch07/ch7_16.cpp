/***************************
    �ɦW:ch7_16.cpp
    �\��:�s�@swap�禡
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void main(void)
{
    int m = 20, n = 60;
    printf("�ܴ��e(m,n)=(%d,%d)\n", m, n);
    swap(m, n);
    printf("�ܴ���(m,n)=(%d,%d)\n", m, n);
    /*  system("pause");  */
}
