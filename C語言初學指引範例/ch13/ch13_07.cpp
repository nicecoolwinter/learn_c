/*******************************
    �ɦW:ch13_07.cpp
    �\��:�غc�禡���޼ƪ������
 *******************************/

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
myclass::myclass(int a = 0, int b = 0)   //�w�q�غc�禡
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
    int i;
    myclass X[3];
    myclass Y(5, 40);
    printf("����Y\n");
    Y.ShowVar();

    for (i = 0; i < 3; i++) {
        printf("����X[%d]\n", i);
        X[i].ShowVar();
    }

    /* system("pause"); */
}
