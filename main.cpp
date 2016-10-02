#include <fstream>

using namespace std;

void option_m(int,int,int);
void option_c(int,int,int);

const int MAX = 100001*4+66;
int valNoua,A[MAX],pozitie,inta,intb,Maximum;

int main()
{
    fstream f("arbint.in",ios::in);
    ofstream g("arbint.out");

    const int MAX = 100001;
    int M,N,i,j,op;
    f>>N>>M;
    for(i=1;i<=N;++i)
        {
            f>>valNoua;
            pozitie=i;
            option_c(1,N,1);
        }
    for(i=1;i<=M;++i)
        {
        f>>op;
        if(op==1)
            {
            f>>pozitie>>valNoua;
            option_c(1,N,1);
            }
        else
            {
            Maximum = -1;
            f>>inta>>intb;
            option_m(1,N,1);
            g<<Maximum<<"\n";
            }
        }

    return 0;
}

void option_c(int left, int right, int node)
{
    if(left==right)
        {
         A[node] = valNoua;
         return;
        }

    int div = (left+right)/2;
    if(pozitie<=div)option_c(left,div,2*node);
    else option_c(div+1,right,2*node+1);
    A[node] = max( A[2*node],A[2*node+1]);
}

void option_m(int left, int right, int node)
{
    if(inta<=left && intb >=right)
        {
        if(Maximum<A[node])Maximum=A[node];
        return;
        }

    int div = (left+right)/2;
    if(inta<=div)option_m(left,div,2*node);
    if(intb>div) option_m(div+1,right,2*node+1);
}
