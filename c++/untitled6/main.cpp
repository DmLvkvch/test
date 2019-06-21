#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int max(vector<int> s){
    int max = s[0];
    int index = 0;
    for(int i = 0;i<s.size();i++){
        if(max<s[i]){
            max = s[i];
            index = i;
        }
    }
    return index;
}

int min(vector<int> s){
    int max = s[0];
    int index = 0;
    for(int i = 0;i<s.size();i++){
        if(max>s[i]){
            max = s[i];
            index = i;
        }
    }
    return index;
}

int F(vector<int> s){
    return s[max(s)] - s[min(s)];
}

int H(vector<int>s1, vector<int> s2){
    return F(s1)+F(s2);
}

int M(int x , int y){
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    int size = 0;
    cin>>size;
    vector<int> s1(size), s2(size);
    for(int i = 0;i<size;i++){
        cin>>s1[i];
        cin.ignore();
    }
    for(int i = 0;i<size;i++){
        cin>>s2[i];
        cin.ignore();
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int y = 0;
    vector<int> q;
    vector<int> w;
    vector<int> save1, save2;
    for(int i = 0;i<s1.size();i++){
        q.push_back(s1[i]);
    }
    for(int i = 0;i<s2.size();i++){
        q.push_back(s2[i]);
    }
    sort(q.begin(), q.end());
    w.push_back(q[q.size()-1]);
    q.pop_back();

    int u = y;
    int m = 0;
    for(int i = 0;i<q.size();i++){
        y = H(q, w);
        w.push_back(q[q.size()-1]);
        q.pop_back();
        u = H(q, w);
        if(u<=y){
            m = u;
            save1 = q;
            save2 = w;
        }
    }
    sort(save2.begin(),save2.end());
    for(int i = 0;i<save1.size();i++)
        cout<<save1[i]<<" ";
    cout<<endl;
    for(int i = 0;i<save2.size();i++)
        cout<<save2[i]<<" ";
        cout<<endl;

    cout<<m<<endl;
    int x1 = 0, x2 = 0;
    sort(s1.begin(), s1.end());
    vector<int> t;
     t=s1;
    for(auto i = 0;i<save1.size();i++){
        for(auto j = 0;j<s1.size();j++){
            if(s1[j]==save1[i]){
                if(s1.size()==1 || save1.size()==1){
                    break;
                }
                s1.erase(s1.begin()+j);
                save1.erase(save1.begin()+i);
            }
        }

    }

    x1 = s1.size()+save1.size();

    for(auto i = 0;i<save2.size();i++){
        for(auto j = 0;j<t.size();j++){
            if(t[j]==save2[i]){
                if(t.size()==1 || save2.size()==1){
                    break;
                }
                t.erase(t.begin()+j);
                save2.erase(save2.begin()+i);
            }
        }

    }
    x2 = t.size()+save2.size();
    if(x1>x2)
        cout<<x2;
    else
        cout<<x1;

    return 0;
}
