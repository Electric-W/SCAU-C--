//广搜AC
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N, M, W, result = 0;
char map[200][200] = { 0 };
int v[200][200] = { 0 }, isdoor[200][200] = { 0 }, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int sc, sr, ec, er;//入口、出口行列数


//传送点入口出口结构体
struct door
{
    int c1;
    int r1;
    int c2;
    int r2;
} door[105];

//记录结构体
typedef struct pos
{
    int x;//记录当前点的行数
    int y;//记录当前点的列数
    int step;//记录步数
} Pos;

//广搜bfs
int bfs()
{
    //创造静态队列，记录位置和到达当前位置的步数
    Pos q[100000] = { 0 };//注意队列数组要开大一点，否则会报错
    int f, r;
    f = 0, r = 0;
    q[r].x = sc, q[r].y = sr,q[r].step = 0;
    r++;
    while (f != r)
    {
        //判断当前点是否是终点,如果是终点，则返回步数
        if (q[f].x == ec && q[f].y == er)
            return q[f].step;
        //如果当前点为传送点
        if (isdoor[q[f].x][q[f].y] != 0)
        {
            //记录数组存储传送门的下标方便访问
            int out_index = isdoor[q[f].x][q[f].y];
            int out_x = door[out_index].c2;
            int out_y = door[out_index].r2;
            //如果出口是墙 或者 不在地图内 或者 已经被走过，则将队头出队
            if (map[out_x][out_y] == '1' || out_x < 0 || out_x >= N || out_y < 0 || out_y >= M || v[out_x][out_y] == 1)
            {
                f++;
                continue;
            }
            //把传送门的出口坐标入队
            q[r].x = out_x;
            q[r].y = out_y;
            q[r].step = q[f].step + 1;
            r++;
            v[out_x][out_y] = 1;//标记传送门出口走过
        }
        else //如果当前点不是出口也不是传送点,则往四个方向走，并且将可以走的点入队
        {
            int i;
            for (i = 0; i < 4; i++)
            {
                int cur_x = q[f].x + dx[i], cur_y = q[f].y + dy[i];
                if (cur_x >= 0 && cur_x < N && cur_y >= 0 && cur_y < M && map[cur_x][cur_y] == '0' && v[cur_x][cur_y] == 0)
                {
                    v[cur_x][cur_y] = 1;//标记当前位置走过
                    q[r].x = cur_x;
                    q[r].y = cur_y;
                    q[r].step = q[f].step + 1;
                    r++;
                }
            }
        }
        f++;//队头出队
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(v, 0, sizeof(v));
        memset(isdoor, 0, sizeof(isdoor));
        memset(door, 0, sizeof(door));
        //读入行和列
        scanf("%d%d", &N, &M);
        getchar();
        //读入路和墙，即地图
        int i, j;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
                scanf("%c", &map[i][j]);
            getchar();
        }
        //读入传送门个数
        scanf("%d",&W);
        //读入传送门入口和出口坐标，同时标记传送门的位置
        for (i = 1; i <= W; i++)
        {
            cin >> door[i].c1 >> door[i].r1 >> door[i].c2 >> door[i].r2;
            isdoor[door[i].c1][door[i].r1] = i;//标记为是传送点
        }
        //读入入口和出口坐标
        cin >> sc >> sr >> ec >> er;
        //标记入口已经走过
        v[sc][sr] = 1;
        //广度搜索
        int step = bfs();
        if (step == -1)
            printf("die\n");
        else
            printf("%d\n", step);
    }
    return 0;
}

