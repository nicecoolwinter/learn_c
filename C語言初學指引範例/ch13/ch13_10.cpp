/*******************************
    �ɦW:ch13_10.cpp
    �\��:�غc�禡���и�
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
public:
    double VarA;
    myclass();                 //�ŧi�L�޼ƪ��غc�禡
    myclass(int, int);         //�ŧi��Ӿ�Ƥ޼ƪ��غc�禡
    myclass(double, double);     //�ŧi��ӯB�I�Ƥ޼ƪ��غc�禡
    void ShowVar();
private:
    double VarB;
};
myclass::myclass()               //�w�q�L�޼ƪ��غc�禡
{
    VarA = 10;
    VarB = 10;
}
myclass::myclass(int a, int b)   //�w�q��Ӿ�Ƥ޼ƪ��غc�禡
{
    VarA = a;
    VarB = a + b;
}
myclass::myclass(double a, double b)   //�w�q��ӯB�I�Ƥ޼ƪ��غc�禡
{
    VarA = a;
    VarB = a * b;
}
void myclass::ShowVar()
{
    printf("VarA=%.2f\n", VarA);
    printf("VarB=%.2f\n", VarB);
}

void main(void)
{
    int i;
    myclass X[3];
    myclass Y(5, 40);
    myclass Z(20.3, 30.6);

    for (i = 0; i < 3; i++) {
        printf("����X[%d]\n", i);
        X[i].ShowVar();
    }

    printf("����Y\n");
    Y.ShowVar();
    printf("����Z\n");
    Z.ShowVar();
    /* system("pause"); */
}
