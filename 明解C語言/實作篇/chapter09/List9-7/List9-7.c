/*
    dmp�K�ɮת��ƥX
*/

#include  <ctype.h>
#include  <stdio.h>

/*--- �N��ysrc�����e�ƥX��dst�v ---*/
void dump(FILE* src, FILE* dst)
{
    int            n;
    unsigned long  count = 0;
    unsigned char  buf[16];

    while ((n = fread(buf, 1, 16, src)) > 0) {
        int  i;

        fprintf(dst, "%08lX ", count);                      /* ��} */

        for (i = 0; i < n; i++) {                           /* 16�i��� */
            fprintf(dst, "%02X ", (unsigned)buf[i]);
        }

        if (n < 16)
            for (i = n; i < 16; i++) {
                fputs("   ", dst);
            }

        for (i = 0; i < n; i++) {                           /* �r�� */
            fputc(isprint(buf[i]) ? buf[i] : '.', dst);
        }

        fputc('\n', dst);

        count += 16;
    }

    fputc('\n', dst);
}

int main(int argc, char* argv[])
{
    FILE*  fp;

    if (argc < 2) {
        fputs("�Ы��w�ɮסC\n", stderr);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "rb")) == NULL) {
                fprintf(stderr, "�ɮ�%s�L�k�}�ҡC\n", *argv);
                return (1);
            } else {
                dump(fp, stdout);    /* ��yfp���зǿ�X */
                fclose(fp);
            }
        }
    }

    return (0);
}
