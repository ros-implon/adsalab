#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void printPermutation(string str){
    queue<string> q;
    string s(1, str[0]);
    q.push(s);
    
    while(q.front().size() != str.size()){
        
        
        int n = q.front().size();
        q.push(q.front() + str[n]);        

        for(int j=0; j<n; j++){
            char x = str[n];
            string temp = q.front();
            swap(temp[j], x);
            q.push(temp + x);
        }
        q.pop();
    }
    
    vector<string> res;  
    
    while(!q.empty()){
        res.push_back(q.front());
        q.pop();
    }
    
    sort(res.begin(), res.end());
    
    int len = res.size();
    for(int i=0; i<len; i++)
        cout << res[i] << endl;

    res.shrink_to_fit();
}

int main() {
   
    int t;
    scanf("%d", &t);
    while(t--){
        char s[10];
        scanf("%s", s);
        printPermutation(s);
        cout << endl;
    }
    
    return 0;
}