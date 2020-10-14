#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Node{
    char data;
    struct Node *left, *right;
};

int level[26] = {0};
int c = 0;

bool isOp(char c){
    if(c=='+' || c=='-' || c=='*' || c=='^' || c=='/'){
        return true;
    }
    return false;
}

Node * buildTree(string str, int n){
    stack<Node *> s;
    
    for(int i=0; i<n; i++){
        if(str[i] == ' '){
            continue;
        }

        if(!isOp(str[i])){
            Node * node = new Node;
            node->data = str[i];
            node->left = NULL;
            node->right = NULL;
            s.push(node);
        }else{
            Node * node = new Node;
            node->data = str[i];
            node->right = s.top();
            s.pop();
            node->left = s.top();
            s.pop();
            s.push(node);
        }
    }
    return s.top();
}

void printLeftView(Node *root, int height){

    if(root == NULL)
        return;
    
    if(level[height] == 0 ){
        cout << root->data << " ";
        level[height] = 1;
        c++;
    }
    
    printLeftView(root->left, height + 1);           
    printLeftView(root->right, height + 1);
}

void clearLevel(int n){
    for(int i=0; i<=n; i++){
        level[i] = 0;
    }
    c = 0;
}

int main() {
    
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        Node * n = buildTree(s, s.size());
        printLeftView(n, 0);
        
        clearLevel(c);
    }

    return 0;
}

