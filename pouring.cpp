#include <bits/stdc++.h>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _fsb(i, a, b) for (int i = (a); i <= (b); ++i)
#define Min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

struct situation
{
    int a, b, c;
} s[10000], f[20][20][20];

int Va = 5, Vb = 6, Vc = 10;

int head = 0, tail = 0, reache = 0;

void output(int a, int b, int c)
{
    if (f[a][b][c].a == 5 && f[a][b][c].b == 6)
    {
        cout << f[a][b][c].a << f[a][b][c].b << f[a][b][c].c << endl;
    }
    else
    {
        output(f[a][b][c].a, f[a][b][c].b, f[a][b][c].c);
        cout << f[a][b][c].a << f[a][b][c].b << f[a][b][c].c << endl;
    }
}

void insert(int a, int b, int c)
{
    if (f[a][b][c].a != -1)
        return;
    f[a][b][c] = s[head];
    s[++tail] = {a, b, c};
    if (c == 8)
    {
        reache = 1;
        output(a, b, 8);
        cout << a << b << c << endl;
    }
}
void bfs()
{
    int aa = 0, bb = 0; // bb->aa

    if (s[head].a != Va)
    {
        if (s[head].b != 0)
        {
            aa = Min(s[head].a + s[head].b, Va);
            bb = s[head].a + s[head].b - aa;
            insert(aa, bb, s[head].c);
        }
        if (s[head].c != 0)
        {
            aa = Min(s[head].a + s[head].c, Va);
            bb = s[head].a + s[head].c - aa;
            insert(aa, s[head].b, bb);
        }
    }
    if (s[head].b != Vb)
    {
        if (s[head].a != 0)
        {
            aa = Min(s[head].a + s[head].b, Vb);
            bb = s[head].a + s[head].b - aa;
            insert(bb, aa, s[head].c);
        }
        if (s[head].c != 0)
        {
            aa = Min(s[head].b + s[head].c, Vb);
            bb = s[head].b + s[head].c - aa;
            insert(s[head].a, aa, bb);
        }
    }
    if (s[head].c != Vc)
    {
        if (s[head].a != 0)
        {
            aa = Min(s[head].a + s[head].c, Vc);
            bb = s[head].a + s[head].c - aa;
            insert(bb, s[head].b, aa);
        }
        if (s[head].b != 0)
        {
            aa = Min(s[head].b + s[head].c, Vc);
            bb = s[head].b + s[head].c - aa;
            insert(s[head].a, bb, aa);
        }
    }

    head++;
}

int main()
{
    _fsb(i, 0, 19) _fsb(j, 0, 19) _fsb(k, 0, 19) f[i][j][k] = {-1, -1, -1};
    s[0] = {5, 6, 0};
    while (reache != 1 && tail >= head)
    {
        bfs();
    }
    return 0;
}