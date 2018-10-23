
#include <iostream>
#include <cstring>
 
using namespace std;
 
 
#define MAX_LEN 256
char stack[MAX_LEN];    // стек для хранения операторов при преобразовании
int st_ptr = 0;             // указатель вершины стека
 
void push(char *_stack, int &_ptr, char data);
char pop(char *_stack, int &_ptr);
typedef struct Node{
	char value;
	Node* right;
	Node* left;
}Node;
//
//  Преобразование записи математ. выражения из инфиксной в постфиксную (в обратную польскую запись)
//
//  Сразу оговоримся, допустимые операторы: +,-,*,/,(,),^; все операции будем считать лево-ассоциативными
//  Все операнды - односимвольные
//
void PostfixNotation(const char *_infix, char *_postfix)
{
 
 
    int out_index = 0;      // индекс в выходной строке
    int in_index = 0;       // индекс во входной строке
 
    // начинаем разбор входящей строки (она не должна быть пустой)
    do
    {
        char c = _infix[in_index];  // берем текущий символ входной строки
 
        switch (c)
        {
            case '+':
            case '-':
                // выталкиваем из стека в выходную строку все операторы с большим или равным приоритетом
                while (st_ptr != 0)
                {
                    char op = stack[st_ptr-1];  // оператор в вершине стека
                    if (op != '(')  // все операторы, кроме откр. скобки имеют больший или равный приоритет
                    {
                        _postfix[out_index++] = op; // добавляем оператор в выходную строку
                        pop(stack, st_ptr);         // удаляем оператор из стека
                    }
                    else
                        break;
                }
                // помещаем оператор в стек
                push(stack, st_ptr, c);
                break;
 
            case '*':
            case '/':
                // выталкиваем из стека в выходную строку все операторы с большим или равным приоритетом
                while (st_ptr != 0)
                {
                    char op = stack[st_ptr-1];
                    if ((op == '^') || (op == '*') || (op == '/'))
                    {
                        _postfix[out_index++] = op; // добавляем оператор в выходную строку
                        pop(stack, st_ptr);         // удаляем оператор из стека
                    }
                    else
                        break;
                }
                // помещаем оператор в стек
                push(stack, st_ptr, c);
                break;
 
            case '(':
                // просто помещаем в стек
                push(stack, st_ptr, c);
                break;
 
            case ')':
                // выталкиваем из стека в выходную строку все элементы до открывающей скобки (откр. скобку просто отбрасываем)
                while (st_ptr != 0)
                {
                    char op = pop(stack, st_ptr);   // забираем из стека оператор
                    if (op == '(')                  // если достигли открывающей скобки
                        break;                      // выталкивание закончили
                    else
                    {
                        _postfix[out_index++] = op; // добавили оператор в выходную строку
                    }
                }
                break;
 
            case '^':
                // помещаем оператор в стек (выталкивать ничего не нужно, нет операторов с большим приоритетом)
                push(stack, st_ptr, c);
                break;
 
            default:        // символ цифры
                _postfix[out_index] = c;    // добавляем цифру в выходную строку
                out_index++;
                break;
        }
 
        in_index++; // переходим к следующему символу входной строки
    }
    while (_infix[in_index] != 0);  // разбор закончен
 
    // выталкиваем все операторы в выходную строку
    while(st_ptr != 0)
    {
        _postfix[out_index++] = pop(stack, st_ptr);
        cout << st_ptr << endl;
    }
 
    // завершающий символ нуля
    _postfix[out_index] = 0;
}

void tree(string str, Node* s) {
	s->right=new Node;
	s->right=new Node;
	int i = str.size()-1;
	s->value=str[i];
	tree(str.substr(0,i--) ,s->left);
	tree(str.substr(0,i--) ,s->right);
	return;
}
 
void push(char *_stack, int &_ptr, char data)
{
    _stack[_ptr++] = data;
}
 
char pop(char *_stack, int &_ptr)
{
    return _stack[--_ptr];
}
 
 
int main()
{
Node *s=new Node;
    char str_infix[] = "(2+2)*3+5*(5+3)";
    char str_postfix[MAX_LEN];
    char result[MAX_LEN];
    cout << str_infix << endl;
    PostfixNotation(str_infix, str_postfix);
string tree = str_postfix;
    cout << tree << endl;
    return 0;
}
