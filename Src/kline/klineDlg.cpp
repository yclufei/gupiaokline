
#include "stdafx.h"
#include "kline.h"
#include "klineDlg.h"
#include "afxdialogex.h"

#include "CRingBuffer.h"

#include "CKUI.h"
#include "CCanvasBuySell.h"
#include "CCanvasGraph.h"
#include "CCanvasList.h"
#include "CCanvasToolbar.h"
#include "CCanvas.h"
#include "CCanvasText.h"
#include <string>
#include <vector>


#include "TestDataSource.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

time_t StringToDatetime(char *str);

#include <cstdlib>


int ran(int MIN_VALUE, int MAX_VALUE)
{
	return rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
}



CklineDlg::CklineDlg(CWnd* pParent ) : CDialogEx(IDD_KLINE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_cKui = NULL;
}


CklineDlg::~CklineDlg()
{

}

void CklineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CklineDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_MESSAGE(WM_GETSTOCKDATA, OnStockData)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()




BOOL CklineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码
	CRect ccRect;
	GetClientRect(&ccRect);


	/*
	int64_t mytesttime = StringToDatetime("2000-3-7");
	int listitemcount = 50;
	int itotalsize = (64 + sizeof(int64_t) + sizeof(double) * 5) * listitemcount;
	unsigned char * buf = new unsigned char[itotalsize];
	CRingBuffer rb((u8*)buf, itotalsize);
	char tmp[100];
	for (int i = 0; i < listitemcount; i++)
	{
		rb.WriteInt64(i);
		sprintf(tmp, "比特币%d", 20-i);
		rb.WriteFixString(tmp);
		rb.WriteDouble(ran(100, 2000) / 3);
		rb.WriteDouble(ran(100, 2000) / 3);
	}

	char curPath[MAX_PATH];
	::GetCurrentDirectoryA(MAX_PATH, curPath);

	char csvpath[MAX_PATH];
	sprintf(csvpath, "%s\\%s", curPath, "tdx.src.csv");
	CTestDataSource * ctds1 = new CTestDataSource(csvpath);
	unsigned char * tdx2_buffer = ctds1->GetBuffer();
	int nRows1 = ctds1->GetRow();


	// 半圆线型数据
	int htotalsize = ( sizeof(int64_t) * 2 + sizeof(double) * 2 ) * nRows1 + 1024;
	unsigned char * hbuf = new unsigned char[htotalsize];
	CRingBuffer hrb((u8*)hbuf, htotalsize);
	for (int i = 0; i < nRows1; i++)
	{
		double key = i + 100;
		hrb.WriteInt64(key);
		if (i%20 > 10)
		{
			double d1 = ran(100, 2000);
			hrb.WriteDouble(d1);
			double d2 = -ran(100, 2000);
			hrb.WriteDouble(d2);
		}
		else
		{
			double d1 = ran(100, 2000);
			hrb.WriteDouble(d1);
			double d2 = ran(100, 2000);
			hrb.WriteDouble(d2);
		}
	}
	*/

	m_cKui = new CKUI();

	m_cKui->Create(L"kui", WS_VISIBLE | WS_CHILD, ccRect, this, 1110);
	



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CklineDlg::OnPaint()
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
HCURSOR CklineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CklineDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (m_cKui != NULL && m_cKui->GetSafeHwnd() != NULL)
	{
		CRect rect;         
		GetClientRect(rect);     
		m_cKui->SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
	}
	
}

BOOL CklineDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//
	Invalidate(false);
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


LRESULT CklineDlg::OnStockData(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}


void CklineDlg::OnTimer(UINT_PTR nIDEvent)
{


	CDialogEx::OnTimer(nIDEvent);
}


void CklineDlg::OnDestroy()
{
	m_cKui->OnFinalRelease();
	delete m_cKui;


	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码

}
