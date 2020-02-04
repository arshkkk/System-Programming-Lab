#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
/*
int graph[4][4]={
{0,20,42,25},
{20,0,30,34},
{42,30,0,10},
{25,34,10,0}
};*/



int ALL_COVERED = (1<<4)-1;



int tsp( vector<vector<int>> graph,int n, int bitmask, int pos)
{

if(bitmask==ALL_COVERED)
return graph[pos][0];


else{

    int ans = INT_MAX;

    for(int i=0;i<n;i++){

    if((1<<i&bitmask)==0){
    int newAns = graph[pos][i] + tsp(graph,n, bitmask|(1<<i), i);
    ans = min(ans, newAns);

    }


    }

    return ans;
}
}


int main(){
vector<vector<int>> graph = {
{0,20,42,25},
{20,0,30,34},
{42,30,0,10},
{25,34,10,0}
};

cout<<"Graph is: \n";

for(int i=0;i<graph.size();i++)
{
for(int j=0;j<graph[i].size();j++)
cout<<graph[i][j]<<" ";

cout<<endl;
}

cout<<"\nMinimum Distance From Top-Left to Bottom-Right is: "<<tsp(graph,4, 0, 0)<<endl;


return 0;
}
