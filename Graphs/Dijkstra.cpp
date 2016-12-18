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
     //N = Number of Nodes
     //M = Number of Vertices
     int source,dest,weight,M;
     fstream f("dijkstra.in",ios::in);
     f>>N>>M;
     do
        {
        f>>source>>dest>>weight;
        Djk[source].push_back(make_pair(dest,weight));
        }while(--M);
}

void solve(int N)
{
    ofstream g("dijkstra.out");
    int i,d;
    
    //Distances from source node (1) to all other nodes are set to "infinity"
    for(i=2;i<=N;++i)Dst[i]= nrMAX;
    
    /*
    We create a pair who's first element is the weight from the source node to the destination node
    and the second element is the destination node
    */
    h.insert(make_pair(0,1));

    while(!h.empty())
        {
         /*
         We get the the top element of the queue and then pop it off
         we store the weight and the nodes stored in the pair
        */
         i = h.begin()->second;
         d = h.begin()->first;

         h.erase(h.begin());
         
         //we check all the vertices that leave from the current node
         for(it = Djk[i].begin();it!=Djk[i].end();++it)
            {
             /*
             if the distance to the current node + the distance to the node connected to it is smaller than the distance stored in the array
             we update the value and insert the element in the queue (if the element already exists in the queue, we update the weight value)
             */
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
