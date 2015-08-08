#ifndef TVC_ManagerH
#define TVC_ManagerH
#include "TLocalStateManager.h"
//---------------------------------------------------------------------------

class TVC_Manager : public TLocalStateManager
{
private:
    unsigned violations1, violations2;
public:
    vector<vector <unsigned> > available_colors;
    void Solver(TDrosophila graph, unsigned M, float Multiplier);
    void Violations(TDrosophila graph);
    void erase(vector<unsigned> &vec, unsigned VALUE)const;
};
#endif
