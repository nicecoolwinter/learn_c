/****************************
    �ɦW:ch13_15.cpp
    �\��:�ͽ˨禡
 ****************************/

#include <stdlib.h>
#include <stdio.h>

class BP
{
public:
    BP();
    BP(int b, int p);

    int GetBaseNo();
    int GetPow();

    friend int CalPow(BP B); //�ŧi�ͽ˨禡

private:
    int    BaseNo;
    int    Pow;
};

BP::BP()
{
}
BP::BP(int b, int p)
{
    BaseNo = b;
    Pow = p;
}

int BP::GetBaseNo()
{
    return BaseNo;
}
int BP::GetPow()
{
    return Pow;
}

int CalPow(BP Obj)     //�ͽ˨禡�w�q,�������w���O
{
    int i;
    int result = 1;

    for (i = 1; i <= Obj.Pow; i++) {   //�p��BaseNo��B.Pow����
        result = result * Obj.BaseNo;
    }

    return result;
}

void main(void)
{
    int Ans;
    BP ObjA(10, 3), ObjB(20, 2);
    Ans = CalPow(ObjA);
    printf("����=%d\t����=%d\t����=%d\n", ObjA.GetBaseNo(), ObjA.GetPow(), Ans);
    Ans = CalPow(ObjB);
    printf("����=%d\t����=%d\t����=%d\n", ObjB.GetBaseNo(), ObjB.GetPow(), Ans);
    /* system("pause"); */
}
