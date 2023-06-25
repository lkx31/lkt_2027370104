
// MFClesson88Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFClesson88.h"
#include "MFClesson88Dlg.h"
#include "afxdialogex.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <afxsock.h>
#include "resource.h"
#include <json/json.h>

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
	afx_msg void OnBnClickedButton3();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CAboutDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFClesson88Dlg 对话框



CMFClesson88Dlg::CMFClesson88Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCLESSON88_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFClesson88Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFClesson88Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CMFClesson88Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CMFClesson88Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFClesson88Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFClesson88Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFClesson88Dlg 消息处理程序

BOOL CMFClesson88Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFClesson88Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFClesson88Dlg::OnPaint()
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFClesson88Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedButton3()
{

}


void CMFClesson88Dlg::OnBnClickedButton3()
{
	CString strFilter = _T("JPEG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, strFilter, this);

	if (dlg.DoModal() == IDOK)
	{
		CString strFileName = dlg.GetPathName();

		CImage image;
		HRESULT hr = image.Load(strFileName);
		if (SUCCEEDED(hr))
		{
			CStatic* pImageCtrl = (CStatic*)GetDlgItem(IDC_STATIC);
			if (pImageCtrl != nullptr)
			{
				CRect rect;
				pImageCtrl->GetClientRect(&rect);
				image.Draw(pImageCtrl->GetDC()->m_hDC, rect);
				pImageCtrl->ReleaseDC(pImageCtrl->GetDC());
				GetDlgItem(IDC_EDIT1)->SetWindowText(strFileName);
			}
		}
	}
}


void CMFClesson88Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFClesson88Dlg::OnBnClickedButton1()
CSocket clientSocket;
if (clientSocket.Create() && clientSocket.Connect(_T("127.0.0.1"), 35000))
{
	// 构造 JSON 对象
	rapidjson::Document doc;
	doc.SetObject();
	rapidjson::Value params(rapidjson::kObjectType);
	params.AddMember("name", "John", doc.GetAllocator());
	params.AddMember("age", 30, doc.GetAllocator());
	doc.AddMember("type", "person", doc.GetAllocator());
	doc.AddMember("params", params, doc.GetAllocator());

	// 转换为 JSON 字符串
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);
	CStringA jsonString(buffer.GetString());

	// 发送 JSON 字符串
	clientSocket.Send(jsonString, jsonString.GetLength());

	// 接收响应
	char buffer[1024] = { 0 };
	int len = clientSocket.Receive(buffer, sizeof(buffer) - 1);

	// 解析 JSON 字符串
	rapidjson::Document response;
	response.Parse(buffer);
	CStringA name = response["name"].GetString();
	int age = response["age"].GetInt();

	// 显示响应
	CStringA message;
	message.Format("Name: %s, Age: %d", name, age);
	SetDlgItemTextA(IDC_STATIC_TEXT, (LPCTSTR)message);
}
else
{
	SetDlgItemText(IDC_STATIC_TEXT, _T("连接服务器失败！"));
}


void CMFClesson88Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
