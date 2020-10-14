#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool sortSecond(pair<int,int> &a, pair<int,int> &b){ 
    return (a.second < b.second); 
} 

void findInterval(vector<pair<int, int>> interval, int n){
    sort(interval.begin(), interval.end(), sortSecond);
    vector<pair<int, int>> res;
    while(true){
        if(interval.size() == 0)
            break;
        pair<int, int> top = interval[0];
        interval.erase(interval.begin());
        res.push_back(top);
        
        int i = 0; 
        while(i<interval.size()){
            if(interval[i].first<top.second)
                interval.erase(interval.begin() + i);
            else i++;
        }
    }
    for(int i=0; i<res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> interval;
        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            interval.push_back(pair<int, int>(x, y));
        }
        findInterval(interval, n);
    }
}
