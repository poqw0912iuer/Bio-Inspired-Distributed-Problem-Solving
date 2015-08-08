#pragma hdrstop
#include <math.h>
#include "TVC_Manager.h"
#include "TLocalStateManager.h"
#include <vector.h>
#include "TDrosophila.h"
#include "Unit2.h"
#include "PuzzleSolver.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TVC_Manager::Solver(TDrosophila graph, unsigned M, float Multiplier)
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
    //****** set list of color options ******
    available_colors.clear();
    for(unsigned i = 0; i < graph.GetNV(); ++i){
        vector<unsigned> row;
        for(unsigned j = 1; j <= graph.GetK(); ++j)
            row.push_back(j);
        available_colors.push_back(row);
    }
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
                        if(available_colors[j].size() > 0)
                            graph.PutColor_temp(j, available_colors[j][random(available_colors[j].size())]);
                        for(unsigned k = 0; k < neighbours[j].size(); ++k){
                            if(graph.GetColor_temp(neighbours[j][k]) == graph.GetColor_temp(j))
                                graph.PutColor_temp(j, 0);
                            graph.PutColor_temp(neighbours[j][k], 0);
                        }
                    }
            }
            //************* Round 2 *************
            for(unsigned j = 0; j < graph.GetNV(); ++j){
                if(graph.GetColor_temp(j) != 0){
                    graph.PutColor(j, graph.GetColor_temp(j));
                    for(unsigned k = 0; k < neighbours[j].size(); ++k)
                        erase(available_colors[neighbours[j][k]], graph.GetColor(j));
                }
            }
            //*********** Primitive Backtracking ***********
            for(unsigned j = 0; j < graph.GetNV(); ++j){
                short count = 0;
                for(unsigned k = 0; k < neighbours[j].size(); ++k)
                    if(available_colors[neighbours[j][k]].size() == 0 && graph.GetColor(neighbours[j][k] == 0))
                        count += 1;
                if(count > 0)
                    goto uncolor;
                else
                    goto next;
                uncolor:
                Form1->Label3->Caption = "Wykryto";
                if(rand() / double(RAND_MAX) < 0.50){
                    graph.PutColor(j,0);
                    // ***** Available colors *****
                    for(unsigned l = 0; l < neighbours[j].size(); ++l){
                        available_colors[neighbours[j][l]].clear();
                        for(unsigned m = 1; m <= graph.GetK(); ++m)
                            available_colors[neighbours[j][l]].push_back(m);
                        for(unsigned m = 0; m < neighbours[neighbours[j][l]].size(); ++m){
                            erase(available_colors[neighbours[j][l]], graph.GetColor(neighbours[neighbours[j][l]][m]));
                        }
                    }
                    // ****************************
                }
                next:
            }
            //************************************
            for(unsigned j = 0; j < graph.GetNV(); ++j)
                graph.PutColor_temp(j, 0);
        }
        p *= Multiplier;
    }
}
//---------------------------------------------------------------------------
void TVC_Manager::Violations(TDrosophila graph){
    violations1 = 0;   violations2 = 0;
    // Two adjacent nodes have the same color
    for(unsigned i = 0; i < graph.GetNV(); ++i)
        for(unsigned k = 0; k < neighbours[i].size(); ++k)
            if(graph.GetColor(neighbours[i][k]) == graph.GetColor(i) && graph.GetColor(i) != 0) violations1 += 1;
    // Uncovered node
    for(unsigned i = 0; i < graph.GetNV(); ++i)
        if(graph.GetColor(i) == 0) violations2 += 1;
    //******************************************
    Form2->Label1->Caption = "violation1 = " + IntToStr(violations1);
    Form2->Label2->Caption = "violation2 = " + IntToStr(violations2);
    Form2->Label3->Caption = "";
}
//---------------------------------------------------------------------------
void TVC_Manager::erase(vector<unsigned> &vec, unsigned VALUE)const{
    for( std::vector<unsigned>::iterator iter = vec.begin(); iter != vec.end(); ++iter )
        if( *iter == VALUE ){
            vec.erase( iter );
            break;
        }
}
//---------------------------------------------------------------------------
