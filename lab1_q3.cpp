#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char stack[100]; 
int top;

void init(){
    top = 0;
}

void push(int x){
    stack[top++] = x;
}

int pop(){
    if(top == 0)
        return -1;
    else{
        return stack[top--];
    }
}

char match(char c){
    char res = '';
    switch (c){
        case ')':
            res = '(';
            break;
        case '}':
            res = '{';
            break;
        case ']':
            res = '[';
            break;
    }
    return res;
}

bool isBalanced(string s){
    init();
    int n = s.length();
    for(int i=0; i<n; i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            push(s[i]);
        }
        else if(s[i] == '}' || s[i] == ')' || s[i] == ']'){
            if(stack[top-1] == match(s[i])){
                pop();
                continue;
            }else{
                return false;
            }
        }
    }
    if(top != 0)
        return false;
    return true;
}

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while(t--){
        string s;
        cin >> s;
        if(isBalanced(s))
            cout << "1";
        else
            cout << "0";

        cout << "\n";
    }

    return 0;
}
