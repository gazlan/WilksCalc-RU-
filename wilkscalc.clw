; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCalc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wilkscalc.h"
LastPage=0

ClassCount=5
Class1=CCalc
Class2=CMen
Class3=CWilksCalcSheet
Class4=CWilksCalcApp
Class5=CWomen

ResourceCount=3
Resource1=IDD_MEN
Resource2=IDD_WOMEN
Resource3=IDD_CALC

[CLS:CCalc]
Type=0
BaseClass=CPropertyPage
HeaderFile=Calc.h
ImplementationFile=Calc.cpp
LastObject=IDC_CALCLIST
Filter=D
VirtualFilter=idWC

[CLS:CMen]
Type=0
BaseClass=CPropertyPage
HeaderFile=Men.h
ImplementationFile=Men.cpp
LastObject=CMen

[CLS:CWilksCalcSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=sheet.h
ImplementationFile=sheet.cpp

[CLS:CWilksCalcApp]
Type=0
BaseClass=CWinApp
HeaderFile=wilkscalc.h
ImplementationFile=WilksCalc.cpp
LastObject=CWilksCalcApp

[CLS:CWomen]
Type=0
BaseClass=CPropertyPage
HeaderFile=Women.h
ImplementationFile=Women.cpp

[DLG:IDD_CALC]
Type=1
Class=CCalc
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDT_WEIGHT,edit,1350631553
Control3=IDC_STATIC,static,1342308865
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDT_MEN,edit,1350633601
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDT_WOMEN,edit,1350633601
Control8=IDC_CALCLIST,SysListView32,1350635917

[DLG:IDD_MEN]
Type=1
Class=CMen
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDT_SPORTSMAN,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDT_WEIGHT,edit,1350631553
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDT_RESULT,edit,1350631553
Control7=IDC_EDT_SUM1,edit,1350633601
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDT_RESULT2,edit,1350631553
Control10=IDC_EDT_SUM2,edit,1350633601
Control11=IDC_STATIC,static,1342308352
Control12=IDC_REDT_SPORTVALUE,RICHEDIT,1350633600
Control13=IDC_BTN_APPEND,button,1342242817
Control14=IDC_BTN_REPORT,button,1342242816
Control15=IDC_MENLIST,SysListView32,1350635917

[DLG:IDD_WOMEN]
Type=1
Class=CWomen
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDT_SPORTSMAN,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDT_WEIGHT,edit,1350631553
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDT_RESULT,edit,1350631553
Control7=IDC_EDT_SUM1,edit,1350633601
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDT_RESULT2,edit,1350631553
Control10=IDC_EDT_SUM2,edit,1350633601
Control11=IDC_STATIC,static,1342308352
Control12=IDC_REDT_SPORTVALUE,RICHEDIT,1350633600
Control13=IDC_BTN_APPEND,button,1342242817
Control14=IDC_BTN_REPORT,button,1342242816
Control15=IDC_WOMENLIST,SysListView32,1350635917

