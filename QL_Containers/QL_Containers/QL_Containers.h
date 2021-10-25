// ql_containers.h : main header file for the QL_CONTAINERS XLL
//

#ifndef __QL_CONTAINERS_H__
#define __QL_CONTAINERS_H__

#if(!defined(XLL_LIB_STL) && !defined(__AFXWIN_H__))
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols
#include <xllplus.h>		// See below
// You may have had fatal error C1083.
// You should make sure that the directory containing the
// XllPlus header files is in your list of include paths.
// You can do this via 'Tools-Options-Directories' or
// via 'Project-Settings-C/C++-Preprocessor-Additional
// include directories'. You should also ensure at this time
// that the directory containing the XllPlus library files 
// is in your list of lib paths.


/////////////////////////////////////////////////////////////////////////////
// CQL_ContainersApp
// See QL_Containers.cpp for the implementation of this class
//

class CQL_ContainersApp : public CXllApp
{
public:
    CQL_ContainersApp();

// Names
public:
    static LPCTSTR m_pszDefName;

// Overrides
    virtual BOOL OnXllOpenEx();
    virtual void OnXllClose();
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CQL_ContainersApp)
    public:
    virtual int ExitInstance();
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

#ifdef XLL_LIB_MFC
    //{{AFX_MSG(CQL_ContainersApp)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
#endif
};

inline CQL_ContainersApp* XllGetTypedApp() { return (CQL_ContainersApp*)::XllGetApp(); }

/////////////////////////////////////////////////////////////////////////////

#endif /* __QL_CONTAINERS_H__ */
