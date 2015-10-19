#include <afx.h>
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkJPEGReader.h"
#include "vtkImageActor.h"
#include "vtkInteractorStyleImage.h"
#include "vtkActor2D.h"
#include "vtkImageMapper3D.h"
#include "vtkImageMapper.h"
#include "vtkBMPReader.h"
#include "vtkActor.h"
#include "vtkRenderer.h" 
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkJPEGReader.h"
#include "vtkImageViewer.h"
#include "vtkImageActor.h"
#include "vtkInteractorStyleImage.h"
#include "vtkActor2D.h"



#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkVolume16Reader.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkOutlineFilter.h"
#include "vtkCamera.h"
#include "vtkProperty.h"
#include "vtkPolyDataNormals.h"
#include "vtkContourFilter.h"
#include "vtkMarchingCubes.h"
#include "vtkDICOMImageReader.h"
#include "vtkImageCast.h"
#include "vtkDecimatePro.h"
#include "vtkStripper.h"
#include "vtkImageShrink3D.h"
#include "vtkSmoothPolyDataFilter.h"
#include "vtkTriangleFilter.h"
#include "vtkFeatureEdges.h"
#include "vtkPolyDataWriter.h"
#include "vtkImageData.h"

#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkInteractorStyleUnicam.h"
#include "vtkInteractorStyleUser.h"
#include "vtkInteractorStyleTrackballActor.h"
#include "vtkInteractorStyleTerrain.h"
#include "vtkInteractorStyleSwitch.h"
#include "vtkInteractorStyleFlight.h"
#include "vtkInteractorStyleJoystickActor.h"



//m_reader->SetFileName("D:\\Toolkits\\VTK\\Examples\\TestVTKBMP\\bin\\Debug\\001comp.jpeg");
//方法一：
//使用vtkImageMapper和vtkAcotor2D来实现
#define EXAMPLE_DATA "D:/001comp.bmp"

void showBMPimage(){
	double origin[3] = {0, 0, 0};
	int extent[6] = {0, 256, 0, 512, 0, 0};
	int i = 1 ;
	vtkBMPReader *m_reader = vtkBMPReader::New();
	m_reader->SetDataByteOrderToLittleEndian();
	m_reader->SetDataScalarTypeToUnsignedChar();
	//m_reader->SetFileDimensionality(3);
	//m_reader->SetDataExtent(extent);
	//m_reader->SetDataOrigin(origin);
	vtkImageActor *m_Actor = vtkImageActor::New();
	vtkRenderer *m_Renderer = vtkRenderer::New();
	vtkRenderWindow *m_RenWin = vtkRenderWindow::New();
	vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
	vtkInteractorStyleImage *interactor = vtkInteractorStyleImage::New();

	CString bmpname;
	//*/
	for(i = 1;i<=1;i++){
		if (i<10){
			bmpname.Format("%s%s%d%s","D:/","00",i,"comp.bmp");
			//this->currentName = "00"+count;
			//this->currentName +=_T("comp.bmp");
		}else if (i <100){
			bmpname.Format("%s%s%d%s","D:/","0",i,"comp.bmp");
			//this->currentName = "0"+image_index;
			//this->currentName +=_T("comp.bmp");
		}else {
			bmpname.Format("%s%d%s","D:/",i,"comp.bmp");
			//this->currentName +=_T("comp.bmp");
		}
		m_reader->SetFileName(bmpname);
		m_reader->SetNumberOfScalarComponents(1);
		m_reader->SetHeaderSize(0);
		m_reader->UpdateWholeExtent();
		
		m_Actor->SetInputData(m_reader->GetOutput());
		m_Actor->SetDisplayExtent(extent[0], extent[1], extent[2], extent[3], 0, 0);
		m_Renderer->SetBackground(0.1, 0.2, 0.4);
		m_Renderer->AddActor(m_Actor);
		m_RenWin->SetSize(500, 500);
		m_RenWin->AddRenderer(m_Renderer);
		iren->SetRenderWindow(m_RenWin);
		//vtkInteractorStyleImage *interactor = vtkInteractorStyleImage::New();
		//iren->SetInteractorStyle(interactor);
		m_RenWin->Render();
		//m_reader->Modified();
		//m_RenWin->Render();
		//iren->SetInteractorStyle(interactor);
		iren->Initialize();
		iren->Start();
		//Sleep(100);
		//iren->RemoveAllObservers();
		//m_RenWin->RemoveAllObservers();
		//m_Renderer->RemoveActor(m_Actor);
		//m_Actor->RemoveAllObservers();
		//m_reader->RemoveAllInputs();


		
	}
//*/
	if (m_reader) m_reader->Delete();
	if (m_Actor) m_Actor->Delete();
	if (m_Renderer) m_Renderer->Delete();
	if (m_RenWin) m_RenWin->Delete();
	if (iren) iren->Delete();

}

void showJEPG(){
	int extent[6]={256,256,0,256,1,1};
vtkJPEGReader *m_reader=vtkJPEGReader::New();
m_reader->SetFileName("D:\\001comp.jpeg");
m_reader->SetDataByteOrderToLittleEndian();
m_reader->SetDataScalarTypeToUnsignedChar();
m_reader->SetFileDimensionality(3);
vtkImageMapper * mapper=vtkImageMapper::New();
mapper->SetInputData(m_reader->GetOutput());
mapper->SetColorLevel(128);
mapper->SetColorWindow(256);
vtkActor2D * actor=vtkActor2D::New();
actor->SetMapper(mapper);
vtkRenderer * m_Renderer=vtkRenderer::New();
vtkRenderWindow * m_RenWin=vtkRenderWindow::New();
m_RenWin->AddRenderer(m_Renderer);
vtkRenderWindowInteractor *iren=vtkRenderWindowInteractor::New();
iren->SetRenderWindow(m_RenWin);
vtkInteractorStyleImage *interactor=vtkInteractorStyleImage::New();
iren->SetInteractorStyle(interactor);
m_Renderer->AddActor(actor);
m_Renderer->SetBackground(0.1,0.2,0.4);
m_RenWin->Render();
m_reader->GetDataExtent(extent);
m_RenWin->SetSize(256,256);
iren->Initialize();
iren->Start();
}

void showJEPG2(){
	vtkJPEGReader *image=vtkJPEGReader::New();
	image->SetFileName("d:\\001comp.jpeg");
	image->SetDataByteOrderToLittleEndian();
	image->SetDataScalarTypeToUnsignedChar();
	vtkImageViewer *pViewer = vtkImageViewer::New();//显示二维图形
	pViewer->SetColorLevel(128);//设置窗宽窗位，
	pViewer->SetColorWindow(256);
	pViewer->SetInputData(image->GetOutput());
	pViewer->Render();
	vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
	iren->SetRenderWindow(pViewer->GetRenderWindow());
	iren->Initialize();
	iren->Start();
}

void DemoFunction(){
	/*
演示各种不同的鼠标交互模式
*/



vtkRenderer *aRenderer = vtkRenderer::New();
vtkRenderWindow *renWin = vtkRenderWindow::New();
renWin->AddRenderer(aRenderer);

///////////////////////////////////////////////////////////////////////////
vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);

// 总共10种交互方式 下面是八种

//   vtkInteractorStyleTrackballCamera *style = //常用的方式 移动摄像机
//     vtkInteractorStyleTrackballCamera::New();
//   iren->SetInteractorStyle(style);

// vtkInteractorStyleTrackballActor *style = //移动对象
//    vtkInteractorStyleTrackballActor::New();
// iren->SetInteractorStyle(style);
// For a 3-button mouse, the left button is for rotation, the right button for zooming,
//the middle button for panning, and ctrl + left button for spinning.
//(With fewer mouse buttons, ctrl + shift + left button is for zooming,
    //and shift + left button is for panning.)


//   vtkInteractorStyleUnicam *style = //只有放大和平移的功能
//     vtkInteractorStyleUnicam::New();
//   iren->SetInteractorStyle(style);


//   vtkInteractorStyleUser *style =   //没有鼠标响应 主要用于用户自定义的操作
//     vtkInteractorStyleUser::New();
//   iren->SetInteractorStyle(style);

//   vtkInteractorStyleTerrain *style =
//     vtkInteractorStyleTerrain::New();
//   iren->SetInteractorStyle(style);

/*
vtkInteractorStyleSwitch *style =
    vtkInteractorStyleSwitch::New();
iren->SetInteractorStyle(style);
*/

//   vtkInteractorStyleFlight *style =
//     vtkInteractorStyleFlight::New();
//   iren->SetInteractorStyle(style);

// vtkInteractorStyleRubberBandZoom *style=vtkInteractorStyleRubberBandZoom::New();
// iren->SetInteractorStyle(style);

// vtkInteractorStyleSwitch *style=vtkInteractorStyleSwitch::New();
//     iren->SetInteractorStyle(style);

//     vtkInteractorStyleJoystickCamera *style=vtkInteractorStyleJoystickCamera::New();
// iren->SetInteractorStyle(style);

// vtkInteractorStyleJoystickActor *style= vtkInteractorStyleJoystickActor::New();
// iren->SetInteractorStyle(style);


///////////////////////////////////////////////////////////////////////////

vtkDICOMImageReader *reader = vtkDICOMImageReader::New();
reader->SetDataByteOrderToLittleEndian();
reader->SetFileName("D:\\1\\3\\CT.dcm");

vtkImageData *imageData = vtkImageData::New();
imageData = reader->GetOutput();
imageData->SetOrigin(.0,.0,.0);
//imageData->SetDimensions(64,64,93);

vtkImageShrink3D *shrink=vtkImageShrink3D::New();//二次采样
   shrink->SetInputData((vtkDataObject *)reader->GetOutput());
   shrink->SetShrinkFactors(4,4,1);//采样因子

vtkMarchingCubes *skinExtractor = vtkMarchingCubes::New();
    skinExtractor->SetInputConnection(shrink->GetOutputPort());
    skinExtractor->SetValue(0,200);//计算体素的等值面 可以提取多个等值面 0~200表示第一个等值面的值为200

vtkDecimatePro *deci=vtkDecimatePro::New();//减少mesh的三角面片
   deci->SetInputConnection(skinExtractor->GetOutputPort());
   deci->SetTargetReduction(0.3);//将原先的三角面片减少到原来的百分之七十
// Specify the desired reduction in the total number of polygons (e.g., if TargetReduction is set to 0.9, this filter will try to reduce the data set to 10% of its original size). Because of various constraints, this level of reduction may not be realized. If you want to guarantee a particular reduction, you must turn off PreserveTopology, turn on SplitEdges and BoundaryVertexDeletion, and set the MaximumError to VTK_DOUBLE_MAX (these ivars are initialized this way when the object is instantiated).


//adjust point positions using Laplacian smoothing
vtkSmoothPolyDataFilter *smooth=vtkSmoothPolyDataFilter::New();
    smooth->SetInputConnection(deci->GetOutputPort());
smooth->SetNumberOfIterations(100) ;//设置Laplace平滑的迭代次数

vtkPolyDataNormals *skinNormals = vtkPolyDataNormals::New();//compute normals for polygonal mesh
    skinNormals->SetInputConnection(smooth->GetOutputPort());
    skinNormals->SetFeatureAngle(60.0);//Specify the angle that defines a sharp edge. If the difference in angle across neighboring polygons is greater than this value, the shared edge is considered "sharp".

////////////////////////////////////////////////////////////////////////////////////////

// vtkTriangleFilter *triangle_filter=vtkTriangleFilter::New();//create triangle polygons from input polygons and triangle strips
// triangle_filter->SetInput( skinNormals->GetOutput());

vtkFeatureEdges *edges_extractor=vtkFeatureEdges::New();//extract boundary, non-manifold, and/or sharp edges from polygonal data
edges_extractor->SetInputData(skinNormals->GetOutput());
edges_extractor->ColoringOff();//Turn on/off the coloring of edges by type.
edges_extractor->BoundaryEdgesOn();//Turn on/off the extraction of boundary edges
edges_extractor->ManifoldEdgesOn();//Turn on/off the extraction of manifold edges.
edges_extractor->NonManifoldEdgesOn();//Turn on/off the extraction of non-manifold edges.

vtkStripper *stripper=vtkStripper::New();
    stripper->SetInputData(skinNormals->GetOutput());

/*
vtkPolyDataWriter *wSP=vtkPolyDataWriter::New();
    wSP->SetInput(stripper->GetOutput());
    wSP->SetFileName("E://CT/aaaa.VTK");
    wSP->Write();
   wSP->Delete();
   *///保存为VTK格式

vtkPolyDataMapper *skinMapper = vtkPolyDataMapper::New();
    skinMapper->SetInputData(stripper->GetOutput());
skinMapper->ScalarVisibilityOff();//Turn on/off flag to control whether the symbol's scalar data is used to color the symbol. If off, the color of the vtkLegendBoxActor is used.


vtkActor *skin = vtkActor::New();
    skin->SetMapper(skinMapper);
skin->GetProperty()->SetDiffuseColor(1, 0.49, 0.25);
    skin->GetProperty()->SetSpecular(.3);
    skin->GetProperty()->SetSpecularPower(20);

vtkCamera *aCamera = vtkCamera::New();
    aCamera->SetViewUp (0, 0, -1);
    aCamera->SetPosition (0, 1, 0);//Set/Get the position of the camera in world coordinates. The default position is (0,0,1).
    aCamera->SetFocalPoint (0, 0, 0);
    aCamera->ComputeViewPlaneNormal();

aRenderer->AddActor(skin);
aRenderer->SetActiveCamera(aCamera);
aRenderer->ResetCamera ();//Automatically set up the camera based on the visible actors. The camera will reposition itself to view the center point of the actors, and move along its initial view plane normal (i.e., vector defined from camera position to focal point) so that all of the actors can be seen.
aCamera->Dolly(1.5);// Move the position of the camera along the direction of projection. Moving towards the focal point (e.g., greater than 1) is a dolly-in, moving away from the focal point (e.g., less than 1) is a dolly-out.

aRenderer->SetBackground(1,1,1);
renWin->SetSize(640, 480);

aRenderer->ResetCameraClippingRange (); // Reset the camera clipping range based on the bounds of the visible actors. This ensures that no props are cut off


iren->Initialize();
iren->Start();

shrink->Delete();
smooth->Delete();
deci->Delete();
stripper->Delete();
skinExtractor->Delete();
skinNormals->Delete();
skinMapper->Delete();
skin->Delete();
aCamera->Delete();
iren->Delete();
renWin->Delete();
aRenderer->Delete();
reader->Delete();

}

#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkDICOMImageReader.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkOutlineFilter.h"
#include "vtkCamera.h"
#include "vtkProperty.h"
#include "vtkPolyDataNormals.h"
#include "vtkContourFilter.h"

void CTDemo ()
{

	// Create the renderer, the render window, and the interactor. The renderer
	// draws into the render window, the interactor enables mouse- and 
	// keyboard-based interaction with the data within the render window.
	//
	vtkRenderer *aRenderer = vtkRenderer::New();
	vtkRenderWindow *renWin = vtkRenderWindow::New();
	renWin->AddRenderer(aRenderer);
	vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
	iren->SetRenderWindow(renWin);

	// The following reader is used to read a series of 2D slices (images)
	// that compose the volume. The slice dimensions are set, and the
	// pixel spacing. The data Endianness must also be specified. The reader
	// usese the FilePrefix in combination with the slice number to construct
	// filenames using the format FilePrefix.%d. (In this case the FilePrefix
	// is the root name of the file: quarter.)
	vtkDICOMImageReader *v16 = vtkDICOMImageReader::New();
	//    v16->SetDataDimensions (64,64);
	//    v16->SetImageRange (1,93);
	v16->SetDataByteOrderToLittleEndian();
	v16->SetDirectoryName("E:\\1\\3");           //文件所在的位置
	v16->SetDataSpacing (3.2, 3.2, 1.5);

	// An isosurface, or contour value of 500 is known to correspond to the
	// skin of the patient. Once generated, a vtkPolyDataNormals filter is
	// is used to create normals for smooth surface shading during rendering.
	vtkContourFilter *skinExtractor = vtkContourFilter::New();
	skinExtractor->SetInputConnection(v16->GetOutputPort());
	skinExtractor->SetValue(0, 500);
	vtkPolyDataNormals *skinNormals = vtkPolyDataNormals::New();
	skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
	skinNormals->SetFeatureAngle(60.0);
	vtkPolyDataMapper *skinMapper = vtkPolyDataMapper::New();
	skinMapper->SetInputConnection(skinNormals->GetOutputPort());
	skinMapper->ScalarVisibilityOff();
	vtkActor *skin = vtkActor::New();
	skin->SetMapper(skinMapper);

	// An outline provides context around the data.
	//
	vtkOutlineFilter *outlineData = vtkOutlineFilter::New();
	outlineData->SetInputConnection(v16->GetOutputPort());
	vtkPolyDataMapper *mapOutline = vtkPolyDataMapper::New();
	mapOutline->SetInputConnection(outlineData->GetOutputPort());
	vtkActor *outline = vtkActor::New();
	outline->SetMapper(mapOutline);
	outline->GetProperty()->SetColor(0,0,0);

	// It is convenient to create an initial view of the data. The FocalPoint
	// and Position form a vector direction. Later on (ResetCamera() method)
	// this vector is used to position the camera to look at the data in
	// this direction.
	vtkCamera *aCamera = vtkCamera::New();
	aCamera->SetViewUp (0, 0, -1);
	aCamera->SetPosition (0, 1, 0);
	aCamera->SetFocalPoint (0, 0, 0);
	aCamera->ComputeViewPlaneNormal();

	// Actors are added to the renderer. An initial camera view is created.
	// The Dolly() method moves the camera towards the FocalPoint,
	// thereby enlarging the image.
	aRenderer->AddActor(outline);
	aRenderer->AddActor(skin);
	aRenderer->SetActiveCamera(aCamera);
	aRenderer->ResetCamera ();
	aCamera->Dolly(1.5);

	// Set a background color for the renderer and set the size of the
	// render window (expressed in pixels).
	aRenderer->SetBackground(1,1,1);
	renWin->SetSize(640, 480);

	// Note that when camera movement occurs (as it does in the Dolly()
	// method), the clipping planes often need adjusting. Clipping planes
	// consist of two planes: near and far along the view direction. The 
	// near plane clips out objects in front of the plane; the far plane
	// clips out objects behind the plane. This way only what is drawn
	// between the planes is actually rendered.
	aRenderer->ResetCameraClippingRange ();

	// Initialize the event loop and then start it.
	iren->Initialize();
	iren->Start(); 

	// It is important to delete all objects created previously to prevent
	// memory leaks. In this case, since the program is on its way to
	// exiting, it is not so important. But in applications it is
	// essential.
	v16->Delete();
	skinExtractor->Delete();
	skinNormals->Delete();
	skinMapper->Delete();
	skin->Delete();
	outlineData->Delete();
	mapOutline->Delete();
	outline->Delete();
	aCamera->Delete();
	iren->Delete();
	renWin->Delete();
	aRenderer->Delete();
	}


int main(int argc, char **argv)
{
	showBMPimage();
	//DemoFunction();
	//CTDemo();
	return 0;
}


