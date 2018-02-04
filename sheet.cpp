/* ******************************************************************** **
** @@ Sheet
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Dscr   :
** ******************************************************************** */

/* ******************************************************************** **
** uses pre-compiled headers
** ******************************************************************** */

#include "stdafx.h"
#include <afxdtctl.h>
#include <math.h>

#include "resource.h"

#include "vector.h"
#include "vector_sorted.h"
#include "Men.h"
#include "Women.h"
#include "Calc.h"
#include "sheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/* ******************************************************************** **
** @@ internal defines
** ******************************************************************** */

#define WM_TRAY_NOTIFY        (WM_USER + 1)

const char* const    pszWC_TITLE = "Wilks Calc";

/* ******************************************************************** **
** @@ internal prototypes
** ******************************************************************** */

/* ******************************************************************** **
** @@ external global variables
** ******************************************************************** */

extern DWORD      dwKeepError = 0;

/* ******************************************************************** **
** @@ static global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@ real code
** ******************************************************************** */

/* ******************************************************************** **
** @@ CWilksCalcSheet::CWilksCalcSheet()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : Constructor
** ******************************************************************** */

// IMPLEMENT_DYNAMIC(CWilksCalcSheet,CPropertySheet)

CWilksCalcSheet::CWilksCalcSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
:  CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
   //{{AFX_DATA_INIT(CWilksCalcSheet)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT

   _bVisible = FALSE;

   AddControlPages();
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::CWilksCalcSheet()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : Constructor
** ******************************************************************** */

CWilksCalcSheet::CWilksCalcSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
:  CPropertySheet(pszCaption,pParentWnd,iSelectPage)
{
   //{{AFX_DATA_INIT(CWilksCalcSheet)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT

   _bVisible = FALSE;

   AddControlPages();
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::~CWilksCalcSheet()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : Destructor
** ******************************************************************** */

CWilksCalcSheet::~CWilksCalcSheet()
{
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::DoDataExchange()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void CWilksCalcSheet::DoDataExchange(CDataExchange* pDX)
{
   CPropertySheet::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CWilksCalcSheet)
      // NOTE: the ClassWizard will add DDX and DDV calls here
   //}}AFX_DATA_MAP
}

/* ******************************************************************** **
** @@ MESSAGE_MAP()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** **
****************************************************************** */

BEGIN_MESSAGE_MAP(CWilksCalcSheet, CPropertySheet)
   //{{AFX_MSG_MAP(CWilksCalcSheet)
   ON_WM_SYSCOMMAND()
   ON_WM_QUERYDRAGICON()
   ON_WM_DROPFILES() // Drag-n-Drop message map entry
   ON_COMMAND(IDCANCEL,OnClose)
   ON_WM_CLOSE()
   ON_WM_DESTROY()
   ON_MESSAGE(WM_TRAY_NOTIFY, OnTrayNotify)
   ON_WM_WINDOWPOSCHANGING()
   ON_WM_SIZE()
   //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/* ******************************************************************** **
** @@ CWilksCalcSheet::AddControlPages()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void CWilksCalcSheet::AddControlPages()
{
   // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
   m_psh.dwFlags |= PSP_USEHICON;
   m_psh.hIcon    = m_hIcon;

   AddPage(&m_Men);
   AddPage(&m_Women);
   AddPage(&m_Calc);
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnInitDialog()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CWilksCalcSheet::OnInitDialog()
{
   CPropertySheet::OnInitDialog(); // init the sheet before getting ClientRect

   CenterWindow();

   DragAcceptFiles();
   
   INITCOMMONCONTROLSEX       ICEx; // Structure for control initialization.
   
   ICEx.dwICC = ICC_LISTVIEW_CLASSES;
   
   InitCommonControlsEx(&ICEx);

   // Hide buttons
   GetDlgItem(IDOK)        ->ShowWindow(SW_HIDE);
   GetDlgItem(IDCANCEL)    ->ShowWindow(SW_HIDE);
   GetDlgItem(ID_APPLY_NOW)->ShowWindow(SW_HIDE);
   
   // Disable
   GetDlgItem(IDOK)        ->EnableWindow(FALSE);
   GetDlgItem(IDCANCEL)    ->EnableWindow(FALSE);
   GetDlgItem(ID_APPLY_NOW)->EnableWindow(FALSE);
   
   CRect    RectOK;
   CRect    RectTab; 

   //Get button sizes and positions 
   GetDlgItem(IDOK)->GetWindowRect(RectOK); 
   GetTabControl() ->GetWindowRect(RectTab); 

   ScreenToClient(RectOK); 
   ScreenToClient(RectTab); 

   //New button -> width, height and Y-coordiate of IDOK 
   // -> X-coordinate of tab control 
   int      iWidth = RectOK.Width() * 4;

   RectOK.left  = RectTab.left - 50; 
   RectOK.right = RectTab.left + iWidth; 

   m_EMail.Create("(c)  gazlan@yandex.ru, 2013",WS_CHILD | WS_VISIBLE | WS_DISABLED | WS_TABSTOP | SS_CENTER,RectOK,this,IDC_EMAIL);

   GetDlgItem(IDOK)->SetWindowText("Отчет");

   // Move right!
   GetDlgItem(ID_APPLY_NOW)->GetWindowRect(RectOK); 

   ScreenToClient(RectOK); 

   GetDlgItem(IDOK)->MoveWindow(RectOK);

   CMenu*   pSysMenu = GetSystemMenu(FALSE);

   if (pSysMenu != NULL)
   {
      pSysMenu->AppendMenu(MF_SEPARATOR);
      pSysMenu->AppendMenu(MF_STRING,IDM_EXIT,"Exit");
   }

   // Set the icon for this dialog.  The framework does this automatically
   // when the application's main window is not a dialog
   SetIcon(m_hIcon,TRUE);         // Set big icon
   SetIcon(m_hIcon,FALSE);        // Set small icon

   SetActivePage(&m_Men);

   return TRUE;
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnSysCommand()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWilksCalcSheet::OnSysCommand(UINT nID,LPARAM lParam)
{
   if (nID == SC_CLOSE)
   {
      _bVisible = FALSE;
      ShowWindow(SW_HIDE);
      SetTrayIcon(this->m_hWnd,IDR_MAINFRAME,m_hIcon,(char*)pszWC_TITLE);
   }
   else if (nID == IDM_EXIT)
   {
      _bVisible = FALSE;
//      PostMessage(WM_CLOSE);
      EndDialog(0);
   }
   else
   {
      CPropertySheet::OnSysCommand(nID,lParam);
   }
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnQueryDragIcon()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

// The system calls this to obtain the cursor to display while the user drags
// the minimized window.
HCURSOR CWilksCalcSheet::OnQueryDragIcon()
{
   return (HCURSOR) m_hIcon;
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::PreTranslateMessage()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CWilksCalcSheet::PreTranslateMessage(MSG* pMsg) 
{  
   if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
   {  
      // Prevent <ESC> exit !
      return TRUE;
   }

   return CPropertySheet::PreTranslateMessage(pMsg);
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnClose()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWilksCalcSheet::OnClose()
{
   CPropertySheet::OnClose();
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnDestroy()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWilksCalcSheet::OnDestroy() 
{
   CPropertySheet::OnDestroy();

   ResetTrayIcon(this->m_hWnd,IDR_MAINFRAME);
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnTrayNotify()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

#pragma warning (disable: 4189)

LRESULT CWilksCalcSheet::OnTrayNotify(WPARAM wParam,LPARAM lParam)
{    
   // wParam - first message parameter of the callback message. 
   // lParam - second message parameter of the callback message. 
   UINT     uID    = (UINT)wParam; 
   UINT     uMouse = (UINT)lParam; 

   if (uMouse == WM_LBUTTONDOWN)
   { 
      Restore();
      // Do not disappear !
      // ResetTrayIcon(this->m_hWnd,IDR_MAINFRAME);
   } 

   return 0; 
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnRestore()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void CWilksCalcSheet::Restore()
{  
   _bVisible = TRUE;
   ShowWindow(SW_NORMAL);
   SetForegroundWindow();
   SetFocus();
}  

/* ******************************************************************** **
** @@ CWilksCalcSheet::SetTrayIcon()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CWilksCalcSheet::SetTrayIcon(HWND hwnd,UINT uID,HICON hicon,LPSTR lpszTip)
{  
   // hwnd - handle to the window to receive callback messages. 
   // uID - identifier of the icon. 
   // hicon - handle to the icon to add. 
   // lpszTip - ToolTip text. 
   NOTIFYICONDATA tnid; 
 
   tnid.cbSize = sizeof(NOTIFYICONDATA); 
   tnid.hWnd   = hwnd; 
   tnid.uID    = uID; 
   tnid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
   tnid.hIcon  = hicon; 

   tnid.uCallbackMessage = WM_TRAY_NOTIFY; 

   if (lpszTip) 
   {
      lstrcpyn(tnid.szTip,lpszTip,sizeof(tnid.szTip)); 
   }
   else 
   {
      *tnid.szTip = 0; 
   } 
   
   BOOL    Res = Shell_NotifyIcon(NIM_ADD,&tnid); 
 
   if (hicon) 
   {
      DestroyIcon(hicon); 
   }

   return Res;
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::ResetTrayIcon()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CWilksCalcSheet::ResetTrayIcon(HWND hwnd,UINT uID)
{
   // hwnd - handle to the window that added the icon. 
   // uID - identifier of the icon to delete. 
   NOTIFYICONDATA tnid; 

   tnid.cbSize = sizeof(NOTIFYICONDATA); 
   tnid.hWnd   = hwnd; 
   tnid.uID    = uID; 

   return Shell_NotifyIcon(NIM_DELETE,&tnid); 
}

/* ******************************************************************** **
** @@ CWilksCalcSheet::OnWindowPosChanging()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

// Now you need to override WM_WINDOWPOSCHANGING. 
// You might have to change your message filtering options 
// to have this message show up in the Class Wizard.
void CWilksCalcSheet::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos) 
{
   CPropertySheet::OnWindowPosChanging(lpwndpos);
      
   if (!_bVisible)
   {
      lpwndpos->flags &= ~SWP_SHOWWINDOW;
      SetTrayIcon(this->m_hWnd,IDR_MAINFRAME,m_hIcon,(char*)pszWC_TITLE);
   }
   
   CPropertySheet::OnWindowPosChanging(lpwndpos);
}

/* ******************************************************************** **
** @@                   The End
** ******************************************************************** */
