#include<iostream>

using namespace std;

class Stack{
    private:
        int size;
        int stack[10000];

    public:
        Stack(){
            size = 0;
        }

        void push(int x){
            stack[++size] = x;
        }

        int pop(){
            if(size == 0)
                return -1;
            else{
                return stack[size--];
            }
        }
        
        void empty(){
            size = 0;
        }

        bool isEmpty(){
            if(size == 0)
                return true;
            else
                return false;
        }

        int top(){
            return stack[size];
        }
};

int main(){
    
    bool terminate = false;
    Stack stack;
    
    int n;
    cin >> n;
    while(1){
        
        if(terminate){
            cin >> n;
            if(n == 0){
                break;
            }else{
                cout << "\n";
            }
        }
        
        int arr[n], x;
        int flag = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x == 0){
                flag = 1;
                break;
            }
            arr[i] = x;
        }

        if(flag == 1){
            terminate = true;
        }else{
            terminate = false;
            int count[n];
            for(int i=0; i<n; i++)
                count[i] = i+1;

            int j=0;
            for(int i=0; i<n; i++){
                stack.push(count[i]);
                while(!stack.isEmpty() && stack.top()==arr[j]){
                    stack.pop();
                    j++;                                
                }    
            }
            if(j==n)
                cout << "Yes\n";
            else
                cout << "No\n";
            stack.empty();
        }
        
    }

    return 0;
}