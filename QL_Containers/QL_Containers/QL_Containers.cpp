// ql_containers.cpp : Defines the initialization routines for the DLL.
//

#ifdef XLL_LIB_MFC
#include "stdafx.h"
#endif
#include "QL_Containers.h"

#ifdef _DEBUG
#ifdef XLL_LIB_MFC
#define new DEBUG_NEW
#endif
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQL_ContainersApp

#ifdef XLL_LIB_MFC
BEGIN_MESSAGE_MAP(CQL_ContainersApp, CXllApp)
    //{{AFX_MSG_MAP(CQL_ContainersApp)
        // NOTE - the ClassWizard will add and remove mapping macros here.
        //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif

/////////////////////////////////////////////////////////////////////////////
// CQL_ContainersApp construction

CQL_ContainersApp::CQL_ContainersApp()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CQL_ContainersApp object

CQL_ContainersApp theApp;

/* static */ LPCTSTR CQL_ContainersApp::m_pszDefName = _T("QL_Containers");

BOOL CQL_ContainersApp::InitInstance() 
{
    // Call the base class
    if ( !CXllApp::InitInstance() )
        return FALSE;

    // Set the name of the library to the default value
    m_stName = m_pszDefName;

    // Add the statically defined function specifications
    AddStaticFns();

    // TODO: Add your specialized code here

    return TRUE;
}

int CQL_ContainersApp::ExitInstance() 
{
    // TODO: Add your specialized code here (then call the base class)

    return CXllApp::ExitInstance();
}

BOOL CQL_ContainersApp::OnXllOpenEx()
{
    // TODO: Allocate any application-level resources
    return TRUE;
}

void CQL_ContainersApp::OnXllClose()
{
    // TODO: Clean up any application-level resources
}

/////////////////////////////////////////////////////////////////////////////
// Exported functions

#include "ql_adapter.h"

// Function:    MatrixInputFn
// Purpose:     Demonstrates use of QuantLib Matrix class adapter

//{{XLP_SRC(MatrixInputFn)
	// NOTE - the FunctionWizard will add and remove mapping code here.
	//    DO NOT EDIT what you see in these blocks of generated code!

#pragma region MatrixInputFn support code
IMPLEMENT_XLLFN4(MatrixInputFn, MatrixInputFn_4, MatrixInputFn_12, "RP", "UQ$",
	L"MatrixInputFn", 0, L"Arg1", 0, L"14", 0, L"Demonstrates use of QuantLib "
	L"Matrix class adapter", 0, L"A QuantLib style 2d array\0", 0, 0, L"{Matri"
	L"xInputFn,,,Demonstrates use of QuantLib Matrix class adapter,14,1,1,U,{{"
	L"0,{Arg1,Double,10,,A QuantLib style 2d array,,{{{,},{,}},{{,},{,}}},,QMa"
	L"trixT<T>}}},{},3,,0,0,,,,0,0}", 1, 0, 0)
	CXlOper* MatrixInputFn_Impl(CXlOper&, const CXlOper*);
extern "C" __declspec(dllexport)
LPXLOPER12 MatrixInputFn_12(LPXLOPER12 Arg1)
{
	XLL_FIX_STATE;
	CXlOper xloResult, Arg1__port(Arg1);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(MatrixInputFn_Impl(xloResult, &Arg1__port));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret12();
}
extern "C" __declspec(dllexport)
LPXLOPER4 MatrixInputFn_4(LPXLOPER4 Arg1)
{
	XLL_FIX_STATE;
	CXlOper xloResult, Arg1__port(Arg1);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(MatrixInputFn_Impl(xloResult, &Arg1__port));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret4();
}

#pragma endregion

CXlOper* MatrixInputFn_Impl(CXlOper& xloResult, const CXlOper* Arg1_op)
{
	// Input buffers
	QMatrixT<double> Arg1;
	// Validate and translate inputs
	XlReadMatrix(*Arg1_op, mtx_adapter(Arg1), L"Arg1", XLA_TRUNC_ONEMPTY |
		XLA_TRUNC_ONBLANK);
	// End of generated code
//}}XLP_SRC
	// TODO - set the value of xloResult, or return another value
	//	      using CXlOper::RetXXX() or throw a CXlRuntimeException.
	Arg1 *= 2.0;
	xloResult = mtx_adapter(Arg1);
	return xloResult.Ret();
}

// Function:    ArrayInputFn
// Purpose:     Test integration of QuantLib Array class

//{{XLP_SRC(ArrayInputFn)
	// NOTE - the FunctionWizard will add and remove mapping code here.
	//    DO NOT EDIT what you see in these blocks of generated code!

#pragma region ArrayInputFn support code
IMPLEMENT_XLLFN4(ArrayInputFn, ArrayInputFn_4, ArrayInputFn_12, "RP", "UQ$",
	L"ArrayInputFn", 0, L"Arg1", 0, L"14", 0, L"Test integration of QuantLib::"
	L"Array class", 0, L"A QuantLib style 1-d array\0", 0, 0, L"{ArrayInputFn,"
	L",,Test integration of QuantLib::Array class,14,1,1,U,{{0,{Arg1,Double,10"
	L",,A QuantLib style 1-d array,,{{{,},{,}}},,QArrayT<T>}}},{},3,,0,0,,,,0,"
	L"0}", 1, 0, 0)
	CXlOper* ArrayInputFn_Impl(CXlOper&, const CXlOper*);
extern "C" __declspec(dllexport)
LPXLOPER12 ArrayInputFn_12(LPXLOPER12 Arg1)
{
	XLL_FIX_STATE;
	CXlOper xloResult, Arg1__port(Arg1);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(ArrayInputFn_Impl(xloResult, &Arg1__port));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret12();
}
extern "C" __declspec(dllexport)
LPXLOPER4 ArrayInputFn_4(LPXLOPER4 Arg1)
{
	XLL_FIX_STATE;
	CXlOper xloResult, Arg1__port(Arg1);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(ArrayInputFn_Impl(xloResult, &Arg1__port));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret4();
}

#pragma endregion

CXlOper* ArrayInputFn_Impl(CXlOper& xloResult, const CXlOper* Arg1_op)
{
	// Input buffers
	QArrayT<double> Arg1;
	// Validate and translate inputs
	XlReadVector(*Arg1_op, Arg1, L"Arg1", XLA_TRUNC_ONEMPTY | XLA_TRUNC_ONBLANK);
	// End of generated code
//}}XLP_SRC
	// TODO - set the value of xloResult, or return another value
	//	      using CXlOper::RetXXX() or throw a CXlRuntimeException.
	Arg1 *= 2.0;
	xloResult = mtx_adapter(Arg1);
	return xloResult.Ret();
}

// Function:    RetArrayFn
// Purpose:     Demonstrates returning a QuantLib::Array to Excel

//{{XLP_SRC(RetArrayFn)
	// NOTE - the FunctionWizard will add and remove mapping code here.
	//    DO NOT EDIT what you see in these blocks of generated code!

#pragma region RetArrayFn support code
IMPLEMENT_XLLFN4(RetArrayFn, RetArrayFn_4, RetArrayFn_12, "RJBB", "UJBB$",
	L"RetArrayFn", 0, L"size,start,inc", 0, L"14", 0, L"Demonstrates returning"
	L" a QuantLib::Array to Excel", 0, L"Size of array\0Starting value\0Increm"
	L"ent\0", 0, 0, L"{RetArrayFn,,,Demonstrates returning a QuantLib::Array t"
	L"o Excel,14,1,1,U,{{0,{size,Int,0,,Size of array,,,,}},{0,{start,Double,0"
	L",,Starting value,,,,}},{0,{inc,Double,0,,Increment,,,,}}},{},3,,0,0,,,,0"
	L",0}", 1, 0, 0)
	CXlOper* RetArrayFn_Impl(CXlOper&, long, double, double);
extern "C" __declspec(dllexport)
LPXLOPER12 RetArrayFn_12(long size, double start, double inc)
{
	XLL_FIX_STATE;
	CXlOper xloResult;
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(RetArrayFn_Impl(xloResult, size, start, inc));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret12();
}
extern "C" __declspec(dllexport)
LPXLOPER4 RetArrayFn_4(long size, double start, double inc)
{
	XLL_FIX_STATE;
	CXlOper xloResult;
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(RetArrayFn_Impl(xloResult, size, start, inc));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret4();
}

#pragma endregion

CXlOper* RetArrayFn_Impl(CXlOper& xloResult, long size, double start, double inc)
{
	// End of generated code
//}}XLP_SRC
	// Create and populate a QuantLib Array
	QuantLib::Array a((QuantLib::Size)size, start, inc);

	// Return the Array to Excel
	xloResult = mtx_adapter(a);
	return xloResult.Ret();
}

// Function:    RetMatrixFn
// Purpose:     Demonstrates returning a QuantLib::Matrix class

//{{XLP_SRC(RetMatrixFn)
	// NOTE - the FunctionWizard will add and remove mapping code here.
	//    DO NOT EDIT what you see in these blocks of generated code!

#pragma region RetMatrixFn support code
IMPLEMENT_XLLFN4(RetMatrixFn, RetMatrixFn_4, RetMatrixFn_12, "RJJB", "UJJB$",
	L"RetMatrixFn", 0, L"rows,cols,start", 0, L"14", 0, L"Demonstrates returni"
	L"ng a QuantLib::Matrix class", 0, L"Number of rows of output\0Number of c"
	L"olumns of output\0Starting value\0", 0, 0, L"{RetMatrixFn,,,Demonstrates"
	L" returning a QuantLib::Matrix class,14,1,1,U,{{0,{rows,Int,0,,Number of "
	L"rows of output,,,,}},{0,{cols,Int,0,,Number of columns of output,,,,}},{"
	L"0,{start,Double,0,,Starting value,,,,}}},{},3,,0,0,,,,0,0}", 1, 0, 0)
	CXlOper* RetMatrixFn_Impl(CXlOper&, long, long, double);
extern "C" __declspec(dllexport)
LPXLOPER12 RetMatrixFn_12(long rows, long cols, double start)
{
	XLL_FIX_STATE;
	CXlOper xloResult;
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(RetMatrixFn_Impl(xloResult, rows, cols, start));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret12();
}
extern "C" __declspec(dllexport)
LPXLOPER4 RetMatrixFn_4(long rows, long cols, double start)
{
	XLL_FIX_STATE;
	CXlOper xloResult;
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(RetMatrixFn_Impl(xloResult, rows, cols, start));
	}
	catch (const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
		return xloResult.Ret4();
}

#pragma endregion

CXlOper* RetMatrixFn_Impl(CXlOper& xloResult, long rows, long cols, double start)
{
	// End of generated code
//}}XLP_SRC
	// Create some test data
	std::vector<double> data(rows * cols);
	std::iota(data.begin(), data.end(), start);

	// Populate a QuantLib Matrix
	QuantLib::Matrix m(rows, cols, data.begin(), data.end());

	// Return the matrix
	xloResult = mtx_adapter(m);
	return xloResult.Ret();
}


// Function:    QLContainerInputs
// Purpose:     Demonstrates the use of QuantLib container classes for inputs

//{{XLP_SRC(QLContainerInputs)
	// NOTE - the FunctionWizard will add and remove mapping code here.
	//    DO NOT EDIT what you see in these blocks of generated code!

#pragma region QLContainerInputs support code
IMPLEMENT_XLLFN4(QLContainerInputs, QLContainerInputs_4, QLContainerInputs_12, 
	"RPP", "UQQ$", L"QLContainerInputs", 0, L"m,v", 0, L"14", 0, L"Demonstrate"
	L"s the use of QuantLib container classes for inputs", 0, L"is a matrix\0i"
	L"s a vector\0", 0, 0, L"{QLContainerInputs,,,Demonstrates the use of Quan"
	L"tLib container classes for inputs,14,1,1,U,{{0,{m,Double,10,,is a matrix"
	L",,{{{,},{,}},{{,},{,}}},,}},{0,{v,Double,10,,is a vector,,{{{,},{,}}},,}"
	L"}},{},3,,0,0,,,,0,0}", 1, 0, 0)
CXlOper* QLContainerInputs_Impl(CXlOper&, const CXlOper*, const CXlOper*);
extern "C" __declspec(dllexport)
LPXLOPER12 QLContainerInputs_12(LPXLOPER12 m, LPXLOPER12 v)
{
	XLL_FIX_STATE;
	CXlOper xloResult, m__port(m), v__port(v);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(QLContainerInputs_Impl(xloResult, &m__port, &
			v__port));
	}
	catch(const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
	return xloResult.Ret12();
}
extern "C" __declspec(dllexport)
LPXLOPER4 QLContainerInputs_4(LPXLOPER4 m, LPXLOPER4 v)
{
	XLL_FIX_STATE;
	CXlOper xloResult, m__port(m), v__port(v);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(QLContainerInputs_Impl(xloResult, &m__port, &
			v__port));
	}
	catch(const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
	return xloResult.Ret4();
}

#pragma endregion

CXlOper* QLContainerInputs_Impl(CXlOper& xloResult, const CXlOper* m_op, const 
	CXlOper* v_op)
{
	// Input buffers
	QMatrixT<double> m;
	QArrayT<double> v;
	// Validate and translate inputs
	XlReadMatrix(*m_op, mtx_adapter(m), L"m", XLA_TRUNC_ONEMPTY|
		XLA_TRUNC_ONBLANK);
	XlReadVector(*v_op, v, L"v", XLA_TRUNC_ONEMPTY|XLA_TRUNC_ONBLANK);
	// End of generated code
//}}XLP_SRC

	// Use m & v wherever QuantLib::Matrix and QuantLib::Array can be used:
	if ((m.rows() != m.columns()) || (m.rows() != v.size())) {
		throw CXlRuntimeException("Expected m to be "
			"square and the same size as v");
	}
	v *= m.diagonal();

	// Return an Array or Matrix via mtx_adapter(...)
	xloResult = mtx_adapter(v);
	return xloResult.Ret();
}

// Function:    GroupedFn
// Purpose:     Demonstrates the use of a group of QuantLib::Array inputs

//{{XLP_SRC(GroupedFn)
	// NOTE - the FunctionWizard will add and remove mapping code here.
	//    DO NOT EDIT what you see in these blocks of generated code!

#pragma region GroupedFn support code
IMPLEMENT_XLLFN4(GroupedFn, GroupedFn_4, GroupedFn_12, "RP", "UQ$", L"GroupedF"
	L"n", 0, L"Distributions", 0, L"14", 0, L"Demonstrates the use of a group "
	L"of QuantLib::Array inputs", 0, L"2 vectors: Means (A vector of means); S"
	L"tdDevs (A vector of standard deviations)\0", 0, 0, L"{GroupedFn,,,Demons"
	L"trates the use of a group of QuantLib::Array inputs,14,1,1,U,{{1,{{Distr"
	L"ibutions,Group,0,,,,{{{,},{,}}},,},5,0,{{0,{Means,Double,10,,A vector of"
	L" means,,{{{,},{,}}},,}},{0,{StdDevs,Double,10,,A vector of standard devi"
	L"ations,,{{{,},{,}}},,}}}}}},{},3,,0,0,,,,0,0}", 1, 0, 0)
CXlOper* GroupedFn_Impl(CXlOper&, const CXlOper*);
extern "C" __declspec(dllexport)
LPXLOPER12 GroupedFn_12(LPXLOPER12 Distributions)
{
	XLL_FIX_STATE;
	CXlOper xloResult, Distributions__port(Distributions);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(GroupedFn_Impl(xloResult, &Distributions__port));
	}
	catch(const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
	return xloResult.Ret12();
}
extern "C" __declspec(dllexport)
LPXLOPER4 GroupedFn_4(LPXLOPER4 Distributions)
{
	XLL_FIX_STATE;
	CXlOper xloResult, Distributions__port(Distributions);
	try {
		CXlStructuredExceptionHandler _seh_;
		xloResult.HandleResult(GroupedFn_Impl(xloResult, &Distributions__port));
	}
	catch(const CXlRuntimeException& ex) {
		CXllApp::Instance()->DisplayException(xloResult, ex);
	}
	XLP_CATCH_CLR_EXCEPTIONS_TO(xloResult)
	return xloResult.Ret4();
}

#pragma endregion

CXlOper* GroupedFn_Impl(CXlOper& xloResult, const CXlOper* Distributions)
{
	// Input buffers
	QArrayT<double> Means;
	QArrayT<double> StdDevs;
	// Validate and translate inputs
	XlReadGroupedVector(*Distributions, Means, L"Distributions", 0, L"Means", 
		XLA_TRUNC_ONEMPTY|XLA_TRUNC_ONBLANK|XLA_OPER_IS_GROUP);
	XlReadGroupedVector(*Distributions, StdDevs, L"Distributions", 1, L"StdDev"
		L"s", XLA_TRUNC_ONEMPTY|XLA_TRUNC_ONBLANK|XLA_OPER_IS_GROUP);
	// End of generated code
//}}XLP_SRC
	// TODO - set the value of xloResult, or return another value
	//	      using CXlOper::RetXXX() or throw a CXlRuntimeException.

	xloResult = mtx_adapter(Means + StdDevs);

	return xloResult.Ret();
}
