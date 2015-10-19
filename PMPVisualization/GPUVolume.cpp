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
				float temp=(k-70)*(k-70)+(j-70)*(j-70)+(i-50)*(i-50)-40*40;	//_求半径40
				if(temp<0.0)
				{
					ptr[k*140*116+j*116+i]=220;
				}
				else
				{
					ptr[k*140*116+j*116+i]=60;
				}
			}




			//_线性插值透明度映射方法  
			vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();   
			opacityTransferFunction->AddPoint(60,0.1);   
			opacityTransferFunction->AddPoint(220,0.8); 

			//_设定标量值的颜色属性  
			vtkColorTransferFunction *colorTransferFunction= vtkColorTransferFunction::New();   
			colorTransferFunction->AddRGBPoint(0, 0.0,1.0,0.0);   
			colorTransferFunction->AddRGBPoint(255,0.0,1.0,1.0);   
			//_设定体数据的属性:的不透明性和颜色值映射标_量值  
			vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();   
			volumeProperty->SetColor(colorTransferFunction);   
			volumeProperty->SetScalarOpacity(opacityTransferFunction);   
			volumeProperty->SetInterpolationTypeToLinear();  //_设定插值类型为线性插值  
			volumeProperty->SetDiffuse(0.7);   
			volumeProperty->SetAmbient(0.01);   
			volumeProperty->SetSpecular(0.5);   
			volumeProperty->SetSpecularPower(70.0);
			volumeProperty->ShadeOn();


			vtkVolume *volume=vtkVolume::New();		//_类似于_vtkActor
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
				//------_CPU绘制方法: vtkVolumeRayCastMapper
				vtkVolumeRayCastCompositeFunction *compositeFunction=vtkVolumeRayCastCompositeFunction::New();  
				vtkVolumeRayCastMapper *volumeMapper=vtkVolumeRayCastMapper::New();
				volumeMapper->SetVolumeRayCastFunction(compositeFunction);

				volumeMapper->SetInput(m_imgData);  
				volume->SetMapper(volumeMapper);
				ren->AddVolume(volume);
			}

			if(method==2)
			{
				//------_CPU或GPU绘制方法：vtkVolumeTextureMapper3D
				vtkOpenGLVolumeTextureMapper3D *volumeMapper=vtkOpenGLVolumeTextureMapper3D::New();	//vtkVolumeTextureMapper3D *volumeMapper=vtkVolumeTextureMapper3D::New();
				volumeMapper->SetPreferredMethodToNVidia();
				volumeMapper->SetInput(m_imgData);
				volumeMapper->SetBlendModeToComposite();
				volumeMapper->SetSampleDistance(0.1);	//_默认为1

				renwin->Render();		//_先render一次，确保OpenGL环境_
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
				//------_GPU绘制方法：vtkGPUVolumeRayCastMapper
				vtkGPUVolumeRayCastMapper *volumeMapper=vtkGPUVolumeRayCastMapper::New();
				volumeMapper->SetInput(m_imgData);
				volumeMapper->SetBlendModeToComposite();
				volumeMapper->SetSampleDistance(0.1);	//_默认为1,	volumeMapper->SetAutoAdjustSampleDistances()

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