#include <iostream>
#include<vector>
#include<math.h>

using namespace std;

int josephus(int n, int k){
    
    vector<int> q;
    int count = k % n;

    for(int i=1; i<=n; i++)
        q.push_back(i);
    
    while(n>1){
        q.erase(q.begin() + count);
        n--;
        count =  (count + k) % n;
    }

    return q[0];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n, k;
        cin >> n;
        cin >> k;
        cout << josephus(n, k) << endl;
    }
    return 0;
}