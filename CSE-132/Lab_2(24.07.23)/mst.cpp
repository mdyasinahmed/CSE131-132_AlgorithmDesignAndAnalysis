#include <bits/stdc++.h>
using namespace std;
#define v 4

int minimumCost(int cost[], bool mstSet[]){
    int min = INT_MAX;
    int min_index;

    for(int i=0; i<v; i++){
        if(mstSet[i]==false && cost[i]<min){
            min = cost[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[v][v]){
    cout<<"Edge \t Cost"<<endl;
    for(int i=1; i<v; i++){
        cout <<parent[i]<<i<<"\t"<<graph[i][parent[i]]<<"\n";
    }
}

void primsMST(int graph[v][v]){
    int parent[v], cost[v];
    bool mstSet[v];
    for(int i=0; i<v; i++){
        cost[i] = INT_MAX;
        mstSet[i]=false;
    }
    
    cost[0] = 0;
    parent[0] = -1;
    for(int i=0; i<v-1; i++){
        int u = minimumCost(cost, mstSet);
        mstSet[u] = true;
        //cout<<mstSet[u]<<endl;
        for(int j=0; j<v; j++){
            //cout<<j<<endl;
            if(graph[u][j] && mstSet[j]==false && graph[u][j] < cost[j]){
                //cout<<"if"<<endl;
                parent[j] = u;
                cost[j] = graph[u][j];
                // cout<<u <<endl;
                // cout<<cost[j]<<endl;
                // cout<< parent[j];
                // cout<<graph[u][j]<<endl;
            }
        }
        printMST(parent, graph);
    }
}

int main(){
    int graph[v][v] = {{0, 1, 2, 1},
                        {1, 0, 1, 2},
                        {2, 1, 0, 2},
                        {1, 3, 2, 0}};
    
    primsMST(graph);
}