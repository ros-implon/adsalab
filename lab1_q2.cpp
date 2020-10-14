#include<iostream>
#include <bits/stdc++.h> 
#include <string.h> 
#include <vector> 
#include <cstring>


using namespace std;

class Stack{
    private:
        int size;
        int stack[10000000];

    public:
        Stack(){
            size = 0;
        }

        void push(int x){
            stack[size++] = x;
        }

        int pop(){
            if(size == 0)
                return -1;
            else{
                return stack[--size];
            }
        }
        void empty(){
            size = 0;
        }
};

bool isNumber(string n){
    if(n.length()>1)
        return true;
    else{
        if(n[0] - '0' >= 0)
            return true;
    }
    return false;
}

int main() {
    Stack stack;
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        vector<string> pf;
        string pfstring;
        getline(cin, pfstring);
        int j = 0;
        int n = pfstring.length();
        for(int i=0; i<=n; i++){
            if(pfstring[i] == ' '){
                pf.push_back(pfstring.substr(j, i-j));
                j = i+1;
            }
        }
        pf.push_back(pfstring.substr(j, pfstring.length()-j));

        int m = pf.size();
        for(int i=0; i<m; i++){
            if(isNumber(pf[i])){
                stack.push(std::stoi(pf[i]));
            }else{
                int a = stack.pop();  
                int b = stack.pop();  
                switch(pf[i][0]) {  
                    case '+': stack.push(b+a); 
                        break;  
                    case '-': stack.push(b-a); 
                        break;  
                    case '*': stack.push(b*a); 
                        break;  
                    case '/': stack.push(b/a); 
                        break;  
                }  
            }
        }
        cout << stack.pop();
        cout << "\n";
        stack.empty();
    }
}