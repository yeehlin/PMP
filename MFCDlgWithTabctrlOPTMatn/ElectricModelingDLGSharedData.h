#pragma once

class CElectricModelingDLGSharedData{
public :
	static float c[6][6][6];
	static float k[6][3][3];
	static float d[6][3][6];
	static float u[6][3][3];
	static float q[6][3][6];
	static float a[6][3][3];
};

float CElectricModelingDLGSharedData::c[6][6][6]={10.0f};
float CElectricModelingDLGSharedData::k[6][3][3]={0.0f};
float CElectricModelingDLGSharedData::d[6][3][6]={0.0f};
float CElectricModelingDLGSharedData::u[6][3][3]={0.0f};
float CElectricModelingDLGSharedData::q[6][3][6]={0.0f};
float CElectricModelingDLGSharedData::a[6][3][3]={0.0f};