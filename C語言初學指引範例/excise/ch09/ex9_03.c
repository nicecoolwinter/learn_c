#include <stdio.h>
#include <stdlib.h>

int x = 100;

void add(void) {
    int x;
    x = x + 1;
}

void main(void) {
    int x;
    int i;

    for (i = 1; i <= 5; i++) {
        add();
    }

    printf("x=%d\n", x);
    system("pause");
}
