#include <iostream>
#include <vector>
using namespace std;

vector<int> alg(string t, string p){
    int n = t.length();
    int m = p.length();
    vector<int> ans;
    for (int i = 0;i<n-m;i++) {
            if(t[i+m-1]==p)
                ans.push_back(i);
        }

return ans;
}

int main()
{
    string needle, haystack;
    cin>>needle>>haystack;
    vector<int> a = alg(haystack, needle);
    cout<<a<<endl;
    return 0;
}
