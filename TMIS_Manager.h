#ifndef TMIS_ManagerH
#define TMIS_ManagerH
#include "TLocalStateManager.h"
//---------------------------------------------------------------------------

class TMIS_Manager : public TLocalStateManager
{
private:
    unsigned violations1, violations2, violations3;
public:
    void Solver(TDrosophila graph, unsigned M, float Multiplier);
    void Violations(TDrosophila graph);
};
#endif
