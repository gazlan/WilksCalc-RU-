/* ******************************************************************** **
** @@ WilksCalc
** @  Copyrt : 
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

#ifndef _WILKS_CALC_HPP_
#define _WILKS_CALC_HPP_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
   #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"            // main symbols

/* ******************************************************************** **
** @@ internal defines
** ******************************************************************** */

enum GENDER
{
   GENDER_NONE,
   GENDER_MEN,
   GENDER_WOMEN
};

/* ******************************************************************** **
** @@ struct ListLine
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

struct LIST_LINE
{
   int            _iNum;
   double         _fWeight;
   double         _fResult1;
   double         _fResult2;
   double         _fWilks;
   double         _fCorrection;
   double         _fSum1;
   double         _fSum2;
   double         _fSportValue;
   char           _pszTitle[MAX_PATH + 1];
};

/* ******************************************************************** **
** @@ class CWilksCalcApp : public CWinApp
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update : 
** @  Notes  : 
** ******************************************************************** */

class CWilksCalcApp : public CWinApp
{
   private:

      HANDLE      _hMutex;

   public:

      CWilksCalcApp();

   // Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CWilksCalcApp)
   public:

   virtual BOOL   InitInstance();
   virtual int    ExitInstance();
   //}}AFX_VIRTUAL

   // Implementation

   //{{AFX_MSG(CWilksCalcApp)
      // NOTE - the ClassWizard will add and remove member functions here.
      //    DO NOT EDIT what you see in these blocks of generated code !
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};


/* ******************************************************************** **
** @@ internal prototypes
** ******************************************************************** */

/* ******************************************************************** **
** @@ external global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@ static global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@ Global Function Prototypes
** ******************************************************************** */

double CalcWilks(double fWeight,GENDER Gender);
double CalcCorrection(double fWeight);

#endif

/* ******************************************************************** **
** @@                   The End
** ******************************************************************** */
