#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int calcTime(int n, int m, int arr[]){
    queue<pair<int, int>> q;
	priority_queue<int> maxQ;

    for(int i=0; i<n; i++){
        q.push(pair<int, int>(i, arr[i]));
        maxQ.push(arr[i]);
    }

    int x, val, count = 0;
    while(1){
		x = q.front().first;
		val = q.front().second;
		q.pop();
		if(val != maxQ.top()) 
            q.push(pair<int, int>(x, val));
		else{
			maxQ.pop();
            count++;
			if(x == m) 
                break;
		}
	}
    return count;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int jobQ[n];
        for(int i=0; i<n; i++){
            cin >> jobQ[i]; 
        }       
        cout << calcTime(n, m, jobQ) << endl;
    }


    return 0;
}