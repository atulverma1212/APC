#include<iostream>
#include<queue>
#define N 4
#define M 4
using namespace std;

struct Qitem
{
    int row;
    int col;
    int dist;
    Qitem(int r, int c, int d) { row=r; col=c; dist=d; }
};

int minDistance(char grid[N][M])
{
    Qitem src(0,0,0);
    bool visited[N][M];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            visited[i][j] = (grid[i][j]=='0')? true : false;
            if(grid[i][j]=='s')
            {
                src.row = i;
                src.col = j;
            }
        }
    }

    queue <Qitem> q;
    q.push(src);
    visited[src.row][src.col]=true;
    while(!q.empty())
    {
        Qitem pt = q.front();
        q.pop();

        if(grid[pt.row][pt.col]=='d')
            return pt.dist;

        // top
        if(pt.row-1>=0 && !visited[pt.row-1][pt.col])
        {
            q.push(Qitem(pt.row-1, pt.col, pt.dist+1));
            visited[pt.row-1][pt.col]=true;
        }

        // bottom
        if(pt.row+1<N && !visited[pt.row+1][pt.col])
        {
            q.push(Qitem(pt.row+1, pt.col, pt.dist+1));
            visited[pt.row+1][pt.col]=true;
        }

        // left
        if(pt.col-1>=0 && !visited[pt.row][pt.col-1])
        {
            q.push(Qitem(pt.row, pt.col-1, pt.dist+1));
            visited[pt.row][pt.col-1]=true;
        }

        // right
        if(pt.col+1<M && !visited[pt.row][pt.col+1])
        {
            q.push(Qitem(pt.row, pt.col+1, pt.dist+1));
            visited[pt.row][pt.col+1]=true;
        }
    }
    return -1;
}

int main()
{
    char grid[N][M] = { { '0', '*', '0', 's' },
                        { '*', '0', '*', '*' },
                        { '0', '*', '*', '*' },
                        { 'd', '*', '*', '*' } };

    cout << minDistance(grid);
    return 0;
}
