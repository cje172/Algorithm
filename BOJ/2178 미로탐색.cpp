#include <iostream>
#include <queue>
using namespace std;

int graph[100][100];
int visited[100][100] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

void bfs(int x, int y)
{
    visited[x][y] = 1;
    
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if(next_x>=0 && next_x<N && next_y>=0 && next_y<M)
            {
                if(graph[next_x][next_y]==1 && visited[next_x][next_y]==0)
                {
                    graph[next_x][next_y] = graph[x][y] + 1;
                    visited[next_x][next_y] = 1;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }
}


int main(){

    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    bfs(0,0);

    cout << graph[N-1][M-1] << endl;

    return 0;
}
