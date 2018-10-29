#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <exception>
#include <windows.h>
using namespace std;


#define MAX_LEN 256
char stack[MAX_LEN];    // стек для хранения операторов при преобразовании
int st_ptr = 0;             // указатель вершины стека
void push(char *_stack, int &_ptr, char data);
char pop(char *_stack, int &_ptr);

//
//  Преобразование записи математ. выражения из инфиксной в постфиксную (в обратную польскую запись)
//
//  Сразу оговоримся, допустимые операторы: +,-,*,/,(,),^; все операции будем считать лево-ассоциативными
//  Все операнды - односимвольные
//
string PostfixNotation(string _infix, char *_postfix)
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
       // cout << st_ptr << endl;
    }

    // завершающий символ нуля
    _postfix[out_index] = '\0';
    return _postfix;
}

void push(char *_stack, int &_ptr, char data)
{
    _stack[_ptr++] = data;
}

char pop(char *_stack, int &_ptr)
{
    return _stack[--_ptr];
}

bool isOperator(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^')
        return true;
    else
        return false;
}

struct BinTree  //Тип узла дерева.
{
  char Key; //Символ.
  BinTree* Left;
  BinTree* Right;
};

struct zveno  //Тип звена стека.
{
  BinTree* Element; //Символ.
  zveno* Sled;
};

class Tree
{
  private:
    BinTree *Root; //Указатель на корень дерева.
    zveno *Stack;
  public:
    Tree();
    void Delete (BinTree **);
    void V_stack (BinTree*);
    void PrintTree (BinTree*);
    void Print_Tree_Left (BinTree*);
    void Print_Tree_End (BinTree*);
    void Print_Tree_Back (BinTree*);
    float Evalbintree(BinTree* T);
    float Operation(char Symbol, float Operand_1, float Operand_2);
    BinTree* GetTree() {return Root;};
};


void Tree::V_stack (BinTree* Elem)
{
  zveno *q=new (zveno);

  q->Element = Elem;
  q->Sled = Stack;
  Stack = q;
}

void Tree::Delete (BinTree** tmp)
{
  zveno *q;

  if  (Stack!=nullptr)
  {
    (*tmp) = Stack->Element;
    q = Stack;
    Stack = Stack->Sled;
    delete q;
  }
}

void Tree::Print_Tree_Left (BinTree* w)
//Левостоpонний обход бинаpного деpева.
{
  if  (w!=nullptr)
  {
    cout << w->Key << " ";
    Print_Tree_Left (w->Left);
    Print_Tree_Left (w->Right);
  }
}

void Tree::Print_Tree_End (BinTree* w)
//Концевой обход бинаpного деpева.
{
  if  (w!=nullptr)
  {
    Print_Tree_End (w->Left);
    Print_Tree_End (w->Right);
    cout << w->Key<<" ";
  }
}

void Tree::Print_Tree_Back (BinTree* w)
//Обpатный обход бинаpного деpева.
{
  if  (w!=nullptr)
  {
    Print_Tree_Back (w->Left);
    cout << w->Key<<" ";
    Print_Tree_Back (w->Right);
  }
}

float Tree::Operation (char Symbol, float Operand_1, float Operand_2)
{
  float temp;

  switch (Symbol)
  {
    case '+': temp = Operand_1 + Operand_2; break;
    case '-': temp = Operand_1 - Operand_2; break;
    case '*': temp = Operand_1 * Operand_2; break;
    case '/': temp = Operand_1 / Operand_2; break;
  }
  return temp;
}

float Tree::Evalbintree (BinTree *T)
{
  float opnd1,opnd2,rez=0;
  char  symb,tmp[2];

  tmp[1]='\0';

  if (T!=nullptr)
  {
     if (strchr("+-*/^",T->Key)!=nullptr)
     {
           opnd1 = Evalbintree (T->Left);
           opnd2 = Evalbintree (T->Right);
           symb  = T->Key;
           rez =  Operation (symb,opnd1,opnd2);
     }
     else
     {
           tmp[0] = T->Key;
           rez = stoi (tmp);
     }
  return rez;
  }
}

Tree::Tree()
{
  Stack = nullptr;  //Вначале опустошим стек.
  //Фоpмиpование заглавного звена деpева.
  Root = new (BinTree);
  Root->Right = nullptr;
}

string strrev(string str){
    char str1[100];
    int k = 0;
    for(int i = str.size()-1;i>=0;i--){
        str1[k]=str[i];
        k++;
    }
    str1[k]='\0';
    string res=str1;
    return res;
}

void print(string str)
{
  char k; //Вспомогательная пеpеменная.
  BinTree* s=nullptr;
  str = strrev (str);
  Tree A;
  BinTree* Temp = A.GetTree(); //Текущий указатель.
  for(int i=0;i<str.size();i++)
  {
    k = str[i];
    //Пеpеходим к анализу символа k.
    if  (strchr("+-*/^",k)!=nullptr)
    { //Символ - опеpация.
      if (Temp->Right==nullptr) //Отсутствует пpавая дуга.
      {
        //Резеpвиpование места для вставляемого узла.
        Temp->Right = new (BinTree);
        // Установка указателя на вставляемый узел.
        Temp = Temp->Right;
        //Инициализация вставляемого узла.
        Temp->Key = k;

        Temp->Left = Temp->Right = nullptr;
        //Ссылка на пpедыдущий узел --> стек.
        A.V_stack (Temp);
       }
       else //Есть пpавая дуга.
       { //Резеpвиpование места для вставляемого узла.
         Temp->Left = new (BinTree);
         // Установка указателя на вставляемый узел.
         Temp = Temp->Left;
         // Инициализация вставляемого узла.
         Temp->Key = k;
         Temp->Left = Temp->Right = nullptr;
         //Ссылка на пpедыдущий узел --> стек.
         A.V_stack (Temp);
       }
    }
    else //Символ - опеpанд.
     if (Temp->Right==nullptr) //Отсутствует пpавая дуга.
     {
       //Резеpвиpование места для вставляемого узла.
       Temp->Right = new (BinTree);
       // Установка указателя на вставляемый узел.
       Temp = Temp->Right;
       //Инициализация вставляемого узла.
       Temp->Key = k;
       Temp->Left = Temp->Right = nullptr;
       // Текущий указатель "возвpащается" назад.
       A.Delete (&s);
       Temp = s;
     }
     else   //Есть пpавая дуга.
     { //Резеpвиpование места для вставляемого узла.
       Temp->Left = new (BinTree);
       // Установка указателя на вставляемый узел.
       Temp = Temp->Left;
       // Инициализация вставляемого узла.
       Temp->Key = k;
       Temp->Left = Temp->Right = nullptr;
       // Текущий указатель "возвpащается" назад.
       A.Delete (&s);
       Temp = s;
     }
  } //Конец for.
  cout << "Пеpед Вами фоpмула, записанная в инфиксной фоpме...\n";
  A.Print_Tree_Back (A.GetTree()->Right);
  cout << endl;
  cout << "------------------------------------------ \n";
  cout << "Пеpед Вами фоpмула, записанная в пpефиксной фоpме...\n";
  A.Print_Tree_Left (A.GetTree()->Right);
  cout << endl;
  cout << "------------------------------------------ \n";
  cout << "Пеpед Вами фоpмула, записанная в постфиксной фоpме...\n";
  A.Print_Tree_End (A.GetTree()->Right);

  cout<<"\nЗначение выражения:"<<A.Evalbintree(A.GetTree()->Right)<<endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str_infix;
    getline(cin, str_infix);
    char str_postfix[MAX_LEN];
    string str = PostfixNotation(str_infix, str_postfix);
    print(str);
    return 0;
}

