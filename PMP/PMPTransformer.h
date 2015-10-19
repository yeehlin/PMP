#pragma once

// CPMPTransformer command target

class CPMPTransformer : public CObject
{
public:
	CPMPTransformer();
	virtual ~CPMPTransformer();
public :
	// 数据转换接口
	void PMPTransformToVTKForScalar(CString filename);
	void PMPTransformToVTKForIsosurface(CString filename);
	void PMPTransformToVTKForTensor1D(CString filename);
	void PMPTransformToVTKForVector3D(CString filename);
	void PMPTransformToVTKForTensor(CString filename);
	// 字符串分割,给出字符串中子串的个数
	int PMPStringSplit(CString str);

	////////////////////////////////////转化数据的方式//////////////////////////////////////
	//   标量
	//   1、Scalar1D 4、Scalar1D1
	//   向量
	//   2、Vector3D 4、Vector1D1、Vector1D2、Vector1D3
	//   张量（该张量对称）
	//   3、Tensor33D 4、Vector1D1、...、Vector1D6
	////////////////////////////////////转化数据的方式//////////////////////////////////////

	// 转化Scalar类型数据，全取（共1列）
	void PMPTransformToVTKForScalar1D(CString filename,CString &outfilename);
	// 转化Vector类型数据，全取（共3列）
	void PMPTransformToVTKForVector3D(CString filename,CString &outfilename);
	// 转化Tensor类型数据，全取（共6列）
	void PMPTransformToVTKForTensor33D(CString filename,CString &outfilename);
	// 转化任意类型数据，取某一列
	void PMPTransformToVTKForVolume(CString filename,int column,CString &outfilename);
};


