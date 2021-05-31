#include <stdio.h>
#include <malloc.h>
//二叉树
typedef char ElemType;
#define empty ' '
#define MAXSIZE 100
#include <string.h>

typedef struct Tree{
    ElemType data;
    Tree *lchild, *rchild;
}Tree,*Bt;

//栈
typedef Bt Elem;
typedef struct Node{
    Elem data;
    Node* next;
}Stack,*Sp;

int StackInit(Sp &s){
    s = (Sp)malloc(sizeof(Stack));
    if(!s) return -1;
    s->next = NULL;
    return 1;
}

int StackPush(Sp &s,Elem x){
	if(!s) return -1;
    Sp t = (Sp)malloc(sizeof(Stack));
    if(!t)  return -1;
    t->data = x;
    t->next = s->next;
    s->next = t;
    return 1;
}

int StackPop(Sp &s,Elem &e){
    if(!s->next) return -1;
    Sp t = s->next;
    e = t->data;
    s->next = t->next;
    free(t);
    return 1;
}

int StackEmpty(Sp &s){
    if(!s->next) return 0;
    return 1;
}
//栈

int TreeInit(Bt &t){
    t = (Bt)malloc(sizeof(Tree));
    if(!t) return -1;
    t->lchild = NULL;
    t->rchild = NULL;
    return 1;
}

void TreeCreat(Bt &t,ElemType* d,int &i,int &length){
    //先序遍历创建二叉树(递归)
    if(length < 0 || d[i] == empty){
        t = NULL;
        return;
    }
    t = (Bt)malloc(sizeof(Tree));
    t->data = d[i];
    t->lchild = NULL;
    t->rchild = NULL;
    i++;
    length--;
    TreeCreat(t->lchild,d,i,length);
    i++;
    length--;
    TreeCreat(t->rchild,d,i,length);
}


void Traver(Bt &t){
    //先序遍历(递归)
    if(t == NULL) return;
    int d = t->data;
    printf("%c ",d);
    Traver(t->lchild);
    Traver(t->rchild);
}

void Traver1(Bt &tt){
    //中序遍历(非递归)
	Bt t = tt;
    if(t == NULL) return;
    Sp s;
    StackInit(s);
    while(t != NULL || StackEmpty(s)){
        while(t != NULL){
            StackPush(s,t);
            t = t->lchild;
        }
        StackPop(s,t);
        printf("%c ",t->data);
        t = t->rchild;
    }
	t = tt;
	printf("\n");
}

void Traver2(Bt &t){
    //后序遍历(递归)
    if(t == NULL) return;
    int d = t->data;
    Traver2(t->lchild);
    Traver2(t->rchild);
    printf("%c ",d);
}



int main(){

    printf("请输入：");
    char str[MAXSIZE];
    fgets(str,sizeof(str),stdin);
    int length = strlen(str);
    Bt t;
    int i  = 0;
    TreeCreat(t,str,i,length);
    printf("先序：");
    Traver(t);

    printf("\n");

    printf("中序：");
    Traver1(t);

    printf("后序：");
    Traver2(t);
    printf("\n");

    return 0;
}
