//����AC
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N, M, W, result = 0;
char map[200][200] = { 0 };
int v[200][200] = { 0 }, isdoor[200][200] = { 0 }, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int sc, sr, ec, er;//��ڡ�����������


//���͵���ڳ��ڽṹ��
struct door
{
    int c1;
    int r1;
    int c2;
    int r2;
} door[105];

//��¼�ṹ��
typedef struct pos
{
    int x;//��¼��ǰ�������
    int y;//��¼��ǰ�������
    int step;//��¼����
} Pos;

//����bfs
int bfs()
{
    //���쾲̬���У���¼λ�ú͵��ﵱǰλ�õĲ���
    Pos q[100000] = { 0 };//ע���������Ҫ����һ�㣬����ᱨ��
    int f, r;
    f = 0, r = 0;
    q[r].x = sc, q[r].y = sr,q[r].step = 0;
    r++;
    while (f != r)
    {
        //�жϵ�ǰ���Ƿ����յ�,������յ㣬�򷵻ز���
        if (q[f].x == ec && q[f].y == er)
            return q[f].step;
        //�����ǰ��Ϊ���͵�
        if (isdoor[q[f].x][q[f].y] != 0)
        {
            //��¼����洢�����ŵ��±귽�����
            int out_index = isdoor[q[f].x][q[f].y];
            int out_x = door[out_index].c2;
            int out_y = door[out_index].r2;
            //���������ǽ ���� ���ڵ�ͼ�� ���� �Ѿ����߹����򽫶�ͷ����
            if (map[out_x][out_y] == '1' || out_x < 0 || out_x >= N || out_y < 0 || out_y >= M || v[out_x][out_y] == 1)
            {
                f++;
                continue;
            }
            //�Ѵ����ŵĳ����������
            q[r].x = out_x;
            q[r].y = out_y;
            q[r].step = q[f].step + 1;
            r++;
            v[out_x][out_y] = 1;//��Ǵ����ų����߹�
        }
        else //�����ǰ�㲻�ǳ���Ҳ���Ǵ��͵�,�����ĸ������ߣ����ҽ������ߵĵ����
        {
            int i;
            for (i = 0; i < 4; i++)
            {
                int cur_x = q[f].x + dx[i], cur_y = q[f].y + dy[i];
                if (cur_x >= 0 && cur_x < N && cur_y >= 0 && cur_y < M && map[cur_x][cur_y] == '0' && v[cur_x][cur_y] == 0)
                {
                    v[cur_x][cur_y] = 1;//��ǵ�ǰλ���߹�
                    q[r].x = cur_x;
                    q[r].y = cur_y;
                    q[r].step = q[f].step + 1;
                    r++;
                }
            }
        }
        f++;//��ͷ����
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
        //�����к���
        scanf("%d%d", &N, &M);
        getchar();
        //����·��ǽ������ͼ
        int i, j;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
                scanf("%c", &map[i][j]);
            getchar();
        }
        //���봫���Ÿ���
        scanf("%d",&W);
        //���봫������ںͳ������꣬ͬʱ��Ǵ����ŵ�λ��
        for (i = 1; i <= W; i++)
        {
            cin >> door[i].c1 >> door[i].r1 >> door[i].c2 >> door[i].r2;
            isdoor[door[i].c1][door[i].r1] = i;//���Ϊ�Ǵ��͵�
        }
        //������ںͳ�������
        cin >> sc >> sr >> ec >> er;
        //�������Ѿ��߹�
        v[sc][sr] = 1;
        //�������
        int step = bfs();
        if (step == -1)
            printf("die\n");
        else
            printf("%d\n", step);
    }
    return 0;
}

