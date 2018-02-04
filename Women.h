/* ******************************************************************** **
** @@ Women
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

/* ******************************************************************** **
** uses precompiled headers
** ******************************************************************** */

#ifndef _WOMEN_HPP_
#define _WOMEN_HPP_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* ******************************************************************** **
** @@ class CWomen : public CPropertyPage
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

class CWomen : public CPropertyPage
{
   DECLARE_DYNCREATE(CWomen)

   private:

      SortedVector            _WomenList;
      double                  _fWeight;
      double                  _fResult1;
      double                  _fResult2;
      double                  _fWilks;
      double                  _fCorrection;
      double                  _fSum1;
      double                  _fSum2;
      double                  _fSportValue;
      int                     _iCurrent;
      CString                 _sReport;  
      bool                    _bNoCheck;

// Construction
public:
   CWomen();
   ~CWomen();

// Dialog Data
   //{{AFX_DATA(CWomen)
   enum { IDD = IDD_WOMEN };
   CListCtrl   m_WomenList;
   CRichEditCtrl  m_SportValue;
   CString  m_Sportsman;
   CString  m_Weight;
   CString  m_Result1;
   CString  m_Result2;
   CString  m_Sum1;
   CString  m_Sum2;
   //}}AFX_DATA

// Overrides
   // ClassWizard generate virtual function overrides
   //{{AFX_VIRTUAL(CWomen)
   protected:
   virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   //}}AFX_VIRTUAL

// Implementation
protected:
   // Generated message map functions
   //{{AFX_MSG(CWomen)
   afx_msg void OnBtnAppend();
   afx_msg void OnBtnReport();
   afx_msg void OnChangeEdtWeight();
   afx_msg void OnChangeEdtResult();
   virtual BOOL OnInitDialog();
   afx_msg void OnGetdispinfoList(NMHDR* pNMHDR, LRESULT* pResult);
   afx_msg void OnChangeEdtResult2();
   afx_msg void OnDestroy();
   afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
   afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
   afx_msg void OnRclickList(NMHDR* pNMHDR, LRESULT* pResult);
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()

   private:

      bool  CopyData(const BYTE* const pBuf,DWORD dwSize);
      bool  OnMenuCopy();
      void  Cleanup();
      void  WriteReport();
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
