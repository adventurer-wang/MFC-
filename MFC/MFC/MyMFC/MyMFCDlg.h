// MyMFCDlg.h: 头文件
//

#pragma once


// CMyMFCDlg 对话框
class CMyMFCDlg : public CDialogEx
{
// 构造
public:
	CMyMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数
	int flag = 1;
	//CComboBox m_comboBox;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_dialog };
#endif

protected:
virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	//自定义消息映射函数
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadioButton1();
	afx_msg void OnBnClickedRadioButton2();
	afx_msg void OnBnClickedRadioButton3();
	afx_msg void OnBnClickedRadioButton4();
	afx_msg void OnSelComChange();
	afx_msg void Onwarring(UINT nID, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CComboBox my_combox;
};
