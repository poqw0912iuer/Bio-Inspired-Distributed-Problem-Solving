#include <vcl.h>
#include <time.h>
#include <fstream.h>
#include <iostream>
#pragma hdrstop
#include <vector.h>
#include "PuzzleSolver.h"
#include "Unit2.h"
#include "TDrosophila.h"
#include "TMIS_Manager.h"
#include "TVC_Manager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
TMIS_Manager GraphManager;
TVC_Manager  GraphManager2;
time_t t1, t2;
//---------------------------------------------------------------------------
void TForm1::erase(vector<unsigned> &vec, unsigned VALUE)const{
    for( std::vector<unsigned>::iterator iter = vec.begin(); iter != vec.end(); ++iter )
        if( *iter == VALUE ){
            vec.erase( iter );
            break;
        }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{   ///*
    vector<unsigned> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    StringGrid6->Cells[1][1] = v[0];  StringGrid6->Cells[2][1] = v[1];  StringGrid6->Cells[3][1] = v[2];
    StringGrid6->Cells[5][1] = v.size();
    erase(v,3);  erase(v,1);  erase(v,2);
    StringGrid6->Cells[1][3] = v[0];  StringGrid6->Cells[2][3] = v[1];  StringGrid6->Cells[3][3] = v[2];
    StringGrid6->Cells[5][3] = v.size();
    //*/
    file_no = Edit2->Text.ToInt();
    K = Edit3->Text.ToInt();
    M = Edit1->Text.ToInt();
    Multiplier = Edit4->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    short elapsed_time;
    file_no = Edit2->Text.ToInt();
    K = Edit3->Text.ToInt();
    M = Edit1->Text.ToInt();
    Multiplier = Edit4->Text.ToDouble();

        time(&t1);
        TDrosophila graph(file_no, K);
        GraphManager.Gnerator(graph);
        GraphManager.Solver(graph, M, Multiplier);
        for(unsigned i = 0; i < 40 /*GraphManager.neighbours.size()*/; ++i){
            for(unsigned j = 0; j < 11; ++j)
                StringGrid1->Cells[j + 1][ i + 1] = "";
            for(unsigned j = 0; j < GraphManager.neighbours[i].size(); ++j)
                StringGrid1->Cells[j + 1][ i + 1] = GraphManager.Get_Neighbours(i, j);
            StringGrid1->Cells[0][ i + 1] = i;
        } //*/
        unsigned D = 0;
        for(unsigned i = 0; i < GraphManager.neighbours.size(); ++i)
            if(GraphManager.neighbours[i].size() > D) D = GraphManager.neighbours[i].size();
        for(int i = 0; i < 40; i++){
            StringGrid5 -> Cells[0][i + 1] = i;
            StringGrid5 -> Cells[1][i + 1] = graph.GetCoordinates(i, 'x');
            StringGrid5 -> Cells[2][i + 1] = graph.GetCoordinates(i, 'y');
            //graph.PutCoordinates(i, i, 'x');
        }
        for(int i = 0; i < 40; i++)
        for(int j = 0; j < 40; j++){
            StringGrid6 -> Cells[0][j + 1] = j;
            StringGrid6 -> Cells[j + 1][0] = j;
            //StringGrid6 -> Cells[j + 1][i + 1] = i;
            //StringGrid6 -> Cells[j + 1][i + 1] = graph.GetArray(i, j);
            StringGrid6 -> Cells[j + 1][i + 1] = graph.GetArray(i, j);
        }
        for(int i = 0; i < 40; i++)
            StringGrid7 -> Cells[0][i + 1] = i;

        for(int i = 0; i < 40; i++){
            StringGrid8 -> Cells[0][i + 1] = i;
            StringGrid8 -> Cells[1][i + 1] = graph.GetColor(i);
        }
        time(&t2);
        elapsed_time = difftime(t2,t1);
        Label3 -> Caption = "t = " + IntToStr(elapsed_time) + " sec";//*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    file_no = Edit2->Text.ToInt();
    K = Edit3->Text.ToInt();
    M = Edit1->Text.ToInt();
    Multiplier = Edit4->Text.ToDouble();
    if(RadioButton1->Checked == true){
        if(file_no > 7) MessageBox( NULL, "Can not find the File!", "Note", MB_OK);
        else{
            TDrosophila graph(file_no, 1);
            GraphManager.Gnerator(graph);
            GraphManager.Solver(graph, M, Multiplier);
            GraphManager.RecordData(graph);
            GraphManager.Plot();
            GraphManager.Violations(graph);
        }
    }
    else if(RadioButton2->Checked == true){
        if(K < 2 || K > 12) MessageBox( NULL, "Choose K between 2 and 12", "Note", MB_OK);
        else{
            if(file_no > 7) MessageBox( NULL, "Can not find the File!", "Note", MB_OK);
            else{
                TDrosophila graph(file_no, K);
                GraphManager2.Gnerator(graph);
                GraphManager2.Solver(graph, M, Multiplier);
                GraphManager2.RecordData(graph);
                GraphManager2.Plot();
                GraphManager2.Violations(graph);
            }
        }
    }
}
//---------------------------------------------------------------------------
