/*****************************
    檔名:ch7_14.c
    功能:傳址呼叫(傳指標呼叫)
 *****************************/

#include <stdio.h>
#include <stdlib.h>

void func1(int* a, int b) {
    *a = *a + 10;
    b = b + 100;
    printf("func1()的*a=%d\n", *a);
    printf("func1()的b=%d\n", b);
}

void main(void) {
    int m = 1, n = 1;
    func1(&m, n);
    printf("main( )的m=%d\n", m);
    printf("main( )的n=%d\n", n);
    /*  system("pause");  */
}
