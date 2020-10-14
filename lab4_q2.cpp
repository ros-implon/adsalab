#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct Node{
    string data;
    int count;
    Node *left, *right;
};

Node * createNewNode(string s){
    Node *node = new Node;
    node->data = s;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printWords(Node *root){
    if(root == NULL){ 
        return; 
    } 
    printWords(root->left); 
    cout << root->data << " " << root->count << endl; 
    printWords(root->right); 
}

Node * buildTree(vector<string> words){
    
    int n = words.size();
    Node *root =  NULL;

    for(int i=0; i<n; i++){  
        Node *temp = root;
        Node *parent;

        if (root == NULL){
            root = createNewNode(words[i]);
            continue;
        }

        while (temp != NULL){
            parent = temp;
            if(words[i].compare(temp->data) < 0){
                temp = temp->left;
            }
            else if(words[i].compare(temp->data) > 0){
                temp = temp->right;
            }
            else{
                temp->count = temp->count + 1;
                break;
            }            
        }

        if(words[i].compare(parent->data) < 0){
            parent->left = createNewNode(words[i]);
        }
        else if(words[i].compare(parent->data) > 0){
            parent->right = createNewNode(words[i]);
        }
        
    }
    return root;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string s;
        getline(cin, s);
        char arr[s.length() + 1];  
        strcpy(arr, s.c_str());

        vector<string> words;    
        char *token = strtok(arr, " "); 
    
        while (token != NULL){ 
            words.push_back(token); 
            token = strtok(NULL, " "); 
        }
        printWords( buildTree(words) ); 
        cout << endl;
    }
    
    return 0;
}
