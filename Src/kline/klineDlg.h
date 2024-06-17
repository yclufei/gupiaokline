
// klineDlg.h : ͷ�ļ�
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


// CklineDlg �Ի���
class CklineDlg : public CDialogEx
{
// ����
public:
	CklineDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CklineDlg();	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KLINE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CKUI * m_cKui;

	// ���ɵ���Ϣӳ�亯��
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
