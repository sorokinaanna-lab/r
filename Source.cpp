#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int push_char(char stack[], unsigned cur, char symb)
{
    if (cur < SIZE)
    {
        stack[cur++] = symb;
    }
    return cur;
}

int pop_char(char stack[], unsigned cur)
{
    if (cur != 0)
    {
        --cur;
    }
    return cur;
}

int is_empty_char(const char stack[], unsigned cur)
{
    return !cur;
}

char top_char(const char stack[], unsigned cur)
{
    if (cur)
        return stack[cur - 1];
    return 0;
}

int push_int(int stack[], unsigned cur, int num)
{
    if (cur < SIZE)
    {
        stack[cur++] = num;
    }
    return cur;
}

int pop_int(int stack[], unsigned cur)
{
    if (cur != 0)
    {
        --cur;
    }
    return cur;
}

int is_empty_int(const int stack[], unsigned cur)
{
    return !cur;
}

int top_int(const int stack[], unsigned cur)
{
    if (cur)
        return stack[cur - 1];
    return 0;
}

int get_priority(char c)
{
    int cur_prio = 0;
    switch (c)
    {
    case '/':
        cur_prio = 2;
        break;

    case '*':
        cur_prio = 2;
        break;

    case '+':
        cur_prio = 1;
        break;

    case '-':
        cur_prio = 1;
        break;

    case '(':
        cur_prio = 0;
    }
    return cur_prio;
}

typedef struct node {
    int mode;
    int number;
    char ch;
}node;

int main()
{
    char str[SIZE] = { (1+1) };
    char stack[SIZE] = { 0 };
    node rez[SIZE] = { 0 };
    char chisla[SIZE] = { -1 };
    int n, i = 0, j = 0, c = 0, cur = 0, cur_priot = 0, z = 0;
    //fgets(str, SIZE, stdin);
    n = strlen(str) - 1;
    str[n] = '\0';
    while (i < n) {
        j = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            chisla[j] = str[i];
            ++j;
            ++i;
        }
        if (j != 0) {
            chisla[j] = '\0';
            int number = atoi(chisla);
            rez[c].number = number;
            ++c;
        }
        if (i >= n)
            break;
        if (str[i] != '(' && str[i] != ')') {
            int OperationPriority = get_priority(str[i]);
            int curPriority = get_priority(top_char(stack, z));
            while (!is_empty_char(stack, z) && OperationPriority <= curPriority) {
                rez[c].mode = 1;
                rez[c].ch = top_char(stack, z);
                c++;
                z = pop_char(stack, z);
                curPriority = get_priority(top_char(stack, z));
            }
            if (is_empty_char(stack, z) || OperationPriority > curPriority) {
                z = push_char(stack, z, str[i]);
            }
        }
        else if (str[i] == '(') {
            z = push_char(stack, z, str[i]);
        }
        else {
            while (0 != get_priority(top_char(stack, z))) {
                rez[c].mode = 1;
                rez[c].ch = top_char(stack, z);
                c++;
                z = pop_char(stack, z);
            }
            z = pop_char(stack, z);
        }
        i++;
    }
    for (i = 0; i < z; ++i)
    {
        rez[c].mode = 1;
        rez[c].ch = top_char(stack, z);
        c++;
        z = pop_char(stack, z);
    }
    printf("Expression:\n");
    printf("%s\n", str);
    printf("Reverse Polish Notation:\n");
    for (i = 0; i < c; ++i)
    {
        if (rez[i].mode == 0)
            printf("%d ", rez[i].number);
        else
            printf("%c ", rez[i].ch);
    }
    int stack_int[SIZE] = { 0 };
    z = 0;
    for (int i = 0; i < c; ++i) {
        if (rez[i].mode == 0) {
            z = push_int(stack_int, z, rez[i].number);
        }
        else {
            int num1 = top_int(stack_int, z);
            z = pop_int(stack_int, z);
            int num2 = top_int(stack_int, z);
            z = pop_int(stack_int, z);
            if (rez[i].ch == '-')
                z = push_int(stack_int, z, num2 - num1);
            if (rez[i].ch == '+')
                z = push_int(stack_int, z, num2 + num1);
            if (rez[i].ch == '*')
                z = push_int(stack_int, z, num2 * num1);
            if (rez[i].ch == '/')
                z = push_int(stack_int, z, num2 / num1);
        }
    }
    printf("\nResult:\n%d ", top_int(stack_int, z));
    return 0;
}