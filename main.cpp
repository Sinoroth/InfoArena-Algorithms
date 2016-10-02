
////////////////////////////////////////////////////// SIMPLE KNAPSACK ALGORITHM //////////////////////////////////////////////////////

#include <fstream>
#include <vector>

using namespace std;

#define MAX 5002
#define intM 32767

//energy memorizes the power produced by each generator, and cost represents the amount of money required for each generator to be running
//We want to produce an energy level equal or higher to the value of W for the minimum cost 
int energy[MAX], cost[MAX], ansArr[MAX][MAX];

int main()
{
    int G,W,i,j;
    fstream f("energii.in",ios::in);
    ofstream g("energii.out");
    
    f>>G>>W;

    for(i=1;i<=G;++i)
        {
        f>>energy[i]>>cost[i];
        }
    
    for(i = 0; i <=G ; ++i)
        {
        for(j = 0; j <=W; ++j)
            {
            //First Row and First collumn are set to the maximum value possible     
            if(!i || !j) ansArr[i][j] = intM;
            else
                {
                    ansArr[i][j] = ansArr[i-1][j];
                    
                    //if j(the energy level we're testing for) is higher than the energy level of the generator, we determine the most cost efficient method of producing it
                    if(j>energy[i])
                    {
                    /*Store the minimum between the current value and the cost of the current generator + the total cost of all the generators
                      that were used to get to the energy level equal to the difference between j and the energy produced by this generator
                     */
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
