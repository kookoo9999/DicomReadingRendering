
// DicomReadingRenderingDlg.h: 헤더 파일
//

#pragma once



// CDicomReadingRenderingDlg 대화 상자
class CDicomReadingRenderingDlg : public CDialogEx
{
// 생성입니다.
public:
	CDicomReadingRenderingDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DICOMREADINGRENDERING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	
// 구현입니다.
	vtkNew<vtkRenderWindow> m_vtkRenderWindow;
	vtkSmartPointer<vtkDICOMImageReader> reader;
	vtkSmartPointer<vtkCamera> aCamera;
	vtkSmartPointer<vtkImageReslice> reslice;

	void InitializeVTKWindow(void* hWnd, int Picid);
	void ResizeVTKWindow(int Picid);


	void Drawing_Method1();
	void Drawing_Method2(BOOL redrawing);
	int nDrawingNum;
	void Drawing_SagCorAxia_View(BOOL bRotation, int sag_num_max, int cor_num_max, int axi_num_max, int sag_num_A, int cor_num_A, int axi_num_A);
	void DicomRotation(double RX, double RY, double RZ);

	vtkNew<vtkRenderWindow> m_vtkRenderSagital;
	vtkNew<vtkRenderWindow> m_vtkRenderCoronal;
	vtkNew<vtkRenderWindow> m_vtkRenderAxial;


protected:
	HICON m_hIcon;

	BOOL bDicomLoading;
	double PX, PY, PZ, VX, VY, VZ, CX, CY, CZ;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen32771();
	BOOL bCheckSkin;
	BOOL bCheckBone;
//	CString sEdSkin;
//	CString sEdBone;
	CSliderCtrl m_ctrSliderSkin;
	CSliderCtrl m_ctrSliderBone;
	int sEdSkin;
	int sEdBone;
	afx_msg void OnBnClickedCheckskin();
	afx_msg void OnBnClickedCheckbone();
	afx_msg void OnEnChangeEditskin2();
	afx_msg void OnEnChangeEditbone2();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnNMReleasedcaptureSliderskin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderbone(NMHDR *pNMHDR, LRESULT *pResult);
	BOOL m_bSaCorAxView;
	afx_msg void OnBnClickedChecksacoax();
	double m_fEditDebug;
	CSliderCtrl m_ctrSliderSag;
	CSliderCtrl m_ctrSliderCor;
	CSliderCtrl m_ctrSliderAxi;
	int m_iStaticSagMax;
	int m_iStaticCorMax;
	int m_iStaticAxiMax;
	int m_iEditSag;
	int m_iEditCor;
	int m_iEditAxi;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CSliderCtrl m_ctrSliderRx;
	CSliderCtrl m_ctrSliderRy;
	CSliderCtrl m_ctrSliderRz;
	double m_dEditRx;
	double m_dEditRy;
	double m_dEditRz;
	afx_msg void OnEnChangeEditrx();
	afx_msg void OnEnChangeEditry();
	afx_msg void OnEnChangeEditrz();
	afx_msg void OnStnClickedPictureControl();
};
