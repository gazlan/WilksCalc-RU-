/* ******************************************************************** **
** @@ WilksCalcSheet
** @  Copyrt : 
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

#ifndef _WILKS_SHEET_HPP_
#define _WILKS_SHEET_HPP_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* ******************************************************************** **
** @@ internal defines
** ******************************************************************** */

/* ******************************************************************** **
** @@ class CWilksCalcSheet : public CPropertySheet
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

class CWilksCalcSheet : public CPropertySheet
{
   private:

      BOOL           _bVisible;

   public:

      CMen           m_Men;
      CWomen         m_Women;
      CCalc          m_Calc;

   public:

   // Construction
   public:

      CWilksCalcSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
      CWilksCalcSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

   protected:

      void AddControlPages(void);

   // Attributes
   public:

      CStatic              m_EMail;

   // Operations
   public:

      virtual BOOL PreTranslateMessage(MSG* pMsg);

   // Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CWilksCalcSheet)
   protected:

      virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   //}}AFX_VIRTUAL

   // Implementation
   public:

      virtual ~CWilksCalcSheet();

   // Generated message map functions
   protected:

   HICON m_hIcon;

   //{{AFX_MSG(CWilksCalcSheet)
   virtual BOOL OnInitDialog();
   afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
   afx_msg HCURSOR OnQueryDragIcon();
   afx_msg void OnClose();
   afx_msg void OnDestroy();
   afx_msg LRESULT OnTrayNotify(WPARAM wParam,LPARAM lParam);
   afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
   //}}AFX_MSG

   DECLARE_MESSAGE_MAP()

   private:
            
      BOOL     SetTrayIcon(HWND hwnd,UINT uID,HICON hicon,LPSTR lpszTip);
      BOOL     ResetTrayIcon(HWND hwnd, UINT uID);
      void     TrayEvent(WPARAM wParam,LPARAM lParam);
      void     Restore();
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
** @@                   The End
** ******************************************************************** */
