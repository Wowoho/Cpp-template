    //���ذ�Dijkstra�㷨

    //����һ��ͼ�ľ��󣬼ٶ����㲻������ȨֵΪ0
    //���ÿ����������·������,���Դ�ӡָ�������·��

    //Dijkstra�㷨��Prim�㷨����
    //��ͬ�ĵط���:
    //���߶���һ���Ѿ����"MST"���Ѿ����"���·"�ļ���
    //ÿ����һ�����x�����ϣ����µ��Ǽ�������xֱ�������ĵ��key[]����d[];
    //��ͬ�ط�����:
    //Prim�У�key��������ĳ�㵽���� ��֮���Ԫ�� �ı�Ȩ
    //Dijkstra��,d����˼��ĳ�㵽���� �������Ԫ�� ����"��"·�ı�Ȩ��

    /*
    Dijkstra�㷨
    ÿ������������;
    d[���] = 0, d[������] = INF;

    ѭ��n��
    {
        ��δ��ǵĽ���У�ѡ��dֵ��С�Ľ��x;
        ��ǽ��x;
        ���ڽ��x,�߱����б�(x,y),����d[y] = min(d[y], d[x]+w[x][y]);
        //x����������á����·���ļ����У�����Ϊx���룬�����ڽӵ��µĵ㣨���³�ʼֵ��
        //Ҳ��������·����֮ǰ���µĵ㣬��ʱ����Ҫ����Ƿ������
    }

    */


     /*
    �ο���������
    ��Դ����wiki�ٿƵ�Dijkstra�㷨gif��̬ͼ
    �����ĸ����������б�̴�0��ʼ��
    �������
    �������
    ��������㣨����·����

    6
    0
    0  7  9  0  0  14
    7  0  10 15 0  0
    9  10 0  11 0  2
    0  15 11 0  6  0
    0  0  0  6  0  9
    14 0  2  0  9  0
    3

    */

    #include <iostream>
    #include<cstdio>
    #include<cstring>
    using namespace std;

    const int N = 110;
    const int INF = 999999999;
    int w[N][N]; //�ڽӾ���
    bool done[N]; //��d[i]���ٸ��£���done[i]=true, Ҳ����������˽⼯
    int d[N]; //d[i]��¼����㵽���i�����·������
    int par[N]; //par[i]�����¼i�ĸ��׽��

    //����ͼ
    void createGraph(int n)
    {
        int i, j;

        for (i = 0; i != n; i++)
            for (j = 0; j != n; j++)
                scanf("%d", &w[i][j]);
    }

    //star:��Դ���
    //n:�����Ŀ
    void dijkstra(int star, int n)
    {
        int i, j, min, x, y;

        //��ʼ��d[], v[]
        memset(done, false, sizeof (done));
        for (i = 0; i != n; i++)
            d[i] = INF;

        //�������
        d[star] = 0;
        //�涨���ĸ�ĸҲ���Լ�
        par[star] = star;

        //ѭ��n��
        for (j = 0; j != n; j++){
            //ѡ��dֵ��С�ĵ���Ϊ���x��d[x]�Ѿ�ȷ���ˣ�
            min = INF;
            for (i = 0; i != n; i++) {
                if (done[i] == false && d[i] < min) {
                    min = d[i];
                    x = i;
                }
            }
            //x��d[i]�Ѿ�ȷ����
            done[x] = 1;
            //������x�ı�(x, y)
            for (y = 0; y != n; y++) {
                if (w[x][y] != 0 && d[y] > d[x]+w[x][y]) {
                    d[y] = d[x]+w[x][y];
                    par[y] = x;
                }
            }
        } //ѭ��n��
    }

    //star:��Դ���
    //i:��ǰ���
    void printPath(int star, int i)
    {
        //��������
        if (star == i) {
            cout << i << " ";
            return;
        }
        printPath(star, par[i]);
        cout << i << " ";
    }

    int main()
    {
        int n, star, end;

      //  cout << "���������n:" << endl;
        cin >> n;
       // cout << "�������ͼ���ڽӾ���:" << endl;
        createGraph(n);
        // cout << "���������[0, n-1]:" << endl;
        cin >> star>>end;
        dijkstra(star, n);

       /* cout << "���δ�ӡn������丸ĸ���:" << endl;
        for (int i = 0; i != n; i++) {
            cout << par[i] << " ";
        }
        cout << endl;*/
      /*  cout << "���δ�ӡ�����" << star
             << "��n��������̾���:" << endl;
        for (int i = 0; i != n; i++) {
            cout << d[i] << " ";
        }
        cout << endl;*/
      /*  cout << "����������[0, n-1]���Դ�ӡ�����·�������Ľ��:" << endl;
        cin >> end;//0 ~ n-1*/
        printPath(star, end);
        cout << endl;
        return 0;
    }
