//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//#define MAX_SIZE 500
//typedef struct node
//{
//    char data;
//    struct node* lchild;
//    struct node* rchild;
//}Tree;
////树，中序，前序，结点总数
//Tree* creat(char* mid, char* pre, int n)
//{
//    if (n <= 0) return NULL;
//    Tree* tmp = (Tree*)malloc(sizeof(Tree));
//    if (tmp == NULL) exit(0);
//    tmp->data = pre[0];
//    int i;
//    for (i = 0; i < n; i++)
//    {
//        if (tmp->data == mid[i])
//            break;
//    }
//    tmp->lchild = creat(mid, pre + 1, i);
//    tmp->rchild = creat(mid + i + 1, pre + i + 1, n - i - 1);
//
//    return tmp;
//}
//void print(Tree* base)
//{
//    if (base != NULL) {
//        printf("%c", base->data);
//        if (base->lchild || base->rchild)
//        {
//            putchar('(');
//            print(base->lchild);
//            if (base->rchild)
//                putchar(',');
//            print(base->rchild);
//            putchar(')');
//        }
//    }
//}
//void free(Tree* base)
//{
//    if (base != NULL)
//    {
//        free(base->lchild);
//        free(base->rchild);
//        delete(base);
//    }
//}
//int main()
//{
//    char mid[MAX_SIZE];
//    char font[MAX_SIZE];
//    scanf("%s", font);
//    scanf("%s", mid);
//    Tree* base = creat(mid, font, strlen(mid));
//    print(base);
//    free(base);
//    return 0;
//}