#include "vtkUnsignedCharArray.h"  
#include "vtkPiecewiseFunction.h"  
#include "vtkColorTransferFunction.h"  
#include "vtkVolumeRayCastCompositeFunction.h"  
#include "vtkVolumeRayCastMapper.h"  
#include "vtkImageData.h"  
#include "vtkVolumeProperty.h"  
#include "vtkVolume.h"  
#include "vtkRenderWindow.h"  
#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkRenderer.h"  
#include "vtkRenderWindowInteractor.h" 
#include "vtkInteractorStyleTrackballActor.h"
#include "vtkImageChangeInformation.h"
#include "vtkGPUVolumeRayCastMapper.h"
#include "vtkVolumeTextureMapper3D.h"
#include "vtkOpenGLVolumeTextureMapper3D.h"
#include "vtkCamera.h"

#include "vtkTestUtilities.h"
#include "vtkGPUInfoList.h"
#include "vtkGPUInfo.h"


#include<iostream>
using namespace std;


void mainGPU()
{
	vtkImageData *m_imgData=vtkImageData::New();  
	m_imgData->SetDimensions(116, 140,140);
	m_imgData->SetScalarType(VTK_UNSIGNED_CHAR);
	m_imgData->SetSpacing(0.1,0.1,0.1);
	m_imgData->SetNumberOfScalarComponents(1);
	m_imgData->AllocateScalars();
	unsigned char *ptr=(unsigned char*)m_imgData->GetScalarPointer();
	for(int k=0;k<140;k++)
		for(int j=0;j<140;j++)
			for(int i=0;i<116;i++)
			{
				float temp=(k-70)*(k-70)+(j-70)*(j-70)+(i-50)*(i-50)-40*40;	//_��뾶40
				if(temp<0.0)
				{
					ptr[k*140*116+j*116+i]=220;
				}
				else
				{
					ptr[k*140*116+j*116+i]=60;
				}
			}




			//_���Բ�ֵ͸����ӳ�䷽��  
			vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();   
			opacityTransferFunction->AddPoint(60,0.1);   
			opacityTransferFunction->AddPoint(220,0.8); 

			//_�趨����ֵ����ɫ����  
			vtkColorTransferFunction *colorTransferFunction= vtkColorTransferFunction::New();   
			colorTransferFunction->AddRGBPoint(0, 0.0,1.0,0.0);   
			colorTransferFunction->AddRGBPoint(255,0.0,1.0,1.0);   
			//_�趨�����ݵ�����:�Ĳ�͸���Ժ���ɫֵӳ���_��ֵ  
			vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();   
			volumeProperty->SetColor(colorTransferFunction);   
			volumeProperty->SetScalarOpacity(opacityTransferFunction);   
			volumeProperty->SetInterpolationTypeToLinear();  //_�趨��ֵ����Ϊ���Բ�ֵ  
			volumeProperty->SetDiffuse(0.7);   
			volumeProperty->SetAmbient(0.01);   
			volumeProperty->SetSpecular(0.5);   
			volumeProperty->SetSpecularPower(70.0);
			volumeProperty->ShadeOn();


			vtkVolume *volume=vtkVolume::New();		//_������_vtkActor
			volume->SetProperty(volumeProperty);
			vtkRenderer* ren=vtkRenderer::New();  
			ren->SetBackground(0.93,0.93,0.93);
			vtkWin32OpenGLRenderWindow *renwin=vtkWin32OpenGLRenderWindow::New();	//vtkRenderWindow* renwin=vtkRenderWindow::New();  
			renwin->SetSize(800,800);

			vtkRenderWindowInteractor* iren=vtkRenderWindowInteractor::New();
			vtkInteractorStyleTrackballActor*ball=vtkInteractorStyleTrackballActor::New();
			iren->SetInteractorStyle(ball);
			iren->SetRenderWindow(renwin);
			renwin->AddRenderer(ren);

			int method=0;
			cin>>method;

			if(method==1)
			{
				//------_CPU���Ʒ���: vtkVolumeRayCastMapper
				vtkVolumeRayCastCompositeFunction *compositeFunction=vtkVolumeRayCastCompositeFunction::New();  
				vtkVolumeRayCastMapper *volumeMapper=vtkVolumeRayCastMapper::New();
				volumeMapper->SetVolumeRayCastFunction(compositeFunction);

				volumeMapper->SetInput(m_imgData);  
				volume->SetMapper(volumeMapper);
				ren->AddVolume(volume);
			}

			if(method==2)
			{
				//------_CPU��GPU���Ʒ�����vtkVolumeTextureMapper3D
				vtkOpenGLVolumeTextureMapper3D *volumeMapper=vtkOpenGLVolumeTextureMapper3D::New();	//vtkVolumeTextureMapper3D *volumeMapper=vtkVolumeTextureMapper3D::New();
				volumeMapper->SetPreferredMethodToNVidia();
				volumeMapper->SetInput(m_imgData);
				volumeMapper->SetBlendModeToComposite();
				volumeMapper->SetSampleDistance(0.1);	//_Ĭ��Ϊ1

				renwin->Render();		//_��renderһ�Σ�ȷ��OpenGL����_
				if(!volumeMapper->IsRenderSupported(volumeProperty,ren))
				{
					cout<<"This mapper is unsupported on this platform"<<endl;
					return;
				}

				volumeMapper->SetInput(m_imgData);  
				volume->SetMapper(volumeMapper);
				ren->AddVolume(volume);
			}
			if(method==3)
			{
				//------_GPU���Ʒ�����vtkGPUVolumeRayCastMapper
				vtkGPUVolumeRayCastMapper *volumeMapper=vtkGPUVolumeRayCastMapper::New();
				volumeMapper->SetInput(m_imgData);
				volumeMapper->SetBlendModeToComposite();
				volumeMapper->SetSampleDistance(0.1);	//_Ĭ��Ϊ1,	volumeMapper->SetAutoAdjustSampleDistances()

				renwin->Render();
				if(!volumeMapper->IsRenderSupported(renwin,volumeProperty))
				{
					cout<<"This mapper is unsupported on this platform"<<endl;
					return;
				}

				volumeMapper->SetInput(m_imgData);  
				volume->SetMapper(volumeMapper);
				ren->AddVolume(volume);
			}



			int timebegin=::GetTickCount();
			for(int i=0;i<90;i++)
			{
				ren->GetActiveCamera()->Azimuth(1);
				ren->ResetCamera();
				renwin->Render();
			}
			int timeend=::GetTickCount();
			cout<<"Elapsed time:"<<(timeend-timebegin)<<endl;

			iren->Start();  
}