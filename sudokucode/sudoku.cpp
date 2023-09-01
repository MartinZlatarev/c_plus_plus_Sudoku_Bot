#include<bits/stdc++.h>
using namespace std;

int table[9][9];

void print()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout<<table[i][j];
        }
        cout<<"\n";
    }
}

bool okx(int x, int y, int i)
{
    for(int j = 0; j < 9; j++)
    {
        if(x == j) continue;
        if(table[j][y] == i) return false;
    }
    return true;
}

bool oky(int x, int y, int i)
{
    for(int j = 0; j < 9; j++)
    {
        if(y == j) continue;
        if(table[x][j] == i) return false;
    }
    return true;
}

bool oks(int x, int y, int k)
{
    int x0 = x/3*3;
    int y0 = y/3*3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(table[x0+i][y0+j] == k) return false;
        }
    }
    return true;
}

bool ok(int x, int y, int i)
{
    return okx(x, y, i) && oky(x, y, i) && oks(x, y, i);
}

void solve(int x, int y)
{
    if(y == 9)
    {
        x++;
        y = 0;
    }
    if(x == 9)
    {
        print();
        exit(0);
    }
    if(table[x][y] != 0) solve(x, y+1);
    else
    {
        for(int i = 1; i <= 9; i++)
        {
            if(!ok(x, y, i)) continue;
            table[x][y] = i;
            solve(x, y+1);
            table[x][y] = 0;
        }
    }
}

int main()
{
    char c;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin>>c;
            table[i][j] = c-'0';
        }
    }
    solve(0, 0);
    return  0;
}
