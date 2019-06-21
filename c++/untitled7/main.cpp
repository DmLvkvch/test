#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;



class Square{
    public:

    Square(size_t N, vector<vector<size_t>> mas):arr(N, vector<size_t>(N, 0)),
        q(N, vector<size_t>(N, 0)), a(N*N), b(N*N, vector<size_t>(2, 0)){
        c = mas;
        size = N;
        bestcolor = size*size;
        color = 1;
        count = 1;
    }
    ~Square(){
    }
    void RemoveSqr(size_t color){
        for(size_t i = 0; i<size;i++)
            for(size_t j = 0; j < size; j++){
                if(arr[i][j]==color)
                    arr[i][j] = 0;
            }
    }

    bool myequal(vector<vector<size_t>>& a1, vector<vector<size_t>>& b1){
        if(a1.size()>b1.size())
            return false;
        for(size_t i = 0;i<a1.size();i++){
            for(size_t j = 0;j<b1.size();j++){
                if(a1[i][0]==b1[j][0]){
                    if(a1[i][1]>b1[j][1])
                        return false;
                }
            }
        }
        return true;
    }

    bool f(){
        m.clear();

        for(size_t i = 0;i<color;i++){
            m[a[i]]++;
        }

        b.clear();
        b.resize(size*size, vector<size_t>(2, 0));
        map<size_t, size_t>::iterator at = m.begin();
        for(size_t i = 0;i<m.size();i++){
            b[i][0] = at->first;
            b[i][1] = at->second;
            at++;
        }
        t = b;
        for(size_t i = 0;i<t.size();i++){
            if(t[i][0] == 0 || t[i][1] == 0){
                t.erase(t.begin()+i);
                i = 0;
            }
        }
        sort(t.begin(), t.end());

        if(myequal(t, c)){
            return true;
        }
        return false;
    }
    void print(){
        for (size_t i = 0;i<size;i++) {
            for(size_t j = 0;j<size;j++)
                cout<<q[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    bool findEmptySquare(size_t & x, size_t & y){
        for (x = 0;x<size;x++) {
            for (y = 0;y<size;y++) {
                if(arr[y][x]==0)
                    return true;
            }
        }
        return false;
    }
    bool findEmptySquare(){
        for (size_t i = 0;i<size;i++) {
            for (size_t j = 0;j<size;j++) {
                if(q[i][j]==0)
                    return true;
            }
        }
        return false;
    }
    bool isOutOfBounds(size_t x, size_t y, size_t width)
    {
        if(width +x > size || width +y > size)
            return true;
        else
            return  false;
    }
    bool PutSquare(size_t x, size_t y, size_t w, size_t color){
        if(isOutOfBounds(x, y, w))
            return false;
        for(size_t i = 0; i<w;i++){
            for(size_t j = 0;j<w;j++){
                if(arr[y+i][x+j] == 0){
                    arr[y+i][x+j] = color;
                }
                else{
                    RemoveSqr(color);
                    return false;
                }
            }
        }
        return true;
    }

    void solve(){
        try{
            v();
            BackTracking(0, 0, c[c.size()-1][0]);

        }catch(const char* s){
            cout<<s<<endl;
            return;
        }catch(exception &a){
            cout<<a.what();
            print();
            for (int i = 0;i<t.size();i++) {
                cout<<t[i][1]<<" "<<t[i][0]<<endl;
            }
        }
        if(findEmptySquare()){
            cout<<"No"<<endl;
            return;
        }
    }

    bool find(int k){
        for(int i = 0;i<c.size();i++){
            if(c[i][0] == k)
                return true;
        }
        return false;
    }

    bool counter(){

    }

    void BackTracking(size_t x, size_t y, size_t N){
        if(color-1>bestcolor){
            return;
        }
        for(size_t i = N ; i >= 1; i--)
        {
            if(find(i)&&PutSquare(x, y, i, color))
            {
                color++;
                size_t x_ = x;
                size_t y_ = y;
                if(findEmptySquare(x_, y_)){
                    BackTracking(x_, y_, N);
                }
                else{
                    color--;
                    print(color);
                    if(f()){
                        q = arr;
                        throw invalid_argument("YES\n");
                    }
                    RemoveSqr(color);
                    return;
                }
                color--;
                RemoveSqr(color);
            }
        }
    }
    const char* s = "No\n";
void v(){
    size_t res = 0;
    for(size_t i = 0;i<c.size();i++){
        res+=c[i][1]*c[i][0]*c[i][0];
    }
    if(res<size*size)
        throw s;
}

    int findSquare(size_t & x, size_t & y,size_t K){
        while (arr[y][x] != K){
            if (x == size-1){
                x = 0;
                ++y;
            }
            else
                ++x;
            if (x>=size || y>=size)
                return 0;
        }
        size_t i = 0;
        while (arr[y][x+i] == K){
            if ((x+i) < size)
            {
                ++i;
            }
            else return --i;
        }
        return i;
    }

    void print(size_t color){
        size_t x, y, size;
        a.clear();
        a.resize(this->size*this->size);
        for(size_t k = 1; k <= color; ++k)
        {
            x = 0;
            y = 0;
            size = findSquare(x, y, k);
            a[k-1] = size;
        }
    }
private:
    vector<vector<size_t>> arr;
    size_t size;
    size_t bestcolor;
    size_t color;
    size_t count;
    vector<vector<size_t>> q;
    vector<size_t> a;
    map<size_t, size_t> m;
    vector<vector<size_t>> b;
    vector<vector<size_t>> c;
            vector<vector<size_t>> t;
};

int main()
{
    size_t k, w;
    size_t N = 0;
    cin>>N;
    vector<vector<size_t>> arr(20, vector<size_t> (2, 0));
    int i = 0;
    while(cin>>k>>w){
        arr[i][0] = w;
        arr[i][1] = k;
        i++;
    }
    for(size_t i = 0;i<arr.size();i++){
        if(arr[i][0] == 0 || arr[i][1] == 0 || arr[i][0]>N){
            arr.erase(arr.begin()+i);
            i = 0;
        }

    }
    if(arr.size()==0){
        cout<<"NO"<<endl;
        return 0;
    }
    sort(arr.begin(), arr.end());
    for(int j = 0;j<arr.size();j++){
    for(size_t i = 0;i<arr.size()-1;i++){
        if(arr[i][0]==arr[i+1][0]){
            arr[i][1]+=arr[i+1][1];
            arr.erase(arr.begin()+i+1);
        }

    }
    i = 0;
    }
    Square a(N, arr);
    a.solve();
    return 0;
}
