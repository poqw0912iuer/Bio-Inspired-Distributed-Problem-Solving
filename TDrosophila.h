#ifndef TDrosophilaH
#define TDrosophilaH
#include <vector.h>
//---------------------------------------------------------------------------

class TDrosophila{
protected:
    float **coordinates;
    short **array;
    unsigned *color, *color_temp;
    short NV, NE;
    short file, K;
public:
    TDrosophila(short file_no, short colors);
    short GetArray(short x, short y);
    void PutArray(short value, short x, short y);
    float GetCoordinates(short vertice, char coordinate);
    void PutCoordinates(float value, short vertice, char coordinate);
    unsigned GetColor(short vertice);
    void PutColor_temp(short vertice, short value);
    unsigned GetColor_temp(short vertice);
    void PutColor(short vertice, short value);
    short GetNV();
    short GetNE();
    short GetFileNo();
    short GetK();
};
#endif