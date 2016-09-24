//stack.hͷ�ļ�

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define STACKSIZE 50
#define STACKINCREMENT 20
#define OVERFLOW -1
#define OK 1
#define ERROR -1

typedef struct {
    int* base;
    int* top;
    int stacksize;
} Stack;

int InitStack(Stack& s) //����һ����ջ
{
    s.base = (int*)malloc(STACKSIZE * sizeof(int));

    if (!s.base) {
        return (OVERFLOW);
    }

    s.top = s.base;
    s.stacksize = STACKSIZE;
    return (OK);
}

int Push(Stack& s, int e)
{
    if ((s.top - s.base) > s.stacksize) {
        s.base = (int*)realloc(s.base, (STACKSIZE + STACKINCREMENT) * sizeof(int));

        if (!s.base) {
            return (OVERFLOW);
        }

        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREMENT;
    }

    *s.top++ = e;
    return (OK);
}

bool Empty(Stack s)
{
    if (s.base == s.top) {
        return true;
    } else {
        return false;
    }
}

int Pop(Stack& s)
{
    int e;
    e = *--s.top;
    return e;
}

//graph.h�ļ�


//�����޻�ͼ����������

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX 20
#define NULL 0

typedef struct ArcNode {     //ͷ�ڵ�
    int adjvex;              //�ñ���ָ��Ķ����λ��
    struct ArcNode* nextarc; //ָ����һ����
} ArcNode;

typedef struct VNode {         //��ڵ�
    int data;    //������Ϣ
    int indegree;         //�ڵ�����
    ArcNode* firstarc;       //ָ���һ�������ýڵ�ıߵ�ָ��
} VNode, AdjList[MAX];

typedef struct {
    AdjList vertices;     //��ڵ�
    int vexnum;           //�ڵ�ĸ���
    int arcnum;           //�ߵ�����
} Graph;


int LocateVex(Graph G, int v)   //���ؽڵ�v��ͼ�е�λ��
{
    int i;

    for (i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == v) {
            break;
        } else {
            continue;
        }

    if (i < G.vexnum) {
        return i;
    } else {
        return -1;
    }
}

void CreateGraph(Graph& G)
{
    int m, n;
    printf("������ͼ�Ľڵ���: ");
    scanf("%d", &m);

    while (m < 0) {
        printf("Error!\n����������С��1.\n");
        printf("����������ͼ�Ķ�����: ");
        scanf("%d", &m);
    }

    printf("������ͼ�ı���: ");
    scanf("%d", &n);

    while (n < 0) {
        printf("Error!\nͼ�ı�������С��0.\n");
        printf("����������ͼ�ı���: ");
        scanf("%d", &n);
    }

    G.vexnum = m;          //������Ŀ
    G.arcnum = n;          //�ߵ���Ŀ
    int i, j, k;

    for (i = 0; i < G.vexnum; ++i) { //��ʼ��ͼ����Ϣ
        G.vertices[i].data = i + 1;  //������Ϣ
        G.vertices[i].firstarc = NULL;
        G.vertices[i].indegree = 0;    //��ʼʱ��ȶ�Ϊ0
    }

    //������Ϣ
    printf("���������Ϣ:\n");

    for (i = 0; i < G.vexnum; ++i) {
        printf("v%d\n", G.vertices[i].data);
    }

    int v1, v2, flag = 0;

    for (k = 0; k < G.arcnum; ++k) {
        printf("�������%d�ߵ������յ�: ", k + 1);
        scanf("%d%d", &v1, &v2);

        i = LocateVex(G, v1);    //����v1��ͼ�е�λ��
        j = LocateVex(G, v2);    //����v2��ͼ�е�λ��

        if (i >= 0 && j >= 0) {
            ++flag;
            (G.vertices[j].indegree)++;
            ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex = j;
            p->nextarc = NULL;
            ArcNode* p1;

            if (! G.vertices[i].firstarc) {
                G.vertices[i].firstarc = p;
            } else {
                for (p1 = G.vertices[i].firstarc; p1->nextarc;
                     p1 = p1->nextarc); //��ö�������һ���ڽӶ���

                p1->nextarc = p;              //��p���뵽���һ���ڽӶ���ĺ���
            }
        } else {   //û�иû���ɾ����
            printf("û�иñ�!\n");
            k = flag;
        }

    }

    //����ڽӱ�
    printf("������ڽӱ�Ϊ:\n");
    printf("λ�� ���� ��\n");

    for (i = 0; i < G.vexnum; ++i) {
        printf(" %d     v%d", i, G.vertices[i].data);
        ArcNode* p = G.vertices[i].firstarc;

        if (p) {
            while (p->nextarc) {
                printf("->v%d", p->adjvex + 1);
                p = p->nextarc;
            }

            printf("->v%d\n", p->adjvex + 1);
        } else {
            printf("\n");
        }
    }

    printf("��������ĵ����:\n");

    for (i = 0; i < G.vexnum; ++i) {
        printf("%d��������Ϊ: %d\n", G.vertices[i].data, G.vertices[i].indegree);
    }
}


int FirstAdjVex(Graph G, int v) //����v�ĵ�һ���ڽӶ���
{
    if (G.vertices[v].firstarc) {
        return G.vertices[v].firstarc->adjvex;
    } else {
        return -1;
    }
}

int NextAdjVex(Graph G, int v, int w) //����v�������w����һ���ڽӶ���
{
    int flag = 0;
    ArcNode* p;
    p = G.vertices[v].firstarc;

    while (p) {
        if (p->adjvex == w) {
            flag = 1;
            break;
        }

        p = p->nextarc;
    }

    if (flag && p->nextarc) {
        return p->nextarc->adjvex;
    } else {
        return -1;
    }
}

bool Visited[MAX];

//������ȱ���
void DFS(Graph G, int v)
{
    Visited[v] = true;
    printf("v%d ", G.vertices[v].data);
    int w;

    for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
        if (!Visited[w]) {
            DFS(G, w);
        }
}

void DFSTraverse(Graph G)
{
    int v;

    for (v = 0; v < G.vexnum; ++v) {
        Visited[v] = false;
    }

    for (v = 0; v < G.vexnum; ++v)
        if (!Visited[v]) {
            DFS(G, v);    //�ݹ�
        }
}

//main.cpp�ļ�

#include "graph.h"
#include "stack.h"

void TopologicalSort(Graph G) //����������
{
    int i, j, k;
    int count = 0;  //����ͳ�ƶ���ĸ���
    Stack s; //����һ��ջ�������������Ϊ0�Ķ���
    InitStack(s); //��ʼ��ջ

    for (i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].indegree ==
            0) { //����i����������Ϊ0 ��i��ʾ������ͼ�е�λ��
            Push(s, i);    //����i��������ջ
        }

    while (!Empty(s)) {
        j = Pop(s);     // ��Ϊ���0�Ķ���λ�ó�ջ�������浽j��
        count++;        //ͳ�ƶ���ĸ���
        printf("v%d ", G.vertices[j].data); //������Ϊ0�Ķ���
        ArcNode* p;

        for (p = G.vertices[j].firstarc; p ;
             p = p->nextarc) { //�����j��������ڽӶ��㣬��������ȼ�1
            k = p->adjvex;
            --(G.vertices[k].indegree);

            if (G.vertices[k].indegree == 0) { //������Ϊ0,����ջ
                Push(s, k);
            }
        }
    }

    if (count <
        G.vexnum) { //countС�ڶ���ĸ���ʱ��˵���л������������������Ҫ��
        printf("Error!\nͼ���л�!���������޻�ͼ!\n");
        exit(0);               //�˳�
    }
}

//��������ʵ��
void main()
{
    Graph G;
    CreateGraph(G);
    printf("\n������ȱ������Ϊ:\n");
    DFSTraverse(G);
    printf("\n��������Ϊ: \n");
    TopologicalSort(G);
    printf("\n");
}
