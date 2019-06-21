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
Square(size_t N, vector<vector<size_t>> mas):arr(N, vector<size_t>(N, 0)), best(15, vector<size_t>(3, 0)), a(N*N), b(N*N, vector<size_t>(2, 0)),q(N, vector<size_t>(N, 0))
{
c = mas;
size = N;
bestcolor = 16;
color = 1;
count = 1;
}
~Square(){

}

void RemoveSqr(size_t N, size_t color){
for(auto i = 0; i<size;i++)
for(auto j = 0; j < size; j++){
if(arr[i][j]==color)
arr[i][j] = 0;
}

}

bool f(){
m.clear();
vector<vector<size_t>> t;
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

if(t == c){
return true;
}
return false;
}

void write(){
ofstream out;
out.open("D:\\untitled7\\a.txt", ios::app);
for (size_t i = 0;i<size;i++) {
for(size_t j = 0;j<size;j++)
out<<q[i][j]<<" ";
out<<endl;
}
out<<endl;
}

void prsize_t(){
for (size_t i = 0;i<size;i++) {
for(size_t j = 0;j<size;j++)
cout<<q[i][j]<<" ";
cout<<endl;
}
cout<<endl;
}

bool findEmptySquare(size_t & x, size_t & y, size_t N){
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
return false;
}

bool PutSquare(size_t x, size_t y, size_t w, size_t color, size_t N){
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


void BackTracking(size_t x, size_t y, size_t N){

if(color>size*size){

return;
}
for(size_t i = N ; i >= 1; i--)
{
if(PutSquare(x, y, i, color, N))
{

color++;
size_t x_ = x;
size_t y_ = y;
if(findEmptySquare(x_, y_, N)){
BackTracking(x_, y_, N);
}
else

{
color--;
prsize_t(color);
if(f()){
q = arr;
throw invalid_argument("YES\n");
}
RemoveSqr(N, color);
return;
}
color--;
RemoveSqr(N, color);
}
}
}
const char* s = "No\n";
void v(){
size_t res = 0;
for(size_t i = 0;i<c.size();i++){
res+=c[i][1]*c[i][0]*c[i][0];
}
if(res!=size*size)
throw s;
}

size_t findSquare(size_t & x, size_t & y,size_t K){
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

void prsize_t(size_t color){
size_t x, y, size;
a.clear();
a.resize(size*size);
for(size_t k = 1; k <= color; ++k)
{
x = 0;
y = 0;
size = findSquare(x, y, k);
a[k-1] = size;
}
}

void solve(){
sort(c.begin(), c.end());
size_t x = 0, y = 0;
try{
v();
BackTracking(0, 0, c[c.size()-1][0]);
}catch(exception& a){
cout<<a.what()<<endl;
prsize_t();
return;
}catch(const char* s){
cout<<s<<endl;
return;
}
if(findEmptySquare()){
cout<<"No"<<endl;
return;
}
}

private:
vector<vector<size_t>> best;
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

};

void g(vector<vector<size_t>> & a){
    sort(a.begin(), a.end());
for(size_t i = 0;i<a.size()-1;i++)
    if(a[i][0]==a[i+1][0]){
        a[i][1]+=a[i+1][1];
        a.erase(a.begin()+i+1);
        i = 0;
    }

}

int main()
{
size_t k, w;
size_t N = 0;
cin>>N;
size_t t;
cin>>t;
vector<vector<size_t>> arr(t, vector<size_t> (2, 0));
for(size_t i = 0;i<t;i++){
cin>>k>>w;
arr[i][0] = w;
arr[i][1] = k;
}
for(size_t i = 0;i<arr.size();i++){
if(arr[i][0] == 0 || arr[i][1] == 0){

arr.erase(arr.begin()+i);
i = 0;
}

}
g(arr);
Square a(N, arr);
a.solve();
return 0;
}
