object Form1: TForm1
  Left = 190
  Top = 92
  Width = 1272
  Height = 762
  Caption = 'Bio-Inspired Distributed Problem Solving'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 32
    Top = 48
    Width = 15
    Height = 13
    Caption = 't = '
  end
  object Label4: TLabel
    Left = 32
    Top = 72
    Width = 16
    Height = 13
    Caption = 'File'
  end
  object Label5: TLabel
    Left = 8
    Top = 96
    Width = 47
    Height = 13
    Caption = 'Colors no.'
  end
  object Label1: TLabel
    Left = 40
    Top = 120
    Width = 9
    Height = 13
    Caption = 'M'
  end
  object Label2: TLabel
    Left = 8
    Top = 144
    Width = 41
    Height = 13
    Caption = 'Multiplier'
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 121
    Height = 25
    Caption = 'Inspect'
    TabOrder = 0
    OnClick = Button1Click
  end
  object StringGrid2: TStringGrid
    Left = 496
    Top = 8
    Width = 345
    Height = 257
    ColCount = 11
    DefaultColWidth = 30
    DefaultRowHeight = 22
    RowCount = 11
    TabOrder = 1
  end
  object StringGrid4: TStringGrid
    Left = 448
    Top = 272
    Width = 345
    Height = 257
    ColCount = 11
    DefaultColWidth = 30
    DefaultRowHeight = 22
    RowCount = 11
    TabOrder = 2
  end
  object StringGrid5: TStringGrid
    Left = 928
    Top = 8
    Width = 129
    Height = 721
    ColCount = 3
    DefaultColWidth = 40
    DefaultRowHeight = 16
    RowCount = 42
    TabOrder = 3
    RowHeights = (
      16
      16
      16
      16
      19
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16)
  end
  object StringGrid6: TStringGrid
    Left = 136
    Top = 6
    Width = 705
    Height = 707
    ColCount = 41
    DefaultColWidth = 16
    DefaultRowHeight = 16
    RowCount = 41
    TabOrder = 4
  end
  object StringGrid7: TStringGrid
    Left = 840
    Top = 6
    Width = 41
    Height = 707
    ColCount = 2
    DefaultColWidth = 16
    DefaultRowHeight = 16
    RowCount = 41
    TabOrder = 5
    ColWidths = (
      16
      18)
    RowHeights = (
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16)
  end
  object StringGrid8: TStringGrid
    Left = 880
    Top = 6
    Width = 41
    Height = 707
    ColCount = 2
    DefaultColWidth = 16
    DefaultRowHeight = 16
    RowCount = 41
    TabOrder = 6
    RowHeights = (
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      14
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16)
  end
  object Button2: TButton
    Left = 8
    Top = 176
    Width = 121
    Height = 25
    Caption = 'Graph coloring'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 56
    Top = 72
    Width = 33
    Height = 21
    TabOrder = 8
    Text = '7'
  end
  object Edit3: TEdit
    Left = 56
    Top = 96
    Width = 33
    Height = 21
    TabOrder = 9
    Text = '4'
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 208
    Width = 121
    Height = 81
    Caption = 'Problem'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    object RadioButton1: TRadioButton
      Left = 8
      Top = 24
      Width = 41
      Height = 17
      Caption = 'MIS'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 48
      Width = 33
      Height = 17
      Caption = 'VC'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = True
    end
  end
  object StringGrid1: TStringGrid
    Left = 1064
    Top = 6
    Width = 193
    Height = 707
    ColCount = 11
    DefaultColWidth = 16
    DefaultRowHeight = 16
    RowCount = 41
    TabOrder = 11
    ColWidths = (
      16
      18
      16
      16
      16
      16
      16
      16
      16
      16
      16)
    RowHeights = (
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16
      16)
  end
  object Edit1: TEdit
    Left = 56
    Top = 120
    Width = 33
    Height = 21
    TabOrder = 12
    Text = '34'
  end
  object Edit4: TEdit
    Left = 56
    Top = 144
    Width = 33
    Height = 21
    TabOrder = 13
    Text = '2'
  end
end
