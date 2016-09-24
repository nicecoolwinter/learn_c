/*
    �ϥΰ}�C���u�ʲM�檺��@�d��
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define Null    -1          /* �Žs�� */

typedef enum {
    Term, Insert, Append, Delete, Print, Clear
} Menu;

typedef int     Index;      /* �s���� */

/*--- �`�I ---*/
typedef struct {
    int    no;          /* �|���s�� */
    char   name[10];        /* �W�� */
    Index  next;            /* ���V���򤸯����s�� */
    Index  Dnext;           /* �R���M����� */
} Node;

/*--- �u�ʲM�� ---*/
typedef struct {
    Node*   n;              /* �M�楻��(�}�C) */
    Index  top;             /* ���V�M��e�Y�������s�� */
    Index  max;             /* ���V�ϥΰO�����̤j�s�� */
    Index  deleted;         /* ���V�R���M�檺�e�Y�������s�� */
} List;

#define Top     (list->top)             /* �M�檺�e�Y */

#define Second  (list->n[Top].next)     /* �M��ĤG�Ӥ��� */

#define Next(x) (list->n[(x)].next)     /* �M���x�Ӥ��� */

/*--- ��M�檺�U�����]�w�� ----*/
void SetNode(Node* x, int no, char* name, Index next)
{
    x->no   = no;
    x->next = next;
    strcpy(x->name, name);
}

/*--- �Ǧ^�n���J���O�����s�� ---*/
int GetIndex(List* list)
{
    if (list->deleted == Null) {        /* �L�R���O���� */
        return (++(list->max));
    } else {
        Index  rec = list->deleted;
        list->deleted = list->n[rec].Dnext;
        return (rec);
    }
}

/*--- �N���w���O���n����R���M�� ---*/
void DeleteIndex(List* list, Index idx)
{
    if (list->deleted == Null) {        /* �L�R���O���� */
        list->deleted = idx;
        list->n[idx].Dnext = Null;
    } else {
        Index  ptr = list->deleted;
        list->deleted = idx;
        list->n[idx].Dnext = ptr;
    }
}

/*--- �b�e�Y���J�`�I ---*/
void InsertNode(List* list, int no, char* name)
{
    Index  ptr = Top;
    Top = GetIndex(list);
    SetNode(&list->n[Top], no, name, ptr);
}

/*--- �b�������J�`�I ---*/
void AppendNode(List* list, int no, char* name)
{
    if (Top == Null) {                      /* �Y�M�欰�Ū��� */
        InsertNode(list, no, name);    /* �h���J�ܫe�Y */
    } else {
        Index  ptr = Top;

        while (Next(ptr) != Null) {         /* ��X�����`�I */
            ptr = Next(ptr);
        }

        Next(ptr) = GetIndex(list);
        SetNode(&list->n[Next(ptr)], no, name, Null);
    }
}

/*--- �N�e�Y�`�I�R�� ---*/
void DeleteNode(List* list)
{
    if (Top != Null) {
        Index  ptr = Second;
        DeleteIndex(list, Top);
        Top = ptr;
    }
}

/*--- �N���`�I�R�� ---*/
void ClearList(List* list)
{
    while (Top != Null) {               /* �R���e�Y�`�I */
        DeleteNode(list);    /* ����M����� */
    }
}

/*--- ��ܩҦ����`�I ---*/
void PrintList(List* list)
{
    Index  ptr = Top;

    puts("�i�@����j");

    while (ptr != Null) {
        printf("%5d %-10.10s\n", list->n[ptr].no, list->n[ptr].name);
        ptr = Next(ptr);
    }
}

/*--- �N�u�ʲM���l�� ---*/
void InitList(List* list, int size)
{
    /* �@���T�O��������Node�B�����Ƭ�size���}�C */
    list->n = calloc(size, sizeof(Node));
    list->top = list->max = list->deleted = Null;
}

/*--- �u�ʲM��ϥε��� ---*/
void TermList(List* list)
{
    ClearList(list);                /* �R���������`�I */
    free(list->n);
}

/*--- ��J��� ---*/
Node Read(char* message)
{
    Node  temp;

    printf("�п�J�n%s����ơC\n", message);

    printf("���X : ");
    scanf("%d", &temp.no);
    printf("�W�� : ");
    scanf("%s", temp.name);

    return (temp);
}

/*--- ���ﶵ ---*/
Menu SelectMenu(void)
{
    int  ch;

    do {
        printf("\n(1)�b�e�Y���J�`�I	(2)�b�������J�`�I\n");
        printf("(3)�R���e�Y���`�I	(4)��ܥ������`�I\n");
        printf("(5)�R���������`�I	(0)���@���@�B�@�z : ");
        scanf("%d", &ch);
    } while (ch < Term  ||  ch > Clear);

    return ((Menu)ch);
}

/*--- �D�{�� ---*/
int main(void)
{
    Menu  menu;
    List  list;

    InitList(&list, 100);               /* �ų̤j�`�I�Ƭ�100�� */

    do {
        Node  x;

        switch (menu = SelectMenu()) {
        case Insert:
            x = Read("���J");
            InsertNode(&list, x.no, x.name);
            break;

        case Append:
            x = Read("���J");
            AppendNode(&list, x.no, x.name);
            break;

        case Delete:
            DeleteNode(&list);
            break;

        case Print :
            PrintList(&list);
            break;

        case Clear :
            ClearList(&list);
            break;
        }
    } while (menu != Term);

    TermList(&list);
    return (0);
}
