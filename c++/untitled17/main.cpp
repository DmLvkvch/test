#include <iostream>

using namespace std;

struct Node{
public:
    Node* next;
    int x;
    Node(){
        next = nullptr;
        x = 0;
    }
    Node(int val){
        next = nullptr;
        x = val;
    }
};

class List{
public:
    Node* head;
    int size = 0;
    List(){
        head = nullptr;
        size = 0;
    }
    void push(int x){
        Node* tmp = head;
        if(head == nullptr){
            head = new Node(x);
        }
        else {
            while (tmp->next) {
                tmp = tmp->next;
            }
            tmp->next = new Node(x);
        }
    }

    void pop(){
        Node* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        delete tmp;
        tmp = nullptr;
    }
};

int main()
{
    List l;
    l.push(5);
    l.push(10);
    l.push(6);
    l.pop();
    return 0;
}
