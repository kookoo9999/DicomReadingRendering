
// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.


#include <afxdisp.h>        // MFC 자동화 클래스입니다.



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원




#include "vtkAutoInit.h"		//
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkInteractionStyle)

#define vtkRenderingCore_AUTOINIT 3(vtkRenderingOpenGL2,vtkInteractionStyle, vtkRenderingFreeType)
#define vtkRenderingContext2D_AUTOINIT 1(vtkRenderingContextOpenGL2)


// VTK 관련 라이브러리 -------------------------------------------------------------------
#pragma comment(lib, "vtkChartsCore-8.2.lib")
#pragma comment(lib, "vtkCommonColor-8.2.lib")
#pragma comment(lib, "vtkCommonComputationalGeometry-8.2.lib")
#pragma comment(lib, "vtkCommonCore-8.2.lib")
//#pragma comment(lib, "vtkCommonCoreCxxTests.lib")
#pragma comment(lib, "vtkCommonDataModel-8.2.lib")
#pragma comment(lib, "vtkCommonExecutionModel-8.2.lib")
#pragma comment(lib, "vtkCommonMath-8.2.lib")
#pragma comment(lib, "vtkCommonMisc-8.2.lib")
#pragma comment(lib, "vtkCommonSystem-8.2.lib")
#pragma comment(lib, "vtkCommonTransforms-8.2.lib")
#pragma comment(lib, "vtkDICOMParser-8.2.lib")
#pragma comment(lib, "vtkDomainsChemistry-8.2.lib")
//#pragma comment(lib, "vtkDomainsChemistryCxxTests.lib")
#pragma comment(lib, "vtkDomainsChemistryOpenGL2-8.2.lib")
#pragma comment(lib, "vtkdoubleconversion-8.2.lib")
#pragma comment(lib, "vtkexodusII-8.2.lib")
#pragma comment(lib, "vtkexpat-8.2.lib")
#pragma comment(lib, "vtkFiltersAMR-8.2.lib")
#pragma comment(lib, "vtkFiltersCore-8.2.lib")
#pragma comment(lib, "vtkFiltersExtraction-8.2.lib")
#pragma comment(lib, "vtkFiltersFlowPaths-8.2.lib")
#pragma comment(lib, "vtkFiltersGeneral-8.2.lib")
#pragma comment(lib, "vtkFiltersGeneric-8.2.lib")
#pragma comment(lib, "vtkFiltersGeometry-8.2.lib")
#pragma comment(lib, "vtkFiltersHybrid-8.2.lib")
#pragma comment(lib, "vtkFiltersHyperTree-8.2.lib")
#pragma comment(lib, "vtkFiltersImaging-8.2.lib")
#pragma comment(lib, "vtkFiltersModeling-8.2.lib")
#pragma comment(lib, "vtkFiltersParallel-8.2.lib")
#pragma comment(lib, "vtkFiltersParallelImaging-8.2.lib")
#pragma comment(lib, "vtkFiltersPoints-8.2.lib")
#pragma comment(lib, "vtkFiltersProgrammable-8.2.lib")
#pragma comment(lib, "vtkFiltersSelection-8.2.lib")
#pragma comment(lib, "vtkFiltersSMP-8.2.lib")
#pragma comment(lib, "vtkFiltersSources-8.2.lib")
#pragma comment(lib, "vtkFiltersStatistics-8.2.lib")
#pragma comment(lib, "vtkFiltersTexture-8.2.lib")
#pragma comment(lib, "vtkFiltersTopology-8.2.lib")
#pragma comment(lib, "vtkFiltersVerdict-8.2.lib")
#pragma comment(lib, "vtkfreetype-8.2.lib")
#pragma comment(lib, "vtkGeovisCore-8.2.lib")
#pragma comment(lib, "vtkgl2ps-8.2.lib")
#pragma comment(lib, "vtkglew-8.2.lib")
#pragma comment(lib, "vtkhdf5_hl-8.2.lib")
#pragma comment(lib, "vtkhdf5-8.2.lib")
#pragma comment(lib, "vtkImagingColor-8.2.lib")
#pragma comment(lib, "vtkImagingCore-8.2.lib")
#pragma comment(lib, "vtkImagingFourier-8.2.lib")
#pragma comment(lib, "vtkImagingGeneral-8.2.lib")
#pragma comment(lib, "vtkImagingHybrid-8.2.lib")
#pragma comment(lib, "vtkImagingMath-8.2.lib")
#pragma comment(lib, "vtkImagingMorphological-8.2.lib")
#pragma comment(lib, "vtkImagingSources-8.2.lib")
#pragma comment(lib, "vtkImagingStatistics-8.2.lib")
#pragma comment(lib, "vtkImagingStencil-8.2.lib")
#pragma comment(lib, "vtkInfovisCore-8.2.lib")
#pragma comment(lib, "vtkInfovisLayout-8.2.lib")
#pragma comment(lib, "vtkInteractionImage-8.2.lib")
#pragma comment(lib, "vtkInteractionStyle-8.2.lib")
#pragma comment(lib, "vtkInteractionWidgets-8.2.lib")
#pragma comment(lib, "vtkIOAMR-8.2.lib")
#pragma comment(lib, "vtkIOAsynchronous-8.2.lib")
#pragma comment(lib, "vtkIOCityGML-8.2.lib")
#pragma comment(lib, "vtkIOCore-8.2.lib")
#pragma comment(lib, "vtkIOEnSight-8.2.lib")
#pragma comment(lib, "vtkIOExodus-8.2.lib")
#pragma comment(lib, "vtkIOExport-8.2.lib")
#pragma comment(lib, "vtkIOExportOpenGL2-8.2.lib")
#pragma comment(lib, "vtkIOExportPDF-8.2.lib")
#pragma comment(lib, "vtkIOGeometry-8.2.lib")
#pragma comment(lib, "vtkIOImage-8.2.lib")
#pragma comment(lib, "vtkIOImport-8.2.lib")
#pragma comment(lib, "vtkIOInfovis-8.2.lib")
#pragma comment(lib, "vtkIOLegacy-8.2.lib")
#pragma comment(lib, "vtkIOLSDyna-8.2.lib")
#pragma comment(lib, "vtkIOMINC-8.2.lib")
#pragma comment(lib, "vtkIOMovie-8.2.lib")
#pragma comment(lib, "vtkIONetCDF-8.2.lib")
#pragma comment(lib, "vtkIOParallel-8.2.lib")
#pragma comment(lib, "vtkIOParallelXML-8.2.lib")
#pragma comment(lib, "vtkIOPLY-8.2.lib")
#pragma comment(lib, "vtkIOSegY-8.2.lib")
#pragma comment(lib, "vtkIOSQL-8.2.lib")
#pragma comment(lib, "vtkIOTecplotTable-8.2.lib")
#pragma comment(lib, "vtkIOVeraOut-8.2.lib")
#pragma comment(lib, "vtkIOVideo-8.2.lib")
#pragma comment(lib, "vtkIOXML-8.2.lib")
#pragma comment(lib, "vtkIOXMLParser-8.2.lib")
#pragma comment(lib, "vtkjpeg-8.2.lib")
#pragma comment(lib, "vtkjsoncpp-8.2.lib")
#pragma comment(lib, "vtklibharu-8.2.lib")
#pragma comment(lib, "vtklibxml2-8.2.lib")
#pragma comment(lib, "vtkLocalExample-8.2.lib")
#pragma comment(lib, "vtklz4-8.2.lib")
#pragma comment(lib, "vtklzma-8.2.lib")
#pragma comment(lib, "vtkmetaio-8.2.lib")
//#pragma comment(lib, "vtkmyCommon.lib")
//#pragma comment(lib, "vtkmyImaging.lib")
//#pragma comment(lib, "vtkmyUnsorted.lib")
#pragma comment(lib, "vtkNetCDF-8.2.lib")
#pragma comment(lib, "vtkogg-8.2.lib")
#pragma comment(lib, "vtkParallelCore-8.2.lib")
#pragma comment(lib, "vtkpng-8.2.lib")
#pragma comment(lib, "vtkproj-8.2.lib")
#pragma comment(lib, "vtkpugixml-8.2.lib")
#pragma comment(lib, "vtkRenderingAnnotation-8.2.lib")
#pragma comment(lib, "vtkRenderingContext2D-8.2.lib")
#pragma comment(lib, "vtkRenderingContextOpenGL2-8.2.lib")
#pragma comment(lib, "vtkRenderingCore-8.2.lib")
#pragma comment(lib, "vtkRenderingFreeType-8.2.lib")
#pragma comment(lib, "vtkRenderingGL2PSOpenGL2-8.2.lib")
#pragma comment(lib, "vtkRenderingImage-8.2.lib")
#pragma comment(lib, "vtkRenderingLabel-8.2.lib")
#pragma comment(lib, "vtkRenderingLOD-8.2.lib")
#pragma comment(lib, "vtkRenderingOpenGL2-8.2.lib")
#pragma comment(lib, "vtkRenderingVolume-8.2.lib")
#pragma comment(lib, "vtkRenderingVolumeOpenGL2-8.2.lib")
#pragma comment(lib, "vtksqlite-8.2.lib")
#pragma comment(lib, "vtksys-8.2.lib")
//#pragma comment(lib, "vtkTestingGenericBridge-8.2.lib")
//#pragma comment(lib, "vtkTestingIOSQL-8.2.lib")
//#pragma comment(lib, "vtkTestingRendering-8.2.lib")
#pragma comment(lib, "vtktheora-8.2.lib")
#pragma comment(lib, "vtktiff-8.2.lib")
#pragma comment(lib, "vtkverdict-8.2.lib")
#pragma comment(lib, "vtkViewsContext2D-8.2.lib")
#pragma comment(lib, "vtkViewsCore-8.2.lib")
#pragma comment(lib, "vtkViewsInfovis-8.2.lib")
#pragma comment(lib, "vtkzlib-8.2.lib")
//#pragma comment(lib, "vtkTestingGenericBridge-8.2.lib")
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")








#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>


#include <vtkSphere.h>
#include <vtkBox.h>
#include <vtkSampleFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkRenderWindow.h>
#include <vtkCamera.h>
#include <vtkImageShiftScale.h>
#include <vtkImageData.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>

#include <vtkMarchingCubes.h>
#include <vtkMetaImageReader.h>
#include <vtkNamedColors.h>
#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkStripper.h>




#include <vtkActor.h>
#include <vtkImageActor.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkImageMapper3D.h>
#include <vtkImageMapToColors.h>
#include <vtkLookupTable.h>


#include <vtkTransform.h>




#include <vtkRenderingOpenGL2ObjectFactory.h>
#include <vtkRenderingVolumeOpenGL2ObjectFactory.h>

















#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

