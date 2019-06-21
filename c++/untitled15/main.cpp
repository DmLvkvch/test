#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

struct Node{
    string c;
    Node* right;
    Node* left;
    Node(string c){
        this->c = c;
        right = nullptr;
        left = nullptr;
    }
};

class FFA{
string str;
public:
    FFA(string s){
        str = s;
    }
    int prior(char c){
        if(c=='+'||c=='-')
            return 3;
        if(c=='*'||c=='/')
            return 2;
        if(c=='^')
            return 1;
        return 0;
    }
    Node* insert(Node* p, string val){
        if(p==nullptr){
            Node* q = new Node(val);
            return q;
        }

    }

    int find_max(string str){
        int tmp = 0;
        int index = -1;
        for(int i = 0;i<str.size();i++){
            if(prior(str[i])>=tmp){
                tmp = prior(str[i]);
                index = i;
            }
        }
        return index;
    }

    bool digit(string str){
        int count = 0;
        for(int i = 0;i<str.size();i++){
            if(isdigit(str[i]))
                count++;
        }
        if(count==str.size())
            return true;
        else {
            false;
        }
    }



    Node* MakeTree(string str, Node* q){
        int i = find_max(str);
        string tmp;
        tmp+=str[i];
        Node* t = nullptr;
        if(digit(str)){
            t = insert(t, str);
            return t;
        }
        t = insert(t, tmp);
        t ->left = MakeTree(str.substr(0, i), t);
        t ->right = MakeTree(str.substr(i+1, str.size()-1), t);
        return t;
    }

    int calc(Node* f){
        int x, y, z;
        if((f->c=="+")||(f->c=="-")||(f->c=="*")||(f->c=="/")||(f->c=="^")){
            x=calc(f->left);
            y=calc(f->right);

            if (f->c=="+"){
                cout<<"you are here: "<<x<<'+'<<y<<endl;
                z=x+y;
            }
            else if (f->c=="-"){
                z=x-y;
                cout<<"you are here: "<<x<<'-'<<y<<endl;
            }
            else if (f->c=="*"){
                cout<<"you are here: "<<x<<'*'<<y<<endl;
                z=x*y;
            }
            else if (f->c=="/"){
                cout<<"you are here: "<<x<<'/'<<y<<endl;
                z=x/y;
            }
            else if (f->c=="^"){
                cout<<"you are here: "<<x<<'^'<<y<<endl;
                z=pow(x, y);
            }
            return z;
        }
        else return atoi(f->c.c_str());
    }

};

int main()
{
    string s;
    cin>>s;
    if(s[0]=='-')
        s = "0"+s;
    FFA c(s);
    Node* t = nullptr;
    t = c.MakeTree(s, t);
    int n = c.calc(t);
    cout<<n;
    return 0;
}
