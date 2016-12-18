#include <fstream>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

const int MAX = 50005;
const int nrMAX = 0x3f3f3f3f;

vector<pair<int,int> > Djk[MAX];
vector<pair<int,int> >::iterator it;
set<pair<int,int> > h;

int Dst[MAX];

void citire(int &N);
void solve(int N);

int main()
{
    int N;

    citire(N);
    solve(N);

    return 0;
}

void citire(int &N)
{
     int x,y,l,M;
     fstream f("dijkstra.in",ios::in);
     f>>N>>M;
     do
        {
        f>>x>>y>>l;
        Djk[x].push_back(make_pair(y,l));
        }while(--M);
}

void solve(int N)
{
    ofstream g("dijkstra.out");
    int i,d;

    for(i=2;i<=N;++i)Dst[i]= nrMAX;

    h.insert(make_pair(0,1));

    while(!h.empty())
        {
         i = h.begin()->second;
         d = h.begin()->first;

         h.erase(h.begin());

         for(it = Djk[i].begin();it!=Djk[i].end();++it)
            {
             if(d+it->second<Dst[it->first])
                {
                Dst[it->first] = d + it->second;
                if(Dst[it->first] !=nrMAX)
                    {
                    h.erase(make_pair(Dst[it->first],it->first));
                    }
                 h.insert(make_pair(Dst[it->first],it->first));
                }
            }
        }
    for(i=2;i<=N;++i)
        {
            if(Dst[i]== nrMAX)g<<"0 ";
            else g<<Dst[i]<<" ";
        }

}
