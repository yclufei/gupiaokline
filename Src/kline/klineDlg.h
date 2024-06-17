
// klineDlg.h : 头文件
//

#pragma once


#include "CKUI.h"
#include "CCanvas.h"
#include "CKUI.h"
#include "CCanvasBuySell.h"
#include "CCanvasGraph.h"
#include "CCanvasList.h"
#include "CCanvasToolbar.h"
#include "CCanvas.h"
#include "CCanvasText.h"


// CklineDlg 对话框
class CklineDlg : public CDialogEx
{
// 构造
public:
	CklineDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CklineDlg();	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KLINE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	CKUI * m_cKui;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	afx_msg LRESULT OnStockData(WPARAM wParam, LPARAM lParam);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};
