
// DicomReadingRenderingDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "DicomReadingRendering.h"
#include "DicomReadingRenderingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDicomReadingRenderingDlg 대화 상자



CDicomReadingRenderingDlg::CDicomReadingRenderingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DICOMREADINGRENDERING_DIALOG, pParent)
	, bCheckSkin(FALSE)
	, bCheckBone(FALSE)
	, sEdSkin(0)
	, sEdBone(0)
	, m_bSaCorAxView(FALSE)
	, m_fEditDebug(0)
	, m_iStaticSagMax(0)
	, m_iStaticCorMax(0)
	, m_iStaticAxiMax(0)
	, m_iEditSag(0)
	, m_iEditCor(0)
	, m_iEditAxi(0)
	, m_dEditRx(0)
	, m_dEditRy(0)
	, m_dEditRz(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDicomReadingRenderingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECKSKIN, bCheckSkin);
	DDX_Check(pDX, IDC_CHECKBONE, bCheckBone);
	DDX_Control(pDX, IDC_SLIDERSKIN, m_ctrSliderSkin);
	DDX_Control(pDX, IDC_SLIDERBONE, m_ctrSliderBone);
	DDX_Text(pDX, IDC_EDITSKIN2, sEdSkin);
	DDX_Text(pDX, IDC_EDITBONE2, sEdBone);
	DDX_Check(pDX, IDC_CHECKSACOAX, m_bSaCorAxView);
	DDX_Text(pDX, IDC_EDITDEBUG, m_fEditDebug);
	DDX_Control(pDX, IDC_SLIDERSAG, m_ctrSliderSag);
	DDX_Control(pDX, IDC_SLIDERCOR, m_ctrSliderCor);
	DDX_Control(pDX, IDC_SLIDERAXI, m_ctrSliderAxi);
	DDX_Text(pDX, IDC_STATICSAG, m_iStaticSagMax);
	DDX_Text(pDX, IDC_STATICCOR, m_iStaticCorMax);
	DDX_Text(pDX, IDC_STATICAXI, m_iStaticAxiMax);
	DDX_Text(pDX, IDC_EDITSAG, m_iEditSag);
	DDX_Text(pDX, IDC_EDITCOR, m_iEditCor);
	DDX_Text(pDX, IDC_EDITAXI, m_iEditAxi);
	DDX_Control(pDX, IDC_SLIDERRX, m_ctrSliderRx);
	DDX_Control(pDX, IDC_SLIDERRY, m_ctrSliderRy);
	DDX_Control(pDX, IDC_SLIDERRZ, m_ctrSliderRz);
	DDX_Text(pDX, IDC_EDITRX, m_dEditRx);
	DDX_Text(pDX, IDC_EDITRY, m_dEditRy);
	DDX_Text(pDX, IDC_EDITRZ, m_dEditRz);
}

BEGIN_MESSAGE_MAP(CDicomReadingRenderingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_OPEN32771, &CDicomReadingRenderingDlg::OnFileOpen32771)
	ON_BN_CLICKED(IDC_CHECKSKIN, &CDicomReadingRenderingDlg::OnBnClickedCheckskin)
	ON_BN_CLICKED(IDC_CHECKBONE, &CDicomReadingRenderingDlg::OnBnClickedCheckbone)
	ON_EN_CHANGE(IDC_EDITSKIN2, &CDicomReadingRenderingDlg::OnEnChangeEditskin2)
	ON_EN_CHANGE(IDC_EDITBONE2, &CDicomReadingRenderingDlg::OnEnChangeEditbone2)
//	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDERSKIN, &CDicomReadingRenderingDlg::OnNMReleasedcaptureSliderskin)
//	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDERBONE, &CDicomReadingRenderingDlg::OnNMReleasedcaptureSliderbone)
//	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDERSKIN, &CDicomReadingRenderingDlg::OnNMCustomdrawSliderskin)
//	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDERBONE, &CDicomReadingRenderingDlg::OnNMCustomdrawSliderbone)
//	ON_NOTIFY(NM_THEMECHANGED, IDC_SLIDERSKIN, &CDicomReadingRenderingDlg::OnNMThemeChangedSliderskin)
ON_WM_HSCROLL()
ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDERSKIN, &CDicomReadingRenderingDlg::OnNMReleasedcaptureSliderskin)
ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDERBONE, &CDicomReadingRenderingDlg::OnNMReleasedcaptureSliderbone)
ON_BN_CLICKED(IDC_CHECKSACOAX, &CDicomReadingRenderingDlg::OnBnClickedChecksacoax)
ON_WM_MOUSEMOVE()
ON_EN_CHANGE(IDC_EDITRX, &CDicomReadingRenderingDlg::OnEnChangeEditrx)
ON_EN_CHANGE(IDC_EDITRY, &CDicomReadingRenderingDlg::OnEnChangeEditry)
ON_EN_CHANGE(IDC_EDITRZ, &CDicomReadingRenderingDlg::OnEnChangeEditrz)
ON_STN_CLICKED(IDC_PICTURE_CONTROL, &CDicomReadingRenderingDlg::OnStnClickedPictureControl)
END_MESSAGE_MAP()


// CDicomReadingRenderingDlg 메시지 처리기

BOOL CDicomReadingRenderingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	InitializeVTKWindow(GetDlgItem(IDC_PICTURE_CONTROL)->GetSafeHwnd(), 0);
	ResizeVTKWindow(0);

	InitializeVTKWindow(GetDlgItem(IDC_PIC_SAG)->GetSafeHwnd(), 1);
	ResizeVTKWindow(1);

	InitializeVTKWindow(GetDlgItem(IDC_PIC_COR)->GetSafeHwnd(), 2);
	ResizeVTKWindow(2);

	InitializeVTKWindow(GetDlgItem(IDC_PIC_AXI)->GetSafeHwnd(), 3);
	ResizeVTKWindow(3);



	nDrawingNum = 2;

	// Bone Thresholding Parameter
	bCheckSkin = FALSE;
	bCheckBone = TRUE;

	sEdSkin = 73;
	sEdBone = 452;

	m_ctrSliderSkin.SetRange(0, 2500);
	m_ctrSliderBone.SetRange(0, 2500);

	m_ctrSliderSkin.SetPos(sEdSkin);
	m_ctrSliderBone.SetPos(sEdBone);

	m_bSaCorAxView = FALSE;

	m_iStaticSagMax = 0;
	m_iStaticAxiMax = 0;
	m_iStaticCorMax = 0;

	m_iEditSag = 0;
	m_iEditCor = 0;
	m_iEditAxi = 0;

	m_ctrSliderSag.SetPos(m_iEditSag);
	m_ctrSliderCor.SetPos(m_iEditCor);
	m_ctrSliderAxi.SetPos(m_iEditAxi);

	// View Direction
	PX = 0.0;		PY = 0.0;		PZ = -1.0;
	VX = 0.0;		VY = -1.0;		VZ = 0.0;

	m_dEditRx = 0;
	m_dEditRy = 0;
	m_dEditRz = 0;
	m_ctrSliderRx.SetRange(0, 360);
	m_ctrSliderRy.SetRange(0, 360);
	m_ctrSliderRz.SetRange(0, 360);
	m_ctrSliderRx.SetPos(m_dEditRx + 180);
	m_ctrSliderRy.SetPos(m_dEditRy + 180);
	m_ctrSliderRz.SetPos(m_dEditRz + 180);


	UpdateData(FALSE);

	bDicomLoading = FALSE;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDicomReadingRenderingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDicomReadingRenderingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDicomReadingRenderingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDicomReadingRenderingDlg::OnFileOpen32771()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
/*	TCHAR szFilter[] = L"DICOM(*.dcm)|All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, _T("*.dcm"), _T("Dicom"), OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{

	}
	*/


	// CString strInitPath = _T("C:\\");
	CString strInitPath = _T("D:\\user2\\Desktop\\DICOM\\");
	CFolderPickerDialog Picker(strInitPath, OFN_FILEMUSTEXIST, NULL, 0);

	if (Picker.DoModal() == IDOK)
	{
		CString strFolderPath = Picker.GetPathName();

		vtkObjectFactory::RegisterFactory(vtkRenderingOpenGL2ObjectFactory::New());
		vtkObjectFactory::RegisterFactory(vtkRenderingVolumeOpenGL2ObjectFactory::New());

		// Dicom Reading -----------------------------------------------------------------
		reader = vtkSmartPointer<vtkDICOMImageReader>::New();

		const char* dest;		dest = (CStringA)strFolderPath;
		reader->SetDirectoryName(dest);
		reader->Update();

		bDicomLoading = TRUE;
		//---------------------------------------------------------------------------------

		if(nDrawingNum == 1)
			Drawing_Method1();
		else if (nDrawingNum == 2)
			Drawing_Method2(TRUE);

	}



}

void CDicomReadingRenderingDlg::DicomRotation(double RX, double RY, double RZ)
{
	if (bDicomLoading) {}
	else { return; }

	reslice = vtkSmartPointer<vtkImageReslice>::New();

	double bounds[6];
	reader->GetOutput()->GetBounds(bounds);

	vtkSmartPointer<vtkTransform> transformA = vtkSmartPointer<vtkTransform>::New();

	double center[3];
	center[0] = (bounds[1] + bounds[0]) / 2.0;
	center[1] = (bounds[3] + bounds[2]) / 2.0;
	center[2] = (bounds[5] + bounds[4]) / 2.0;

	transformA->Translate(center[0], center[1], center[2]);
	transformA->RotateX(RX);
	transformA->RotateY(RY);
	transformA->RotateZ(RZ);
	transformA->Translate(-center[0], -center[1], -center[2]);

	reslice->SetInputConnection(reader->GetOutputPort());
	reslice->SetResliceTransform(transformA);
	reslice->SetInterpolationModeToCubic();
	reslice->SetOutputSpacing(reader->GetOutput()->GetSpacing()[0], reader->GetOutput()->GetSpacing()[1], reader->GetOutput()->GetSpacing()[2]);
	reslice->SetOutputOrigin(reader->GetOutput()->GetOrigin()[0], reader->GetOutput()->GetOrigin()[1], reader->GetOutput()->GetOrigin()[2]);
	reslice->SetOutputExtent(reader->GetOutput()->GetExtent());

}



void CDicomReadingRenderingDlg::Drawing_Method1()
{
	vtkSmartPointer<vtkImageData> imageData = vtkSmartPointer<vtkImageData>::New();
	// vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New();
	// vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> interactorStyle = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
	// vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
	vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
	vtkSmartPointer<vtkPiecewiseFunction> gradientOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
	vtkSmartPointer<vtkPiecewiseFunction> scalarOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
	vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
	vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();

	//const char* dest;		dest = (CStringA)strFolderPath;
	//reader->SetDirectoryName(dest);
	//reader->Update();

	imageData->ShallowCopy(reader->GetOutput());
	renderer->SetBackground(0.0, 0.0, 0.0);
	//renderWindow->AddRenderer(renderer);
	//renderWindow->SetSize(500, 500);
	//renderWindowInteractor->SetInteractorStyle(interactorStyle);
	//renderWindowInteractor->SetRenderWindow(renderWindow);

	volumeMapper->SetBlendModeToComposite();
	volumeMapper->SetRequestedRenderModeToGPU();
	volumeMapper->SetInputData(imageData);



	volumeProperty->ShadeOn();
	volumeProperty->SetInterpolationTypeToLinear();
	volumeProperty->SetAmbient(0.1);
	volumeProperty->SetDiffuse(0.9);
	volumeProperty->SetSpecular(0.2);
	volumeProperty->SetSpecularPower(10.0);
	gradientOpacity->AddPoint(0.0, 0.0);
	gradientOpacity->AddPoint(2000.0, 1.0);
	volumeProperty->SetGradientOpacity(gradientOpacity);

	scalarOpacity->AddPoint(-800.0, 0.0);
	scalarOpacity->AddPoint(-750.0, 1.0);
	scalarOpacity->AddPoint(-350.0, 1.0);
	scalarOpacity->AddPoint(-300.0, 0.0);
	scalarOpacity->AddPoint(-200.0, 0.0);
	scalarOpacity->AddPoint(-100.0, 1.0);
	scalarOpacity->AddPoint(1000.0, 0.0);
	scalarOpacity->AddPoint(2750.0, 0.0);
	scalarOpacity->AddPoint(2976.0, 1.0);
	scalarOpacity->AddPoint(3000.0, 0.0);
	volumeProperty->SetScalarOpacity(scalarOpacity);

	color->AddRGBPoint(-750.0, 0.08, 0.05, 0.03);
	color->AddRGBPoint(-350.0, 0.39, 0.25, 0.16);
	color->AddRGBPoint(-200.0, 0.80, 0.80, 0.80);
	color->AddRGBPoint(2750.0, 0.70, 0.70, 0.70);
	color->AddRGBPoint(3000.0, 0.35, 0.35, 0.35);
	volumeProperty->SetColor(color);

	volume->SetMapper(volumeMapper);
	volume->SetProperty(volumeProperty);
	renderer->AddVolume(volume);

	//renderWindow->Render();
	//renderWindowInteractor->Start();

	m_vtkRenderWindow->AddRenderer(renderer);
	m_vtkRenderWindow->Render();

	renderer->ResetCamera();
	m_vtkRenderWindow->Render();

}

#include <array>
void CDicomReadingRenderingDlg::Drawing_Method2(BOOL redrawing)
{
	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

	// Set the colors.
	std::array<unsigned char, 4> skinColor{ {255, 125, 64} };
	colors->SetColor("SkinColor", skinColor.data());
	std::array<unsigned char, 4> bkg{ {51, 77, 102, 255} };
	colors->SetColor("BkgColor", bkg.data());

	// Create the renderer, the render window, and the interactor. The renderer
	// draws into the render window, the interactor enables mouse- and
	// keyboard-based interaction with the data within the render window.
	//
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	//	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
	//	renWin->AddRenderer(render);

	//	vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//	iren->SetRenderWindow(renWin);

		// The following reader is used to read a series of 2D slices (images)
		// that compose the volume. The slice dimensions are set, and the
		// pixel spacing. The data Endianness must also be specified. The reader
		// uses the FilePrefix in combination with the slice number to construct
		// filenames using the format FilePrefix.%d. (In this case the FilePrefix
		// is the root name of the file: quarter.)
	//vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New();

	//const char* dest;		dest = (CStringA)strFolderPath;
	//reader->SetDirectoryName(dest);
	//reader->Update();

//	vtkSmartPointer<vtkImageData> imageData = vtkSmartPointer<vtkImageData>::New();
//	imageData->ShallowCopy(reader->GetOutput());

	// DICOM Image Transformation ---------------------------------------------------------------------------------------
	double bounds[6];
	reader->GetOutput()->GetBounds(bounds);
	//--------------------------------------------------------------------------------------------------------------------

	// 값 rotation -------------------------------------------------------------------------------------------------------
	BOOL bRotation = TRUE;

	if (bRotation)
	{
		UpdateData(TRUE);
		DicomRotation(m_dEditRx, m_dEditRy, m_dEditRz);
	}
	//--------------------------------------------------------------------------------------------------------------------

	// An isosurface, or contour value of 500 is known to correspond to the skin of the patient.
	// The triangle stripper is used to create triangle strips from the isosurface; these render much faster on many systems.
	vtkSmartPointer<vtkMarchingCubes> skinExtractor = vtkSmartPointer<vtkMarchingCubes>::New();

	if (bRotation)
		skinExtractor->SetInputConnection(reslice->GetOutputPort());
	else
		skinExtractor->SetInputConnection(reader->GetOutputPort());

	skinExtractor->SetValue(0, sEdSkin);
	CString strtest;
	strtest.Format(L"%d", sEdSkin);
	//AfxMessageBox(_T("sEdSkin="));
	//AfxMessageBox(strtest);

	vtkSmartPointer<vtkStripper> skinStripper = vtkSmartPointer<vtkStripper>::New();
	skinStripper->SetInputConnection(skinExtractor->GetOutputPort());

	vtkSmartPointer<vtkPolyDataMapper> skinMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	skinMapper->SetInputConnection(skinStripper->GetOutputPort());
	skinMapper->ScalarVisibilityOff();

	vtkSmartPointer<vtkActor> skin = vtkSmartPointer<vtkActor>::New();
	skin->SetMapper(skinMapper);
	skin->GetProperty()->SetDiffuseColor(colors->GetColor3d("SkinColor").GetData());
	skin->GetProperty()->SetSpecular(.3);
	skin->GetProperty()->SetSpecularPower(20);
	skin->GetProperty()->SetOpacity(.5);

	// An isosurface, or contour value of 1150 is known to correspond to the
	// bone of the patient.
	// The triangle stripper is used to create triangle strips from the
	// isosurface; these render much faster on may systems.
	vtkSmartPointer<vtkMarchingCubes> boneExtractor = vtkSmartPointer<vtkMarchingCubes>::New();

	if (bRotation) {
		boneExtractor->SetInputConnection(reslice->GetOutputPort());
		//AfxMessageBox(_T("bRotation True"));
	}
	else {
		boneExtractor->SetInputConnection(reader->GetOutputPort());
		//AfxMessageBox(_T("bRotation True"));
	}
	boneExtractor->SetValue(0, sEdBone);
	CString str = _T("");
	str.Format(_T("sEdBone = %d\n"),sEdBone);
	OutputDebugString(str);
	//AfxMessageBox(_T("sEdBone="));
	//AfxMessageBox(str);
	

	vtkSmartPointer<vtkStripper> boneStripper = vtkSmartPointer<vtkStripper>::New();
	boneStripper->SetInputConnection(boneExtractor->GetOutputPort());

	vtkSmartPointer<vtkPolyDataMapper> boneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	boneMapper->SetInputConnection(boneStripper->GetOutputPort());
	boneMapper->ScalarVisibilityOff();

	vtkSmartPointer<vtkActor> bone = vtkSmartPointer<vtkActor>::New();
	bone->SetMapper(boneMapper);
	bone->GetProperty()->SetDiffuseColor(colors->GetColor3d("Ivory").GetData());

	// An outline provides context around the data.
	//
	vtkSmartPointer<vtkOutlineFilter> outlineData = vtkSmartPointer<vtkOutlineFilter>::New();

	if (bRotation)
		outlineData->SetInputConnection(reslice->GetOutputPort());
	else
		outlineData->SetInputConnection(reader->GetOutputPort());

	vtkSmartPointer<vtkPolyDataMapper> mapOutline = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapOutline->SetInputConnection(outlineData->GetOutputPort());

	vtkSmartPointer<vtkActor> outline = vtkSmartPointer<vtkActor>::New();
	outline->SetMapper(mapOutline);
	outline->GetProperty()->SetColor(colors->GetColor3d("Black").GetData());


	// It is convenient to create an initial view of the data. The FocalPoint
	// and Position form a vector direction. Later on (ResetCamera() method)
	// this vector is used to position the camera to look at the data in
	// this direction.
//	vtkSmartPointer<vtkCamera> aCamera = vtkSmartPointer<vtkCamera>::New();
	if (redrawing)
	{
		aCamera = vtkSmartPointer<vtkCamera>::New();
//		aCamera->SetViewUp(0, 0, -1);
//		aCamera->SetPosition(0, -1, 0);
		aCamera->SetViewUp(PX, PY, PZ);
		aCamera->SetPosition(VX, VY, VZ);
		aCamera->SetFocalPoint(0, 0, 0);
		aCamera->ComputeViewPlaneNormal();
		aCamera->Azimuth(30.0);
		aCamera->Elevation(30.0);
	}
	else
	{
		aCamera->SetViewUp(PX, PY, PZ);
		aCamera->SetPosition(VX, VY, VZ);
	}

	// Actors are added to the renderer. An initial camera view is created.
	// The Dolly() method moves the camera towards the FocalPoint,
	// thereby enlarging the image.

	// renderer->RemoveAllViewProps();


	renderer->AddActor(outline);
	if(bCheckSkin)
		renderer->AddActor(skin);

	if(bCheckBone)
		renderer->AddActor(bone);


	vtkSmartPointer<vtkImageActor> sagittal = vtkSmartPointer<vtkImageActor>::New();
	vtkSmartPointer<vtkImageActor> axial = vtkSmartPointer<vtkImageActor>::New();
	vtkSmartPointer<vtkImageActor> coronal = vtkSmartPointer<vtkImageActor>::New();

	double renderer_bounds[6];
	renderer->ComputeVisiblePropBounds(renderer_bounds);

//	m_fEditDebug = renderer_bounds[1];
//	UpdateData(FALSE);

//	int axial_num_max = (int)abs(reader->GetImagePositionPatient()[1]);
//	int coronal_num_max = reader->GetWidth();
//	int sag_num_max = reader->GetHeight();
	int axial_num_max = renderer_bounds[5]/ reader->GetPixelSpacing()[2];
	int coronal_num_max = renderer_bounds[1] / reader->GetPixelSpacing()[0];
	int sag_num_max = renderer_bounds[3] / reader->GetPixelSpacing()[1];



	if (redrawing)
	{
		m_iStaticSagMax = sag_num_max;
		m_iStaticAxiMax = axial_num_max;
		m_iStaticCorMax = coronal_num_max;

		m_ctrSliderSag.SetRange(0, sag_num_max);
		m_ctrSliderCor.SetRange(0, coronal_num_max);
		m_ctrSliderAxi.SetRange(0, axial_num_max);

		m_iEditSag = (int)sag_num_max / 2;
		m_iEditCor = (int)coronal_num_max / 2;
		m_iEditAxi = (int)axial_num_max / 2;

		m_ctrSliderSag.SetPos(m_iEditSag);
		m_ctrSliderCor.SetPos(m_iEditCor);
		m_ctrSliderAxi.SetPos(m_iEditAxi);

		UpdateData(FALSE);
	}



//	m_fEditDebug = reader->GetImagePositionPatient()[2];
//	UpdateData(FALSE);


	UpdateData(TRUE);
	int axial_num_A = m_iEditAxi;
	int coronal_num_A = m_iEditCor;
	int sag_num_A = m_iEditSag;


	if (m_bSaCorAxView)
	{


		// Now we are creating three orthogonal planes passing through the
		// volume. Each plane uses a different texture map and therefore has
		// different coloration.

		// Start by creating a black/white lookup table.
		vtkSmartPointer<vtkLookupTable> bwLut = vtkSmartPointer<vtkLookupTable>::New();
		bwLut->SetTableRange(0, 2000);
		bwLut->SetSaturationRange(0, 0);
		bwLut->SetHueRange(0, 0);
		bwLut->SetValueRange(0, 1);
		bwLut->Build(); //effective built

		// Now create a lookup table that consists of the full hue circle (from HSV).
		vtkSmartPointer<vtkLookupTable> hueLut = vtkSmartPointer<vtkLookupTable>::New();
		hueLut->SetTableRange(0, 2000);
		hueLut->SetHueRange(0, 1);
		hueLut->SetSaturationRange(1, 1);
		hueLut->SetValueRange(1, 1);
		hueLut->Build(); //effective built

		// Finally, create a lookup table with a single hue but having a range in the saturation of the hue.
		vtkSmartPointer<vtkLookupTable> satLut = vtkSmartPointer<vtkLookupTable>::New();
		satLut->SetTableRange(0, 2000);
		satLut->SetHueRange(.6, .6);
		satLut->SetSaturationRange(0, 1);
		satLut->SetValueRange(1, 1);
		satLut->Build(); //effective built

		// Create the first of the three planes. The filter vtkImageMapToColors
		// maps the data through the corresponding lookup table created above.  The
		// vtkImageActor is a type of vtkProp and conveniently displays an image on
		// a single quadrilateral plane. It does this using texture mapping and as
		// a result is quite fast. (Note: the input image has to be unsigned char
		// values, which the vtkImageMapToColors produces.) Note also that by
		// specifying the DisplayExtent, the pipeline requests data of this extent
		// and the vtkImageMapToColors only processes a slice of data.
		vtkSmartPointer<vtkImageMapToColors> sagittalColors = vtkSmartPointer<vtkImageMapToColors>::New();

		if (bRotation)
			sagittalColors->SetInputConnection(reslice->GetOutputPort());
		else
			sagittalColors->SetInputConnection(reader->GetOutputPort());

		sagittalColors->SetLookupTable(bwLut);
		sagittalColors->Update();

		//		vtkSmartPointer<vtkImageActor> sagittal = vtkSmartPointer<vtkImageActor>::New();
		sagittal->GetMapper()->SetInputConnection(sagittalColors->GetOutputPort());
		sagittal->SetDisplayExtent(sag_num_A, sag_num_A, 0, coronal_num_max, 0, axial_num_max);
		sagittal->ForceOpaqueOn();

		// Create the second (axial) plane of the three planes. We use the
		// same approach as before except that the extent differs.
		vtkSmartPointer<vtkImageMapToColors> axialColors = vtkSmartPointer<vtkImageMapToColors>::New();

		if (bRotation)
			axialColors->SetInputConnection(reslice->GetOutputPort());
		else
			axialColors->SetInputConnection(reader->GetOutputPort());

		axialColors->SetLookupTable(hueLut);
		axialColors->Update();

		//		vtkSmartPointer<vtkImageActor> axial = vtkSmartPointer<vtkImageActor>::New();
		axial->GetMapper()->SetInputConnection(axialColors->GetOutputPort());
		axial->SetDisplayExtent(0, sag_num_max, 0, coronal_num_max, axial_num_A, axial_num_A);
		axial->ForceOpaqueOn();

		// Create the third (coronal) plane of the three planes. We use
		// the same approach as before except that the extent differs.
		vtkSmartPointer<vtkImageMapToColors> coronalColors = vtkSmartPointer<vtkImageMapToColors>::New();
		
		if (bRotation)
			coronalColors->SetInputConnection(reslice->GetOutputPort());
		else
			coronalColors->SetInputConnection(reader->GetOutputPort());

		coronalColors->SetLookupTable(satLut);
		coronalColors->Update();

		//		vtkSmartPointer<vtkImageActor> coronal = vtkSmartPointer<vtkImageActor>::New();
		coronal->GetMapper()->SetInputConnection(coronalColors->GetOutputPort());
		coronal->SetDisplayExtent(0, sag_num_max, coronal_num_A, coronal_num_A, 0, axial_num_max);
		coronal->ForceOpaqueOn();

	}

	//-----------------------------------------------------------------------------------------------------
	Drawing_SagCorAxia_View(bRotation, sag_num_max, coronal_num_max, axial_num_max, sag_num_A, coronal_num_A, axial_num_A);
	//-----------------------------------------------------------------------------------------------------


	if (m_bSaCorAxView)
	{
		renderer->AddActor(sagittal);
		renderer->AddActor(axial);
		renderer->AddActor(coronal);
	}


	if (bCheckSkin)
		skin->VisibilityOn();
	else
		skin->VisibilityOff();

	if (bCheckBone)
		bone->VisibilityOn();
	else
		bone->VisibilityOff();


//	if (redrawing) {
		renderer->SetActiveCamera(aCamera);
		renderer->ResetCamera();
		aCamera->Dolly(1.5);
//	}
	// Set a background color for the renderer and set the size of the
	// render window (expressed in pixels).
	renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());
	//	renWin->SetSize(640, 480);

		// Note that when camera movement occurs (as it does in the Dolly()
		// method), the clipping planes often need adjusting. Clipping planes
		// consist of two planes: near and far along the view direction. The
		// near plane clips out objects in front of the plane; the far plane
		// clips out objects behind the plane. This way only what is drawn
		// between the planes is actually rendered.
//	if (redrawing)
		renderer->ResetCameraClippingRange();


	m_vtkRenderWindow->AddRenderer(renderer);
	m_vtkRenderWindow->Render();

	//if (redrawing) {
		renderer->ResetCamera();
		m_vtkRenderWindow->Render();
	//}

}



void CDicomReadingRenderingDlg::Drawing_SagCorAxia_View(BOOL bRotation, int sag_num_max, int cor_num_max, int axi_num_max, int sag_num_A, int cor_num_A, int axi_num_A)
{
	CString strtest;
	strtest.Format(L"%d", sag_num_max);
	AfxMessageBox(strtest);
	
	/*AfxMessageBox(_T("sag_num_max = %d\n", sag_num_max));
	AfxMessageBox(_T("sag_num_A = %d\n", sag_num_A));
	AfxMessageBox(_T("cor_num_max = %d\n", cor_num_max));
	AfxMessageBox(_T("cor_num_A = %d\n", cor_num_A));
	AfxMessageBox(_T("axi_num_max = %d\n", axi_num_max));
	AfxMessageBox(_T("axi_num_A = %d\n", axi_num_A));*/
	
	vtkSmartPointer<vtkLookupTable> bwLut = vtkSmartPointer<vtkLookupTable>::New();
	bwLut->SetTableRange(0, 256);
	bwLut->SetSaturationRange(0, 0);
	bwLut->SetHueRange(0, 0);
	bwLut->SetValueRange(0, 3);
	bwLut->Build(); //effective built

	vtkSmartPointer<vtkCamera> sagCamera = vtkSmartPointer<vtkCamera>::New();
	sagCamera->SetViewUp(0, 0, -1);
	sagCamera->SetPosition(-1, 0, 0);
	sagCamera->SetFocalPoint(0, 0, 0);
	sagCamera->ComputeViewPlaneNormal();
	sagCamera->Azimuth(0.0);
	sagCamera->Elevation(0.0);

	vtkSmartPointer<vtkCamera> corCamera = vtkSmartPointer<vtkCamera>::New();
	corCamera->SetViewUp(0, -1, 0);
	corCamera->SetPosition(0, -1, 0);
	corCamera->SetFocalPoint(0, 0, 0);
	corCamera->ComputeViewPlaneNormal();
	corCamera->Azimuth(0.0);
	corCamera->Elevation(0.0);

	vtkSmartPointer<vtkCamera> axiCamera = vtkSmartPointer<vtkCamera>::New();
	axiCamera->SetViewUp(0, 0, -1);
	axiCamera->SetPosition(0, 0, -1);
	axiCamera->SetFocalPoint(0, 0, 0);
	axiCamera->ComputeViewPlaneNormal();
	axiCamera->Azimuth(0.0);
	axiCamera->Elevation(0.0);


	//-----------------------------------------------------------------------------------------------------
	vtkSmartPointer<vtkImageMapToColors> sagittalColors2 = vtkSmartPointer<vtkImageMapToColors>::New();

	/*if (bRotation) {
		sagittalColors2->SetInputConnection(reslice->GetOutputPort());
		AfxMessageBox(_T("reslice data"));
	}
	else {
		sagittalColors2->SetInputConnection(reader->GetOutputPort());
		AfxMessageBox(_T("reader data"));
	}*/
	sagittalColors2->SetInputConnection(reslice->GetOutputPort());

	sagittalColors2->SetLookupTable(bwLut);
	sagittalColors2->Update();

	vtkSmartPointer<vtkImageActor> sagittal2 = vtkSmartPointer<vtkImageActor>::New();
	sagittal2->GetMapper()->SetInputConnection(sagittalColors2->GetOutputPort());
	sagittal2->SetDisplayExtent(sag_num_A, sag_num_A, 0, cor_num_max, 0, axi_num_max);
	sagittal2->ForceOpaqueOn();

	vtkSmartPointer<vtkRenderer> aRenderer_Sag = vtkSmartPointer<vtkRenderer>::New();
	aRenderer_Sag->AddActor(sagittal2);
	m_vtkRenderSagital->AddRenderer(aRenderer_Sag);
	m_vtkRenderSagital->Render();

	aRenderer_Sag->SetActiveCamera(sagCamera);
	aRenderer_Sag->ResetCamera();
	sagCamera->Dolly(1.5);


	aRenderer_Sag->ResetCamera();
	m_vtkRenderSagital->Render();
	//-----------------------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------------------
	vtkSmartPointer<vtkImageMapToColors> coronalColors2 = vtkSmartPointer<vtkImageMapToColors>::New();

	if (bRotation)
		coronalColors2->SetInputConnection(reslice->GetOutputPort());
	else
		coronalColors2->SetInputConnection(reader->GetOutputPort());

	coronalColors2->SetLookupTable(bwLut);
	coronalColors2->Update();

	vtkSmartPointer<vtkImageActor> coronal2 = vtkSmartPointer<vtkImageActor>::New();
	coronal2->GetMapper()->SetInputConnection(coronalColors2->GetOutputPort());
	coronal2->SetDisplayExtent(0, sag_num_max, cor_num_A, cor_num_A, 0, axi_num_max);
	coronal2->ForceOpaqueOn();

	vtkSmartPointer<vtkRenderer> aRenderer_Cor = vtkSmartPointer<vtkRenderer>::New();
	aRenderer_Cor->AddActor(coronal2);
	m_vtkRenderCoronal->AddRenderer(aRenderer_Cor);
	m_vtkRenderCoronal->Render();

	aRenderer_Cor->SetActiveCamera(corCamera);
	aRenderer_Cor->ResetCamera();
	corCamera->Dolly(1.5);


	aRenderer_Cor->ResetCamera();
	m_vtkRenderCoronal->Render();
	//-----------------------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------------------
	vtkSmartPointer<vtkImageMapToColors> axiallColors2 = vtkSmartPointer<vtkImageMapToColors>::New();

	if (bRotation)
		axiallColors2->SetInputConnection(reslice->GetOutputPort());
	else
		axiallColors2->SetInputConnection(reader->GetOutputPort());

	axiallColors2->SetLookupTable(bwLut);
	axiallColors2->Update();

	vtkSmartPointer<vtkImageActor> axiall2 = vtkSmartPointer<vtkImageActor>::New();
	axiall2->GetMapper()->SetInputConnection(axiallColors2->GetOutputPort());
	axiall2->SetDisplayExtent(0, sag_num_max, 0, cor_num_max, axi_num_A, axi_num_A);
	axiall2->ForceOpaqueOn();

	vtkSmartPointer<vtkRenderer> aRenderer_Axi = vtkSmartPointer<vtkRenderer>::New();
	aRenderer_Axi->AddActor(axiall2);
	m_vtkRenderAxial->AddRenderer(aRenderer_Axi);
	m_vtkRenderAxial->Render();

	aRenderer_Axi->SetActiveCamera(axiCamera);
	aRenderer_Axi->ResetCamera();
	axiCamera->Dolly(1.5);


	aRenderer_Axi->ResetCamera();
	m_vtkRenderAxial->Render();
	//-----------------------------------------------------------------------------------------------------


}

/*
class MouseInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
	static MouseInteractorStyle* New();
	vtkTypeRevisionMacro(MouseInteractorStyle, vtkInteractorStyleTrackballCamera);

	virtual void OnLeftButtonDown()
	{
		cout << "Pressed left mouse button." << endl;
		// forward events
		vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
	}
};
*/

void CDicomReadingRenderingDlg::InitializeVTKWindow(void* hWnd, int Picid )
{
	vtkNew<vtkRenderWindowInteractor> interactor;
	if (Picid == 0)
	{
		interactor->SetInteractorStyle(vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New());
	}
	else 
	{
		//vtkSmartPointer<MouseInteractorStyle> style = vtkSmartPointer<MouseInteractorStyle>::New();
		//interactor->SetInteractorStyle(style);
		interactor->SetInteractorStyle(vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New());
	}




	if (Picid == 0)
	{
		vtkNew<vtkRenderer> renderer;
		renderer->SetBackground(0.1, 0.2, 0.3);
		m_vtkRenderWindow->SetParentId(hWnd);
		m_vtkRenderWindow->SetInteractor(interactor);
		m_vtkRenderWindow->AddRenderer(renderer);
		m_vtkRenderWindow->Render();
	}
	else if (Picid == 1)
	{
		vtkNew<vtkRenderer> renderer;
		renderer->SetBackground(0.1, 0.1, 0.1);
		m_vtkRenderSagital->SetParentId(hWnd);
		m_vtkRenderSagital->SetInteractor(interactor);
		m_vtkRenderSagital->AddRenderer(renderer);
		m_vtkRenderSagital->Render();
	}
	else if (Picid == 2)
	{
		vtkNew<vtkRenderer> renderer;
		renderer->SetBackground(0.1, 0.1, 0.1);
		m_vtkRenderCoronal->SetParentId(hWnd);
		m_vtkRenderCoronal->SetInteractor(interactor);
		m_vtkRenderCoronal->AddRenderer(renderer);
		m_vtkRenderCoronal->Render();
	}
	else if (Picid == 3)
	{
		vtkNew<vtkRenderer> renderer;
		renderer->SetBackground(0.1, 0.1, 0.1);
		m_vtkRenderAxial->SetParentId(hWnd);
		m_vtkRenderAxial->SetInteractor(interactor);
		m_vtkRenderAxial->AddRenderer(renderer);
		m_vtkRenderAxial->Render();
	}
	else 	{ 	}


}

void CDicomReadingRenderingDlg::ResizeVTKWindow(int Picid)
{
	CRect rc;
	if (Picid == 0)
	{
		GetDlgItem(IDC_PICTURE_CONTROL)->GetClientRect(rc);
		m_vtkRenderWindow->SetSize(rc.Width(), rc.Height());
	}
	else if(Picid == 1)
	{
		GetDlgItem(IDC_PIC_SAG)->GetClientRect(rc);
		m_vtkRenderSagital->SetSize(rc.Width(), rc.Height());
	}
	else if (Picid == 2)
	{
		GetDlgItem(IDC_PIC_COR)->GetClientRect(rc);
		m_vtkRenderCoronal->SetSize(rc.Width(), rc.Height());
	}
	else if (Picid == 3)
	{
		GetDlgItem(IDC_PIC_AXI)->GetClientRect(rc);
		m_vtkRenderAxial->SetSize(rc.Width(), rc.Height());
	}

}


void CDicomReadingRenderingDlg::OnBnClickedCheckskin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
}


void CDicomReadingRenderingDlg::OnBnClickedCheckbone()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
}


void CDicomReadingRenderingDlg::OnEnChangeEditskin2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrSliderSkin.SetPos(sEdSkin);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
	UpdateData(FALSE);
}


void CDicomReadingRenderingDlg::OnEnChangeEditbone2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrSliderBone.SetPos(sEdBone);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
	UpdateData(FALSE);
}


void CDicomReadingRenderingDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		if (pScrollBar == (CScrollBar*)&m_ctrSliderSkin)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderSkin.GetPos();
			sEdSkin = nPos;
			UpdateData(FALSE);

			if ( (nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE ) )
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}
		if (pScrollBar == (CScrollBar*)&m_ctrSliderBone)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderBone.GetPos();
			sEdBone = nPos;
			UpdateData(FALSE);

			if ((nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE))
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}

		if (pScrollBar == (CScrollBar*)&m_ctrSliderSag)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderSag.GetPos();
			m_iEditSag = nPos;
			UpdateData(FALSE);

			if ((nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE))
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}

		if (pScrollBar == (CScrollBar*)&m_ctrSliderCor)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderCor.GetPos();
			m_iEditCor = nPos;
			UpdateData(FALSE);

			if ((nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE))
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}

		if (pScrollBar == (CScrollBar*)&m_ctrSliderAxi)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderAxi.GetPos();
			m_iEditAxi = nPos;
			UpdateData(FALSE);

			if ((nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE))
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}

		if (pScrollBar == (CScrollBar*)&m_ctrSliderRx)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderRx.GetPos();
			m_dEditRx = nPos - 180;
			UpdateData(FALSE);

			if ((nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE))
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}

		if (pScrollBar == (CScrollBar*)&m_ctrSliderRy)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderRy.GetPos();
			m_dEditRy = nPos - 180;
			UpdateData(FALSE);

			if ((nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE))
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}

		if (pScrollBar == (CScrollBar*)&m_ctrSliderRz)
		{
			// 슬라이더의 위치를 검사한다.
			int nPos = m_ctrSliderRz.GetPos();
			m_dEditRz = nPos - 180;
			UpdateData(FALSE);

			if ((nSBCode == SB_ENDSCROLL) && (bDicomLoading == TRUE))
				CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
		}

	}
	else
	{
		// CScrollView를 상속받은 뷰의 경우 프래임의 스크롤롤 동작시 pScrollBar이 NULL된다.
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDicomReadingRenderingDlg::OnNMReleasedcaptureSliderskin(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CDicomReadingRenderingDlg::OnNMReleasedcaptureSliderbone(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CDicomReadingRenderingDlg::OnBnClickedChecksacoax()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
}


void CDicomReadingRenderingDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (bDicomLoading)
	{
		VX = aCamera->GetPosition()[0];
		VY = aCamera->GetPosition()[1];
		VZ = aCamera->GetPosition()[2];
		PX = aCamera->GetViewUp()[0];
		PY = aCamera->GetViewUp()[1];
		PZ = aCamera->GetViewUp()[2];
		CX = aCamera->GetClippingRange()[0];
		CY = aCamera->GetClippingRange()[1];
		CZ = aCamera->GetClippingRange()[2];

//		m_fEditDebug = VX;
//		UpdateData(FALSE);

	}


	CDialogEx::OnMouseMove(nFlags, point);
}


void CDicomReadingRenderingDlg::OnEnChangeEditrx()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrSliderRx.SetPos(m_dEditRx +180);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
}


void CDicomReadingRenderingDlg::OnEnChangeEditry()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrSliderRy.SetPos(m_dEditRy + 180);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
}


void CDicomReadingRenderingDlg::OnEnChangeEditrz()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrSliderRz.SetPos(m_dEditRz + 180);
	CDicomReadingRenderingDlg::Drawing_Method2(FALSE);
}


void CDicomReadingRenderingDlg::OnStnClickedPictureControl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
