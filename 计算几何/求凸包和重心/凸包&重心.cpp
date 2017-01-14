#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Point
{
        double x, y;
        Point() {}
        Point(double x, double y): x(x), y(y) {}
};

typedef Point Vector;

Vector operator + (Vector a, Vector b)
{
        return Vector(a.x + b.x, a.y + b.y);
}

Vector operator - (Vector a, Vector b)
{
        return Vector(a.x - b.x, a.y - b.y);
}

Vector operator * (Vector a, double p)
{
        return Vector(a.x * p, a.y * p);
}

Vector operator / (Vector a, double p)
{
        return Vector(a.x / p, a.y / p);
}

bool operator < (Point a, Point b)
{
        return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double cross(Vector a, Vector b)
{
        return (a.x * b.y - a.y * b.x);
}

double Dot(Vector a, Vector b)
{
        return (a.x * b.x + a.y * b.y);
}

const double eps = 1e-10;
int dcmp(double x)
{
        if (fabs(x) < eps)
        {
                return 0;
        }
        return x < 0 ? -1 : 1;
}

double Length2(Vector a)
{
        return Dot(a, a);
}

Point polygon[50010];
Point ch[50010];

bool cmp(Point a, Point b)
{
        int d = dcmp(cross(a - polygon[0], b - polygon[0]));
        return d > 0 || (d == 0 && Length2(a - polygon[0]) < Length2(b - polygon[0]));
}

Point Focus(int n)
{
        double area = 0;
        Point s = Point(0, 0);
        for (int i = 1; i < n - 1; ++i)
        {
                double a = cross(polygon[i + 1] - polygon[0], polygon[i] - polygon[0]);
                s.x = s.x + (polygon[0].x + polygon[i].x + polygon[i + 1].x) * a;
                s.y = s.y + (polygon[0].y + polygon[i].y + polygon[i + 1].y) * a;
                area += a;
        }
        s.x = s.x / 3 / area;
        s.y = s.y / 3 / area;
        return s;
        ///  S为重心
}

int ConvexHull(int n)
{
        sort(polygon, polygon + n);
        sort(polygon + 1, polygon + n, cmp);
        int m = 0;
        for (int i = 0; i < n; ++i)
        {
                while (m > 1 && cross(ch[m - 1] - ch[m - 2], polygon[i] - ch[m - 2]) <= 0)
                {
                        m--;
                }
                ch[m++] = polygon[i];
        }
        return m;

        //m为凸包上顶点个数  ch为各顶点
}

int main()
{
        int T;
        scanf("%d", &T);
        while (T--)
        {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
                scanf("%lf%lf", &polygon[i].x, &polygon[i].y);
        }
        ///

        }
        return 0;
}
