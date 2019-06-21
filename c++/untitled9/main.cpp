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
    Square(int N, vector<vector<int>> mas):arr(N, vector<int>(N, 0)), best(15, vector<int>(3, 0)), a(15), b(15, vector<int>(2, 0))
    {
        c = mas;
        size = N;
        bestcolor = 16;
        color = 1;
        count = 3;
    }
    ~Square(){

    }

    void solve(){
        try{
        BackTracking(0,0, size-1);
        }
        catch(exception &a){
            cout<<a.what()<<endl;
            print();
        }
        cout<<"NO"<<endl;
    }

    void print(){
        for (int i = 0;i<size;i++) {
            for(int j = 0;j<size;j++)
                cout<<q[i][j]<<" ";
            cout<<endl;
        }
    }

private:
    vector<vector<int>> best;
    vector<vector<int>> arr;
    int size;
    int bestcolor;
    int color;
    int count;
    vector<vector<int>> q;
    vector<int> a;
    map<int, int> m;
    vector<vector<int>> b;
    vector<vector<int>> c;

    void RemoveSqr(int N, int color){
        for(auto i = 0; i<size;i++)
            for(auto j = 0; j < size; j++){
                if(arr[i][j]==color)
                    arr[i][j] = 0;
            }

    }

    bool findEmptySquare(int & x, int & y, int N){
        for (y = 0;y<size;y++) {
            for (x = 0;x<size;x++) {
                if(arr[y][x]==0)
                    return true;
            }
        }
        return false;
    }

    bool isOutOfBounds(int x, int y, int width)
    {
        if(width +x > size || width +y > size)
            return true;
        else
            return  false;
    }

    bool PutSquare(int x, int y, int w, int color, int N){
        if(isOutOfBounds(x, y, w))
            return false;
        for(auto i = 0; i<w;i++){
            for(auto j = 0;j<w;j++){
                if(arr[y+i][x+j] == 0){
                    arr[y+i][x+j] = color;
                }
                else{
                    RemoveSqr(N, color);
                    return false;
                }
            }
        }

        return true;
    }

    bool f(){
        vector<vector<int>> t;
        for(int i = 0;i<color-1;i++){
            m[a[i]]++;
        }
        map<int, int>::iterator at = m.begin();
        for(int i = 0;i<m.size();i++){
            b[i][0] = at->first;
            b[i][1] = at->second;
            at++;
        }
        t = b;
        for(int i = 0;i<t.size();i++){
            if(t[i][0] == 0 || t[i][1] == 0){
                t.erase(t.begin()+i);
                i = 0;
            }
        }
        sort(t.begin(), t.end());
        sort(c.begin(), c.end());
        if(t == c){
            return true;
        }
        return false;
    }

    void BackTracking(int x, int y, unsigned N){
        if(findEmptySquare(x, y, N)){
            for(int i = 5; i > 0;i--){
                if(PutSquare(x, y, i, color, N)){
                    color++;
                    write();
                    BackTracking(x, y, N);
                    write();
                    color--;
                }
             RemoveSqr(N, color);
            }
        }
        else {
            q = arr;
            print(color-1);
            m.clear();
            if(f())
                throw invalid_argument("YES");
            return;
        }
    }

    void write(){
        ofstream out;
        out.open("D:\\untitled9\\a.txt", ios::app);
        for (int i = 0;i<size;i++) {
            for(int j = 0;j<size;j++)
                out<<arr[i][j]<<" ";
            out<<endl;
        }
        out<<endl;
    }

    int findSquare(int & x, int & y,int K){
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
        int i = 0;
        while (arr[y][x+i] == K){
            if ((x+i) < size)
            {
                ++i;
            }
            else return --i;
        }
        return i;
    }

    void print(int color){
        int x, y, size;
        for(int k = 1; k <= color; ++k)
        {
            x = 0;
            y = 0;
            size = findSquare(x, y, k);
            best[k-1][0] = x + 1;
            best[k-1][1] = y + 1;
            best[k-1][2] = size;
            a[k-1] = size;
        }
    }
    void ans(){
        cout << bestcolor << endl;
        for(int i = 0;i<bestcolor;i++){
           cout<<best[i][0]<<" "<<best[i][1]<<" "<<best[i][2]<<endl;
        }
    }
};

int main()
{
    int k, w;
    int N = 0;
    cin>>N;
    vector<vector<int>> arr(3, vector<int> (2, 0));
    for(int i = 0;i<3;i++){
        cin>>k>>w;
        arr[i][0] = w;
        arr[i][1] = k;
    }
   // sort(arr.end(), arr.begin());
    Square a(N, arr);
    a.solve();
    return 0;
}
