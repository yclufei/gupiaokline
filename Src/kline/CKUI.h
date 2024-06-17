// CKUI.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装器类的声明

#pragma once

#include "commacro.h"
/////////////////////////////////////////////////////////////////////////////
// CKUI

class CKUI : public CWnd
{
protected:
	DECLARE_DYNCREATE(CKUI)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xF1F71C14, 0xD8D6, 0x4256, { 0xBC, 0xD3, 0xC5, 0x5, 0x21, 0xB5, 0xD, 0x88 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:

// 操作
public:

	LPDISPATCH GetMainCnv()
	{
		LPDISPATCH result;
		InvokeHelper(DISPIDGETMAINCNV, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void SetData(signed char * pszCanvasName, unsigned char * pData, long nSize, signed char * pszDataFmts, signed char * pszColNames, signed char * pszLineTypes, signed char * pszColors)
	{
		static BYTE parms[] = VTS_PI1 VTS_PUI1 VTS_I4 VTS_PI1 VTS_PI1 VTS_PI1 VTS_PI1 ;
		InvokeHelper(DISPIDSETDATA, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pszCanvasName, pData, nSize, pszDataFmts, pszColNames, pszLineTypes, pszColors);
	}
	void SetTitle(signed char * Canvas, signed char * title)
	{
		static BYTE parms[] = VTS_PI1 VTS_PI1 ;
		InvokeHelper(DISPIDSETTITLE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Canvas, title);
	}

	void SetXAxis(signed char * pszCanvasName, signed char * __MIDL__KUI0000)
	{
		static BYTE parms[] = VTS_PI1 VTS_PI1;
		InvokeHelper(DISPIDSETXAXIS, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pszCanvasName, __MIDL__KUI0000);
	}
	void SetXAxisVisible(signed char * pszCanvasName, long __MIDL__KUI0001)
	{
		static BYTE parms[] = VTS_PI1 VTS_I4;
		InvokeHelper(DISPIDSETXAXISVISIBLE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pszCanvasName, __MIDL__KUI0001);
	}
	void SetXRange(signed char * pszCanvasName, __int64 __MIDL__KUI0002, __int64 __MIDL__KUI0003)
	{
		static BYTE parms[] = VTS_PI1 VTS_I8 VTS_I8;
		InvokeHelper(DISPIDSETXRANGE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pszCanvasName, __MIDL__KUI0002, __MIDL__KUI0003);
	}
	void SetXRangeByRow(signed char * pszCanvasName, long __MIDL__KUI0004, long __MIDL__KUI0005)
	{
		static BYTE parms[] = VTS_PI1 VTS_I4 VTS_I4;
		InvokeHelper(DISPIDSETXRANGEBYROW, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pszCanvasName, __MIDL__KUI0004, __MIDL__KUI0005);
	}


};
