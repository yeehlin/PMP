#pragma once

// CPMPTransformer command target

class CPMPTransformer : public CObject
{
public:
	CPMPTransformer();
	virtual ~CPMPTransformer();
public :
	// ����ת���ӿ�
	void PMPTransformToVTKForScalar(CString filename);
	void PMPTransformToVTKForIsosurface(CString filename);
	void PMPTransformToVTKForTensor1D(CString filename);
	void PMPTransformToVTKForVector3D(CString filename);
	void PMPTransformToVTKForTensor(CString filename);
	// �ַ����ָ�,�����ַ������Ӵ��ĸ���
	int PMPStringSplit(CString str);

	////////////////////////////////////ת�����ݵķ�ʽ//////////////////////////////////////
	//   ����
	//   1��Scalar1D 4��Scalar1D1
	//   ����
	//   2��Vector3D 4��Vector1D1��Vector1D2��Vector1D3
	//   �������������Գƣ�
	//   3��Tensor33D 4��Vector1D1��...��Vector1D6
	////////////////////////////////////ת�����ݵķ�ʽ//////////////////////////////////////

	// ת��Scalar�������ݣ�ȫȡ����1�У�
	void PMPTransformToVTKForScalar1D(CString filename,CString &outfilename);
	// ת��Vector�������ݣ�ȫȡ����3�У�
	void PMPTransformToVTKForVector3D(CString filename,CString &outfilename);
	// ת��Tensor�������ݣ�ȫȡ����6�У�
	void PMPTransformToVTKForTensor33D(CString filename,CString &outfilename);
	// ת�������������ݣ�ȡĳһ��
	void PMPTransformToVTKForVolume(CString filename,int column,CString &outfilename);
};


