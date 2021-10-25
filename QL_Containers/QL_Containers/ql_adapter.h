#pragma once

/*************************************************************************
QuantLib::Array and QuantLib::Matrix inputs

Instructions for use:
  In the Xll Plus Function Wizard, use the Vector tab of the Details 
  windows to define the vector container class to be QArrayT<T>.
  
  In the Xll Plus Function Wizard, use the Matrix tab of the Details 
  windows to define the matrix container class to be QMatrixT<T>.

  Consider using the XLL Plus Options page to change the settings for 
  defaultVectorCOntainer and DefaultMatrixContainer to these types.

  In the source file containing your XLL add-in functions, #include 
  this file.

  You can use an instance of QArrayT<double> anywhere you might use an 
  instance of QuantLib::Array, or an instance of QMatrixT<double> 
  anywhere you might use an instance of QuantLib::Matrix.

QuantLib::Array and QuantLib::Matrix outputs

Instructions for use:

  Wrap an instance of any of the following using mtx_adapter(...):
  QuantLib::Matrix, QMatrixT<T>, QuantLib::Array or QArrayT<T>.
  
  e.g.:

  // Create and populate a QuantLib Array
  QuantLib::Array a((QuantLib::Size)size, start, inc);
  
  // Return the Array to Excel
  xloResult = mtx_adapter(a);
  return xloResult.Ret();
}

***************************************************************************/

#include <ql/math/matrix.hpp>
#include <type_traits>
#include <assert.h>
#ifndef __XLPOPER_H__
#error XlpOper.h is required
#endif

#ifndef QL_ADAPTER_NOLIB
#ifdef _DEBUG
#pragma comment(lib, "QuantLib-mt-sgd.lib")
#else
#pragma comment(lib, "QuantLib-mt-s.lib")
#endif
#endif

template<class T>
class QArrayT : public QuantLib::Array {
public:
	static_assert(std::is_same<double, T>::value, "QuantLib::Array only works with QL_REAL elements");
	QArrayT<T>() : QuantLib::Array() {}
	template <class ForwardIterator>
	inline QArrayT<T>(ForwardIterator begin, ForwardIterator end) : QuantLib::Array(begin, end) {
	}
	operator std::vector<T>() const {
		std::vector<T> v(begin(), end());
		return v;
	}
};

template<class T>
std::vector<T> mtx_adapter(QArrayT<T>& src) {
	static_assert(std::is_same<double, T>::value, "QuantLib::Array only works with QL_REAL elements");
	return std::vector<T>(src);
}

std::vector<QL_REAL> mtx_adapter(QuantLib::Array& src) {
	return std::vector<QL_REAL>(src.begin(), src.end());
}

// Shorthand - ungrouped
template<class ElemType>
void XlReadVector(const CXlOper& xlo, QArrayT<ElemType>& value,
	const wchar_t* argName, unsigned long flags = 0, long* expectedSize = 0,
	unsigned long lowerBound = 0, const ElemType& defaultCellValue = ElemType())
{
	static_assert(std::is_same<double, ElemType>::value, "QuantLib Array only works with QL_REAL elements");
	std::vector<ElemType> v;
	CXlConverter<ElemType>::ReadVector(xlo, v,
		CVectorConvertParams<ElemType>(argName, flags, 0, (size_t)-1,
			expectedSize, lowerBound, defaultCellValue));
	value = QArrayT<ElemType>(&v[0], &v[0] + v.size());
}

// Shorthand - grouped
template<class ElemType>
void XlReadGroupedVector(const CXlOper& xlo, QArrayT<ElemType>& value,
	const wchar_t* groupName, size_t rowOrColumn,
	const wchar_t* argName, unsigned long flags = 0, long* expectedSize = 0,
	unsigned long lowerBound = 0, const ElemType& defaultCellValue = ElemType())
{
	static_assert(std::is_same<double, ElemType>::value, "QuantLib Array only works with QL_REAL elements");
	std::vector<ElemType> v;
	CXlConverter<ElemType>::ReadVector(xlo, v,
		CVectorConvertParams<ElemType>(argName, flags | XLA_OPER_IS_GROUP,
			groupName, rowOrColumn, expectedSize, lowerBound, defaultCellValue));
	value = QArrayT<ElemType>(&v[0], &v[0] + v.size());
}

template<class T>
class QMatrixT : public QuantLib::Matrix {
public:
	static_assert(std::is_same<double, T>::value, "QuantLib Matrix only works with REAL elements");
	QMatrixT<T>() : QuantLib::Matrix() {}
};

template<class T>
class ql_matrix_adapter : public ple::imtx_impl<T> {
public:
	static_assert(std::is_same<double, T>::value, "QuantLib Matrix only works with REAL elements");
	ql_matrix_adapter(QuantLib::Matrix& impl) : _impl(impl) {}
	virtual void resize(bool preserve, mtx_size dim0, mtx_size dim1) {
		assert(!preserve);
		_impl = QuantLib::Matrix(dim0, dim1);
	}
	virtual T& at(mtx_size i0, mtx_size i1) {
		return _impl.at(i0)[i1];
	}
	virtual const T& at(mtx_size i0, mtx_size i1) const {
		return _impl.at(i0)[i1];
	}
	virtual mtx_size size(int dim) const {
		return (dim == 0) ? _impl.rows() : _impl.columns();
	}
	virtual bool get_flat(T*& data) {
		data = _impl.begin();
		return true;
	}
	virtual bool get_flat(const T*& data) const {
		data = _impl.begin();
		return true;
	}
protected:
	QuantLib::Matrix& _impl;
};

template<class T>
ql_matrix_adapter<T> mtx_adapter(QMatrixT<T>& src) {
	return ql_matrix_adapter<T>(src);
}

ql_matrix_adapter<QL_REAL> mtx_adapter(QuantLib::Matrix& src) {
	return ql_matrix_adapter<QL_REAL>(src);
}

