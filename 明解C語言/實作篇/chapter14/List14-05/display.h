/*
    �e������(��h�r��/Win32API)���Y��--"display.h"
*/

enum {  BLACK,              /* �¦� */
        BLUE,               /* �Ŧ� */
        RED,                /* ���� */
        GREEN,              /* ��� */
        MAGENTA,            /* ���� */
        CYAN,               /* ���� */
        YELLOW,             /* ���� */
        WHITE,              /* �զ� */
        GRAY,               /* �Ǧ� */
        LIGHT_BLUE,         /* �G�Ŧ� */
        LIGHT_RED,          /* �G���� */
        LIGHT_GREEN,        /* �G��� */
        LIGHT_MAGENTA,      /* �G������ */
        LIGHT_CYAN,         /* �G���� */
        LIGHT_YELLOW,       /* �G���� */
        BLIGHT_WHITE        /* �G�զ� */
     };

/*--- �e�����h ---*/
void cls(void);

/*--- �N��Ц�m�]��(__x, __y) ---*/
void locate(int __x, int __y);

/*--- �N�r����]��__fg�A�N�I����]��__bg ---*/
void colorx(int __fg, int __bg);

/*--- �N�r����]��__col ---*/
void color(int __col);
