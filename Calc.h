/* ******************************************************************** **
** @@ Calc
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

/* ******************************************************************** **
** uses precompiled headers
** ******************************************************************** */

#ifndef _CALC_HPP_
#define _CALC_HPP_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* ******************************************************************** **
** @@ struct WILKS_ENTRY
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

struct WILKS_ENTRY
{
   double      _fWeight;
   double      _fMen;
   double      _fWomen;
};   

/* ******************************************************************** **
** @@ class CCalc : public CPropertyPage
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

class CCalc : public CPropertyPage
{
   DECLARE_DYNCREATE(CCalc)

   private:

      SortedVector            _WilksList;
      int                     _iCurrent;
      int                     _iTotal;

// Construction
public:

   CCalc();
   ~CCalc();

// Dialog Data
   //{{AFX_DATA(CCalc)
   enum { IDD = IDD_CALC };
   CListCtrl   m_CalcList;
   CString  m_Weight;
   CString  m_Men;
   CString  m_Women;
   //}}AFX_DATA

// Overrides
   // ClassWizard generate virtual function overrides
   //{{AFX_VIRTUAL(CCalc)
   protected:
   virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   //}}AFX_VIRTUAL

// Implementation
protected:
   // Generated message map functions
   //{{AFX_MSG(CCalc)
   afx_msg void OnGetdispinfoList(NMHDR* pNMHDR, LRESULT* pResult);
   virtual BOOL OnInitDialog();
   afx_msg void OnChangeEdtWeight();
   afx_msg void OnDestroy();
	afx_msg void OnGetdispinfoCalclist(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
   DECLARE_MESSAGE_MAP()

   private:
      
      void  Cleanup();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

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

#endif

/* ******************************************************************** **
** End of File
** ******************************************************************** */
