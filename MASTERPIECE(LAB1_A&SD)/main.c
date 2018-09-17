#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int* getToken(char*); //Получает лексему из строки
void pars(char*); //Точка входа анализатора
int fSum(int*); //Обрабатывает сложение и вычитание
int fMulti(int*); //Обрабатывает умножение и деление
int fUnary(int*); //Обработка унарных операторов
int fAtom(int*); //Получает значение числа
int count = 0;
//int max;
char *expr; //Указатель на обрабатываемую строку
char token[80]; //Лексема

int main(void)
{
    int value=0;
    char expr[255]; //Содержит вычисляемое выражение
    int k = 0;
    FILE *in=fopen("input.txt", "r");
    FILE *out=fopen("output.txt", "w");
    printf("Введите 1, если хотите ввести выражение из терминала, 2-из файла\n");
    scanf("%d\n", &k);
    switch(k){
    case 1:
        fgets(expr,80, stdin);
        if(!*expr) return 0;    //Если введена пустая строка - завершить программу
        pars(expr); //Вычислить выражение
        value=atoi(expr);
        printf("Result: %d\n", value);
        break;
    case 2:
        fgets(expr, 80, in);
        pars(expr);
        value=atoi(expr);
        fprintf(out, "%d", value);
        break;
    default:
        printf("Введен неверный символ\n");
        break;

    }
    fclose(in);
    fclose(out);
    return 0;
}

void pars(char *line)
{
    int *pointer;
    int result;
    expr=line;
    pointer=getToken(expr);
    fSum(&result);
    *pointer=0;
    sprintf(expr, "%d", result);
}

int* getToken(char *expr)
{
    static int i=0;

    if(expr[i]=='\0') //Если конец выражения
    {
        i=0;
        return 0;
    }
    while(isspace(expr[i])) i++; //Пропустить разделительные символы

    if(strchr("+-*", expr[i]))
    {
        *token = expr[i];
        *(token+1) = '\0';
    }
    else if(isdigit(expr[i]))
    {
        int j=0;
        token[j]=expr[i];
        while(isdigit(expr[i+1]))
            token[++j]=expr[++i];
        token[j+1]='\0';
    }
    i++;
    return &i;
}

int fSum(int *anw)
{
    char op;
    int temp;
    if(fMulti(anw)) return 1;

    while((op = *token) == '+' || op == '-')
    {
        getToken(expr);
        fMulti(&temp);
        switch(op)
        {
         case '+':
            *anw += temp;
            count ++;
            break;
         case '-':
            *anw -= temp;
            count++;
            break;
        }
    }

return 0;
}

int fMulti(int *anw)
{
    char op;
    int temp;
    if(fUnary(anw)) return 1; //Ошибка

    while((op = *token) == '*')
    {
        getToken(expr);
        if(fUnary(&temp)) return 1; //Ошибка
        switch(op)
        {
         case '*':
            *anw *= temp;
            count++;
            break;
        }
    }

return 0;
}

int fUnary(int *anw)
{
    char op=0;
    if(*token == '+' || *token == '-')
    {
        op = *token;
        getToken(expr);
    }
    if(fAtom(anw)) return 1; //Ошибка

    if(op == '-') *anw = -(*anw);

return 0;
}

int fAtom(int *anw){
        *anw = atoi(token);
        getToken(expr);
return 0;
}
