/*******************************
    �ɦW:ch13_03.cpp
    �\��:�X�֩w�q�P�ŧi�����禡
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
public:
    void InitVar()
    {
        Var = 0;
    }
    void AddVar(int b)
    {
        Var = Var + b;
    }
    void ShowVar()
    {
        RealShow();  //����private���禡
    }
private:
    int Var;
    void RealShow()
    {
        printf("Var=%d\n", Var);
    }
};

void main(void)
{
    myclass X, Y;
    X.InitVar();      //�bX����W,����InitVar�����禡
    Y.InitVar();      //�bY����W,����InitVar�����禡
    X.AddVar(10);     //�bX����W,����AddVar�����禡
    printf("����X\t");
    X.ShowVar();
    printf("����Y\t");
    Y.AddVar(5);      //�bY����W,����AddVar�����禡
    Y.ShowVar();
    printf("����Y\t");
    Y.AddVar(3);      //�bY����W,����AddVar�����禡
    Y.ShowVar();
    /* system("pause"); */
}
