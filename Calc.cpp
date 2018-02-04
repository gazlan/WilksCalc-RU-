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

#include "stdafx.h"

#include <float.h>

#include "vector.h"
#include "vector_sorted.h"
#include "wilkscalc.h"
#include "Calc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/* ******************************************************************** **
** @@ internal defines
** ******************************************************************** */
                                          
#define LIST_DEFAULT_SIZE              (1024)
#define LIST_DEFAULT_DELTA             (512)

/* ******************************************************************** **
** @@ Sorter()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

static int __cdecl Sorter(const void** const pKey1,const void** const pKey2)
{                               
   WILKS_ENTRY*   p1 = (WILKS_ENTRY*)*pKey1;  
   WILKS_ENTRY*   p2 = (WILKS_ENTRY*)*pKey2;  

   if (p1->_fWeight > p2->_fWeight)
   {
      return 1;
   }
   else if (p1->_fWeight < p2->_fWeight)
   {
      return -1;
   }
   else
   {
      return 0;
   }
}

/* ******************************************************************** **
** @@ CCalc::CCalc() : CPropertyPage()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : Constructor
** ******************************************************************** */

IMPLEMENT_DYNCREATE(CCalc, CPropertyPage)

CCalc::CCalc() : CPropertyPage(CCalc::IDD)
{
   //{{AFX_DATA_INIT(CCalc)
   m_Weight = _T("");
   m_Men = _T("");
   m_Women = _T("");
   //}}AFX_DATA_INIT

   _iCurrent = -1;
   _iTotal   =  0;
}

/* ******************************************************************** **
** @@ CCalc::~CCalc()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : Destructor
** ******************************************************************** */

CCalc::~CCalc()
{
}

/* ******************************************************************** **
** @@ CCalc::DoDataExchange()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void CCalc::DoDataExchange(CDataExchange* pDX)
{
   CPropertyPage::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CCalc)
   DDX_Control(pDX, IDC_CALCLIST, m_CalcList);
   DDX_Text(pDX, IDC_EDT_WEIGHT, m_Weight);
   DDV_MaxChars(pDX, m_Weight, 8);
   DDX_Text(pDX, IDC_EDT_MEN, m_Men);
   DDV_MaxChars(pDX, m_Men, 255);
   DDX_Text(pDX, IDC_EDT_WOMEN, m_Women);
   DDV_MaxChars(pDX, m_Women, 255);
   //}}AFX_DATA_MAP
}

/* ******************************************************************** **
** @@ CCalc::MESSAGE_MAP()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BEGIN_MESSAGE_MAP(CCalc, CPropertyPage)
   //{{AFX_MSG_MAP(CCalc)
   ON_NOTIFY(LVN_GETDISPINFO,IDC_CALCLIST,OnGetdispinfoList)
   ON_EN_CHANGE(IDC_EDT_WEIGHT, OnChangeEdtWeight)
   ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/* ******************************************************************** **
** @@ CCalc::OnInitDialog()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

BOOL CCalc::OnInitDialog() 
{
   CPropertyPage::OnInitDialog();
   
   CenterWindow();
   
   _WilksList.Resize(LIST_DEFAULT_SIZE);
   _WilksList.Delta (LIST_DEFAULT_DELTA);

   _WilksList.SetSorter(Sorter);

   // Virtual List !
   m_CalcList.InsertColumn(0,"Вес",    LVCFMT_LEFT,100,0);
   m_CalcList.InsertColumn(1,"Мужчины",LVCFMT_LEFT,100,1);
   m_CalcList.InsertColumn(2,"Женщины",LVCFMT_LEFT,100,2);

   for (double ww = 40.0; ww < 205.9; ww += 0.1)
   {
      WILKS_ENTRY*   pEntry = new WILKS_ENTRY;

      if (pEntry)
      {
         pEntry->_fWeight = ww;
         pEntry->_fMen    = CalcWilks(ww,GENDER_MEN);

         if (ww < 150.9)
         {
            pEntry->_fWomen = CalcWilks(ww,GENDER_WOMEN);
         }
         else
         {
            pEntry->_fWomen = 0.0;
         }
         
         if (_WilksList.Insert(pEntry) == -1)
         {
            delete pEntry;
            pEntry = NULL;
         }
      }
   }

   DWORD    dwStyle = m_CalcList.GetExtendedStyle();

   dwStyle |= LVS_OWNERDATA | LVS_EX_FULLROWSELECT | LVS_EX_SUBITEMIMAGES | LVS_EX_FLATSB | LVS_EX_GRIDLINES;
   
   m_CalcList.SetExtendedStyle(dwStyle);
   
   m_CalcList.SetItemCount(_WilksList.Count());
   m_CalcList.UpdateWindow();

   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}

/* ******************************************************************** **
** @@ CCalc::OnGetdispinfoList()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void CCalc::OnGetdispinfoList(NMHDR* pNMHDR, LRESULT* pResult) 
{
   *pResult = 0;

   NMLVDISPINFO*     pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);

   LV_ITEM*    pItem = &(pDispInfo)->item;

   int      iIndex = pItem->iItem;

   if (pItem->mask & LVIF_TEXT)
   {
      WILKS_ENTRY*   pRecord = (WILKS_ENTRY*)_WilksList.At(iIndex);

      if (pRecord)
      {
         switch (pItem->iSubItem)
         {
            case 0: 
            {
               sprintf(pItem->pszText,"%.1f",pRecord->_fWeight);
               break;
            }
            case 1: 
            {
               sprintf(pItem->pszText,"%.4f",pRecord->_fMen);
               break;
            }
            case 2: 
            {
               if (pRecord->_fWomen > FLT_EPSILON)
               {
                  sprintf(pItem->pszText,"%.4f",pRecord->_fWomen);
               }
               else
               {
                  *pItem->pszText = 0;
               }
               break;
            }
         }
      }
   }
}

/* ******************************************************************** **
** @@ CCalc::OnChangeEdtWeight()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

void CCalc::OnChangeEdtWeight() 
{
   UpdateData(TRUE);

   // Be Tolerant !
   m_Weight.Replace(',','.');

   double   fWeight  = atof((LPCTSTR)m_Weight);
   
   double   fWilks_M = CalcWilks(fWeight,GENDER_MEN);
   double   fWilks_W = CalcWilks(fWeight,GENDER_WOMEN);

   m_Men.Format  ("%.4f",fWilks_M);
   m_Women.Format("%.4f",fWilks_W);

   UpdateData(FALSE);
}

/* ******************************************************************** **
** @@ CCalc::OnDestroy() 
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

void CCalc::OnDestroy() 
{
   CPropertyPage::OnDestroy();
   
   Cleanup();
}

/* ******************************************************************** **
** @@ CCalc::Cleanup()
** @  Copyrt :
** @  Author : 
** @  Modify :
** @  Update : 
** @  Notes  : 
** ******************************************************************** */

void CCalc::Cleanup()
{
   DWORD    dwCnt = _WilksList.Count();

   if (dwCnt)
   {
      // Should be int !
      for (int ii = (dwCnt - 1); ii >= 0; --ii)
      {
         WILKS_ENTRY*   pEntry = (WILKS_ENTRY*)_WilksList.At(ii);

         _WilksList.RemoveAt(ii);

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
