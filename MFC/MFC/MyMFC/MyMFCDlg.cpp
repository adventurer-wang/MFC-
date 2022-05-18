
// MyMFCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MyMFC.h"
#include "MyMFCDlg.h"
#include "afxdialogex.h"
#include<cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


//
class CwarringDlg : public CDialogEx
{
public:
	CwarringDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CwarringDlg::CwarringDlg() : CDialogEx(IDD_DIALOG1)
{
}

void CwarringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CwarringDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CwarringDlg::OnBnClickedOk)
END_MESSAGE_MAP()

void CwarringDlg::OnBnClickedOk()
{
	CPaintDC dc(this);
	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
	CDialogEx::OnOK();
}

// CMyMFCDlg 对话框

CMyMFCDlg::CMyMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, my_combox);
}

BEGIN_MESSAGE_MAP(CMyMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDR__button1, &CMyMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CMyMFCDlg::OnBnClickedRadioButton1)
	ON_BN_CLICKED(IDC_RADIO2, &CMyMFCDlg::OnBnClickedRadioButton2)
	ON_BN_CLICKED(IDC_RADIO3, &CMyMFCDlg::OnBnClickedRadioButton3)
	ON_BN_CLICKED(IDC_RADIO4, &CMyMFCDlg::OnBnClickedRadioButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CwarringDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyMFCDlg::OnSelComChange)
	
END_MESSAGE_MAP()


// CMyMFCDlg 消息处理程序

BOOL CMyMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString num1=CString(_T("0")),num2= CString(_T("0"));;
	SetDlgItemText(IDC_EDIT1, num1);
	SetDlgItemText(IDC_EDIT2, num2);
	my_combox.SetCurSel(flag - 1);
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);
	
	//CString str = TEXT("");
	//m_comboBox.AddString(str);
	//m_comboBox.GetLBText(str); // 获取第0行的内容
	//IDC_COMBO1.A

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CMyMFCDlg::OnBnClickedOk()
{
	CPaintDC dc(this);
	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
	CDialogEx::OnOK();
}

void CMyMFCDlg::OnBnClickedButton1()
{ 
	CString str1, str2;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	double x = _ttof(str1), y = _ttof(str2);
	//CString CellID;
	//GetDlgItem(IDC_COMBO1)->GetWindowText(CellID);  //获得组合框中的选中内
	double sum = 0;
	if (flag == 4 && fabs(y) < 1e-15)
	{
		CwarringDlg dlg;
		dlg.DoModal();
	}
	else
	{
		if (this->flag == 1)
		{
			sum = x + y;
		}
		else if (this->flag == 2)
		{
			sum = x - y;
		}
		else if (this->flag == 3)
		{
			sum = x * y;
		}
		else
		{
			sum = x / y;
		}
		CString sum1;
		sum1.Format(TEXT("%f"), sum);
		GetDlgItem(IDC_EDIT3)->SetWindowText(sum1);
	}
}

void CMyMFCDlg::OnBnClickedRadioButton1()
{
	this->flag = 1;
	UpdateData(TRUE);
	my_combox.SetCurSel(flag-1); //设置第nIndex项为显示的内容
	UpdateData(FALSE);
}

void CMyMFCDlg::OnBnClickedRadioButton2()
{
	this->flag = 2;
	UpdateData(TRUE);
	my_combox.SetCurSel(flag - 1);
	UpdateData(FALSE);
}

void CMyMFCDlg::OnBnClickedRadioButton3()
{
	this->flag = 3;
	UpdateData(TRUE);
	my_combox.SetCurSel(flag - 1);
	UpdateData(FALSE);
}

void CMyMFCDlg::OnBnClickedRadioButton4()
{
	this->flag = 4;
	UpdateData(TRUE);
	my_combox.SetCurSel(flag - 1);
	UpdateData(FALSE);
}
void CMyMFCDlg::OnSelComChange()//选择下拉框某一列的时候得到响应
{
	UpdateData(TRUE);
	int index = my_combox.GetCurSel();
	if (index == 0)flag = 1;
	else if (index == 1)flag = 2;
	else if (index == 2)flag = 3;
	else flag = 4;
	switch(flag)
	{
	case 1:
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(0);
		break;
	case 2:
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(0);
		break;
	case 3:
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(1);
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(0);
		break;
	case 4:
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(1);
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(0);
		break;
	default:;
	}
	UpdateData(FALSE);
	/*CString ComSelItem(_T(""));//获取当前下拉框的值 
	my_combox.GetLBText(my_combox.GetCurSel(), ComSelItem);//获取CComBox下拉框当前选中的值
	if(_toComSelItem)*/
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。

void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CPaintDC dc(this);
	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
	CDialogEx::OnOK();
	//MessageBox(_T("自定义消息响应成功"));
}

