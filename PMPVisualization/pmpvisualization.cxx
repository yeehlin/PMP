#include "vtkDataSetReader.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCommand.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkPointData.h"
#include "vtkContourFilter.h"
#include "vtkDataSetMapper.h"
#include "vtkProperty.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkArrowSource.h"
#include "vtkMaskPoints.h"
#include "vtkOutlineFilter.h"
#include "vtkGlyph3D.h"
#include "vtkTransform.h"
#include "vtkAxesActor.h"
#include "vtkCaptionActor2D.h"
#include "vtkProperty2D.h"
#include "vtkLookupTable.h"
#include "vtkSmartVolumeMapper.h"
#include "vtkPiecewiseFunction.h"
#include "vtkColorTransferFunction.h"
#include "vtkVolumeProperty.h"
// tensor.vtk
#include "vtkStructuredPointsReader.h"
#include "vtkSuperquadricSource.h"
#include "vtkTensorGlyph.h"
#include "vtkPointSource.h"
#include "vtkStreamLine.h"
#include "vtkStructuredPoints.h"
#include "vtkExtractTensorComponents.h"
#include "vtkScalarBarActor.h"
#include "vtkTextProperty.h"

// GPU加速
#include "vtkGPUVolumeRayCastMapper.h"

#include "afx.h"

extern double isoValue1;
extern double isoValue2;
// 旧的可视化程序
void pmpvisualizationisosurface(){
	//CString file_name = "grid.vtk";

	CString filename;
	printf("input the name of vtk file:\n");
	scanf("%s",filename);
//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update();
//# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
		//print(id);
		//print(scalar_range);

		vtkLookupTable * colormap=vtkLookupTable::New();
		colormap->SetHueRange(0,0);
		colormap->SetSaturationRange(0,0);
		colormap->SetAlphaRange(0.5,0.5);
		colormap->SetValueRange(0,0);
		vtkContourFilter * contour = vtkContourFilter::New();
		contour->SetInput(id);
		contour->SetValue(0,1);
		contour->ComputeScalarsOn();
		vtkContourFilter * contour1 = vtkContourFilter::New();
		contour1->SetInput(id);
		contour1->ComputeScalarsOn();
		contour1->SetValue(0,2);
//# Create the mapper that corresponds the objects of the vtk file
//# into graphics elements
		vtkDataSetMapper * mapper = vtkDataSetMapper::New();
		mapper->SetInputConnection(reader->GetOutputPort());
		mapper->SetScalarRange(0,0);
		mapper->SetLookupTable(colormap);

		vtkDataSetMapper * mapper1 = vtkDataSetMapper::New();
		mapper1->SetInputConnection(contour->GetOutputPort());
		mapper1->SetScalarRange(scalar_range);

		vtkDataSetMapper *mapper2 = vtkDataSetMapper::New();
		mapper2->SetInputConnection(contour1->GetOutputPort());
		mapper2->SetScalarRange(scalar_range);
//# Create the Actor
		vtkActor * actor = vtkActor::New();
		actor->SetMapper(mapper);
		actor->GetProperty()->SetColor(0,0,0);
		actor->GetProperty()->SetOpacity(0.5);
//#actor->GetProperty()->SetRepresentationToSurface()

		vtkActor *actor1 = vtkActor::New();
		actor1->SetMapper(mapper1);

		vtkActor *actor2 = vtkActor::New();
		actor2->SetMapper(mapper2);

//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
//# Create the Renderer
		vtkRenderer *renderer = vtkRenderer::New();
		renderer->AddActor(actor);
		renderer->AddActor(actor1);
		renderer->AddActor(actor2);
		renderer->SetBackground(1, 1, 1);
//# Set background to white

//# Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);

//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);
		interactor->Initialize();
		interactor->Start();

}
void pmpvisualizationpolarization(){

	CString filename;
	printf("input the name of vtk file:\n");
	scanf("%s",filename);
	//CString file_name = "vector.vtk";

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update();
//# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		//double  * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
		//printf("%f ",&scalar_range);
		//print(scalar_range);

//# Create the mapper that corresponds the objects of the vtk file
//# into graphics elements

		vtkArrowSource *arrow = vtkArrowSource::New();
		arrow->Update();
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetOnRatio(10);
		mask->SetInput(id);
		mask->Update();
		vtkGlyph3D * glyph = vtkGlyph3D::New();
		glyph->SetSourceConnection(arrow->GetOutputPort());
		glyph->SetInput(mask->GetOutput());
		glyph->OrientOn();
		glyph->SetVectorModeToUseVector();
		glyph->SetColorModeToColorByVector();
		glyph->SetScaleModeToScaleByVector();
		glyph->SetScaleFactor(100000);

		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());

		vtkDataSetMapper * mapper = vtkDataSetMapper::New();
		mapper->SetInputConnection(glyph->GetOutputPort());
		mapper->SetScalarRange(-0.00001,0.00001);

		vtkPolyDataMapper * outlineMapper=vtkPolyDataMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());
//# Create the Actor
		vtkActor * actor = vtkActor::New();
		actor->SetMapper(mapper);
		actor->GetProperty()->SetOpacity(0.5);
		actor->GetProperty()->SetRepresentationToSurface();

		vtkTransform * transform=vtkTransform::New();
		transform->Translate(-5,0.0,0.0);
		vtkAxesActor * axes=vtkAxesActor::New();
		axes->SetUserTransform(transform);
		axes->SetScale(10);
		axes->SetTotalLength(10,10,10);
		axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		vtkActor *outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);
//#actor.GetProperty().SetOrigin(1.0,1.0,1.0);
// Create the Renderer
		vtkRenderer *renderer = vtkRenderer::New();
		renderer->AddActor(actor);
		renderer->AddActor(outlineActor);
		renderer->AddActor(axes);
		renderer->SetBackground(0.9, 0.9, 0.9);
//# Set background to white

// Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);

//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);
		interactor->Initialize();
		interactor->Start();

		//arrow->Delete();
		//mask->Delete();
		//glyph->Delete();
		//outline->Delete();
		//mapper->Delete();
		//outlineMapper->Delete();
		//actor->Delete();
		//transform->Delete();
		//axes->Delete();
		//outlineActor->Delete();
		//renderer->Delete();
		//renderer_window->Delete();
		//interactor->Delete();
		//interactor->Delete();
		//renderer_window->Delete();
}
void pmpvisualizationstreamline(){

	CString filename;
	printf("input the name of vtk file:\n");
	scanf("%s",filename);

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update();// # Needed because of GetScalarRange
		double * scalar_range = reader->GetStructuredPointsOutput()->GetPointData()->GetVectors()->GetRange(-1);
		vtkDataSet * id=reader->GetOutput();

		double * length=reader->GetOutput()->GetBounds();

//#Reduce the number of points to be plotted
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetOnRatio(10);
		mask->SetInput(id);
		mask->Update();

//#Set the source for stream lines
		vtkPointSource * seeds=vtkPointSource::New();
		seeds->SetCenter(10,10,10);
		seeds->SetNumberOfPoints(10);
		seeds->SetRadius(5);
//#create stream lines
		vtkStreamLine * stream = vtkStreamLine::New();
		stream->SetInputConnection(reader->GetOutputPort());
		stream->SetStepLength(0.1/sqrt(scalar_range[0]*scalar_range[1]));
		stream->SetIntegrationStepLength(0.1);
		stream->SetNumberOfThreads(10);
		stream->SetSource(seeds->GetOutput());
		stream->SetMaximumPropagationTime(length[1]/sqrt(scalar_range[0]*scalar_range[1]));
		stream->SpeedScalarsOn();
		stream->SetIntegrationDirectionToForward();

//#create the outer boundary of data
		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());

//#set the colormap based on vector's magnitude
		vtkColorTransferFunction * colormap=vtkColorTransferFunction::New();
		colormap->SetColorSpaceToLab();
		colormap->AddRGBPoint(scalar_range[0],0,0,1);
		colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/4,0,1,0);
		colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/2,1,0,0);
		colormap->Build();

//#Streamline mapper and outline mapper
		vtkPolyDataMapper * streamMapper=vtkPolyDataMapper::New();
		streamMapper->SetInputConnection(stream->GetOutputPort());
		streamMapper->SetLookupTable(colormap);

		vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());


//# Create the Actor
		vtkTransform * transform=vtkTransform::New();
		transform->Translate(-5,0.0,0.0);
		vtkAxesActor * axes=vtkAxesActor::New();
		axes->SetUserTransform(transform);
		axes->SetScale(10);
		axes->SetTotalLength(10,10,10);
		axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		vtkActor * outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);

		vtkActor * streamActor=vtkActor::New();
		streamActor->SetMapper(streamMapper);
		streamActor->VisibilityOn();

//# Create the Renderer
		vtkRenderer * renderer = vtkRenderer::New();

		renderer->AddActor(outlineActor);
		renderer->AddActor(axes);
		renderer->AddActor(streamActor);
		renderer->SetBackground(0.6, 0.6, 0.6);// # Set background to white

//# Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);

//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);
		interactor->Initialize();
		interactor->Start();
}
void pmpvisualizationtensor(){

	CString filename;
	printf("input the name of vtk file:\n");
	scanf("%s",filename);

//# Read the source file.
		vtkStructuredPointsReader * reader = vtkStructuredPointsReader::New();
		reader->SetFileName(filename);
		vtkStructuredPoints * id = reader->GetOutput();


//#Reduce the amount of points to be plotted, using maskPoints
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetInputConnection(reader->GetOutputPort());
		mask->SetOnRatio(100);
		mask->SetMaximumNumberOfPoints(1000000);
		mask->RandomModeOn();

//#Making tensor glyph with superquadratic glyph
		vtkSuperquadricSource * super=vtkSuperquadricSource::New();
		vtkTensorGlyph * tensorglyph=vtkTensorGlyph::New();
		tensorglyph->SetInputConnection(mask->GetOutputPort());
		tensorglyph->SetSourceConnection(super->GetOutputPort());
		tensorglyph->SetScaleFactor(5000);
		tensorglyph->ColorGlyphsOn();
		tensorglyph->SetColorModeToEigenvalues();

//#tensor glyph mapper
		vtkPolyDataMapper * mapper = vtkPolyDataMapper::New();
		mapper->SetInputConnection(tensorglyph->GetOutputPort());

		vtkActor * actor = vtkActor::New();
		actor->SetMapper(mapper);

//#create the outer boundary of the data
		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());
		vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());
		vtkActor * outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);


		vtkRenderer * renderer = vtkRenderer::New();
		renderer->AddActor(actor);
		renderer->AddActor(outlineActor);
		renderer->SetBackground(1, 1, 1);// # Set background to white

		vtkRenderWindow * renWin = vtkRenderWindow::New();
		renWin->AddRenderer(renderer);


		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renWin);

		interactor->Initialize();

		renWin->Render();

		interactor->Start();
}
void pmpvisualizationmultiview(){

	CString filename;
	printf("input the name of vtk file:\n");
	scanf("%s",filename);

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update();
		vtkDataSet * id = reader->GetOutput();
		float scalar_range[2]={10e-8,0.0001};

//#Reduce the amount of points to be plotted, using maskPoints
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetInputConnection(reader->GetOutputPort());
		mask->SetOnRatio(2);
		mask->SetMaximumNumberOfPoints(10000000);
		mask->RandomModeOn();
		mask->Update();

//#Making tensor glyph with superquadratic glyph

		vtkExtractTensorComponents * tensor11=vtkExtractTensorComponents::New();
		tensor11->SetInputConnection(reader->GetOutputPort());
		tensor11->ExtractScalarsOn();
		tensor11->PassTensorsToOutputOff();
		tensor11->SetScalarComponents(0,0);
		tensor11->Update();
		std::cout<<(tensor11->GetOutput());

		vtkExtractTensorComponents * tensor12=vtkExtractTensorComponents::New();
		tensor12->SetInputConnection(reader->GetOutputPort());
		tensor12->ExtractScalarsOn();
		tensor12->SetScalarComponents(0,1);

		vtkExtractTensorComponents * tensor13=vtkExtractTensorComponents::New();
		tensor13->SetInputConnection(reader->GetOutputPort());
		tensor13->ExtractScalarsOn();
		tensor13->SetScalarComponents(0,2);

		vtkExtractTensorComponents * tensor22=vtkExtractTensorComponents::New();
		tensor22->SetInputConnection(reader->GetOutputPort());
		tensor22->ExtractScalarsOn();
		tensor22->SetScalarComponents(1,1);

		vtkExtractTensorComponents * tensor23=vtkExtractTensorComponents::New();
		tensor23->SetInputConnection(reader->GetOutputPort());
		tensor23->ExtractScalarsOn();
		tensor23->SetScalarComponents(1,2);

		vtkExtractTensorComponents * tensor33=vtkExtractTensorComponents::New();
		tensor33->SetInputConnection(reader->GetOutputPort());
		tensor33->ExtractScalarsOn();
		tensor33->SetScalarComponents(2,2);
//#tensor glyph mapper
		vtkSmartVolumeMapper * mapper11 = vtkSmartVolumeMapper::New();
		mapper11->SetInputConnection(tensor11->GetOutputPort());

		vtkSmartVolumeMapper * mapper12 = vtkSmartVolumeMapper::New();
		mapper12->SetInputConnection(tensor12->GetOutputPort());
		vtkSmartVolumeMapper * mapper13 = vtkSmartVolumeMapper::New();
		mapper13->SetInputConnection(tensor13->GetOutputPort());
		vtkSmartVolumeMapper * mapper22 = vtkSmartVolumeMapper::New();
		mapper22->SetInputConnection(tensor22->GetOutputPort());
		vtkSmartVolumeMapper * mapper23 = vtkSmartVolumeMapper::New();
		mapper23->SetInputConnection(tensor23->GetOutputPort());
		vtkSmartVolumeMapper * mapper33 = vtkSmartVolumeMapper::New();
		mapper33->SetInputConnection(tensor33->GetOutputPort());


		vtkColorTransferFunction * colormap=vtkColorTransferFunction::New();
		colormap->SetColorSpaceToDiverging();
		colormap->AddRGBPoint(scalar_range[0],0,0,1);
		colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/4,0,1,0);
		colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/2,1,0,0);
		colormap->Build();
//# mapper11->SetLookupTable(colormap)
//# mapper12->SetLookupTable(colormap)
//# mapper13->SetLookupTable(colormap)
//# mapper21->SetLookupTable(colormap)


		vtkVolume * actor11 = vtkVolume::New();
		actor11->SetMapper(mapper11);
		vtkVolume * actor12 = vtkVolume::New();
		actor12->SetMapper(mapper12);
		vtkVolume * actor13 = vtkVolume::New();
		actor13->SetMapper(mapper13);
		vtkVolume * actor21 = vtkVolume::New();
		actor21->SetMapper(mapper12);
		vtkVolume * actor22 = vtkVolume::New();
		actor22->SetMapper(mapper22);
		vtkVolume * actor23 = vtkVolume::New();
		actor23->SetMapper(mapper23);
		vtkVolume * actor31 = vtkVolume::New();
		actor31->SetMapper(mapper13);
		vtkVolume * actor32 = vtkVolume::New();
		actor32->SetMapper(mapper23);
		vtkVolume * actor33 = vtkVolume::New();
		actor33->SetMapper(mapper33);



		vtkVolumeProperty * volumeProperty=vtkVolumeProperty::New();
		vtkColorTransferFunction * color=vtkColorTransferFunction::New();
		color->SetColorSpaceToLab();
		color->AddRGBPoint(scalar_range[0],0.0,0.0,1.0);
		color->AddRGBPoint(scalar_range[0]+scalar_range[1]/2,0,1,0);
		color->AddRGBPoint(scalar_range[1],1.0,0.0,0.0);
		volumeProperty->SetColor(color);
		volumeProperty->SetInterpolationTypeToNearest();

		actor11->SetProperty(volumeProperty);
		actor12->SetProperty(volumeProperty);
		actor13->SetProperty(volumeProperty);
		actor21->SetProperty(volumeProperty);
		actor22->SetProperty(volumeProperty);
		actor23->SetProperty(volumeProperty);
		actor31->SetProperty(volumeProperty);
		actor32->SetProperty(volumeProperty);
		actor33->SetProperty(volumeProperty);

//#create the outer boundary of the data
		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());
		vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());
		vtkActor * outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);



		double xmins[3]={0,0.333333,0.666667};
		double xmaxs[3]={0.333333,0.666667,1};
		double ymins[3]={0,0.333333,0.666667};
		double ymaxs[3]={0.333333,0.666667,1};

		vtkCamera *camera=vtkCamera::New();
		camera->SetPosition(0,0,100);
		camera->SetFocalPoint(0,0,0);
		vtkRenderer * renderer11 = vtkRenderer::New();
		vtkRenderer * renderer12 = vtkRenderer::New();
		vtkRenderer * renderer13 = vtkRenderer::New();
		vtkRenderer * renderer21 = vtkRenderer::New();
		vtkRenderer * renderer22 = vtkRenderer::New();
		vtkRenderer * renderer23 = vtkRenderer::New();
		vtkRenderer * renderer31 = vtkRenderer::New();
		vtkRenderer * renderer32 = vtkRenderer::New();
		vtkRenderer * renderer33 = vtkRenderer::New();

		renderer11->SetActiveCamera(camera);
		renderer12->SetActiveCamera(camera);
		renderer13->SetActiveCamera(camera);
		renderer21->SetActiveCamera(camera);
		renderer22->SetActiveCamera(camera);
		renderer23->SetActiveCamera(camera);
		renderer31->SetActiveCamera(camera);
		renderer32->SetActiveCamera(camera);
		renderer33->SetActiveCamera(camera);

		renderer11->SetViewport(xmins[0],ymins[2],xmaxs[0],ymaxs[2]);
		renderer12->SetViewport(xmins[1],ymins[2],xmaxs[1],ymaxs[2]);
		renderer13->SetViewport(xmins[2],ymins[2],xmaxs[2],ymaxs[2]);
		renderer21->SetViewport(xmins[0],ymins[1],xmaxs[0],ymaxs[1]);
		renderer22->SetViewport(xmins[1],ymins[1],xmaxs[1],ymaxs[1]);;
		renderer23->SetViewport(xmins[2],ymins[1],xmaxs[2],ymaxs[1]);
		renderer31->SetViewport(xmins[0],ymins[0],xmaxs[0],ymaxs[0]);
		renderer32->SetViewport(xmins[1],ymins[0],xmaxs[1],ymaxs[0]);
		renderer33->SetViewport(xmins[2],ymins[0],xmaxs[2],ymaxs[0]);

		renderer11->AddActor(actor11);
		renderer11->AddActor(outlineActor);
		renderer11->SetBackground(1, 1, 1); //# Set background to white

		renderer12->AddActor(actor12);
		renderer12->AddActor(outlineActor);
		renderer12->SetBackground(1, 1, 1); //# Set background to white

		renderer13->AddActor(actor13);
		renderer13->AddActor(outlineActor);
		renderer13->SetBackground(1, 1, 1) ;//# Set background to white

		renderer21->AddActor(actor21);
		renderer21->AddActor(outlineActor);
		renderer21->SetBackground(1, 1, 1); //# Set background to white

		renderer22->AddActor(actor22);
		renderer22->AddActor(outlineActor);
		renderer22->SetBackground(1, 1, 1) ;//# Set background to white

		renderer23->AddActor(actor23);
		renderer23->AddActor(outlineActor);
		renderer23->SetBackground(1, 1, 1) ;//# Set background to white

		renderer31->AddActor(actor31);
		renderer31->AddActor(outlineActor);
		renderer31->SetBackground(1, 1, 1) ;//# Set background to white

		renderer32->AddActor(actor32);
		renderer32->AddActor(outlineActor);
		renderer32->SetBackground(1, 1, 1); //# Set background to white

		renderer33->AddActor(actor33);
		renderer33->AddActor(outlineActor);
		renderer33->SetBackground(1, 1, 1) ;//# Set background to white

		vtkRenderWindow * renWin = vtkRenderWindow::New();
		renWin->AddRenderer(renderer11);
		renWin->AddRenderer(renderer12);
		renWin->AddRenderer(renderer13);
		renWin->AddRenderer(renderer21);
		renWin->AddRenderer(renderer22);
		renWin->AddRenderer(renderer23);
		renWin->AddRenderer(renderer31);
		renWin->AddRenderer(renderer32);
		renWin->AddRenderer(renderer33);

		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New() ;
		interactor->SetRenderWindow(renWin);

		interactor->Initialize();

		renWin->Render();

		interactor->Start();
}
void pmpvisualizationvolume(){
	//CString file_name = "strain.vtk";
	CString filename;
	printf("input the name of vtk file:\n");
	scanf("%s",filename);
//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update();
//# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
		//print(id);
		//print(scalar_range);

		vtkLookupTable * colormap = vtkLookupTable::New();
		colormap->SetHueRange(0.333333,0.6666667);
		colormap->SetSaturationRange(0,0);
		colormap->SetAlphaRange(0.5,0.5);
		colormap->SetValueRange(scalar_range);

		vtkContourFilter * contour = vtkContourFilter::New();
		contour->SetInput(id);
		contour->SetValue(0,1);
		contour->ComputeScalarsOn();
		vtkContourFilter *contour1 = vtkContourFilter::New();
		contour1->SetInput(id);
		contour1->ComputeScalarsOn();
		contour1->SetValue(1,2);
//# Create the mapper that corresponds the objects of the vtk file
//# into graphics elements
		vtkSmartVolumeMapper * mapper = vtkSmartVolumeMapper::New();
		mapper->SetInputConnection(reader->GetOutputPort());

//#mapper->SetScalarRange(scalar_range)
//#mapper->SetLookupTable(colormap)

		vtkDataSetMapper *mapper1 = vtkDataSetMapper::New();
		mapper1->SetInputConnection(contour->GetOutputPort());
		mapper1->SetScalarRange(scalar_range);

		vtkDataSetMapper *mapper2 = vtkDataSetMapper::New();
		mapper2->SetInputConnection(contour1->GetOutputPort());
		mapper2->SetScalarRange(scalar_range);
//# Create the Actor


		vtkVolume *actor = vtkVolume::New();
		actor->SetMapper(mapper);
		vtkVolumeProperty * volumeProperty= vtkVolumeProperty::New();
		vtkPiecewiseFunction * opacity= vtkPiecewiseFunction::New();
		opacity->AddPoint(scalar_range[0],0.3);
		opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.3);
		opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.05);
		opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.05);
		opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.3);
		opacity->AddPoint(scalar_range[1],0.3);

		vtkColorTransferFunction * color=vtkColorTransferFunction::New();
		color->SetColorSpaceToLab();
		color->AddRGBPoint(scalar_range[0],0.0,0.0,1.0);
		color->AddRGBPoint((scalar_range[0]+scalar_range[1])/2,0,1,0);
		color->AddRGBPoint(scalar_range[1],1.0,0.0,0.0);

		vtkPiecewiseFunction * gradOpacity = vtkPiecewiseFunction::New();
		gradOpacity->AddPoint(scalar_range[0],0);
		gradOpacity->AddPoint(scalar_range[1],0.3);

		volumeProperty->SetScalarOpacity(opacity);
		volumeProperty->SetColor(color);
//#volumeProperty->SetGradientOpacity(gradOpacity);
		volumeProperty->SetInterpolationTypeToNearest();

		actor->SetProperty(volumeProperty);
//#actor->GetProperty()->SetColor(0,0,0);
//#actor->GetProperty()->SetOpacity(0.5);
//#actor->GetProperty()->SetRepresentationToVolume();;

		vtkActor * actor1 = vtkActor::New();
		actor1->SetMapper(mapper1);
		vtkActor *actor2 = vtkActor::New();
		actor2->SetMapper(mapper2);

//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
//# Create the Renderer
		vtkRenderer * renderer = vtkRenderer::New();
		renderer->AddActor(actor);
//#renderer->AddActor(actor1)
//#renderer->AddActor(actor2)
		renderer->SetBackground(1, 1, 1);
//# Set background to white

//# Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);
		//print(scalar_range[0],scalar_range[1]);
//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);
//#style=vtkInteractorStyleTrackballActor()
//#interactor->SetInteractorSytle(style)
//#style->SetCurrentStyleToTrackballCamera()

		interactor->Initialize();
		interactor->Start();

}

// 新的可视化程序
vtkContourFilter * contour ;
vtkContourFilter * contour1;
// 标量数的等值面
void PMPVisualizeIsosurface(CString filename){

//	from vtk import *

//		file_name = "strain.vtk"

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update(); //# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();

		printf("%g %g\n",scalar_range[0],scalar_range[1]);
		///////////////////////////////////20140821///////////////////////////////////////
		//vtkLookupTable * colormap=vtkLookupTable::New();
		//colormap->SetHueRange(0,0);
		//colormap->SetSaturationRange(0,0);
		//colormap->SetAlphaRange(0.5,0.5);
		//colormap->SetValueRange(0,0);

		double diff = scalar_range[1]-scalar_range[0];
		vtkColorTransferFunction * color=vtkColorTransferFunction::New();
		color->SetColorSpaceToLab();
		int RGBPoint=12;
		double * RGBValue;
		RGBValue = (double *)malloc(RGBPoint*sizeof(double));
		//double RGBValue[3]={scalar_range[0],diff/(RGBPoint - 1)+scalar_range[0],scalar_range[1]};
		for (int i=0;i<RGBPoint;i++)
		{
			RGBValue[i] = scalar_range[0]+(diff/(RGBPoint-1))*i;
		}
		double **RGB;
		//RGB = (double **)(new double[RGBPoint][3]);
		RGB = (double **)malloc(RGBPoint*sizeof(double *));
		for (int i =0;i<RGBPoint;i++)
		{
			*(RGB + i) = (double *)malloc(3*sizeof(double));
		}
		for (int i = 0;i<RGBPoint;i++)
		{
			if (i%3==0)
			{
				RGB[i][0]=0.0;
				RGB[i][1]=0.0;
				RGB[i][2]=1.0;
			}
			if (i%3==1)
			{
				RGB[i][0]=0.0;
				RGB[i][1]=1.0;
				RGB[i][2]=0.0;
			}
			if (i%3==2)
			{
				RGB[i][0]=1.0;
				RGB[i][1]=0.0;
				RGB[i][2]=0.0;
			}

		}
		//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
		for (int i=0;i<RGBPoint;i++)
		{
			color->AddRGBPoint(RGBValue[i],RGB[i][0],RGB[i][1],RGB[i][2]);
		}
		/////////////////////////////////////20140821/////////////////////////////////////

		contour = vtkContourFilter::New();
		contour->SetInput(id);

//#-------------------------------------------------------------------------------
		double range=scalar_range[1]-scalar_range[0];
//#-------------------------------------------------------------------------------

//#-------------------------------------------------------------------------------
//#isoValue1 should be set by user, the following gis default value
		// 等值面值1由用户输入，以下是默认值
	isoValue1=range*1/8+scalar_range[0];
	// 输入等值面值1
	//printf("isoValue1:\n");
	//scanf("%g",&isoValue1);
	contour->SetValue(0,isoValue1);
//#-------------------------------------------------------------------------------
		contour->ComputeScalarsOn();


		contour1 = vtkContourFilter::New();
		contour1->SetInput(id);
		contour1->ComputeScalarsOn();
//#-------------------------------------------------------------------------------
//#isoValue2 should be set by user, the following gis default value
		// 等值面值2由用户输入，以下是默认值
		isoValue2=range*3/8+scalar_range[0];
		//printf("isoValue2:\n");
		//scanf("%g",&isoValue2);
	contour1->SetValue(0,isoValue2);
//#-------------------------------------------------------------------------------
//# Create the mapper that corresponds the objects of the vtk file
//# into graphics elements
		vtkDataSetMapper * mapper = vtkDataSetMapper::New();
		mapper->SetInputConnection(reader->GetOutputPort());
		//mapper->SetScalarRange(0,0);
		mapper->SetLookupTable(color);

		vtkDataSetMapper * mapper1 = vtkDataSetMapper::New();
		mapper1->SetInputConnection(contour->GetOutputPort());
		mapper1->SetScalarRange(scalar_range);

		mapper1->SetLookupTable(color);

		vtkDataSetMapper * mapper2 = vtkDataSetMapper::New();
		mapper2->SetInputConnection(contour1->GetOutputPort());
		mapper2->SetScalarRange(scalar_range);
		mapper2->SetLookupTable(color);
//# Create the Actor
		vtkActor * actor = vtkActor::New();
		actor->SetMapper(mapper);
		actor->GetProperty()->SetColor(0,0,0);
		actor->GetProperty()->SetOpacity(0.1);
//#actor->GetProperty()->SetRepresentationToSurface()

		vtkActor * actor1 = vtkActor::New();
		actor1->SetMapper(mapper1);
		double iso1Opacity  = 0.5;
		actor1->GetProperty()->SetOpacity(iso1Opacity);

		vtkActor * actor2 = vtkActor::New();
		actor2->SetMapper(mapper2);

		double iso2Opacity  = 0.7;
		actor2->GetProperty()->SetOpacity(iso2Opacity);
//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
//# Create the Renderer
		vtkRenderer * renderer = vtkRenderer::New();
		renderer->AddActor(actor);
		renderer->AddActor(actor1);
		renderer->AddActor(actor2);

//#-------------------------------------------------------------------------------
//#20140820
		vtkScalarBarActor * scaleBar=vtkScalarBarActor::New();
			scaleBar->SetLookupTable(color);
			scaleBar->SetTitle("Scale Bar");
			scaleBar->SetNumberOfLabels(RGBPoint);
			scaleBar->GetTitleTextProperty()->SetColor(0,0,0);
			scaleBar->GetLabelTextProperty()->SetColor(0,0,0);
			renderer->AddActor2D(scaleBar);

			vtkTransform * transform=vtkTransform::New();
			transform->Translate(-5,-5,-5);
			vtkAxesActor * axes=vtkAxesActor::New();
			axes->SetUserTransform(transform);
			axes->SetScale(10);
			axes->SetTotalLength(10,10,10);
			axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			vtkOutlineFilter * outline=vtkOutlineFilter::New();
			outline->SetInput(reader->GetOutput());
			vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
			outlineMapper->SetInputConnection(outline->GetOutputPort());
			vtkActor * outlineActor=vtkActor::New();
			outlineActor->SetMapper(outlineMapper);
			outlineActor->GetProperty()->SetColor(0,0,0);
			renderer->AddActor(outlineActor);
			renderer->AddActor(axes);
//#-------------------------------------------------------------------------------

		renderer->SetBackground(1, 1, 1); //# Set background to white

//# Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);

//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor *interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);
		interactor->Initialize();
		interactor->Start();
		renderer_window->Render();
		renderer_window->Start();

		// 销毁动态内存
		if (RGBValue != NULL)
		{
			free(RGBValue);
		}
		for(int i=0;i<RGBPoint;i++){
			if (*(RGB+i) != NULL)
			{
				free(*(RGB+i));
			}
		}
		if (RGB != NULL)
		{
			free(RGB);
		}
}
// 标量数据体绘制
void PMPVisualizeVolumn(CString filename){

//	from vtk import *

//		file_name = "strain.vtk"

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update(); //# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
		//print(scalar_range);

		vtkLookupTable * colormap=vtkLookupTable::New();
		//HSV(Hue, Saturation, Value),色调（H），饱和度（S），亮度（V）
		colormap->SetHueRange(0.333333,0.6666667);
		colormap->SetSaturationRange(0,0);
		colormap->SetAlphaRange(0.5,0.5);
		colormap->SetValueRange(scalar_range);


//# Create the mapper that corresponds the objects of the vtk file
//# into graphics elements
		vtkSmartVolumeMapper * mapper = vtkSmartVolumeMapper::New();
		mapper->SetInputConnection(reader->GetOutputPort());

//# Create the Actor


		vtkVolume * actor = vtkVolume::New();
		actor->SetMapper(mapper);
		vtkVolumeProperty * volumeProperty=vtkVolumeProperty::New();
		vtkPiecewiseFunction * opacity=vtkPiecewiseFunction::New();
		vtkColorTransferFunction * color=vtkColorTransferFunction::New();
		color->SetColorSpaceToLab();
		//opacity->AddPoint(scalar_range[0],0.3);
		//opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.3);
		//opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.05);
		//opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.05);
		//opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.3);
		//opacity->AddPoint(scalar_range[1],0.3);

		//color->AddRGBPoint(scalar_range[0],0.0,0.0,1.0);
		//color->AddRGBPoint((scalar_range[0]+scalar_range[1])/2,0,1,0);
		//color->AddRGBPoint(scalar_range[1],1.0,0.0,0.0);

		//vtkPiecewiseFunction * gradOpacity = vtkPiecewiseFunction::New();
		//gradOpacity->AddPoint(scalar_range[0],0);
		//gradOpacity->AddPoint(scalar_range[1],0.3);
/////////////////////////////////20140821/////////////////////////////////////////
		double diff = scalar_range[1]-scalar_range[0];
		// 设置透明度
		int opacityPoint=6;
		double * opValue;
		opValue = (double * )malloc(opacityPoint * sizeof(double));
		for (int i = 0;i<opacityPoint;i++)
		{
			opValue[i]=scalar_range[0]+(diff/(opacityPoint - 1))*i;
		}
		//opValue=[scalar_range[0],scalar_range[0]+diff/100,diff/100+scalar_range[0],6*diff/100+scalar_range[0],6*diff/100+scalar_range[0],scalar_range[1]]
		double * alpha;
		alpha = (double *)malloc(opacityPoint*sizeof(double));
		for (int i =0;i<opacityPoint;i++)
		{
			alpha[i] = 0.0+(1.0/(opacityPoint-1))*i;
		}
		//=[0.1,0.1,0.0,0.0,1,1]
		//for a in range(0,opacityPoint):
		//opacity.AddPoint(opValue[a],alpha[a])
		for (int i =0 ;i<opacityPoint;i++)
		{
			opacity->AddPoint(opValue[i],alpha[i]);
		}

		// 设置颜色点
		int RGBPoint=4;
		double * RGBValue;
		RGBValue = (double *)malloc(RGBPoint*sizeof(double));
		//double RGBValue[3]={scalar_range[0],diff/(RGBPoint - 1)+scalar_range[0],scalar_range[1]};
		for (int i=0;i<RGBPoint;i++)
		{
			RGBValue[i] = scalar_range[0]+(diff/(RGBPoint-1))*i;
		}
		double **RGB;
		//RGB = (double **)(new double[RGBPoint][3]);
		RGB = (double **)malloc(RGBPoint*sizeof(double *));
		for (int i =0;i<RGBPoint;i++)
		{
			*(RGB + i) = (double *)malloc(3*sizeof(double));
		}
		for (int i = 0;i<RGBPoint;i++)
		{
			if (i%3==0)
			{
				RGB[i][0]=0.0;RGB[i][1]=0.0;RGB[i][2]=1.0;
			}
			if (i%3==1)
			{
				RGB[i][0]=0.0;RGB[i][1]=1.0;RGB[i][2]=0.0;
			}
			if (i%3==2)
			{
				RGB[i][0]=1.0;RGB[i][1]=0.0;RGB[i][2]=0.0;
			}

		}
		//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
		for (int i=0;i<RGBPoint;i++)
		{
			color->AddRGBPoint(RGBValue[i],RGB[i][0],RGB[i][1],RGB[i][2]);
		}
//////////////////////////////////20140821////////////////////////////////////////


		volumeProperty->SetScalarOpacity(opacity);
		volumeProperty->SetColor(color);
//#volumeProperty->SetGradientOpacity(gradOpacity)
		volumeProperty->SetInterpolationTypeToNearest();

		actor->SetProperty(volumeProperty);

//# Create the Renderer
		vtkRenderer * renderer = vtkRenderer::New();
		renderer->AddActor(actor);


//#---------------------------------------------------------------------------
//#20140820 added
		vtkScalarBarActor * scaleBar=vtkScalarBarActor::New();
			scaleBar->SetLookupTable(color);
			scaleBar->SetTitle("Scale Bar");
			scaleBar->SetNumberOfLabels(RGBPoint);
			scaleBar->GetTitleTextProperty()->SetColor(0,0,0);
			scaleBar->GetLabelTextProperty()->SetColor(0,0,0);
			renderer->AddActor2D(scaleBar);

			vtkTransform * transform=vtkTransform::New();
			transform->Translate(-5,-5,-5);
			vtkAxesActor * axes=vtkAxesActor::New();
			axes->SetUserTransform(transform);
			axes->SetScale(10);
			axes->SetTotalLength(10,10,10);
			axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			vtkOutlineFilter * outline=vtkOutlineFilter::New();
			outline->SetInput(reader->GetOutput());
			vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
			outlineMapper->SetInputConnection(outline->GetOutputPort());
			vtkActor * outlineActor=vtkActor::New();
			outlineActor->SetMapper(outlineMapper);
			outlineActor->GetProperty()->SetColor(0,0,0);
			renderer->AddActor(outlineActor);
			renderer->AddActor(axes);
//#----------------------------------------------------------------------------



		renderer->SetBackground(1, 1, 1); //# Set background to white

//# Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);
		//print(scalar_range[0],scalar_range[1]);
//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);


		interactor->Initialize();
		//测试时间
		int timebegin=::GetTickCount();
		for(int i=0;i<90;i++)
		{
			renderer->GetActiveCamera()->Azimuth(1);
			renderer->ResetCamera();
			renderer_window->Render();
		}
		int timeend=::GetTickCount();
		cout<<"Elapsed time:"<<(timeend-timebegin)<<endl;
		interactor->Start();

		// 销毁动态内存
		// 销毁opValue
		if (opValue != NULL)
		{
			free(opValue);
		}
		// 销毁alpha
		if (alpha != NULL)
		{
			free(alpha);
		}
		// 销毁RGBValue
		if (RGBValue != NULL)
		{
			free(RGBValue);
		}
		// 销毁RGB
		for(int i=0;i<RGBPoint;i++){
			if (*(RGB+i) != NULL)
			{
				free(*(RGB+i));
			}
		}
		if (RGB != NULL)
		{
			free(RGB);
		}

}
// Scalar数据可视化
void PMPVisualizeScalar1D(CString filename){
	PMPVisualizeIsosurface(filename);
}
// Vector数据可视化
void PMPVisualizeVector3D(CString filename){

//	from vtk import *
//		from math import sqrt

//		file_name = "vector.vtk"

//# Read the source file.
		vtkDataSetReader *reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update(); //# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range = id->GetPointData()->GetArray(0)->GetRange(-1);
		printf("reader:%d\n",reader);

//# Create the mapper that corresponds the objects of the vtk file
//# into graphics elements



		vtkArrowSource * arrow = vtkArrowSource::New();
		arrow->Update();
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetOnRatio(10);
		mask->SetInput(id);
		mask->Update();
		vtkGlyph3D * glyph = vtkGlyph3D::New();
		glyph->SetSourceConnection(arrow->GetOutputPort());
		glyph->SetInput(mask->GetOutput());
		glyph->OrientOn();
		glyph->SetVectorModeToUseVector();
		glyph->SetColorModeToColorByVector();
		glyph->SetScaleModeToScaleByVector();

//#-------------------------------------------------------------------------------
		double scaleFactor=1/sqrt(scalar_range[0]*scalar_range[1]);
		glyph->SetScaleFactor(scaleFactor);
//#-------------------------------------------------------------------------------
		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());

		vtkDataSetMapper * mapper = vtkDataSetMapper::New();
		mapper->SetInputConnection(glyph->GetOutputPort());

//#-------------------------------------------------------------------------------
		mapper->SetScalarRange(scalar_range[0],scalar_range[1]);
//#-------------------------------------------------------------------------------

//#-------------------------------------------------------------------------------
//#20140820 changes
		vtkColorTransferFunction * color=vtkColorTransferFunction::New();
			color->SetColorSpaceToLab();
			double diff=scalar_range[1]-scalar_range[0];
		int RGBPoint=3;
		double * RGBValue;
		RGBValue = (double *)malloc(RGBPoint*sizeof(double));
		for (int i= 0;i<RGBPoint;i++)
		{
			RGBValue[i] = scalar_range[0]+(diff/(RGBPoint - 1))*i;
		}
		//RGBValue=[scalar_range[0],diff/6+scalar_range[0],scalar_range[1]]
		double **RGB;
		RGB = (double **)malloc(RGBPoint*sizeof(double *));
		for (int i =0;i<RGBPoint;i++)
		{
			*(RGB + i) = (double *)malloc(3*sizeof(double));
		}
		for (int i = 0;i<RGBPoint;i++)
		{
			if (i%3==0)
			{
				RGB[i][0]=0.0;
				RGB[i][1]=0.0;
				RGB[i][2]=1.0;
			}
			if (i%3==1)
			{
				RGB[i][0]=0.0;
				RGB[i][1]=1.0;
				RGB[i][2]=0.0;
			}
			if (i%3==2)
			{
				RGB[i][0]=1.0;
				RGB[i][1]=0.0;
				RGB[i][2]=0.0;
			}

		}
		//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
		for (int i=0;i<RGBPoint;i++)
		{
			color->AddRGBPoint(RGBValue[i],RGB[i][0],RGB[i][1],RGB[i][2]);
		}

		mapper->SetLookupTable(color);
//#-------------------------------------------------------------------------------


		vtkPolyDataMapper * outlineMapper=vtkPolyDataMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());
//# Create the Actor
		vtkActor * actor = vtkActor::New();
		actor->SetMapper(mapper);
		actor->GetProperty()->SetOpacity(0.5);
		actor->GetProperty()->SetRepresentationToSurface();

		vtkTransform * transform=vtkTransform::New();
		transform->Translate(-5,-5,-5);
		vtkAxesActor * axes=vtkAxesActor::New();
		axes->SetUserTransform(transform);
		axes->SetScale(10);
		axes->SetTotalLength(10,10,10);
		axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		vtkActor *outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);
//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
//# Create the Renderer
		vtkRenderer *renderer = vtkRenderer::New();
		renderer->AddActor(actor);
		renderer->AddActor(outlineActor);
		renderer->AddActor(axes);

//#-------------------------------------------------------------------------------
//#20140820
		vtkScalarBarActor * scaleBar=vtkScalarBarActor::New();
			scaleBar->SetLookupTable(color);
			scaleBar->SetTitle("Scale Bar");
			scaleBar->SetNumberOfLabels(RGBPoint);
			scaleBar->GetTitleTextProperty()->SetColor(0,0,0);
			scaleBar->GetLabelTextProperty()->SetColor(0,0,0);
			renderer->AddActor2D(scaleBar);

//#-------------------------------------------------------------------------------


		renderer->SetBackground(0.9, 0.9, 0.9); //# Set background to white

//# Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);

//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);
		interactor->Initialize();
		interactor->Start();

		// 销毁动态内存
		if (RGBValue != NULL)
		{
			free(RGBValue);
		}
		for(int i=0;i<RGBPoint;i++){
			if (*(RGB+i) != NULL)
			{
				free(*(RGB+i));
			}
		}
		if (RGB != NULL)
		{
			free(RGB);
		}
}
// Tensor数据可视化
void PMPVisualizeTensor33D(CString filename){

//	from vtk import *
//		from math import sqrt

//		file_name = "tensor.vtk"

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update();
		vtkDataSet * id = reader->GetOutput();
//#--------------------------------------------------------------------------
		double * scalar_range = reader->GetStructuredPointsOutput()->GetPointData()->GetTensors()->GetRange(-1);
//#--------------------------------------------------------------------------
		printf("Tensor scalar_range:%f   %f\n",scalar_range[0],scalar_range[1]);
//#Reduce the amount of points to be plotted, using maskPoints
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetInputConnection(reader->GetOutputPort());
		mask->SetOnRatio(100);
		mask->SetMaximumNumberOfPoints(1000000);
		mask->RandomModeOn();

//#Making tensor glyph with superquadratic glyph
		vtkSuperquadricSource * super=vtkSuperquadricSource::New();
		vtkTensorGlyph * tensorglyph=vtkTensorGlyph::New();
		tensorglyph->SetInputConnection(mask->GetOutputPort());
		tensorglyph->SetSourceConnection(super->GetOutputPort());
//#----------------------------------------------------------------------------
		double scaleFactor=0.6/sqrt(scalar_range[0]*scalar_range[1]);
		tensorglyph->SetScaleFactor(scaleFactor);
//#----------------------------------------------------------------------------
		tensorglyph->ColorGlyphsOn();
		tensorglyph->SetColorModeToEigenvalues();

//#tensor glyph mapper
		vtkPolyDataMapper * mapper = vtkPolyDataMapper::New();
		mapper->SetInputConnection(tensorglyph->GetOutputPort());

		vtkActor * actor = vtkActor::New();
		actor->SetMapper(mapper);

//#create the outer boundary of the data
		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());
		vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());
		vtkActor * outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);


		vtkRenderer * renderer = vtkRenderer::New();
		renderer->AddActor(actor);
		renderer->AddActor(outlineActor);
		renderer->SetBackground(1, 1, 1); //# Set background to white

		vtkRenderWindow * renWin = vtkRenderWindow::New();
		renWin->AddRenderer(renderer);


		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renWin);

		interactor->Initialize();

		renWin->Render();

		interactor->Start();

}
// Vector数据Streamline可视化
void PMPVisualizeVector3DStreamline(CString filename){

//	from vtk import *
//		from math import sqrt

//		file_name = "vector.vtk"

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update(); //# Needed because of GetScalarRange

		double * scalar_range = reader->GetStructuredPointsOutput()->GetPointData()->GetVectors()->GetRange(-1);

		vtkDataSet * id=reader->GetOutput();
		printf("vectors:%d\n",reader->GetStructuredPointsOutput()->GetPointData()->GetVectors());
//#---------------------------------------------------------------------------------
		double * length=reader->GetOutput()->GetBounds();
//#---------------------------------------------------------------------------------

//#Reduce the number of points to be plotted
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetOnRatio(10);
		mask->SetInput(id);
		mask->Update();

//#Set the source for stream lines
//#x,y,z,nPoints,radius should be set by user, the following is default value
		int x=10;
		int y=10;
		int z=10;
		int nPoints=10;
		int radius=5;

		vtkPointSource * seeds=vtkPointSource::New();
		seeds->SetCenter(x,y,z);
		seeds->SetNumberOfPoints(nPoints);
		seeds->SetRadius(radius);
//#create stream lines
		vtkStreamLine * stream=vtkStreamLine::New();
		stream->SetInputConnection(reader->GetOutputPort());
//#---------------------------------------------------------------------------------
		stream->SetStepLength(0.1/sqrt(scalar_range[0]*scalar_range[1]));
//#---------------------------------------------------------------------------------
		stream->SetIntegrationStepLength(0.1);
		stream->SetNumberOfThreads(10);
		stream->SetSource(seeds->GetOutput());
//#---------------------------------------------------------------------------------
		stream->SetMaximumPropagationTime(length[1]/sqrt(scalar_range[0]*scalar_range[1]));
//#---------------------------------------------------------------------------------
		stream->SpeedScalarsOn();
		stream->SetIntegrationDirectionToForward();

//#create the outer boundary of data
		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());

//#set the colormap based on vector's magnitude
		//vtkColorTransferFunction * colormap=vtkColorTransferFunction::New();
		//colormap->SetColorSpaceToLab();
		//colormap->AddRGBPoint(scalar_range[0],0,0,1);
		//colormap->AddRGBPoint((scalar_range[0]+scalar_range[1])/4,0,1,0);
		//colormap->AddRGBPoint((scalar_range[0]+scalar_range[1])/2,1,0,0);
		//colormap->Build();


		vtkColorTransferFunction * color=vtkColorTransferFunction::New();
		color->SetColorSpaceToLab();
		double diff = scalar_range[1]-scalar_range[0];
		int RGBPoint=6;
		double * RGBValue;
		RGBValue = (double *)malloc(RGBPoint*sizeof(double));
		//double RGBValue[3]={scalar_range[0],diff/(RGBPoint - 1)+scalar_range[0],scalar_range[1]};
		for (int i=0;i<RGBPoint;i++)
		{
			RGBValue[i] = scalar_range[0]+(diff/(RGBPoint-1))*i;
		}
		double **RGB;
		//RGB = (double **)(new double[RGBPoint][3]);
		RGB = (double **)malloc(RGBPoint*sizeof(double *));
		for (int i =0;i<RGBPoint;i++)
		{
			*(RGB + i) = (double *)malloc(3*sizeof(double));
		}
		for (int i = 0;i<RGBPoint;i++)
		{
			if (i%3==0)
			{
				RGB[i][0]=0.0;RGB[i][1]=0.0;RGB[i][2]=1.0;
			}
			if (i%3==1)
			{
				RGB[i][0]=0.0;RGB[i][1]=1.0;RGB[i][2]=0.0;
			}
			if (i%3==2)
			{
				RGB[i][0]=1.0;RGB[i][1]=0.0;RGB[i][2]=0.0;
			}

		}
		//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
		for (int i=0;i<RGBPoint;i++)
		{
			color->AddRGBPoint(RGBValue[i],RGB[i][0],RGB[i][1],RGB[i][2]);
		}


//#Streamline mapper and outline mapper
		vtkPolyDataMapper * streamMapper=vtkPolyDataMapper::New();
		streamMapper->SetInputConnection(stream->GetOutputPort());
		streamMapper->SetLookupTable(color);

		vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());


//# Create the Actor
		vtkTransform * transform=vtkTransform::New();
		transform->Translate(-5,-5,-5);
		vtkAxesActor * axes=vtkAxesActor::New();
		axes->SetUserTransform(transform);
		axes->SetScale(10);
		axes->SetTotalLength(10,10,10);
		axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
		vtkActor * outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);

		vtkActor * streamActor=vtkActor::New();
		streamActor->SetMapper(streamMapper);
		streamActor->VisibilityOn();

//# Create the Renderer
		vtkRenderer * renderer = vtkRenderer::New();

		renderer->AddActor(outlineActor);
		renderer->AddActor(axes);
		renderer->AddActor(streamActor);

//#-------------------------------------------------------------------------------
//#20140820
		vtkScalarBarActor * scaleBar=vtkScalarBarActor::New();
			scaleBar->SetLookupTable(color);
			scaleBar->SetTitle("Scale Bar");
			scaleBar->SetNumberOfLabels(RGBPoint);
			scaleBar->GetTitleTextProperty()->SetColor(0,0,0);
			scaleBar->GetLabelTextProperty()->SetColor(0,0,0);
			renderer->AddActor2D(scaleBar);
//#-------------------------------------------------------------------------------



		renderer->SetBackground(0.6, 0.6, 0.6); //# Set background to white

//# Create the RendererWindow
		vtkRenderWindow * renderer_window = vtkRenderWindow::New();
		renderer_window->AddRenderer(renderer);

//# Create the RendererWindowInteractor and display the vtk_file
		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renderer_window);
		interactor->Initialize();
		interactor->Start();

		// 销毁动态内存
		if (RGBValue != NULL)
		{
			free(RGBValue);
		}
		for(int i=0;i<RGBPoint;i++){
			if (*(RGB+i) != NULL)
			{
				free(*(RGB+i));
			}
		}
		if (RGB != NULL)
		{
			free(RGB);
		}

}
// Tensor数据的multiview可视化
void PMPVisualizeTensor33DMultiview(CString filename){

//	from vtk import *

//		file_name = "tensor.vtk"

//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename);
		reader->Update();
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range=id->GetPointData()->GetArray(0)->GetRange(-1);
		printf("scalar_range:%f   %f\n",scalar_range[0],scalar_range[1]);

//#Reduce the amount of points to be plotted, using maskPoints
		vtkMaskPoints * mask = vtkMaskPoints::New();
		mask->SetInputConnection(reader->GetOutputPort());
		mask->SetOnRatio(2);
		mask->SetMaximumNumberOfPoints(10000000);
		mask->RandomModeOn();
		mask->Update();

//#Making tensor glyph with superquadratic glyph

		vtkExtractTensorComponents * tensor11=vtkExtractTensorComponents::New();
		tensor11->SetInputConnection(reader->GetOutputPort());
		tensor11->ExtractScalarsOn();
		tensor11->PassTensorsToOutputOff();
		tensor11->SetScalarComponents(0,0);
		tensor11->Update();

		vtkExtractTensorComponents * tensor12=vtkExtractTensorComponents::New();
		tensor12->SetInputConnection(reader->GetOutputPort());
		tensor12->ExtractScalarsOn();
		tensor12->SetScalarComponents(0,1);

		vtkExtractTensorComponents * tensor13=vtkExtractTensorComponents::New();
		tensor13->SetInputConnection(reader->GetOutputPort());
		tensor13->ExtractScalarsOn();
		tensor13->SetScalarComponents(0,2);

		vtkExtractTensorComponents * tensor22=vtkExtractTensorComponents::New();
		tensor22->SetInputConnection(reader->GetOutputPort());
		tensor22->ExtractScalarsOn();
		tensor22->SetScalarComponents(1,1);

		vtkExtractTensorComponents * tensor23=vtkExtractTensorComponents::New();
		tensor23->SetInputConnection(reader->GetOutputPort());
		tensor23->ExtractScalarsOn();
		tensor23->SetScalarComponents(1,2);

		vtkExtractTensorComponents * tensor33=vtkExtractTensorComponents::New();
		tensor33->SetInputConnection(reader->GetOutputPort());
		tensor33->ExtractScalarsOn();
		tensor33->SetScalarComponents(2,2);
//#tensor glyph mapper
		vtkSmartVolumeMapper * mapper11 = vtkSmartVolumeMapper::New();
		mapper11->SetInputConnection(tensor11->GetOutputPort());

		vtkSmartVolumeMapper * mapper12 = vtkSmartVolumeMapper::New();
		mapper12->SetInputConnection(tensor12->GetOutputPort());
		vtkSmartVolumeMapper * mapper13 = vtkSmartVolumeMapper::New();
		mapper13->SetInputConnection(tensor13->GetOutputPort());
		vtkSmartVolumeMapper * mapper22 = vtkSmartVolumeMapper::New();
		mapper22->SetInputConnection(tensor22->GetOutputPort());
		vtkSmartVolumeMapper * mapper23 = vtkSmartVolumeMapper::New();
		mapper23->SetInputConnection(tensor23->GetOutputPort());
		vtkSmartVolumeMapper * mapper33 = vtkSmartVolumeMapper::New();
		mapper33->SetInputConnection(tensor33->GetOutputPort());



		vtkVolume * actor11 = vtkVolume::New();
		actor11->SetMapper(mapper11);
		vtkVolume * actor12 = vtkVolume::New();
		actor12->SetMapper(mapper12);
		vtkVolume * actor13 = vtkVolume::New();
		actor13->SetMapper(mapper13);
		vtkVolume * actor21 = vtkVolume::New();
		actor21->SetMapper(mapper12);
		vtkVolume * actor22 = vtkVolume::New();
		actor22->SetMapper(mapper22);
		vtkVolume * actor23 = vtkVolume::New();
		actor23->SetMapper(mapper23);
		vtkVolume * actor31 = vtkVolume::New();
		actor31->SetMapper(mapper13);
		vtkVolume * actor32 = vtkVolume::New();
		actor32->SetMapper(mapper23);
		vtkVolume * actor33 = vtkVolume::New();
		actor33->SetMapper(mapper33);



		vtkVolumeProperty * volumeProperty=vtkVolumeProperty::New();
		vtkColorTransferFunction * color=vtkColorTransferFunction::New();
		color->SetColorSpaceToLab();
		vtkPiecewiseFunction * opacity=vtkPiecewiseFunction::New();

		//color->AddRGBPoint(scalar_range[0],0.0,0.0,1.0);
		//color->AddRGBPoint((scalar_range[0]+scalar_range[1])/2,0,1,0);
		//color->AddRGBPoint(scalar_range[1],1.0,0.0,0.0);
//#----------------------------------------------------------------------------
		//opacity->AddPoint(scalar_range[0],0.1);
		//opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.1);
		//opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.05);
		//opacity->AddPoint(7*(scalar_range[0]+scalar_range[1])/8,0.05);
		//opacity->AddPoint(7*(scalar_range[0]+scalar_range[1])/8,0.1);
		//opacity->AddPoint(scalar_range[1],0.1);
		double diff = scalar_range[1]-scalar_range[0];
		// 设置透明度
		int opacityPoint=6;
		double * opValue;
		opValue = (double * )malloc(opacityPoint * sizeof(double));
		for (int i = 0;i<opacityPoint;i++)
		{
			opValue[i]=scalar_range[0]+(diff/(opacityPoint - 1))*i;
		}
		//opValue=[scalar_range[0],scalar_range[0]+diff/100,diff/100+scalar_range[0],6*diff/100+scalar_range[0],6*diff/100+scalar_range[0],scalar_range[1]]
		double * alpha;
		alpha = (double *)malloc(opacityPoint*sizeof(double));
		for (int i =0;i<opacityPoint;i++)
		{
			alpha[i] = 0.0+(1.0/(opacityPoint-1))*i;
		}
		//=[0.1,0.1,0.0,0.0,1,1]
		//for a in range(0,opacityPoint):
		//opacity.AddPoint(opValue[a],alpha[a])
		for (int i =0 ;i<opacityPoint;i++)
		{
			opacity->AddPoint(opValue[i],alpha[i]);
		}

		// 设置颜色点
		int RGBPoint=4;
		double * RGBValue;
		RGBValue = (double *)malloc(RGBPoint*sizeof(double));
		//double RGBValue[3]={scalar_range[0],diff/(RGBPoint - 1)+scalar_range[0],scalar_range[1]};
		for (int i=0;i<RGBPoint;i++)
		{
			RGBValue[i] = scalar_range[0]+(diff/(RGBPoint-1))*i;
		}
		double **RGB;
		//RGB = (double **)(new double[RGBPoint][3]);
		RGB = (double **)malloc(RGBPoint*sizeof(double *));
		for (int i =0;i<RGBPoint;i++)
		{
			*(RGB + i) = (double *)malloc(3*sizeof(double));
		}
		for (int i = 0;i<RGBPoint;i++)
		{
			if (i%3==0)
			{
				RGB[i][0]=0.0;RGB[i][1]=0.0;RGB[i][2]=1.0;
			}
			if (i%3==1)
			{
				RGB[i][0]=0.0;RGB[i][1]=1.0;RGB[i][2]=0.0;
			}
			if (i%3==2)
			{
				RGB[i][0]=1.0;RGB[i][1]=0.0;RGB[i][2]=0.0;
			}

		}
		//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
		for (int i=0;i<RGBPoint;i++)
		{
			color->AddRGBPoint(RGBValue[i],RGB[i][0],RGB[i][1],RGB[i][2]);
		}




		volumeProperty->SetScalarOpacity(opacity);
//#------------------------------------------------------------------------------
		volumeProperty->SetColor(color);

		volumeProperty->SetInterpolationTypeToNearest();

		actor11->SetProperty(volumeProperty);
		actor12->SetProperty(volumeProperty);
		actor13->SetProperty(volumeProperty);
		actor21->SetProperty(volumeProperty);
		actor22->SetProperty(volumeProperty);
		actor23->SetProperty(volumeProperty);
		actor31->SetProperty(volumeProperty);
		actor32->SetProperty(volumeProperty);
		actor33->SetProperty(volumeProperty);

//#create the outer boundary of the data
		vtkOutlineFilter * outline=vtkOutlineFilter::New();
		outline->SetInput(reader->GetOutput());
		vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
		outlineMapper->SetInputConnection(outline->GetOutputPort());
		vtkActor * outlineActor=vtkActor::New();
		outlineActor->SetMapper(outlineMapper);
		outlineActor->GetProperty()->SetColor(0,0,0);



		double xmins[3]={0,0.333333,0.666667};
		double xmaxs[3]={0.333333,0.666667,1};
		double ymins[3]={0,0.333333,0.666667};
		double ymaxs[3]={0.333333,0.666667,1};

	vtkCamera * camera=vtkCamera::New();
		camera->SetPosition(0,0,300);
		camera->SetFocalPoint(0,0,0);
		vtkRenderer * renderer11 = vtkRenderer::New();
		vtkRenderer * renderer12 = vtkRenderer::New();
		vtkRenderer * renderer13 = vtkRenderer::New();
		vtkRenderer * renderer21 = vtkRenderer::New();
		vtkRenderer * renderer22 = vtkRenderer::New();
		vtkRenderer * renderer23 = vtkRenderer::New();
		vtkRenderer * renderer31 = vtkRenderer::New();
		vtkRenderer * renderer32 = vtkRenderer::New();
		vtkRenderer * renderer33 = vtkRenderer::New();

		renderer11->SetActiveCamera(camera);
		renderer12->SetActiveCamera(camera);
		renderer13->SetActiveCamera(camera);
		renderer21->SetActiveCamera(camera);
		renderer22->SetActiveCamera(camera);
		renderer23->SetActiveCamera(camera);
		renderer31->SetActiveCamera(camera);
		renderer32->SetActiveCamera(camera);
		renderer33->SetActiveCamera(camera);

		renderer11->SetViewport(xmins[0],ymins[2],xmaxs[0],ymaxs[2]);
		renderer12->SetViewport(xmins[1],ymins[2],xmaxs[1],ymaxs[2]);
		renderer13->SetViewport(xmins[2],ymins[2],xmaxs[2],ymaxs[2]);
		renderer21->SetViewport(xmins[0],ymins[1],xmaxs[0],ymaxs[1]);
		renderer22->SetViewport(xmins[1],ymins[1],xmaxs[1],ymaxs[1]);
		renderer23->SetViewport(xmins[2],ymins[1],xmaxs[2],ymaxs[1]);
		renderer31->SetViewport(xmins[0],ymins[0],xmaxs[0],ymaxs[0]);
		renderer32->SetViewport(xmins[1],ymins[0],xmaxs[1],ymaxs[0]);
		renderer33->SetViewport(xmins[2],ymins[0],xmaxs[2],ymaxs[0]);

		renderer11->AddActor(actor11);
		renderer11->AddActor(outlineActor);
		renderer11->SetBackground(1, 1, 1); //# Set background to white

		renderer12->AddActor(actor12);
		renderer12->AddActor(outlineActor);
		renderer12->SetBackground(1, 1, 1); //# Set background to white

		renderer13->AddActor(actor13);
		renderer13->AddActor(outlineActor);
		renderer13->SetBackground(1, 1, 1); //# Set background to white

		renderer21->AddActor(actor21);
		renderer21->AddActor(outlineActor);
		renderer21->SetBackground(1, 1, 1); //# Set background to white

		renderer22->AddActor(actor22);
		renderer22->AddActor(outlineActor);
		renderer22->SetBackground(1, 1, 1); //# Set background to white

		renderer23->AddActor(actor23);
		renderer23->AddActor(outlineActor);
		renderer23->SetBackground(1, 1, 1); //# Set background to white

		renderer31->AddActor(actor31);
		renderer31->AddActor(outlineActor);
		renderer31->SetBackground(1, 1, 1); //# Set background to white

		renderer32->AddActor(actor32);
		renderer32->AddActor(outlineActor);
		renderer32->SetBackground(1, 1, 1); //# Set background to white

		renderer33->AddActor(actor33);
		renderer33->AddActor(outlineActor);
		renderer33->SetBackground(1, 1, 1); //# Set background to white

		vtkRenderWindow * renWin = vtkRenderWindow::New();
		renWin->AddRenderer(renderer11);
		renWin->AddRenderer(renderer12);
		renWin->AddRenderer(renderer13);
		renWin->AddRenderer(renderer21);
		renWin->AddRenderer(renderer22);
		renWin->AddRenderer(renderer23);
		renWin->AddRenderer(renderer31);
		renWin->AddRenderer(renderer32);
		renWin->AddRenderer(renderer33);

//#-------------------------------------------------------------------------------
//#20140820
		vtkScalarBarActor * scaleBar=vtkScalarBarActor::New();
			scaleBar->SetLookupTable(color);
			scaleBar->SetTitle("Scale Bar");
			scaleBar->SetNumberOfLabels(RGBPoint);
			scaleBar->GetTitleTextProperty()->SetColor(0,0,0);
			scaleBar->GetLabelTextProperty()->SetColor(0,0,0);
			renderer12->AddActor2D(scaleBar);

			vtkTransform * transform=vtkTransform::New();;
			transform->Translate(-5,-5,-5);
			vtkAxesActor * axes=vtkAxesActor::New();;
			axes->SetUserTransform(transform);
			axes->SetScale(10);
			axes->SetTotalLength(10,10,10);
			axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
			//vtkOutlineFilter * outline=vtkOutlineFilter::New();
			outline->SetInput(reader->GetOutput());
			//vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
			outlineMapper->SetInputConnection(outline->GetOutputPort());
			//vtkActor * outlineActor=vtkActor::New();
			outlineActor->SetMapper(outlineMapper);
			outlineActor->GetProperty()->SetColor(0,0,0);
			renderer11->AddActor(outlineActor);
			renderer12->AddActor(outlineActor);
			renderer13->AddActor(outlineActor);
			renderer21->AddActor(outlineActor);
			renderer22->AddActor(outlineActor);
			renderer23->AddActor(outlineActor);
			renderer31->AddActor(outlineActor);
			renderer32->AddActor(outlineActor);
			renderer33->AddActor(outlineActor);
			renderer12->AddActor(axes);
//#-------------------------------------------------------------------------------



		vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
		interactor->SetRenderWindow(renWin);

		interactor->Initialize();

		renWin->Render();

		interactor->Start();

		// 销毁动态内存
		// 销毁opValue
		if (opValue != NULL)
		{
			free(opValue);
		}
		// 销毁alpha
		if (alpha != NULL)
		{
			free(alpha);
		}
		// 销毁RGBValue
		if (RGBValue != NULL)
		{
			free(RGBValue);
		}
		// 销毁RGB
		for(int i=0;i<RGBPoint;i++){
			if (*(RGB+i) != NULL)
			{
				free(*(RGB+i));
			}
		}
		if (RGB != NULL)
		{
			free(RGB);
		}
}

//GPU加速
void PMPVisualizeVolumnGPU(CString filename){

	//	from vtk import *

	//		file_name = "strain.vtk"

	//# Read the source file.
	vtkDataSetReader * reader = vtkDataSetReader::New();
	reader->SetFileName(filename);
	reader->Update(); //# Needed because of GetScalarRange
	vtkDataSet * id = reader->GetOutput();
	double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
	//print(scalar_range);

	vtkLookupTable * colormap=vtkLookupTable::New();
	//HSV(Hue, Saturation, Value),色调（H），饱和度（S），亮度（V）
	colormap->SetHueRange(0.333333,0.6666667);
	colormap->SetSaturationRange(0,0);
	colormap->SetAlphaRange(0.5,0.5);
	colormap->SetValueRange(scalar_range);


	//# Create the mapper that corresponds the objects of the vtk file
	//# into graphics elements
	//vtkSmartVolumeMapper * mapper = vtkSmartVolumeMapper::New();
	vtkGPUVolumeRayCastMapper *mapper=vtkGPUVolumeRayCastMapper::New();
	mapper->SetInputConnection(reader->GetOutputPort());

	//# Create the Actor


	vtkVolume * actor = vtkVolume::New();
	actor->SetMapper(mapper);
	vtkVolumeProperty * volumeProperty=vtkVolumeProperty::New();
	vtkPiecewiseFunction * opacity=vtkPiecewiseFunction::New();
	vtkColorTransferFunction * color=vtkColorTransferFunction::New();
	color->SetColorSpaceToLab();
	//opacity->AddPoint(scalar_range[0],0.3);
	//opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.3);
	//opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.05);
	//opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.05);
	//opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.3);
	//opacity->AddPoint(scalar_range[1],0.3);

	//color->AddRGBPoint(scalar_range[0],0.0,0.0,1.0);
	//color->AddRGBPoint((scalar_range[0]+scalar_range[1])/2,0,1,0);
	//color->AddRGBPoint(scalar_range[1],1.0,0.0,0.0);

	//vtkPiecewiseFunction * gradOpacity = vtkPiecewiseFunction::New();
	//gradOpacity->AddPoint(scalar_range[0],0);
	//gradOpacity->AddPoint(scalar_range[1],0.3);
	/////////////////////////////////20140821/////////////////////////////////////////
	double diff = scalar_range[1]-scalar_range[0];
	// 设置透明度
	int opacityPoint=6;
	double * opValue;
	opValue = (double * )malloc(opacityPoint * sizeof(double));
	for (int i = 0;i<opacityPoint;i++)
	{
		opValue[i]=scalar_range[0]+(diff/(opacityPoint - 1))*i;
	}
	//opValue=[scalar_range[0],scalar_range[0]+diff/100,diff/100+scalar_range[0],6*diff/100+scalar_range[0],6*diff/100+scalar_range[0],scalar_range[1]]
	double * alpha;
	alpha = (double *)malloc(opacityPoint*sizeof(double));
	for (int i =0;i<opacityPoint;i++)
	{
		alpha[i] = 0.0+(1.0/(opacityPoint-1))*i;
	}
	//=[0.1,0.1,0.0,0.0,1,1]
	//for a in range(0,opacityPoint):
	//opacity.AddPoint(opValue[a],alpha[a])
	for (int i =0 ;i<opacityPoint;i++)
	{
		opacity->AddPoint(opValue[i],alpha[i]);
	}

	// 设置颜色点
	int RGBPoint=4;
	double * RGBValue;
	RGBValue = (double *)malloc(RGBPoint*sizeof(double));
	//double RGBValue[3]={scalar_range[0],diff/(RGBPoint - 1)+scalar_range[0],scalar_range[1]};
	for (int i=0;i<RGBPoint;i++)
	{
		RGBValue[i] = scalar_range[0]+(diff/(RGBPoint-1))*i;
	}
	double **RGB;
	//RGB = (double **)(new double[RGBPoint][3]);
	RGB = (double **)malloc(RGBPoint*sizeof(double *));
	for (int i =0;i<RGBPoint;i++)
	{
		*(RGB + i) = (double *)malloc(3*sizeof(double));
	}
	for (int i = 0;i<RGBPoint;i++)
	{
		if (i%3==0)
		{
			RGB[i][0]=0.0;RGB[i][1]=0.0;RGB[i][2]=1.0;
		}
		if (i%3==1)
		{
			RGB[i][0]=0.0;RGB[i][1]=1.0;RGB[i][2]=0.0;
		}
		if (i%3==2)
		{
			RGB[i][0]=1.0;RGB[i][1]=0.0;RGB[i][2]=0.0;
		}

	}
	//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
	for (int i=0;i<RGBPoint;i++)
	{
		color->AddRGBPoint(RGBValue[i],RGB[i][0],RGB[i][1],RGB[i][2]);
	}
	//////////////////////////////////20140821////////////////////////////////////////


	volumeProperty->SetScalarOpacity(opacity);
	volumeProperty->SetColor(color);
	//#volumeProperty->SetGradientOpacity(gradOpacity)
	volumeProperty->SetInterpolationTypeToNearest();

	actor->SetProperty(volumeProperty);

	//# Create the Renderer
	vtkRenderer * renderer = vtkRenderer::New();
	renderer->AddActor(actor);


	//#---------------------------------------------------------------------------
	//#20140820 added
	vtkScalarBarActor * scaleBar=vtkScalarBarActor::New();
	scaleBar->SetLookupTable(color);
	scaleBar->SetTitle("Scale Bar");
	scaleBar->SetNumberOfLabels(RGBPoint);
	scaleBar->GetTitleTextProperty()->SetColor(0,0,0);
	scaleBar->GetLabelTextProperty()->SetColor(0,0,0);
	renderer->AddActor2D(scaleBar);

	vtkTransform * transform=vtkTransform::New();
	transform->Translate(-5,-5,-5);
	vtkAxesActor * axes=vtkAxesActor::New();
	axes->SetUserTransform(transform);
	axes->SetScale(10);
	axes->SetTotalLength(10,10,10);
	axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	vtkOutlineFilter * outline=vtkOutlineFilter::New();
	outline->SetInput(reader->GetOutput());
	vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
	outlineMapper->SetInputConnection(outline->GetOutputPort());
	vtkActor * outlineActor=vtkActor::New();
	outlineActor->SetMapper(outlineMapper);
	outlineActor->GetProperty()->SetColor(0,0,0);
	renderer->AddActor(outlineActor);
	renderer->AddActor(axes);
	//#----------------------------------------------------------------------------



	renderer->SetBackground(1, 1, 1); //# Set background to white

	//# Create the RendererWindow
	vtkRenderWindow * renderer_window = vtkRenderWindow::New();
	renderer_window->AddRenderer(renderer);
	//print(scalar_range[0],scalar_range[1]);
	//# Create the RendererWindowInteractor and display the vtk_file
	vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
	interactor->SetRenderWindow(renderer_window);


	interactor->Initialize();
	//测试时间
	int timebegin=::GetTickCount();
	for(int i=0;i<90;i++)
	{
		renderer->GetActiveCamera()->Azimuth(1);
		renderer->ResetCamera();
		renderer_window->Render();
	}
	int timeend=::GetTickCount();
	cout<<"Elapsed time:"<<(timeend-timebegin)<<endl;

	interactor->Start();

	// 销毁动态内存
	// 销毁opValue
	if (opValue != NULL)
	{
		free(opValue);
	}
	// 销毁alpha
	if (alpha != NULL)
	{
		free(alpha);
	}
	// 销毁RGBValue
	if (RGBValue != NULL)
	{
		free(RGBValue);
	}
	// 销毁RGB
	for(int i=0;i<RGBPoint;i++){
		if (*(RGB+i) != NULL)
		{
			free(*(RGB+i));
		}
	}
	if (RGB != NULL)
	{
		free(RGB);
	}

}