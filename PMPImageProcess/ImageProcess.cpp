#include "vtkSmartPointer.h"
#include "vtkJPEGReader.h"
#include "vtkImageAccumulate.h"
#include "vtkBarChartActor.h"
#include "vtkLegendBoxActor.h"
#include "vtkIntArray.h"
#include "vtkDataObject.h"
#include "vtkImageData.h"
#include "vtkProperty2D.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkFieldData.h"
#include "vtkRenderWindowInteractor.h"

// colorHistogram
#include "vtkXYPlotActor.h"
#include "vtkImageExtractComponents.h"

void histogramDemo();
void colorHistogram();
void colorHistogram2();

int main(){

	//histogramDemo();
	colorHistogram();
	//colorHistogram2();
}

void histogramDemo(){
	vtkSmartPointer<vtkJPEGReader> reader =
		vtkSmartPointer<vtkJPEGReader>::New();
	reader->SetFileName ("1.jpg");
	reader->Update();
	int bins = 16;
	vtkSmartPointer<vtkImageAccumulate> histogram =
		vtkSmartPointer<vtkImageAccumulate>::New();
	histogram->SetInput((vtkDataObject *)(reader->GetOutput()));
	histogram->SetComponentExtent(0, bins-1, 0, 0, 0, 0);
	histogram->SetComponentOrigin(0, 0, 0);
	histogram->SetComponentSpacing(256/bins, 0, 0);
	histogram->Update();
	vtkSmartPointer<vtkIntArray> frequencies = 
		vtkSmartPointer<vtkIntArray>::New();
	frequencies->SetNumberOfComponents(1);
	frequencies->SetNumberOfTuples(bins);
	int* output = static_cast<int*>(histogram->GetOutput()->GetScalarPointer());
	for(int j = 0; j < bins; ++j)
	{
		frequencies->SetTuple1(j, *output++);
	}
	vtkSmartPointer<vtkDataObject> dataObject =
		vtkSmartPointer<vtkDataObject>::New();
	dataObject->GetFieldData()->AddArray( frequencies );
	vtkSmartPointer<vtkBarChartActor> barChart =
		vtkSmartPointer<vtkBarChartActor>::New();
	barChart->SetInput(dataObject);
	barChart->SetTitle("Histogram");
	barChart->GetPositionCoordinate()->SetValue(0.05,0.05,0.0);
	barChart->GetPosition2Coordinate()->SetValue(0.95,0.95,0.0);
	barChart->GetProperty()->SetColor(1,1,1);
	barChart->GetLegendActor()->SetNumberOfEntries(
		dataObject->GetFieldData()->GetArray(0)->GetNumberOfTuples());
	barChart->LegendVisibilityOff();
	barChart->LabelVisibilityOff();
	double red[3] = {1, 0, 0 };
	for(int i = 0; i < bins; ++i)
	{
		barChart->SetBarColor(i, red );
	}
	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	renderer->AddActor(barChart);
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	renderWindow->SetSize(640, 480);
	vtkSmartPointer<vtkRenderWindowInteractor> interactor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	interactor->SetRenderWindow(renderWindow);
	interactor->Initialize();
	interactor->Start();
}

void colorHistogram(){
	vtkSmartPointer<vtkJPEGReader>reader =
		vtkSmartPointer<vtkJPEGReader>::New();
	reader->SetFileName ( "1.jpg" );
	reader->Update();
	
	int numComponents =reader->GetOutput()->GetNumberOfScalarComponents();
	
	vtkSmartPointer<vtkXYPlotActor> plot =
		vtkSmartPointer<vtkXYPlotActor>::New();
	plot->ExchangeAxesOff();
	plot->SetLabelFormat( "%g" );
	plot->SetXTitle( "Value" );
	plot->SetYTitle( "Frequency" );
	plot->SetXValuesToValue();
	double colors[3][3] = {
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 1 }
		};
		const char* labels[3] = { "Red", "Green","Blue" };
		int xmax = 0;
		int ymax = 0;
		vtkSmartPointer<vtkImageExtractComponents> extract =
			vtkSmartPointer<vtkImageExtractComponents>::New();
		extract->SetInputConnection( reader->GetOutputPort() );
		extract->SetComponents( 1 );
		extract->Update();
		int temp = extract->GetOutput()->GetNumberOfPoints();
		vtkPointData * points = extract->GetOutput()->GetPointData();
		int mypoint =3344 ;
		double coordinates [3] = {76,44,1};
		vtkImageData * d = extract->GetOutput();
		int com=0;
		com = d->GetScalarComponentAsFloat(75,200-43,0,0);
		int dimension[3];
		d->GetDimensions(dimension);
		
		extract->GetOutput()->GetPoint(mypoint,coordinates);
		printf("%d %d %d %d %d",temp,dimension[0],dimension[1],dimension[2],com);
		for( int i = 0; i < numComponents; ++i )
		{
				vtkSmartPointer<vtkImageExtractComponents> extract =
				vtkSmartPointer<vtkImageExtractComponents>::New();
				extract->SetInputConnection( reader->GetOutputPort() );
				extract->SetComponents( i );
				extract->Update();
				double range[2];
				extract->GetOutput()->GetScalarRange( range );
				
				int extent =static_cast<int>(range[1])-static_cast<int>(range[0])-1;
				vtkSmartPointer<vtkImageAccumulate> histogram =
					vtkSmartPointer<vtkImageAccumulate>::New();
				histogram->SetInputConnection( extract->GetOutputPort() );
				histogram->SetComponentExtent( 0,extent, 0,0, 0,0);
				histogram->SetComponentOrigin( range[0],0,0 );
				histogram->SetComponentSpacing( 5,0,0 );
				histogram->SetIgnoreZero( 1 );
				histogram->Update();
				if( range[1] > xmax )
					{
						 xmax = range[1];
						}
				if( histogram->GetOutput()->GetScalarRange()[1] > ymax )
					{
						ymax =histogram->GetOutput()->GetScalarRange()[1];
						}
				plot->AddInput( histogram->GetOutput() );
				plot->SetPlotColor(i,colors[i]);
				plot->SetPlotLabel(i,labels[i]);
				plot->LegendOn();
			}
		plot->SetXRange( 0, xmax);
		plot->SetYRange( 0, ymax);
		vtkSmartPointer<vtkRenderer> renderer =
			vtkSmartPointer<vtkRenderer>::New();
		renderer->AddActor(plot);
		vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
		renderWindow->AddRenderer( renderer );
		renderWindow->SetSize(640, 480);
		vtkSmartPointer<vtkRenderWindowInteractor> interactor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();
		interactor->SetRenderWindow( renderWindow );
		interactor->Initialize();
		interactor->Start();
}
void colorHistogram2(){
	vtkSmartPointer<vtkJPEGReader>reader =
		vtkSmartPointer<vtkJPEGReader>::New();
	reader->SetFileName ( "2.jpg" );
	reader->Update();
	int numComponents =reader->GetOutput()->GetNumberOfScalarComponents();

	vtkSmartPointer<vtkXYPlotActor> plot =
		vtkSmartPointer<vtkXYPlotActor>::New();
	plot->ExchangeAxesOff();
	plot->SetLabelFormat( "%g" );
	plot->SetXTitle( "Value" );
	plot->SetYTitle( "Frequency" );
	plot->SetXValuesToValue();
	double colors[3][3] = {
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 1 }
	};
	const char* labels[3] = { "Red", "Green","Blue" };
	int xmax = 0;
	int ymax = 0;
	for( int i = 0; i < numComponents; ++i )
	{
		vtkSmartPointer<vtkImageExtractComponents> extract =
			vtkSmartPointer<vtkImageExtractComponents>::New();
		extract->SetInputConnection( reader->GetOutputPort() );
		extract->SetComponents( i );
		extract->Update();
		double range[2];
		extract->GetOutput()->GetScalarRange( range );
		int extent =static_cast<int>(range[1])-static_cast<int>(range[0])-1;
		vtkSmartPointer<vtkImageAccumulate> histogram =
			vtkSmartPointer<vtkImageAccumulate>::New();
		histogram->SetInputConnection( extract->GetOutputPort() );
		histogram->SetComponentExtent( 0,extent, 0,0, 0,0);
		histogram->SetComponentOrigin( range[0],0,0 );
		histogram->SetComponentSpacing( 1,0,0 );
		histogram->SetIgnoreZero( 1 );
		histogram->Update();

		if( range[1] > xmax )
		{
			xmax = range[1];
		}
		if( histogram->GetOutput()->GetScalarRange()[1] > ymax )
		{
			ymax =histogram->GetOutput()->GetScalarRange()[1];
		}
		plot->AddInput( histogram->GetOutput() );
		plot->SetPlotColor(i,colors[i]);
		plot->SetPlotLabel(i,labels[i]);
		plot->LegendOn();
	}
	plot->SetXRange( 0, xmax);
	plot->SetYRange( 0, ymax);
	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	renderer->AddActor(plot);
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer( renderer );
	renderWindow->SetSize(640, 480);
	vtkSmartPointer<vtkRenderWindowInteractor> interactor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	interactor->SetRenderWindow( renderWindow );
	interactor->Initialize();
	interactor->Start();
}