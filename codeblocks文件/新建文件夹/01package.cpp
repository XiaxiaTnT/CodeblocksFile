#include <stdio.h>
#include <tchar.h>
#include <queue>
#include "iostream"

using namespace std;

const int N = 4;
const int W = 5;
int weight[N] = {2, 1, 3, 2};
int value[N] = {3, 2, 4, 2};
int record[N][W];
void init()
{
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < W; j ++)
        {
            record[i][j] = -1;
        }
    }
}

int solve(int i, int residue)
{
    if(-1 != record[i][residue])
        return record[i][residue];
    int result = 0;
    if(i >= N)
        return result;
    if(weight[i] > residue)
    {
        record[i + 1][residue] = solve(i+1, residue);

    }
    else
    {
        result = max(solve(i+1, residue), solve(i+1, residue-weight[i]) + value[i]);
    }
    return record[i + 1][residue] = result;
}

int main() {
    init();
    int result = solve(0, W);
    cout << result << endl;
    return 0;
}
