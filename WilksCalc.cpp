/* ******************************************************************** **
** @@ Wilks Calc
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

#include "stdafx.h"

#include <math.h>
#include <afxdtctl.h>

#include "resource.h"

#include "vector.h"
#include "vector_sorted.h"
#include "Men.h"
#include "Women.h"
#include "Calc.h"
#include "sheet.h"
#include "wilkscalc.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef NDEBUG
#pragma optimize("gsy",on)
#pragma comment(linker,"/FILEALIGN:512 /MERGE:.rdata=.text /MERGE:.data=.text /SECTION:.text,EWR /IGNORE:4078")
#endif

/* ******************************************************************** **
** @@                   internal defines
** ******************************************************************** */

/* ******************************************************************** **
** @@                   internal prototypes
** ******************************************************************** */

static double CalcWilksMen  (double fWeight);
static double CalcWilksWomen(double fWeight);

/* ******************************************************************** **
** @@                   external global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@                   static global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@                   real code
** ******************************************************************** */

CWilksCalcApp     theApp;

/* ******************************************************************** **
** @@ CWilksCalcApp::MESSAGE_MAP()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

BEGIN_MESSAGE_MAP(CWilksCalcApp,CWinApp)
   //{{AFX_MSG_MAP(CWilksCalcApp)
      // NOTE - the ClassWizard will add and remove mapping macros here.
      //    DO NOT EDIT what you see in these blocks of generated code!
   //}}AFX_MSG
END_MESSAGE_MAP()

/* ******************************************************************** **
** @@ CWilksCalcApp::CWilksCalcApp()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : Constructor
** ******************************************************************** */

CWilksCalcApp::CWilksCalcApp()
{
   // TODO: add construction code here,
   // Place all significant initialization in InitInstance
}

/* ******************************************************************** **
** @@ CWilksCalcApp::InitInstance()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

BOOL CWilksCalcApp::InitInstance()
{
   // Call this function to initialize the rich edit control for the application. 
   // It will also initialize the common controls library, if the library hasn’t 
   // already been initialized for the process. If you use the rich edit control 
   // directly from your MFC application, you should call this function to assure 
   // that MFC has properly initialized the rich edit control runtime. 
   AfxInitRichEdit();

   AfxEnableControlContainer();

   CoInitialize(NULL);

   // Only One Instance of this App is available !
   _hMutex = CreateMutex(NULL,TRUE,"WilksCalc Mutex");

   if (!_hMutex)
   {
      return FALSE;
   }

   if (GetLastError() == ERROR_ALREADY_EXISTS)
   {
      return FALSE;
   }

   // Standard initialization
   // If you are not using these features and wish to reduce the size
   // of your final executable, you should remove from the following
   // the specific initialization routines you do not need.

   #ifdef _AFXDLL
   Enable3dControls();         // Call this when using MFC in a shared DLL
   #else
   Enable3dControlsStatic();   // Call this when linking to MFC statically
   #endif

   CWilksCalcSheet     WilksCalcSheet(_T("   Wilks Calc"));

   m_pMainWnd = &WilksCalcSheet;

   CCommandLineInfo     cmdInfo;
   
   ParseCommandLine(cmdInfo);

   if (!cmdInfo.m_strFileName.IsEmpty())
   {
      //
   }

   WilksCalcSheet.DoModal();

   // Since the dialog has been closed, return FALSE so that we exit the
   // application, rather than start the application's message pump.
   return FALSE;
}

/* ******************************************************************** **
** @@ CWilksCalcApp::ExitInstance()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

int CWilksCalcApp::ExitInstance()
{
   CloseHandle(_hMutex);
   _hMutex = INVALID_HANDLE_VALUE;

   CoUninitialize();

   return CWinApp::ExitInstance();
}

/* ******************************************************************** **
** @@ CalcWilks()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

double CalcWilks(double fWeight,GENDER Gender)
{
   switch (Gender)
   {
      case GENDER_MEN:
      {
         return CalcWilksMen(fWeight);
      }
      case GENDER_WOMEN:
      {
         return CalcWilksWomen(fWeight);
      }
      default :
      {
         return 0.0;
      }
   }
}

/* ******************************************************************** **
** @@ CalcWilksMen()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

static double CalcWilksMen(double fWeight)
{
   const double   AA = -216.0475144;
   const double   BB =   16.2606339;
   const double   CC =   -0.002388645;
   const double   DD =   -0.00113732;
   const double   EE =    7.01863E-06;
   const double   FF =   -1.291E-08;

   double   F1 = AA;
   double   F2 = BB * fWeight;
   double   F3 = CC * pow(fWeight,2.0);
   double   F4 = DD * pow(fWeight,3.0);
   double   F5 = EE * pow(fWeight,4.0);
   double   F6 = FF * pow(fWeight,5.0);

   return 500.0 / (F1 + F2 + F3 + F4 + F5 + F6);
}

/* ******************************************************************** **
** @@ CalcWilksWomen()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

static double CalcWilksWomen(double fWeight)
{                 
   const double   AA = 594.31747775582;
   const double   BB = -27.23842536447;
   const double   CC =   0.82112226871;
   const double   DD =  -0.00930733913;
   const double   EE =   0.00004731582;
   const double   FF =  -0.00000009054;

   double   F1 = AA;
   double   F2 = BB * fWeight;
   double   F3 = CC * pow(fWeight,2.0);
   double   F4 = DD * pow(fWeight,3.0);
   double   F5 = EE * pow(fWeight,4.0);
   double   F6 = FF * pow(fWeight,5.0);

   return 500.0 / (F1 + F2 + F3 + F4 + F5 + F6);
}

/* ******************************************************************** **
** @@ CalcCorrection()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

double CalcCorrection(double fWeight)
{
   int   iWeight = (int)fWeight;

   if (iWeight < 60)
   {
      return 1.0;
   }
   else if ((iWeight >= 60) && (iWeight < 70))
   {
      return 1.0;
   }
   else if ((iWeight >= 70) && (iWeight < 80))
   {
      return 1.05;
   }
   else if ((iWeight >= 80) && (iWeight < 90))
   {
      return 1.1;
   }
   else if ((iWeight >= 90) && (iWeight < 100))
   {
      return 1.15;
   }
   else if ((iWeight >= 100) && (iWeight < 110))
   {
      return 1.2;
   }
   else if ((iWeight >= 110) && (iWeight < 120))
   {
      return 1.25;
   }
   else if ((iWeight >= 120) && (iWeight < 130))
   {
      return 1.3;
   }
   else if ((iWeight >= 130) && (iWeight < 140))
   {
      return 1.35;
   }
   else
   {
      return 1.4;
   }
}

/* ******************************************************************** **
** @@                   The End
** ******************************************************************** */
