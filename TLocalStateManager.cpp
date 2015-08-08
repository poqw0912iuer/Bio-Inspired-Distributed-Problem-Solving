#include <vcl.h>
#include <iostream>
#include <fstream.h>
#pragma hdrstop
#include "TLocalStateManager.h"
#include "Unit2.h"
#include "TDrosophila.h"
#include "PuzzleSolver.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TLocalStateManager::Gnerator(TDrosophila graph)
{
    short NV, NE, read_x, read_y;
    float read;
    std::fstream myStream;
    short file_no = graph.GetFileNo();
    if(file_no == 1)
        myStream.open( "Graph 1 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file_no == 2)
        myStream.open( "Graph 2 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file_no == 3)
        myStream.open( "Graph 3 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file_no == 4)
        myStream.open( "Graph 4 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file_no == 5)
        myStream.open( "Graph 5 (K = 6) .txt", std::ios::in | std::ios::out );
    else if(file_no == 6)
        myStream.open( "Graph 6 (K = 4) .txt", std::ios::in | std::ios::out );
    else if(file_no == 7)
        myStream.open( "graph-color-3.txt", std::ios::in | std::ios::out );

    if( myStream.good() == true){
        myStream >> NV;
        myStream >> NE;
        for(int i = 0; i < NV; i++){
            myStream >> read;
            myStream >> read;
            graph.PutCoordinates(read, i, 'x');
            myStream >> read;
            graph.PutCoordinates(read, i, 'y');
        }
        for(int i = 0; i < NV; i++)
            for(int j = 0; j < NV; j++)
                graph.PutArray(0, i, j);
        for(int i = 0; i < NE; i++){
            myStream >> read_x;
            myStream >> read_y;
            graph.PutArray(1, read_x, read_y);
            graph.PutArray(1, read_y, read_x);
        }
        for(int i = 0; i < NV; i++){
            graph.PutColor(i, 0);//random(graph.GetK()) + 1);
            graph.PutColor_temp(i, 0);//random(graph.GetK()) + 1);
        }
        myStream.close();
    }else cout << "B£¥D: nie mo¿na otworzyæ pliku do odczytu." << endl; //*/     !!!!!!!
}
//---------------------------------------------------------------------------
unsigned TLocalStateManager::Get_Neighbours(unsigned vertice, unsigned neighbour){
    return neighbours[vertice][neighbour];
}
//---------------------------------------------------------------------------
void TLocalStateManager::RecordData(TDrosophila graph){
    Form1->coordinates = new float*[graph.GetNV()];
    for (int i = 0; i < graph.GetNV(); ++i)
        Form1->coordinates[i] = new float[2];

    Form1->array = new short*[graph.GetNV()];
    for (int i = 0; i < graph.GetNV(); ++i)
        Form1->array[i] = new short[graph.GetNV()];
    Form1->color = new short[graph.GetNV()]; 

    for(int vertice = 0; vertice < graph.GetNV(); ++vertice){
        Form1->coordinates[vertice][0] = graph.GetCoordinates(vertice, 'x');
        Form1->coordinates[vertice][1] = graph.GetCoordinates(vertice, 'y');
    }
    for(int i = 0; i < graph.GetNV(); i++)
        for(int j = 0; j < graph.GetNV(); j++)
            Form1->array[i][j] = graph.GetArray(i, j);
    for(int vertice = 0; vertice < graph.GetNV(); ++vertice)
        Form1->color[vertice] = graph.GetColor(vertice);
    Form1->NV = graph.GetNV();
}
//---------------------------------------------------------------------------
void TLocalStateManager::Plot(){
    float xmin = 1e6; float xmax = -1e6; float ymin = 1e6; float ymax = -1e6;
    short r = 8;      short bound = 20;      // By bound mean boundary
    for(int i = 0; i < Form1 -> NV; i++){
        if(Form1->coordinates[i][0] < xmin)   xmin = Form1->coordinates[i][0];
        if(Form1->coordinates[i][0] > xmax)   xmax = Form1->coordinates[i][0];
        if(Form1->coordinates[i][1] < ymin)   ymin = Form1->coordinates[i][1];
        if(Form1->coordinates[i][1] > ymax)   ymax = Form1->coordinates[i][1];
    }

    float rwidth = xmax - xmin;                              float rheight = ymax - ymin;
    float ewidth = Form2 -> ClientWidth - 2 * (bound + r);   float eheight = Form2 -> ClientHeight - 2 * (bound + r);
    Form2 -> Show();   Form2 -> Canvas -> Rectangle(bound, bound, Form2 -> ClientWidth - bound, Form2 -> ClientHeight - bound);
    for(int i = 0; i < Form1 -> NV; i ++)
    for(int j = 0; j < Form1 -> NV; j ++){
        if(Form1->array[i][j] == 1){
            Form2 -> Canvas -> MoveTo(Form1->coordinates[i][0] * ewidth / rwidth + bound + r - (xmin + rwidth / 2 - rwidth / 2) * ewidth / rwidth,
                                   - Form1->coordinates[i][1] * eheight / rheight + bound + r + (ymin + rheight / 2 + rheight / 2) * eheight / rheight);
            Form2 -> Canvas -> LineTo(Form1->coordinates[j][0] * ewidth / rwidth + bound + r - (xmin + rwidth / 2 - rwidth / 2) * ewidth / rwidth,
                                   - Form1->coordinates[j][1] * eheight / rheight + bound + r + (ymin + rheight / 2 + rheight / 2) * eheight / rheight);
        }
    }
    for( int i = 0; i < Form1 -> NV; i ++){
        if(Form1->color[i] == 0)   Form2 -> Canvas->Brush->Color = clGray;
        else if(Form1->color[i] == 1)   Form2 -> Canvas->Brush->Color = clBlue;
        else if(Form1->color[i] == 2)   Form2 -> Canvas->Brush->Color = clRed;
        else if(Form1->color[i] == 3)   Form2 -> Canvas->Brush->Color = clYellow;
        else if(Form1->color[i] == 4)   Form2 -> Canvas->Brush->Color = clPurple;
        else if(Form1->color[i] == 5)   Form2 -> Canvas->Brush->Color = clMaroon;
        else if(Form1->color[i] == 6)   Form2 -> Canvas->Brush->Color = clBlack;
        else if(Form1->color[i] == 7)   Form2 -> Canvas->Brush->Color = clFuchsia;
        else if(Form1->color[i] == 8)   Form2 -> Canvas->Brush->Color = clAqua;
        else if(Form1->color[i] == 9)   Form2 -> Canvas->Brush->Color = clLime;
        else if(Form1->color[i] == 10)   Form2 -> Canvas->Brush->Color = clTeal;
        else if(Form1->color[i] == 11)   Form2 -> Canvas->Brush->Color = clGreen;
        else if(Form1->color[i] == 12)   Form2 -> Canvas->Brush->Color = clOlive;

        Form2 -> Canvas -> Ellipse(
            Form1->coordinates[i][0] * ewidth / rwidth + bound + r - (xmin + rwidth / 2 - rwidth / 2) * ewidth / rwidth - r,
            - Form1->coordinates[i][1] * eheight / rheight + bound + r + (ymin + rheight / 2 + rheight / 2) * eheight / rheight - r,
            Form1->coordinates[i][0] * ewidth / rwidth + bound + r - (xmin + rwidth / 2 - rwidth / 2) * ewidth / rwidth + r,
            - Form1->coordinates[i][1] * eheight / rheight + bound + r + (ymin + rheight / 2 + rheight / 2) * eheight / rheight + r);
        Form2 -> Canvas -> Brush -> Color = clBtnFace;
    }
}
//---------------------------------------------------------------------------
