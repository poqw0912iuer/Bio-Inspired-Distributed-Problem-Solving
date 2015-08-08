#ifndef TLocalStateManagerH
#define TLocalStateManagerH
#include <vector.h>
//---------------------------------------------------------------------------

class TLocalStateManager{
friend class TDrosophila;
friend class TForm1;
private:  
public:
    vector<vector <unsigned> > neighbours;
    void Gnerator(TDrosophila graph);
    unsigned Get_Neighbours(unsigned vertice, unsigned neighbour);
    void RecordData(TDrosophila graph);
    void Plot();
};
#endif