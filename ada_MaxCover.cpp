#include <iostream>
#include<cstdlib>
#include<cstdbool>
#define M 6
#define N 4
using namespace std;
bool bpGraph[M][N];
bool bpMax(int u, bool visited[], int a[]) {
   for (int v = 0; v < N; v++) {
      if (bpGraph[u][v] && !visited[v]) {
         visited[v] = true;
         if (a[v] < 0 || bpMax(a[v], visited, a)) {
            a[v] = u;
            return true;
         }
      }
   }
   return false;
}
int maxMatch() {
   int a[N];
   for(int i = 0; i<N; i++)
      a[i] = -1;
   int count = 0;
   for (int u = 0; u < M; u++) {
      bool visited[N];
      for(int i = 0; i<N; i++)
         visited[i] = false;
      if (bpMax(u, visited, a))
         count++;
   }
   return count;
}
int main() {
    cout<<"Enter the matrix:\n";
    int i,j;
    int graph[M][N];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
        cin>>graph[i][j];
        bpGraph[i][j]=graph[i][j];
        }
    }
    cout<<"Maximum number of matching is : "<<maxMatch();
}

