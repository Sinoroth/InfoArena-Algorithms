#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

std::fstream f("bellmanford.in",std::ios::in);
std::fstream g("bellmanford.out",std::ios::out);

const long long MAX = 9223372036854775807;
const int nrMAX = 50001;

std::vector<std::pair<int, int> > srDest[nrMAX];
std::vector<std::pair<int, int> >::iterator it;
long long dist[nrMAX];
std::queue<int> Q;
int nrOfTimes[nrMAX];

void init(int &N,int &M);
void solve(int N,int M);

int main()
{
    int N,M;

    init(N,M);
    solve(N,M);

    return 0;
}

void init(int &N,int &M)
{
  f>>N>>M;

  int i,source,dest,weight;

  dist[1] = 0;
  nrOfTimes[1]=1;
  Q.push(1);
  for(i = 2; i <= N; ++i)dist[i] = MAX;

  for(i = 1; i <= M; ++i)
    {
        f>>sorce>>dest>>weight;
        srDest[source].push_back(std::make_pair(dest,weight));
    }
}

void solve(int N,int M)
{
   int nod;

   while(Q.size())
    {
       nod = Q.front();
       Q.pop();
       for(it = srDest[nod].begin();it!=srDest[nod].end();++it)
        {
         if(dist[it->first]>dist[nod]+it->second)
            {
            dist[it->first] = dist[nod]+it->second;
            Q.push(it->first);
            nrOfTimes[it->first]+=1;
            if(nrOfTimes[it->first]>N)
                {
                g<<"Ciclu negativ!";
                return;
                }
            }
        }
    }

    for(int i = 2; i<=N;++i)
        {
        g<<dist[i]<<" ";
        }
}
