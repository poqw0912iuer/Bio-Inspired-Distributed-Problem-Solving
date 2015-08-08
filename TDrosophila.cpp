#include <fstream.h>
#include <iostream>
#pragma hdrstop
#include "TDrosophila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TDrosophila::TDrosophila(short file_no, short colors){
    std::fstream myStream;
    file = file_no;
    K = colors;
    if(file == 1)
        myStream.open( "Graph 1 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file == 2)
        myStream.open( "Graph 2 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file == 3)
        myStream.open( "Graph 3 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file == 4)
        myStream.open( "Graph 4 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file == 5)
        myStream.open( "Graph 5 (K = 6) .txt", std::ios::in | std::ios::out );
    else if(file == 6)
        myStream.open( "Graph 6 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file == 7)
        myStream.open( "graph-color-3.txt", std::ios::in | std::ios::out );

    if( myStream.good() == true )
    {
        myStream >> NV;
        myStream >> NE;
        myStream.close();
    }else goto end;

    coordinates = new float*[NV];
    for (int i = 0; i < NV; ++i)
        coordinates[i] = new float[2];
    array = new short*[NV];
    for (int i = 0; i < NV; ++i)
        array[i] = new short[NV];
    color = new unsigned[NV];   color_temp = new unsigned[NV];
    end:
}
//---------------------------------------------------------------------------
short TDrosophila::GetArray(short x, short y){
    return array[x][y];
}
//---------------------------------------------------------------------------
void TDrosophila::PutArray(short value, short x, short y){
    array[x][y] = value;
}
//---------------------------------------------------------------------------
float TDrosophila::GetCoordinates(short vertice, char coordinate){
    if(coordinate == 'x')
        return coordinates[vertice][0];
    else if(coordinate == 'y')
        return coordinates[vertice][1];
    else return 0;
}
//---------------------------------------------------------------------------
void TDrosophila::PutCoordinates(float value, short vertice, char coordinate){
    if(coordinate == 'x')
        coordinates[vertice][0] = value;
    else if(coordinate == 'y')
        coordinates[vertice][1] = value;
}
//--------------------------------------------------------------------------------
unsigned TDrosophila::GetColor(short vertice){
    return color[vertice];
}
//--------------------------------------------------------------------------------
void TDrosophila::PutColor(short vertice, short value){
    color[vertice] = value;
}
//--------------------------------------------------------------------------------
unsigned TDrosophila::GetColor_temp(short vertice){
    return color_temp[vertice];
}
//--------------------------------------------------------------------------------
void TDrosophila::PutColor_temp(short vertice, short value){
    color_temp[vertice] = value;
}
//--------------------------------------------------------------------------------
short TDrosophila::GetNV(){
    return NV;
}
//--------------------------------------------------------------------------------
short TDrosophila::GetNE(){
    return NE;
}
//--------------------------------------------------------------------------------
short TDrosophila::GetFileNo(){
    return file;
}
//--------------------------------------------------------------------------------
short TDrosophila::GetK(){
    return K;
}
//--------------------------------------------------------------------------------
