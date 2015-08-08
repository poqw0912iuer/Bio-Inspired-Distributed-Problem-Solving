#ifndef PuzzleSolverH
#define PuzzleSolverH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TLabel *Label3;
        TStringGrid *StringGrid2;
        TStringGrid *StringGrid4;
        TStringGrid *StringGrid5;
        TStringGrid *StringGrid6;
        TStringGrid *StringGrid7;
        TStringGrid *StringGrid8;
        TButton *Button2;
        TLabel *Label4;
        TEdit *Edit2;
        TLabel *Label5;
        TEdit *Edit3;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TStringGrid *StringGrid1;
        TEdit *Edit1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        int r;
        short K, M;
        float Multiplier;
        short file_no, NV;
        float **coordinates;
        short **array;
        short *color;
        void erase(vector<unsigned> &vec, unsigned VALUE)const;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
