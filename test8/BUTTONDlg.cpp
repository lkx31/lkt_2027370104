// BUTTONDlg.cpp: 实现文件
//

#include "pch.h"
#include "holy.h"
#include "afxdialogex.h"
#include "BUTTONDlg.h"


// BUTTONDlg 对话框

IMPLEMENT_DYNAMIC(BUTTONDlg, CDialogEx)

BUTTONDlg::BUTTONDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

BUTTONDlg::~BUTTONDlg()
{
}

void BUTTONDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BUTTONDlg, CDialogEx)
END_MESSAGE_MAP()


// BUTTONDlg 消息处理程序
