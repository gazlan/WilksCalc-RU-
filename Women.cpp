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

#include "stdafx.h"

#include <float.h>

#include "vector.h"
#include "vector_sorted.h"
#include "wilkscalc.h"
#include "Women.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/* ******************************************************************** **
** @@ internal defines
** ******************************************************************** */
                                          
#define LIST_DEFAULT_SIZE              (128)
#define LIST_DEFAULT_DELTA             (16)

/* ******************************************************************** **
** @@ Sorter()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

static int Sorter(const void** const pKey1,const void** const pKey2)
{
   LIST_LINE**  p1 = (LIST_LINE**)pKey1;
   LIST_LINE**  p2 = (LIST_LINE**)pKey2;

   return strcmp((*p1)->_pszTitle,(*p2)->_pszTitle);
}

/* ******************************************************************** **
** @@ CWomen::CWomen()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : Constructor
** ******************************************************************** */

IMPLEMENT_DYNCREATE(CWomen, CPropertyPage)

CWomen::CWomen() : CPropertyPage(CWomen::IDD)
{
   //{{AFX_DATA_INIT(CWomen)
   m_Sportsman = _T("");
   m_Weight    = _T("");
   m_Result1   = _T("");
   m_Result2   = _T("");
   m_Sum1      = _T("");
   m_Sum2      = _T("");
   //}}AFX_DATA_INIT

   _fWeight     = 0.0;
   _fResult1    = 0.0;
   _fResult2    = 0.0;
   _fWilks      = 0.0;
   _fCorrection = 0.0;
   _fSum1       = 0.0;
   _fSum2       = 0.0;
   _fSportValue = 0.0;

   _iCurrent = 0;

   _sReport = _T("");

   _bNoCheck = false;
}

/* ******************************************************************** **
** @@ CWomen::~CWomen()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : Destructor
** ******************************************************************** */

CWomen::~CWomen()
{
}

/* ******************************************************************** **
** @@ CWomen::DoDataExchange()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::DoDataExchange(CDataExchange* pDX)
{
   CPropertyPage::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CWomen)
   DDX_Control(pDX, IDC_WOMENLIST, m_WomenList);
   DDX_Control(pDX, IDC_REDT_SPORTVALUE, m_SportValue);
   DDX_Text(pDX, IDC_EDT_SPORTSMAN, m_Sportsman);
   DDV_MaxChars(pDX, m_Sportsman, 128);
   DDX_Text(pDX, IDC_EDT_WEIGHT, m_Weight);
   DDV_MaxChars(pDX, m_Weight, 8);
   DDX_Text(pDX, IDC_EDT_RESULT, m_Result1);
   DDV_MaxChars(pDX, m_Result1, 8);
   DDX_Text(pDX, IDC_EDT_RESULT2, m_Result2);
   DDV_MaxChars(pDX, m_Result2, 8);
   DDX_Text(pDX, IDC_EDT_SUM1, m_Sum1);
   DDV_MaxChars(pDX, m_Sum1, 255);
   DDX_Text(pDX, IDC_EDT_SUM2, m_Sum2);
   DDV_MaxChars(pDX, m_Sum2, 255);
   //}}AFX_DATA_MAP
}

/* ******************************************************************** **
** @@ CWomen::MESSAGE_MAP()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

BEGIN_MESSAGE_MAP(CWomen, CPropertyPage)
   //{{AFX_MSG_MAP(CWomen)
   ON_BN_CLICKED(IDC_BTN_APPEND, OnBtnAppend)
   ON_BN_CLICKED(IDC_BTN_REPORT, OnBtnReport)
   ON_EN_CHANGE(IDC_EDT_WEIGHT, OnChangeEdtWeight)
   ON_EN_CHANGE(IDC_EDT_RESULT, OnChangeEdtResult)
   ON_NOTIFY(LVN_GETDISPINFO, IDC_WOMENLIST, OnGetdispinfoList)
   ON_EN_CHANGE(IDC_EDT_RESULT2, OnChangeEdtResult2)
   ON_WM_DESTROY()
   ON_NOTIFY(NM_CLICK, IDC_WOMENLIST, OnClickList)
   ON_NOTIFY(NM_DBLCLK, IDC_WOMENLIST, OnDblclkList)
   ON_NOTIFY(NM_RCLICK, IDC_WOMENLIST, OnRclickList)
   //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/* ******************************************************************** **
** @@ CWomen::OnBtnAppend()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnBtnAppend() 
{
   UpdateData(TRUE);

   if (m_Sportsman.IsEmpty())
   {
      MessageBox("Не указано имя спортсмена.","Ошибка",MB_OK | MB_ICONERROR);
      return;
   }

   if (_fWeight < FLT_EPSILON)
   {
      MessageBox("Не задан вес спортсмена.","Ошибка",MB_OK | MB_ICONERROR);
      return;
   }

   if (_fResult1 < FLT_EPSILON)
   {
      MessageBox("Не задан результат в первом упражнении.","Ошибка",MB_OK | MB_ICONERROR);
      return;
   }

   if (_fResult2 < FLT_EPSILON)
   {
      MessageBox("Не задан результат во втором упражнении.","Ошибка",MB_OK | MB_ICONERROR);
      return;
   }

   LIST_LINE*     pRecord = new LIST_LINE;

   if (!pRecord)
   {
      // Error !
      return;
   }

   memset(pRecord,0,sizeof(LIST_LINE));

   pRecord->_fWeight     = _fWeight;
   pRecord->_fResult1    = _fResult1;
   pRecord->_fResult2    = _fResult2;
   pRecord->_fWilks      = _fWilks;
   pRecord->_fCorrection = _fCorrection;
   pRecord->_fSum1       = _fSum1;
   pRecord->_fSum2       = _fSum2;
   pRecord->_fSportValue = _fSportValue;

   strncpy(pRecord->_pszTitle,(LPCTSTR)m_Sportsman,MAX_PATH);
   pRecord->_pszTitle[MAX_PATH] = 0; // ASCIIZ

   if (_WomenList.Insert(pRecord) == -1)
   {
      delete pRecord;
      pRecord = NULL;
   }

   DWORD    dwCnt = _WomenList.Count();

   for (DWORD ii = 0; ii < dwCnt; ++ii)
   {
      LIST_LINE*     pRecord = (LIST_LINE*)_WomenList.At(ii);

      if (pRecord)
      {
         pRecord->_iNum = (int)(ii + 1);
      }
   }

   m_WomenList.SetItemCount(dwCnt);
   m_WomenList.UpdateWindow();
}

/* ******************************************************************** **
** @@ CWomen::OnBtnReport()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnBtnReport() 
{
   DWORD    dwCnt = _WomenList.Count();

   if (!dwCnt)
   {
      MessageBox("Список пуст.","Ошибка",MB_OK | MB_ICONEXCLAMATION);
      return;
   }

   char     pszNewFile[MAX_PATH + 1];

   memset(pszNewFile,0,sizeof(pszNewFile));

   DWORD    dwFlags = OFN_EXPLORER | OFN_CREATEPROMPT | OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_OVERWRITEPROMPT;
      
   char     pszFilter[] = "*.txt\0*.txt\0*.*\0*.*\0\0";

   OPENFILENAME         OFN;

   memset(&OFN,0,sizeof(OPENFILENAME));

   OFN.lStructSize     = sizeof(OPENFILENAME); 
   OFN.hwndOwner       = GetSafeHwnd();
   OFN.lpstrFilter     = pszFilter; 
   OFN.nFilterIndex    = 1;
   OFN.lpstrFile       = pszNewFile;
   OFN.nMaxFile        = MAX_PATH;
   OFN.lpstrFileTitle  = NULL;
   OFN.nMaxFileTitle   = MAX_PATH;
   OFN.Flags           = dwFlags;

   if (GetSaveFileName(&OFN) == TRUE)
   {
      _sReport = pszNewFile; 

      WriteReport();
   }
}

/* ******************************************************************** **
** @@ CWomen::WriteReport()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::WriteReport()
{
   if (_sReport.IsEmpty())
   {
      // Error !
      MessageBox("Имя файла отчета не задано.","Ошибка",MB_OK | MB_ICONEXCLAMATION);
      return;
   }

   if (_sReport.Find('.') == -1)
   {
      _sReport += ".women.txt";
   }

   FILE*    pReport = fopen((LPCTSTR)_sReport,"wt");

   if (!pReport)
   {
      // Error !
      return;
   }

   DWORD    dwCnt = _WomenList.Count();

   if (dwCnt)
   {
      fprintf(pReport,"Женщины\n",(LPCTSTR)_sReport);
      fprintf(pReport,"Соб. Вес    Упр. 1      Упр. 2      Сп. Вел.    Вилкс       Поправка    Сумма 1     Сумма 2     Спортсмен\n",(LPCTSTR)_sReport);
      fprintf(pReport,"----------  ----------  ----------  ----------  ----------  ----------  ----------  ----------  ------------------------\n",(LPCTSTR)_sReport);

      for (DWORD ii = 0; ii < dwCnt; ++ii)
      {
         LIST_LINE*     pEntry = (LIST_LINE*)_WomenList.At(ii);

         if (pEntry)
         {  
            fprintf(pReport,"%10.2f  ",pEntry->_fWeight);
            fprintf(pReport,"%10.2f  ",pEntry->_fResult1);
            fprintf(pReport,"%10.2f  ",pEntry->_fResult2);
            fprintf(pReport,"%10.4f  ",pEntry->_fSportValue);
            fprintf(pReport,"%10.4f  ",pEntry->_fWilks);
            fprintf(pReport,"%10.2f  ",pEntry->_fCorrection);
            fprintf(pReport,"%10.4f  ",pEntry->_fSum1);
            fprintf(pReport,"%10.4f  ",pEntry->_fSum2);
            fprintf(pReport,"%s\n",   pEntry->_pszTitle);
         }
      }
   }
         
   fclose(pReport);
   pReport = NULL;
}

/* ******************************************************************** **
** @@ CWomen::OnChangeEdtWeight()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnChangeEdtWeight() 
{
   UpdateData(TRUE);

   // Be Tolerant !
   m_Weight.Replace(',','.');

   _fWeight = atof((LPCTSTR)m_Weight);

   if (!m_Result1.IsEmpty())
   {
      _bNoCheck = true;
      OnChangeEdtResult();
      _bNoCheck = false;
   }
}

/* ******************************************************************** **
** @@ CWomen::OnChangeEdtResult()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnChangeEdtResult() 
{
   UpdateData(TRUE);

   if (m_Weight.IsEmpty())
   {
      m_Result1 = _T("");
      m_Result2 = _T("");
      MessageBox("Не задан вес спортсмена.","Ошибка",MB_OK | MB_ICONERROR);
      UpdateData(FALSE);
      return;
   }

   if (!_bNoCheck)
   {
      if (_fWeight < 40.0)
      {
         MessageBox("Вес спортсмена не должен быть меньше 40 кг.","Ошибка",MB_OK | MB_ICONERROR);
         return;
      }

      if (_fWeight > 151.0)
      {
         MessageBox("Вес спортсмена не должен превышать 151 кг.","Ошибка",MB_OK | MB_ICONERROR);
         return;
      }
   }

   // Be Tolerant !
   m_Result1.Replace(',','.');

   _fWeight  = atof((LPCTSTR)m_Weight);
   _fResult1 = atof((LPCTSTR)m_Result1);
   _fWilks   = CalcWilks(_fWeight,GENDER_WOMEN);
   _fSum1    = 10.0 * _fResult1 * _fWilks;

   m_Sum1.Format("%.4f",_fSum1);

   if (!m_Result2.IsEmpty())
   {
      OnChangeEdtResult2();
   }

   UpdateData(FALSE);
}

/* ******************************************************************** **
** @@ CWomen::OnChangeEdtResult2()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnChangeEdtResult2() 
{
   UpdateData(TRUE);

   if (m_Weight.IsEmpty())
   {
      m_Result1 = _T("");
      m_Result2 = _T("");
      MessageBox("Не задан вес спортсмена.","Ошибка",MB_OK | MB_ICONERROR);
      UpdateData(FALSE);
      return;
   }

   if (m_Result1.IsEmpty())
   {
      m_Result2 = _T("");
      MessageBox("Не задан результат в первом упражнении.","Ошибка",MB_OK | MB_ICONERROR);
      UpdateData(FALSE);
      return;
   }

   if (!_bNoCheck)
   {
      if (_fWeight < 40.0)
      {
         MessageBox("Вес спортсмена не должен быть меньше 40 кг.","Ошибка",MB_OK | MB_ICONERROR);
         return;
      }

      if (_fWeight > 206.0)
      {
         MessageBox("Вес спортсмена не должен превышать 206 кг.","Ошибка",MB_OK | MB_ICONERROR);
         return;
      }
   }

   // Be Tolerant !
   m_Result2.Replace(',','.');

   _fResult2 = atof((LPCTSTR)m_Result2);
   _fSum2    = _fResult2 * _fWilks;

   m_Sum2.Format("%.4f",_fSum2);

   _fCorrection = CalcCorrection(_fWeight);

   _fSportValue = (_fSum1 + _fSum2) * _fCorrection;

   CString     sValue = _T("");
   
   sValue.Format("%.4f",_fSportValue);

   m_SportValue.SetWindowText((LPCTSTR)sValue);

   UpdateData(FALSE);
}

/* ******************************************************************** **
** @@ CWomen::OnInitDialog()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CWomen::OnInitDialog() 
{
   CPropertyPage::OnInitDialog();
   
   CenterWindow();
   
   CHARFORMAT  CF;

   memset(&CF,0,sizeof(CHARFORMAT));
                  
   CF.cbSize      = sizeof(CHARFORMAT);
   CF.dwMask      = CFM_EFFECTS | CFM_SIZE;
   CF.dwEffects   = CFE_BOLD;
   CF.crTextColor = RGB(0,0,255);
   CF.yHeight     = 250;

   m_SportValue.SetDefaultCharFormat(CF);

   PARAFORMAT  PF;

   memset(&PF,0,sizeof(PARAFORMAT));

   PF.cbSize = sizeof(PARAFORMAT);
   PF.dwMask = PFM_ALIGNMENT;
   PF.wAlignment = PFA_CENTER;
   m_SportValue.SetParaFormat(PF);

   _WomenList.Resize(LIST_DEFAULT_SIZE);
   _WomenList.Delta (LIST_DEFAULT_DELTA);

   _WomenList.SetSorter(Sorter);

   // Virtual List !
   m_WomenList.InsertColumn(0,"##",       LVCFMT_LEFT, 40,0);
   m_WomenList.InsertColumn(1,"Вес",      LVCFMT_LEFT, 60,1);
   m_WomenList.InsertColumn(2,"Упр. 1",   LVCFMT_LEFT, 70,2);
   m_WomenList.InsertColumn(3,"Упр. 2",   LVCFMT_LEFT, 70,3);
   m_WomenList.InsertColumn(4,"Результат",LVCFMT_LEFT, 80,4);
   m_WomenList.InsertColumn(5,"Спортсмен",LVCFMT_LEFT,200,5);
   m_WomenList.InsertColumn(6,"Вилкс",    LVCFMT_LEFT, 80,6);
   m_WomenList.InsertColumn(7,"Коэф.",    LVCFMT_LEFT, 60,7);
   m_WomenList.InsertColumn(8,"Сумма 1",  LVCFMT_LEFT, 80,8);
   m_WomenList.InsertColumn(9,"Сумма 2",  LVCFMT_LEFT, 80,9);

   DWORD    dwStyle = m_WomenList.GetExtendedStyle();

   dwStyle |= LVS_OWNERDATA | LVS_EX_FULLROWSELECT | LVS_EX_SUBITEMIMAGES | LVS_EX_FLATSB | LVS_EX_GRIDLINES;
   
   m_WomenList.SetExtendedStyle(dwStyle);
   
   m_WomenList.SetItemCount(_WomenList.Count());
   m_WomenList.UpdateWindow();

   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}

/* ******************************************************************** **
** @@ CWomen::OnClickList()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void CWomen::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
   *pResult = 0;

   NMLISTVIEW*   pNMListView = (NMLISTVIEW*)pNMHDR;
   
   _iCurrent = pNMListView->iItem;
}

/* ******************************************************************** **
** @@ CWomen::CopyData()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

bool CWomen::CopyData(const BYTE* const pBuf,DWORD dwSize)
{
   if (!OpenClipboard())
   { 
      return FALSE; 
   }

   EmptyClipboard(); 

   // Allocate a global memory object for the text. 
   HGLOBAL     hMem = GlobalAlloc(GMEM_MOVEABLE,dwSize); 

   if (!hMem) 
   { 
      CloseClipboard(); 
      return false; 
   } 

   // Lock the handle and copy the text to the buffer. 
   LPVOID      pMem = GlobalLock(hMem); 

   memcpy(pMem,pBuf,dwSize); 
   
   GlobalUnlock(hMem); 

   // Place the handle on the clipboard. 
   SetClipboardData(CF_TEXT,hMem); 

   CloseClipboard(); 
   GlobalFree(hMem);

   return true;
}

/* ******************************************************************** **
** @@ CWomen::OnMenuCopy()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

bool CWomen::OnMenuCopy()
{
   if (!_WomenList.Count())
   {
      return false;
   }

   int      iSelected = m_WomenList.GetSelectedCount();

   ASSERT(iSelected != -1);

   if (iSelected <= 0)
   {
      MessageBox("Копирование невозможно.\nНи одна запись не выбрана.","Ошибка",MB_OK | MB_ICONSTOP);
      return false;         
   }

   POSITION    Pos = m_WomenList.GetFirstSelectedItemPosition();

   if (!Pos)
   {
      MessageBox("Копирование невозможно.\nНи одна запись не выбрана.","Ошибка",MB_OK | MB_ICONSTOP);
      return false;         
   }
   
   CMemFile    MemFile;

   int      iIndex = m_WomenList.GetNextSelectedItem(Pos);

   LIST_LINE*     pEntry = (LIST_LINE*)_WomenList.At(iIndex);

   MemFile.Write(pEntry->_pszTitle,strlen(pEntry->_pszTitle));
   MemFile.Write("\r\n",2);

   CString     sText = _T("");

   sText.Format("Собственный вес:   %.2f",pEntry->_fWeight);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   sText.Format("Первое упражнение: %.4f",pEntry->_fResult1);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   sText.Format("Второе упражнение: %.4f",pEntry->_fResult2);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   sText.Format("Спорт. величина:   %.4f",pEntry->_fSportValue);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   MemFile.Write("\r\n",2);

   sText.Format("Коэфф. Вилкса:     %.4f",pEntry->_fWilks);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   sText.Format("Коэфф. Вынослив.:  %.4f",pEntry->_fCorrection);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   sText.Format("Первая сумма:      %.4f",pEntry->_fSum1);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   sText.Format("Вторая сумма:      %.4f",pEntry->_fSum2);   

   MemFile.Write((LPCTSTR)sText,sText.GetLength());
   MemFile.Write("\r\n",2);

   DWORD    dwSize = MemFile.GetLength();

   BYTE*    pBuf = MemFile.Detach();

   CopyData(pBuf,dwSize);

   free(pBuf);

   MemFile.Close();
      
   return true;
}

/* ******************************************************************** **
** @@ CWomen::OnDblclkList()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
   *pResult = 0;

   NMLISTVIEW*   pNMListView = (NMLISTVIEW*)pNMHDR;
   
   _iCurrent = pNMListView->iItem;

   if (OnMenuCopy())
   {
      MessageBox("Запись скопирована в буфер обмена.","Копирование",MB_OK | MB_ICONINFORMATION);
   }
}

/* ******************************************************************** **
** @@ CWomen::OnRclickList()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnRclickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
   *pResult = 0;

   NMLISTVIEW*   pNMLISTVIEW = (NMLISTVIEW*)pNMHDR;
   
   _iCurrent = pNMLISTVIEW->iItem;

   if (_iCurrent < 0)
   {
      MessageBox("Удаление невозможно.\nНи одна запись не выбрана.","Ошибка",MB_OK | MB_ICONSTOP);
      return;         
   }

   POSITION    Pos = m_WomenList.GetFirstSelectedItemPosition();

   if (!Pos)
   {
      MessageBox("Удаление невозможно.\nНи одна запись не выбрана.","Ошибка",MB_OK | MB_ICONSTOP);
      return;         
   }
   
   if (MessageBox("Действительно удалить?","Удаление",MB_YESNO | MB_DEFBUTTON2 | MB_ICONQUESTION) != IDYES)
   {
      return;
   } 

   int      iIndex = m_WomenList.GetNextSelectedItem(Pos);

   LIST_LINE*     pEntry = (LIST_LINE*)_WomenList.At(iIndex);

   if (pEntry)
   {
      _WomenList.RemoveAt(iIndex);

      delete pEntry;
      pEntry = NULL;
   }

   DWORD    dwCnt = _WomenList.Count();

   for (DWORD ii = 0; ii < dwCnt; ++ii)
   {
      LIST_LINE*     pRecord = (LIST_LINE*)_WomenList.At(ii);

      if (pRecord)
      {
         pRecord->_iNum = (int)(ii + 1);
      }
   }

   m_WomenList.SetItemCount(dwCnt);
   m_WomenList.UpdateWindow();
}

/* ******************************************************************** **
** @@ CWomen::OnGetdispinfoList()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnGetdispinfoList(NMHDR* pNMHDR, LRESULT* pResult) 
{
   *pResult = 0;

   NMLVDISPINFO*     pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);

   LV_ITEM*    pEntry = &(pDispInfo)->item;

   int      iIndex = pEntry->iItem;

   if (pEntry->mask & LVIF_TEXT)
   {
      LIST_LINE*     pRecord = (LIST_LINE*)_WomenList.At(iIndex);

      if (pRecord)
      {
         switch (pEntry->iSubItem)
         {
            case 0: 
            {
               sprintf(pEntry->pszText,"%d",pRecord->_iNum);
               break;
            }
            case 1: 
            {
               sprintf(pEntry->pszText,"%.1f",pRecord->_fWeight);
               break;
            }
            case 2: 
            {
               sprintf(pEntry->pszText,"%.2f",pRecord->_fResult1);
               break;
            }
            case 3: 
            {
               sprintf(pEntry->pszText,"%.2f",pRecord->_fResult2);
               break;
            }
            case 4: 
            {
               sprintf(pEntry->pszText,"%.4f",pRecord->_fSportValue);
               break;
            }
            case 5: 
            {
               sprintf(pEntry->pszText,"%s",pRecord->_pszTitle);
               break;
            }
            case 6: 
            {
               sprintf(pEntry->pszText,"%.4f",pRecord->_fWilks);
               break;
            }
            case 7: 
            {
               sprintf(pEntry->pszText,"%.2f",pRecord->_fCorrection);
               break;
            }
            case 8: 
            {
               sprintf(pEntry->pszText,"%.4f",pRecord->_fSum1);
               break;
            }
            case 9: 
            {
               sprintf(pEntry->pszText,"%.4f",pRecord->_fSum2);
               break;
            }
         }
      }
   }
}

/* ******************************************************************** **
** @@ CWomen::OnDestroy()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update : 
** @  Notes  : 
** ******************************************************************** */

void CWomen::OnDestroy() 
{
   CPropertyPage::OnDestroy();
   
   Cleanup();
}

/* ******************************************************************** **
** @@ CWomen::Cleanup()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update : 
** @  Notes  : 
** ******************************************************************** */

void CWomen::Cleanup()
{
   DWORD    dwCnt = _WomenList.Count();

   if (dwCnt)
   {
      // Should be int !
      for (int ii = (dwCnt - 1); ii >= 0; --ii)
      {
         LIST_LINE*     pEntry = (LIST_LINE*)_WomenList.At(ii);

         _WomenList.RemoveAt(ii);

         if (pEntry)
         {
            delete pEntry;
            pEntry = NULL;
         }
      }
   }
}

/* ******************************************************************** **
** End of File
** ******************************************************************** */
