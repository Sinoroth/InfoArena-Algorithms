#include <fstream>
#include <vector>

using namespace std;

#define MAX 5002
#define intM 32767

int energy[MAX], cost[MAX], ansArr[MAX][MAX];

int main()
{
    int G,W;
    fstream f("energii.in",ios::in);
    ofstream g("energii.out");

    int i,j;

    f>>G>>W;

    for(i=1;i<=G;++i)
        {
        f>>energy[i]>>cost[i];
        }

    for(i = 0; i <=G ; ++i)
        {
        for(j = 0; j <=W; ++j)
            {
            if(!i || !j) ansArr[i][j] = intM;
            else
                {
                    ansArr[i][j] = ansArr[i-1][j];
                    if(j>energy[i])
                    {
                    ansArr[i][j] = min(ansArr[i][j],cost[i] + ansArr[i-1][j-energy[i]]);
                    }
                    else
                    {
                    ansArr[i][j] = min(ansArr[i][j],cost[i]);
                    }
                }
            }
        }

    if(ansArr[G][W] == intM) g<<"-1";
    else g<<ansArr[G][W];

    return 0;
}
