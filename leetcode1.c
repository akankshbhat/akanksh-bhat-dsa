#include <stdio.h>
#include <string.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    if (open == '{' && close == '}')
        return 1;

    return 0;
}

int main()
{
    char str[MAX];
    int i;
    int valid = 1;

    printf("Enter the brackets: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }

        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (top == -1)
            {
                valid = 0;
                break;
            }

            if (!isMatching(pop(), str[i]))
            {
                valid = 0;
                break;
            }
        }
    }

    if (top != -1)
    {
        valid = 0;
    }

    if (valid)
        printf("True \n");
    else
        printf("False \n");

    return 0;
}