#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

struct Node{
    int data;
    Node * next;
};

class LinkedList{
    public:
        Node * head, * tail;
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        void push_node(int x){
            Node * temp = new Node{x, NULL};
            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                temp->next = head;
                head = temp;
            }
        }

        void print_list(){
            Node * temp = head;
            while(true){
                cout << temp->data;
                if(temp->next == NULL)
                    break;
                temp = temp->next;
            }
        }
};

class BigInteger{
    private:
        LinkedList value;
    public:
        BigInteger(string v){
            for(int i=0; i<v.length(); i++){
                value.push_node(v[i]-'0');
            }
        }

        LinkedList operator + (BigInteger& bigInt){
            LinkedList res;
            int carry = 0;
            int c;
            Node * temp1 = value.head;
            Node * temp2 = bigInt.value.head;
            while(temp1 != NULL && temp2 != NULL){
                c = temp1->data + temp2->data + carry;
                res.push_node(c%10);
                carry = c/10;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            while(temp1 != NULL){
                c = temp1->data + carry;
                res.push_node(c%10);
                carry = c/10;
                temp1 = temp1->next;
            }
            while(temp2 != NULL){
                c = temp2->data + carry;
                res.push_node(c%10);
                carry = c/10;
                temp2 = temp2->next;
            }
            if (carry) 
                res.push_node(carry);

            return res;
        }
};

int main() {

    int t;
    cin >> t;

    while (t--){
        string n1, n2;
        cin >> n1;
        cin >> n2;
        
        BigInteger b1(n1);
        BigInteger b2(n2);

        LinkedList res = b1 + b2;
        res.print_list();
        cout << endl;
    }
    

    return 0;
}

