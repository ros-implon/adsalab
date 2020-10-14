#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class BinarySearchTree{

    string data;
    BinarySearchTree *left, *right;
    int leftTreeSize;

public:  
    

    BinarySearchTree(){
        data = "";
        left = right = NULL;
        leftTreeSize = 0;
    }

    BinarySearchTree(string s){
        data = s;
        left = right = NULL;
        leftTreeSize = 0;
    }

    BinarySearchTree * insert(BinarySearchTree *root, string s){
        BinarySearchTree *temp = root;
        BinarySearchTree *parent;

        if (root == NULL){
            root = new BinarySearchTree(s);
            return root;
        }

        while (temp != NULL){
            parent = temp;
            if(s.compare(temp->data) < 0){
                temp->leftTreeSize++;
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }          
        }

        if(s.compare(parent->data) < 0){
            parent->left = new BinarySearchTree(s);
        }
        else if(s.compare(parent->data) > 0){
            parent->right = new BinarySearchTree(s);
        }
        return root;
    }

    int findRank(BinarySearchTree *root, string s){
        BinarySearchTree *temp = root;
        int rank = 1;
        while(temp != NULL){
            if(s.compare(temp->data) < 0){
                temp = temp->left;
            }
            else if(s.compare(temp->data) > 0){
                rank += temp->leftTreeSize + 1;
                temp = temp->right;
            }
            else{
                rank += temp->leftTreeSize;
                return rank;
            }    
        }      
        return 0;        
    }

    bool search(BinarySearchTree *root, string s){
        BinarySearchTree *temp = root;
        while(true){
            if(temp == NULL){
                return false;
            }
            if(s.compare(temp->data) < 0){
                temp = temp->left;
            }
            else if(s.compare(temp->data) > 0){
                temp = temp->right;
            }
            else{
                return true;
            }     
        }
    }

    string findSmallest(BinarySearchTree *root, int i){
        BinarySearchTree *temp = root;
        stack<BinarySearchTree *> s;
        while(temp != NULL || !s.empty()){
            while (temp != NULL){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            i--;
            if(i==0){
                return temp->data;
            }
            temp = temp->right;
            s.pop();
        }
        return "";
    }

    string findMin(BinarySearchTree *root){
        
        BinarySearchTree *temp = root;
        BinarySearchTree *parent = NULL;
        
        while(temp != NULL){
            parent = temp;
            temp = temp->left;
        }
        if(parent != NULL)
            return parent->data;
        return "";        
    }

    string findMax(BinarySearchTree *root){
        
        BinarySearchTree *temp = root;
        BinarySearchTree *parent = NULL;
        
        while(temp != NULL){
            parent = temp;
            temp = temp->right;
        }
        if(parent != NULL)
            return parent->data;
        return "";        
    }

    BinarySearchTree * deleteString(BinarySearchTree *root, string s){
        BinarySearchTree *temp = root;
        BinarySearchTree *parent = NULL;
        while(temp != NULL){            
            if(s.compare(temp->data) < 0){
                parent = temp;
                temp->leftTreeSize--;
                temp = temp->left;
            }
            else if(s.compare(temp->data) > 0){
                parent = temp;
                temp = temp->right;
            }else{
                break;
            } 
        }
        if(temp->left != NULL && temp->right != NULL){
            BinarySearchTree *leftSide = temp->left;
            temp->leftTreeSize--;
            BinarySearchTree *pre = NULL;
            while(leftSide->right != NULL) { 
                pre = leftSide;
                leftSide = leftSide->right; 
            }
            if(pre != NULL){ 
                pre->right = leftSide->left;
            }else{
                temp->left = leftSide->left; 
            }
            temp->data = leftSide->data;
        }
        else if(temp->right != NULL){
            BinarySearchTree *node = temp->right;
            if(parent == NULL)
                return node;
            else if(parent->left == temp){
                parent->left = node;
            }
            else{
                parent->right = node;
            }
        }else{
            BinarySearchTree *node = temp->left;
            if(parent == NULL)
                return node;
            else if(parent->left == temp){
                parent->left = node;
            }
            else{
                parent->right = node;
            }
        }
        return root;        
    }

    void preOrder(BinarySearchTree *root){
        BinarySearchTree *temp = root;
        stack<BinarySearchTree *> s;
        while(temp != NULL || !s.empty()){
            while (temp != NULL){
                cout << temp->data << " ";
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }

    void postOrder(BinarySearchTree *root){
        if(root == NULL){ 
            return; 
        } 
        postOrder(root->left); 
        postOrder(root->right);
        cout << root->data << " ";
    }

    void inOrder(BinarySearchTree *root){
        if(root == NULL){ 
            return; 
        } 
        inOrder(root->left); 
        cout << root->data << " "; 
        inOrder(root->right); 
    }
};


int main() {
    int t;
    cin >> t;
    BinarySearchTree bst;
    BinarySearchTree *node = NULL;
    while (t--){
        int n;
        cin >> n;
        string s;
        int i;
        switch(n){
        case 1:
            cin >> s;
            node = bst.insert(node, s);
            break;
        case 2:
            cin >> s;
            cout << bst.findRank(node, s) << endl;
            break;
        case 3:
            cin >> s;
            if(bst.search(node, s)){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
            break;
        case 4:
            cin >> i;
            cout << bst.findSmallest(node, i) << endl;
            break;
        case 5:
            cout << bst.findMin(node) << endl;
            break;
        case 6:
            cout << bst.findMax(node) << endl;
            break;
        case 7:
            cin >> s;
            node = bst.deleteString(node, s);
            break;
        case 8:
            bst.preOrder(node);
            cout << endl;
            break;
        case 9: 
            bst.postOrder(node);
            cout << endl;
            break;
        case 10:
            bst.inOrder(node);
            cout << endl;
            break;
        default:
            break;
        }
    }
      
    return 0;
}
