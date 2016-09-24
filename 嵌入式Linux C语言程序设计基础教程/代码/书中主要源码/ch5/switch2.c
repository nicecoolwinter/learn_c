#include <stdio.h>

int main()
{
    float score;
    int grade;

    printf("input score:");
    scanf("%f", &score);

    if (score < 0 || score > 100) {
        printf("score is invalid\n");
        return 0;
    }

    grade = score / 10;

    switch (grade) {
    case 9:
        printf("A\n");

    case 8:
        printf("B\n");

    case 7:
        printf("C\n");

    case 6:
        printf("D\n");

    default:
        printf("E\n");
    }

    return 0;
}
