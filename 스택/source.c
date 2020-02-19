// ���� 10828 ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) //���� �ʱ�ȭ �Լ�
{
    s->top = -1;
}

int empty(StackType *s) //������� Ȯ�� �Լ�
{
    return (s->top == -1);
}

int full(StackType *s) // ��ȭ���� Ȯ�� �Լ�
{
    return ( s->top == (MAX_STACK_SIZE -1));
}

void push(StackType *s, element item) // �����Լ�
{
    if (full(s)){
        fprintf(stderr,"���� ��ȭ \n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s) // �����Լ�
{
    if (empty(s)){
        return -1;
    }
    else return s->data[(s->top)--];
}

element top(StackType *s) // ��ũ�Լ�
{
    if(empty(s)){
        return -1;
    }
    else return s->data[s->top];
}

element size(StackType *s) // ũ��Ȯ�� �Լ�
{
    return s->top+1;
}

int main(void)
{
    int i,N;
    int item;
    char str[10];
    StackType stack;
    init_stack(& stack); 

    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        scanf("%s", str);
        
        if(!strcmp(str, "push")){
            scanf("%d", &item);
            push(&stack, item);
        }
        else if(!strcmp(str, "pop"))
        {
            printf("%d\n", pop(&stack));
        }
        else if(!strcmp(str, "empty"))
        {
            printf("%d\n", empty(&stack));
        }
        else if(!strcmp(str, "size"))
        {
            printf("%d\n", size(&stack));
        }
        else if(!strcmp(str, "top"))
        {
            printf("%d\n", top(&stack));
        }
        else
        {
            printf("�ٽ��Է����ֽñ� �ٶ��ϴ�.\n");
        }
    }

return 0;
}