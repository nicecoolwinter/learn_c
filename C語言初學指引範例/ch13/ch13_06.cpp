/*********************************
    �ɦW:ch13_06.cpp
    �\��:�غc�禡���޼�����
 *********************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
public:
    int VarA;
    myclass(int, int);         //�ŧi�غc�禡
    void ShowVar();
private:
    int VarB;
};
myclass::myclass(int a, int b)   //�w�q�غc�禡
{
    VarA = a;
    VarB = a + b;
}
void myclass::ShowVar()
{
    printf("VarA=%d\n", VarA);
    printf("VarB=%d\n", VarB);
}

void main(void)
{
    myclass X(3, 10);
    myclass Y(5, 40);
    printf("����X\n");
    X.ShowVar();
    printf("����Y\n");
    Y.ShowVar();
    /* system("pause"); */
}
