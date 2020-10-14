#include <iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{ 
    int v, r, c; 
    list< pair<int, int> > *vList;

public: 
    Graph(int m, int n){
        r = m; c = n;
        v = m*n;
        vList = new list< pair<int, int> >[v];
    } 
  
    void addEdge(int i, int j, pair<int, int> d){
        vList[(i*c) + j].push_back(d);
    }
    
    void printG(){
        for(int i=0; i<v; i++){
            for (list<pair<int, int>>::iterator j = vList[i].begin(); j!=vList[i].end(); ++j){
                cout << i << (*j).first << (*j).second << endl;
            }
        }
    }

    bool findPath( pair<int, int> s, pair<int, int> d){
        
        bool visited[v]; 
        for(int i=0; i<v; i++) 
            visited[i] = false; 
    
        queue<pair<int, int>> q; 
    
        int ele = (s.first*c) + s.second;
        visited[ele] = true; 
        q.push(s); 
        list<pair<int, int>>::iterator i; 
    
        while(!q.empty()){ 
            s = q.front();
            //cout << s.first << s.second << endl;
            ele = (s.first*c) + s.second;
            if(s.first == d.first && s.second == d.second){
                return true;
            } 
            q.pop(); 
            for (i = vList[ele].begin(); i!=vList[ele].end(); ++i){
                //cout << (*i).first << (*i).second << endl;
                int index = (*i).first*c + (*i).second; 
                if (!visited[index]) 
                { 
                    visited[index] = true; 
                    q.push(*i); 
                } 
            } 
        }
        return false;
    }   
}; 

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int m, n;
        cin >> m;
        cin >> n;
        int maze[m][n];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> maze[i][j];
            }
        }

        Graph graph(m,n);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(maze[i][j] == 1){
                    if(i+1<m && maze[(i+1)][j] == 1){
                        graph.addEdge(i, j, pair<int, int>((i+1), j));
                    }
                    if(j+1<n && maze[i][(j+1)] == 1){
                        graph.addEdge(i, j, pair<int, int>(i, (j+1)));
                    }
                }
            }
        }

        //graph.printG();

        pair<int, int> s;
        pair<int, int> d;
        cin >> s.first >> s.second;
        cin >> d.first >> d.second;

        if(graph.findPath(s, d)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}

