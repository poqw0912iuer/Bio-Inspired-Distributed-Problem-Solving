#pragma hdrstop
#include <math.h>
#include "TMIS_Manager.h"
#include "TLocalStateManager.h"
#include "TDrosophila.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TMIS_Manager::Solver(TDrosophila graph, unsigned M, float Multiplier)
{
    //************* set up D *************
    float D = 0;
    neighbours.clear();
    for(unsigned i = 0; i < graph.GetNV(); ++i){
        vector<unsigned> row;
        for(unsigned j = 0; j < graph.GetNV(); ++j){
            if(graph.GetArray(i, j) == 1)
                row.push_back(j);
        }
        neighbours.push_back(row);
        if(neighbours[i].size() > D) D = neighbours[i].size();
    }
    Form2->Label4->Caption = "D = " + FloatToStr(D);
    //************************************
    unsigned repetitions = M * log(graph.GetNV())/log(2);
    float p = 1/D;
    //************* Algorithm *************
    while(p <= 1){
        for(unsigned i = 0; i < repetitions; ++i){
            //************* Round 1 *************
            for(unsigned j = 0; j < graph.GetNV(); ++j){
                if(graph.GetColor(j) == 0)
                    if(rand()/double(RAND_MAX) < p){
                        graph.PutColor_temp(j, 2);
                        for(unsigned k = 0; k < neighbours[j].size(); ++k){
                            if(graph.GetColor_temp(neighbours[j][k]) == 2)
                                graph.PutColor_temp(j, 0);
                            graph.PutColor_temp(neighbours[j][k], 0);
                        }
                    }
            }
            //************* Round 2 *************
            for(unsigned j = 0; j < graph.GetNV(); ++j){
                if(graph.GetColor_temp(j) == 2){
                    graph.PutColor(j, 2);
                    for(unsigned k = 0; k < neighbours[j].size(); ++k)
                        graph.PutColor(neighbours[j][k], 1);
                }
            }
            for(unsigned j = 0; j < graph.GetNV(); ++j)
                graph.PutColor_temp(j, 0);
        }
        p *= Multiplier;
    }
}
//---------------------------------------------------------------------------
void TMIS_Manager::Violations(TDrosophila graph){
    violations1 = 0;   violations2 = 0;   violations3 = 0;
    // Two adjacent nodes are both in L
    for(unsigned i = 0; i < graph.GetNV(); ++i){
        if(graph.GetColor(i) == 2)
            for(unsigned k = 0; k < neighbours[i].size(); ++k)
                if(graph.GetColor(neighbours[i][k]) == 2) violations1 += 1;
    }
    // Node in NL does not have any neighbours in L
    for(unsigned i = 0; i < graph.GetNV(); ++i){
        if(graph.GetColor(i) == 1){
            unsigned Ls = 0;
            for(unsigned k = 0; k < neighbours[i].size(); ++k)
                if(graph.GetColor(neighbours[i][k]) == 2) Ls += 1;
            if(Ls == 0) violations2 += 1;
        }
    }
    // Node is neither in L nor NL
    for(unsigned i = 0; i < graph.GetNV(); ++i)
        if(graph.GetColor(i) == 0) violations3 += 1;
    //******************************************
    Form2->Label1->Caption = "violation1 = " + IntToStr(violations1);
    Form2->Label2->Caption = "violation2 = " + IntToStr(violations2);
    Form2->Label3->Caption = "violation3 = " + IntToStr(violations3);
}
//---------------------------------------------------------------------------
